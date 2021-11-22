//LI CHUN LAM 1155116313 
//Assignment 3
//1155116313@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
using namespace std;


int gridState(long long grid, int pos){
    long long value = 1;
    int state;
    
    //multiplies to correct value for division
    for(int i = 0; i < (16-pos); i++){
        value *= 10;
    }
    //mod 10 to get the state of that position
    grid = grid / value;    
    state = grid % 10;

    return state;
    
}

void printGrid(long long grid){
    int state;
    int pos = 1;
  
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            state = gridState(grid, pos);
     
            if(state == 1){
                cout << "A";
            }else if (state == 2){
                cout << "B";
            }else if (state == 0)
            {
                cout << ".";
            }
           
            pos++;
            
        }
        cout << "\n";
    }
}

bool isPlaceable(long long grid, int pos, int p){
    int neighbor_pos, state1, state2;
    
    //check player who can't enter the particular value
    if(p == 2){
        if(pos == 4 || pos == 8 || pos == 12 || pos == 16){
            return false;
        }
        neighbor_pos = pos + 1;
    }
    else if(p == 1){
        if(pos == 13 || pos == 14 || pos == 15 || pos == 16){
            return false;
        }
        neighbor_pos = pos + 4;
    }
    state1 = gridState(grid, pos);
    state2 = gridState(grid, neighbor_pos);

    //check for the state of those two position value is placeable or not.
    if(state1 != 0 || state2 != 0){
        return false;
    }
    else return true;

}

void putToGrid(long long &grid, int pos, int p){
    int mulIndex = 16 - pos;
    long long value1 = p;
    long long value2;

    //add the right among of value to the grid.
    if(p == 2){
        for(int i = 0; i < mulIndex; i++){
            value1 *= 10;
        }
        value2 = value1 / 10;
        grid = (value1 + value2);

    }else{
        for(int i = 0; i < mulIndex; i++){
            value1 *= 10;
        }
        value2 = value1 / 10000;
        grid = (value1 + value2);
    }

}
bool checkWin(long long grid, int p){
    int state1;
    int state2;


    if(p == 1){
        for(int i = 1; i <= 16; i++){
               state1 = gridState(grid, i);
               
               //if there is still a position is placeable, the game will goes on. And return false.
               if(isPlaceable(grid, i, 2)){
                   return false;
               }
               else{
                   //check untill the last position of player 2, and claim victory.
                   if(i != 15){
                       continue;
                   }
                   else return true;                  
               }
        }
        
    }else if(p == 2){
        for(int i = 1; i <= 12; i++){
            state1 = gridState(grid, i);

            if(isPlaceable(grid, i, 1)){
                return false;
            }
            else{
                   //check untill the last position of player 2, and claim victory.
                   if(i != 12){
                       continue;
                   }
                   else return true;                  
               }
            
        }
    }

}
int main(){
    int pos, p;
    long long grid = 0;
    long long realGrid = 0;
    bool p1Turn = true;
    
    //print an empty grid first.
    printGrid(0);

    do
    {   
        //player 1 get started, and take turn to swap player by the bool p1turn.
        if(p1Turn){
           
            cout << "Player 1's move: ";
            cin >> pos;

            //check if the position is placeable.
            if(isPlaceable(realGrid, pos, 1) || pos > 16){
                putToGrid(grid, pos, 1);
                //add the grid number in the real grid.
                realGrid += grid;

                printGrid(realGrid);
                //swap player.
                p1Turn = false;

                //check the victory condition         
                if(checkWin(realGrid, 1)){
                    cout << "Player 1 wins!";
                    break;
                }

            }
            //input again if its not placeable.
            else{
            cout << "Invaild! Try again" << endl;
            }
        }
        else{
       
            cout << "Player 2's move: ";
            cin >> pos;

            //check if the position is placeable.
            if(isPlaceable(realGrid, pos, 2)|| pos > 16){
                putToGrid(grid, pos, 2);
                realGrid += grid;
                printGrid(realGrid);
                
                 //swap player.
                p1Turn = true;
            
                //check the victory condition
                if(checkWin(realGrid, 2)){
                    cout << "Player 2 wins!";
                    break;
                }
            }
            else{
                //input again if its not placeable.
                cout << "Invaild! Try again" << endl;
            }

        }
        
       

    } while (1);
    

    return 0;


}