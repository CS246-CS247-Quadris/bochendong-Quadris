#include <iostream>
#include "Grid.hpp"
using namespace std;

void prefix(string s){
    int n = 1;
    stringstream ss;
    vector <string> operation;
    
    operation.push_back("clockwise");
    operation.push_back("counterclockwise");
    operation.push_back("left");
    operation.push_back("right");
    operation.push_back("down");
    operation.push_back("drop");
    operation.push_back("levelup");
    operation.push_back("leveldown");
    
    if (s == "c" || s == "d" || s == "le" || s == "l" || s == "lev" || s == "leve" || s == "level") {
        throw No_Matching_prefix("ambiguous operation");
    }
    unsigned long int first_number = s.find_first_not_of("1234567890");
    if (first_number != 0){
        string pre = s.substr(0,first_number);
        ss << pre;
        ss >> n;
        s = s.substr(first_number,s.length());
    }
    if (s == "c" || s == "d" || s == "le" || s == "l" || s == "lev" || s == "leve" || s == "level") {
        throw No_Matching_prefix("ambiguous operation");
    }
    for (int i = 0; i < 8; i ++){
        unsigned long int len = s.length();
        unsigned long int op_len = operation[i].length();
        if (len <= op_len){
            int k;
            for (k = 0; k < len ; k ++){
                if (s[k] != operation[i][k]) break;
            }
            if (k == len) throw Has_front_number(n,operation[i]);
        }
    }
    throw No_Matching_prefix("Invalid operation");
}

int main(int argc, const char * argv[]) {
    string s;
    Grid grid;
    cout << "=============" << endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "|  QUADRIS  |" << endl;
    cout << "|           |" << endl;
    cout << "|+---------+|" << endl;
    cout << "||  START  ||" << endl;
    cout << "|+---------+|" << endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "|+---------+|" << endl;
    cout << "||  EXIT   ||" << endl;
    cout << "|+---------+|" << endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "=============" << endl;
    bool text_only = false;
    int level = 0;
    string file = "sequence.txt";
    int pos = 1;
    while(pos < argc){
        string command = argv[pos++];
        if (command == "-text") {
            text_only = true;
        } else if (command == "-scriptfile") {
            file = argv[pos++];
        } else if (command == "-startlevel") {
            string start = argv[pos++];
            stringstream ss;
            ss << start;
            ss >> level;
        } else{;}
    }
    while (cin >> s){
        if (s == "start"){
            grid.init(text_only,level,file);
            cout << grid << endl;
        } else if (s == "restart"){
            grid.clear();
            grid.init(text_only,level,file);
            cout << grid << endl;
        } else if (s == "random"){
            grid.dorandom();
        } else if (s == "norandom"){
            string file;
            cin >> file;
            grid.norandom(file);
        } else if (s == "hint") {
            
        } else if ((s == "I") || (s == "J")||(s == "L")||(s == "O")
                    ||(s == "T")||(s == "S")||(s == "Z")){
            grid.setblock(s.front());
            cout << grid << endl;
        } else if (s=="exit"){
            break;
        } else {
            try{
                prefix(s);
            } catch (Has_front_number &ex){
                int n = ex.n;
                string op = ex.what();
                if (op == "levelup"){
                    grid.level_up();
                    cout << grid << endl;
                } else if (op == "leveldown"){
                    grid.level_down();
                    cout << grid << endl;
                } else{
                    try{
                        for (int i = 0; i < n; i ++) grid.Operation(op);
                        
                        cout << grid << endl;
                    } catch (Full & ex){
                        cout << grid << endl;
                        cout << ex.what() << endl;
                    }
                }
            }
            catch (No_Matching_prefix & ex){
                if (ex.what() == "ambiguous operation"){
                    cout << "Need more information to determine the correct command." << endl;
                } else if (ex.what() == "Invalid operation"){
                    cout << "Invalid command! Please type in a new command." << endl;
                }
            }
        }
    }
}
