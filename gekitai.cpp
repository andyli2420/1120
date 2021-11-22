//LI CHUN LAM 1155116313 
//Assignment 4
//1155116313@link.cuhk.edu.hk
#include <iostream>
#include <cmath>

using namespace std;
const int P = 8;
const int N = 6;
const int L = 3;

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

bool is_valid_move(char board[][N], char player, int y, int x){
    //cout << board[x][y] << " <<< sign y&x: " << y << x << endl;
    if(board[x][y] != '.'){
        
        return false;
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
    return false;
}


void move(char board[][6], int y, int x, char z){
    board[x][y] = z;
    //right
    if(y != 5 && y != 4){
    if((board[x][y+1] != '.') && (board[x][y+2] == '.' || y+2 > 5) ){
      
        if(y+2 > 5){
            board[x][y+1] = '.';
        }
        board[x][y+2] = board[x][y+1];
        board[x][y+1] = '.';
    }
    //down
    if((board[x+1][y] != '.') && (board[x+2][y] == '.' || x+2 > 5) ){
      
        if(x+2 > 5){
            board[x+1][y] = '.';
        }
        board[x+2][y] = board[x+1][y];
        board[x+1][y] = '.';
    }
    //rightbotxxxx
    if((board[x+1][y+1] != '.') && (board[x+2][y+2] == '.') || (x+2 >5 || y+2 >5)){
       
        if(x+2 >5 || y+2 > 5){
            board[x+1][y+1] = '.';
        }
        board[x+2][y+2] = board[x+1][y+1];
        board[x+1][y+1] = '.';
    }
    //left
    if((board[x][y-1] != '.') && (board[x][y-2] == '.') || y-2 < 0){
        
        if(y-2 <0){
            board[x][y-1] = '.';
        }
        board[x][y-2] = board[x][y-1];
        board[x][y-1] = '.';
    }
    //top
    if((board[x-1][y] != '.') && (board[x-2][y] == '.') || x-2 <0){
     
        if(x-2 <0){
            board[x-1][y] = '.';
        }
        board[x-2][y] = board[x-1][y];
        board[x-1][y] = '.';
    }
    //leftbot
    if((board[x+1][y-1] != '.') && (board[x+2][y-2] == '.') || (x+2 >5 || y -2 <0)){
      
        if(x+2 >5 || y-2 < 0){
            board[x+1][y-1] = '.';
        }
        board[x+2][y-2] = board[x+1][y-1];
        board[x+1][y-1] = '.';
    }
    //lefttop
    if((board[x-1][y-1] != '.') && (board[x-2][y-2] == '.') || (x-2 <0 || y-2 < 0)){
       
        if(x-2 <0 || y-2 < 0){
            board[x-1][y-1] = '.';
        }
        board[x-2][y-2] = board[x-1][y-1];
        board[x-1][y-1] = '.';
    }
    //righttop
    if((board[x-1][y+1] != '.') && (board[x-2][y+2] == '.') || (x-2 <0 || y+2 >5)){
       
        if(x-2 <0 || y+2 >5){
            board[x-1][y+1] = '.';
        }
        board[x-2][y+2] = board[x-1][y+1];
        board[x-1][y+1] = '.';
    }
    }
    else{    //y = 4,5
    //top
    if((board[x-1][y] != '.') && (board[x-2][y] == '.') || x-2 <0){
       
        if(x-2 <0){
            board[x-1][y] = '.';
        }
        board[x-2][y] = board[x-1][y];
        board[x-1][y] = '.';
    }
    //down
    if((board[x+1][y] != '.') && (board[x+2][y] == '.' || x+2 > 5) ){
      
        if(x+2 > 5){
            board[x+1][y] = '.';
        }
        board[x+2][y] = board[x+1][y];
        board[x+1][y] = '.';
    }
    //rightbotxxxx
    if((board[x+1][y+1] != '.') && (board[x+2][y+2] == '.') || (x+2 >5 || y+2 >5)){
       
        if(x+2 >5 || y+2 > 5){
            board[x+1][y+1] = '.';
        }
        board[x+2][y+2] = board[x+1][y+1];
        board[x+1][y+1] = '.';
    }
    //left
    if((board[x][y-1] != '.') && (board[x][y-2] == '.') || y-2 < 0){
       
        if(y-2 <0){
            board[x][y-1] = '.';
        }
        board[x][y-2] = board[x][y-1];
        board[x][y-1] = '.';
    }
    //lefttop
    if((board[x-1][y-1] != '.') && (board[x-2][y-2] == '.') || (x-2 <0 || y-2 < 0)){
      
        if(x-2 <0 || y-2 < 0){
            board[x-1][y-1] = '.';
        }
        board[x-2][y-2] = board[x-1][y-1];
        board[x-1][y-1] = '.';
    }
    //leftbot
    if((board[x+1][y-1] != '.') && (board[x+2][y-2] == '.') || (x+2 >5 || y -2 <0)){
       
        if(x+2 >5 || y-2 < 0){
            board[x+1][y-1] = '.';
        }
        board[x+2][y-2] = board[x+1][y-1];
        board[x+1][y-1] = '.';
    }
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

int main()
{
    int x, y;
    char ay;
    int round = 1;

    char player1 = 'X';
    char player2 = 'O';
    bool p1Turn = true;
    bool input = true;
    bool game = true;
    

    char board[N][N];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            board[i][j] = '.';
        }
    }
    
    do
    {
        if(p1Turn)
        {
            cout << "Round " << round << ":" << endl;
            print(board);
            do
            {
                cout << "Player X's turn: ";
                cin >> ay >> x;        
                y = toInt(ay);
                x-=1;
            
            if(is_valid_move(board, player1, y, x) && (x>=0 && x<6) && (y>=0 && y<6)){
                move(board, y, x, player1);
                if(pieces_in_line(board, player1)){
                    
                    cout << "Game over:\n";
                    print(board);
                    if(pieces_in_line(board, player2)){
                        cout << "Draw game!\n";
                    }else{
                        cout << "Player X wins!";
                    }
                    game = false;
                    break;
                }
                p1Turn = false;
                input = false;
                round++;
                if(x == 5){
                        break;
                    }
            
            }else{
                cout << "Invalid move!\n";
                input = true;
                //print(board);

            }
            } while (input);
            
            

        }
        else{
            cout << "Round " << round << ":" << endl;
            print(board);

            do
            {
                cout << "Player O's turn: ";
                cin >> ay >> x;
    
                y = toInt(ay);
                x-=1;

            
                if(is_valid_move(board, player2, y, x) && (x>=0 && x<6) && (y>=0 && y<6)){
                    move(board, y, x, player2);
                    if(pieces_in_line(board, player2)){
                        
                        cout << "Game over:\n";
                        print(board);
                        if(pieces_in_line(board, player1)){
                            cout << "Draw game!\n";
                        }else{
                            cout << "Player O wins!";
                        }
                        
                        game = false;
                        break;
                    }
                    p1Turn = true;
                    input = false;
                    round++;
                    if(x == 5){
                        break;
                    }
                }else{
                    cout << "Invalid move!\n";
                    input = true;
                    //print(board);
                }
            } while (input);
            
            
            
        }
    } while (game);
    
    


    return 0;
}