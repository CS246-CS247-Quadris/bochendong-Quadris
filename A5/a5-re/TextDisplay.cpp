#include "TextDisplay.hpp"
using namespace std;
TextDisplay::TextDisplay(vector<vector<char>>&grid):grid(grid){}

void TextDisplay::notify(Subject &whoFrom){
    State state = whoFrom.getState();
    level = state.level;
    nextType = state.nextType;
    Curr_score = state.Curr_Score;
    High_score = state.High_Score;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
    out << "=============" << endl;
    out << "|Level: " << td.level << "   |" << endl;
    int Curr_Score_count = 1;
    while (td.Curr_score / 10 != 0) Curr_Score_count += 1;
    
    out << "|Score: " << td.Curr_score;
    for (int i = 0; i < 4 - Curr_Score_count; i ++) out << " ";
    out << "|" << endl;
    
    int High_Score_count = 1;
    while (td.High_score / 10 != 0) High_Score_count += 1;
    
    out << "|High:  " << td.High_score;
    for (int i = 0; i < 4 - Curr_Score_count; i ++) out << " ";
    out << "|" << endl;
    
    out << " +++++++++++"<<endl;
    for (int i = 17; i >= 0; i --){
        out << "|";
        for (int k = 0; k < 11; k ++){
            if (td.grid[k][i] == 'S' || td.grid[k][i] == 'L' || td.grid[k][i] == 'O'||
                td.grid[k][i] == 'T' || td.grid[k][i] == 'Z' || td.grid[k][i] == 'J'
                || td.grid[k][i] == 'I' || td.grid[k][i] == '?'){
                out << td.grid[k][i];
            }
            else out << ' ';
        }
        out << "|" << std::endl;
    }
    out<<"============="<<endl;
    out<<"Next:"<<endl;
    switch(td.nextType){
        case 'I':
            out<<"IIII"<<endl;
            break;
        case 'J':
            out<<"J"<<endl;
            out<<"JJJ"<<endl;
            break;
        case 'L':
            out<<"  L"<<endl;
            out<<"LLL"<<endl;
            break;
        case 'O':
            out<<"OO"<<endl;
            out<<"OO"<<endl;
            break;
        case 'S':
            out<<" SS"<<endl;
            out<<"SS"<<endl;
            break;
        case 'Z':
            out<<"ZZ"<<endl;
            out<<" ZZ"<<endl;
            break;
        case 'T':
            out<<"TTT "<<endl;
            out<<" T"<<endl;
            break;
    }
    return out;
}

