#include "Grid.hpp"
using namespace std;
const int Width = 11;
const int Height = 18;
const int Block_Size = 4;

void Grid::level_up(){
    cout << 2 << endl;
    LV = Level::levelup(LV);
    notify();
}
void Grid::level_down(){
    LV = Level::leveldown(LV);
    notify();
}
void Grid::init(bool Text_Only, int level, string file){
    // clear old grid, if nessery.
    clear();
    // Set level
    LV = Level::setlevel(level,file);
    // Set current block type and next block type.
    Curr_Type = LV->getblock();
    Next_Type = LV->getblock();
    // Check if we need Graphic Display.
    Graphic = (!Text_Only);
    // Initialize the Grid.
    grid.resize(Width);
    for (int i = 0; i < Width; i ++){
        for (int k = 0; k < Height; k ++) grid[i].push_back(' ');
    }
    // Each Block need to know which level does it born.
    // Get Block has Duty to update the grid.
    Get_Block(level);
    
    if (!Graphic){
        td = new TextDisplay(grid);
        this->attach(td);
    } else {
        td = new TextDisplay(grid);
        this->attach(td);
    }
    notify();
}
void Grid::clear(){
    Graphic = !(Curr_Score = LV4_Counter = 0);
    Curr_Type = Next_Type = ' ';
    if (!(Blocks.empty())){
        for (unsigned int i = 0; i < grid.size(); i++) grid[i].clear();
        grid.clear();
        Blocks.clear();
    }
    delete td;
}
// Every time we get a block, we need to update the Grid and need to check if the game is over
void Grid::Get_Block(int level){
    if (Curr_Type == 'I') b = new Iblock(Curr_Type,level);
    else if (Curr_Type == 'J') b = new Jblock(Curr_Type,level);
    else if (Curr_Type == 'L') b = new Lblock(Curr_Type,level);
    else if (Curr_Type == 'O') b = new Oblock(Curr_Type,level);
    else if (Curr_Type == 'Z') b = new Zblock(Curr_Type,level);
    else if (Curr_Type == 'T') b = new Tblock(Curr_Type,level);
    else b = new Sblock(Curr_Type,level);
    Blocks.push_back(b);
    // Try to update the Grid, if catch some expection, then print Game Over
    try {
        Update_Grid();
    } catch (Full & ex){
        throw ; // need to handle here
    }
}
void Grid::Update_Grid(){
    Info info = b->getinfo();
    for (int i = 0; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        if (grid[x][y] != ' ') {
            throw Full("Game Over. Type Restart to restart the game.");
        }
    }
    for (int i = 0; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        grid[x][y] = info.type;
    }
}

void Grid::notify(){
    State state = {LV->getlevel(), Curr_Score, High_Score, Next_Type};
    setState(state);
    notifyObservers();
}

void Grid::Operation(string OP){
    Info info = b->getinfo();
    for (int i = 0; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        grid[x][y] = ' ';
    }
    // drop will always has effect
    if (OP == "drop"){
        // we will find the smallest distance between the current block and the block bloew it
        int Smallest_Dis = info.pos[0].y;
        for (int i = 0; i < Block_Size; i++){
            int x = info.pos[i].x, y = info.pos[i].y;
            if (Smallest_Dis > y) Smallest_Dis = y;
            for (int k = y; k >= 0; k--){
                if (grid[x][k] != ' ' && grid[x][k] != '?'){
                    if ((y - k - 1) < Smallest_Dis) Smallest_Dis = y - k - 1;
                }
            }
        }
        b->drop(Smallest_Dis);
    }
    // The other operators may not has effect (eg: It can be not possible to move left if it is at the left edge of the grid)
    else{
        try{
            if (OP == "left") b->left();
            else if (OP == "right") b->right();
            else if (OP == "clockwise") b->clockwise();
            else if (OP == "down") b->down();
            else b->counterclock();
            
    
            info = b->getinfo();
            for (int i = 0; i < Block_Size; i ++){
                if (info.pos[i].x < 0 || info.pos[i].x > 10 || info.pos[i].y > 17 || info.pos[i].y < 0){
                    throw Has_No_Effect("Out Of Range");
                }
            }
            
            for (int i = 0; i < Block_Size; i ++){
                int x = info.pos[i].x, y = info.pos[i].y;
                if (grid[x][y] != ' ' && grid[x][y] != '?') throw Has_No_Effect("Already Has a Block");
            }
        } catch (Has_No_Effect & hne){
            if (OP == "left") b->right();
            else if (OP == "right") b->left();
            else if (OP == "clockwise") b->counterclock();
            else if (OP == "down") b->up();
            else b->clockwise();
            cout << "no effect" << endl;
            Update_Grid();
            return;
        }
    }
    Update_Grid();
    
    // Consider if the block is undroped or droped by checking if there already exit a block under the current block's every cloumn's lowest block
    // Firstly, we record the low edge of the current block of Curr_Block_Edge
    
    info = b->getinfo(); // update info here
    vector <Posn> Curr_Block_Edge;
    Curr_Block_Edge.push_back(info.pos[0]);
    for (int i = 1; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        try{
            for (unsigned int k = 0; k < Curr_Block_Edge.size(); k++) {
                if ((Curr_Block_Edge[k].x == x) && (Curr_Block_Edge[k].y > y)) {
                    int index = k;
                    throw Posn{index,y};
                }
            }
            Curr_Block_Edge.push_back(info.pos[i]);
        } catch (Posn &p){
            int i = p.x, y = p.y;
            Curr_Block_Edge[i].y = y;
        }
    }
    // Then we check if there is a block under the current block's edge
    try{
        for (unsigned int i = 0; i < Curr_Block_Edge.size(); i ++){
            int x = Curr_Block_Edge[i].x, y = Curr_Block_Edge[i].y;
            if (grid[x][y - 1] != ' '&& grid[x][y] != '?') throw 'N';
            if (y == 0) throw 'N';
        }
    }
    // if the block is not a undroped block, we need to check if we need to eliminate any row
    catch(const char& s){
        eliminate();
        Curr_Type = Next_Type;
        Next_Type = LV->getblock();
        try{
            Get_Block(LV->getlevel());
        } catch(Full & ex){
            throw ;
        }
    }
    eliminate();
    notify();
}
// Has duty to rewrite current score and high score
void Grid::eliminate(){
    int elim = 0,line_score = 0,block_score = 0;
    vector <vector<char>> temp;
    temp.resize(Width);
    for (int i = 0; i < Height; i ++){
        int count = 0;
        for (int k = 0; k < Width; k ++){
            if (grid[k][i] != ' ' && grid[k][i] != '?') count += 1;
        }
        if (count == Width) {
            cout << "ffffff" << endl;
            elim += 1;
            for (unsigned int m = 0; m < Blocks.size(); m++){
                Info info = Blocks[m]->getinfo();
                if (info.uneliminate > 0){
                    for (int n = 0; n < Block_Size ; n++){
                        if (info.pos[n].y == i) Blocks[m]->eliminate();
                    }
                }
            }
        } else{
            for (int j = 0; j < Width; j ++){
                temp[j].push_back(grid[j][i]);
            }
        }
    }
    
    for (int i = 0; i < Height; i ++){
        for (int k = 0; k < Width; k ++){
            grid[k][i] = temp[k][i];
        }
    }
    if (elim > 0){
        line_score = (LV->getlevel() + elim) * (LV->getlevel() + elim);
        Curr_Score += line_score;
    }
    
    for (unsigned int i = 0; i < Blocks.size(); i ++){
        Info info = Blocks[i]->getinfo();
        if (info.uneliminate == 0){
            block_score += (info.level + 1)*(info.level + 1);
            Blocks[i]->eliminate();
        }
    }
    Curr_Score += block_score;
    if (Curr_Score >= High_Score) High_Score = Curr_Score;
}

void Grid::setblock(char c){
    // Use for Testing, so we do not consider the case that after setting block, the block is changed from
    // an undroped block to droped block
    Info info = b->getinfo();
    Curr_Type = c;
    for (int i = 0; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        grid[x][y] = ' ';
    }
    
    b->setblock(c);
    info = b->getinfo();
    for (int i = 0; i < Block_Size; i ++){
        int x = info.pos[i].x, y = info.pos[i].y;
        grid[x][y] = Curr_Type;
    }
    
    notify();
}

std::ostream &operator<<(std::ostream &out, const Grid &g){
    out<<(*g.td);
    return out;
}

