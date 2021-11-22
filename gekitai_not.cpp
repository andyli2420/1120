//LI CHUN LAM 1155116313 
//Assignment 4
//1155116313@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int P = 8;
const int N = 6;
const int L = 3;

bool is_valid_move(char board[][N], char player, int y, int x){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j] != '.'){
                return false;
            }
        }
      
    }
    return true;
}

int pieces_on_board(char board[][N], char player){
    int count = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j] == player){
                count++;
            }
            
        }
    }
    return count;
}

bool pieces_in_line(char board[][N], char player){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j] == player){
                if(board[i][j+1] == player && board[i][j+2] == player){
                    return true;
                }
                else if(board[i+1][j] == player && board[i+2][j] == player){
                    return true;
                }
                else if(board[i+1][j+1] == player && board[i+2][j+2] == player){
                    return true;
                }
                else if(board[i-1][j-1] == player && board[i-2][j-2] == player){
                    return true;
                }
            }
            
        }
        
    }
}

void move(char board[][N], char player, int y, int x){
    board[y][x] = player;

   /*
    if((board[y][x+1] != '.') && (board[y][x+2] != '.') ){
        board[y][x+2] = board[y][x+1];
    }
    else if((board[y+1][x] != '.') && (board[y+2][x] != '.')){
        board[y+2][x] = board[y+1][x];
    }
    else if((board[y+1][x+1] != '.') && (board[y+2][x+2] != '.')){
        board[y+2][x+2] = board[y+1][x+1];
    }
    else if((board[y+1][x+1] != '.') && (board[y+2][x+2] != '.')){
        board[y+2][x+2] = board[y+1][x+1];
    }
    */
}

void print(char board[][N]){

    char charA = 'A';
    cout << "  ";
    for(int i = 0; i < 6; i++){
        cout << charA << " ";
        charA++;
    }
    cout << endl;

    for(int i = 0; i < 6; i++){
        cout << (i+1) << " ";
        for(int j = 0; j < 6; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int toInt(char ay){
    int x1, x2;

    x1 = ay - 'A';
    x2 = ay - 'a';
    x1 = abs(x1);
    x2 = abs(x2);
    if(x2 > x1){
        return x1;
    }else return x2;
}

/*
int main(){
    int x, y;
    char ay;
    int round = 1;
    char player1 = 'X';
    char player2 = 'O';
    bool p1Turn = true;

    char board[N][N];

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            board[i][j] = '.';
        }
    }

    //print(board);
    do
    {
        cout << "Round " << round << ":" << endl;
        print(board);
        if(p1Turn){
            cout << "Player X's turn: ";
            cin >> ay >> x;
    
            y = toInt(ay);
            move(board, y, x, player1);
        
            print(board);
            p1Turn = false;
        }
        else{
            cout << "Player O's turn: ";
            cin >> ay >> x;
    
            y = toInt(ay);
            move(board, y, x, player2);
        
            print(board);
            p1Turn = true;
        }
        
        
    } while (1);
    


    
}
*/

int main()
{
    int x, y;
    char ay;
    char player1 = 'X';
    char board[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            board[i][j] = '.';
        }
    }
    
   print(board);
    
    cin >> ay >> x;
    
    y = toInt(ay);
    move(board, y, x, player1);
    
   
    
    print(board);


    return 0;
}
