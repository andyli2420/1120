//LI CHUN LAM 1155116313 
//Assignment 5
//1155116313@link.cuhk.edu.hk
#include <iostream>
#include <cmath>
using namespace std;

class KnightsPath{
private:
    int board[6][6];
    int currentR, currentC;
    int steps;
    int previousR, previousC;
public:
    const static int N = 6;
    KnightsPath(int r, int c){
        currentR = r;
        currentC = c;
        steps = 0;
        for(int i = 0; i < N; i++ ){
            for(int j = 0; j < N; j++){
                board[i][j] = -1;
                if( i == r && j == c){
                    board[i][j] = 0;
                }
            }
        }
    }

    void print() const{

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
                if(board[i][j] == -1){
                    cout << ".";
                }
                else if(board[i][j] == 0){
                    cout << "k";
                }
                else if( i == currentR && j == currentC){
                    cout << "K";
                }
                else{
                    cout << board[i][j];
                }
                cout << " ";
            }
            cout << endl;
        }
        cout << "Steps: " << getSteps() << endl;
    }
    
    int getSteps () const{
        return steps;
    }

    bool isValid(int r, int c) const{

        //check destination value within 2/1
        int changeR = r - currentR;
        int changeC = c - currentC;

        //check previous position value
        int preR = r - previousR;
        int preC = c - previousC;

        //false if destination is previous position
        if(r == previousR && c == previousC){
            return false;
        }
        
        //check if it's run in 2H1V/1H2V
        if( (abs(changeC) == 2 && abs(changeR) == 1) || (abs(changeC) == 1 && abs(changeR) == 2)){
       
            return true;
        }

        int validNum = preR*currentR + preC*currentC;

        if(validNum > 0){
            return false;
        }
        else return true;
    }

    
    bool hasMoreMoves() const{

        int possibleR, possibleC;
        int tempR = currentR, tempC = currentC;

        //check 8個方向 ISVALID? ALL NOT return false
        

        

        return true;
    };
    bool move(int r, int c){
        if(isValid(r, c)){
            steps+=1;
            board[r][c] = steps;
            
            previousC = currentC;
            previousR = currentR;

            currentC = c;
            currentR = r;

            return true;
        }
        else return false;

    }
};

int main(){

    char charCol;
    int col, row;

    do{
        cout << "Enter starting position (col row):";
        cin >> charCol >> row;
        

        if(charCol > 'F' || charCol < 'A'){
            cout << "Invalid. Try again!\n"; 
        }

    }while(charCol > 'F' || charCol < 'A');

    col = charCol - 65;
    row -=1;

    KnightsPath Knight = KnightsPath(row, col);
    Knight.print();
    
    do
    {
        cout << "Move the knight (col row): ";
        cin >> charCol >> row;

        if(charCol > 'F' || charCol < 'A'){

            cout << "Char bug!!!"<< "Invalid move. Try again!\n"; 
        }
        col = charCol - 65;
        row -=1;

        if(Knight.isValid(row, col)){

            Knight.move(row, col);
            Knight.print();

        }
        else{
            cout << "Invalid move. Try again!\n";
        }

        
    } while (Knight.hasMoreMoves());

    
    cout << "Finished! No more moves!\n";
    if(Knight.getSteps() >= 18){
        cout << "Well done!";
    }
    else{
        cout << "Still drunk? Walk wiser!";
    }
    
    return 0;
}