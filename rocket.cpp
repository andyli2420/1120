//LI CHUN LAM 1155116313 
//Assignment 2
//1155116313@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>

using namespace std;

void head(int h, int w){
    for(int i = 0; i<= h;i++){
        for(int x= 0;x< w;x++){
            cout << " ";
        }
        if(i!=h){
            for (int k = i; k < h; k++)
            {
                cout <<" ";
            }
        }
        if(i == 0){
            cout << " |\n";
            continue;
        }
        cout << " /*";
        for (int j = 1; j < i; j++)
        {
            
            cout <<"**";
        }
        cout << "\\\n" ;
    }
}
void bodyLine(int h, int w){
    cout << setw(w+2);
    cout << "+-";
    for (int i = 0; i < 2*h; i++)
    {
        cout <<"-";
    }
    cout <<  "+\n";
    
}
void bodyDot(int h){
    
    for (int i = 0; i < 2*h; i++)
    {
        cout <<".";
    }
}
void bodyWing(int w,int side){
    if(side == 0)
    {for(int i = 0; i < w; i++){
        cout << "/";
    }}else{
        for(int i = 0; i < w; i++){
            
        cout << "\\";
    }
    }
}
void body(int b, int w, int h){
    int wingLine = b/2;
    
    if(b%2 == 1){
        wingLine+= 1;
    }
    
    bodyLine(h, w);

    for(int i = b; i>= 1;i--){
        if(i <= wingLine){
          bodyWing(w, 0);
        }
        else{
            cout << setw(w+2);
        }
        
        cout << "|.";
        bodyDot(h);
        cout << "|" ;
        if(i <= wingLine){
          bodyWing(w, 1);
        }
        else{
            cout << setw(w+2);
        }
        cout << "\n";
    
    }

    
    bodyLine(h, w);

    
}

void tails(int t, int w,int h){

    int upperPart = t/2.0;
    int h2 = h/2;

   //upper
   for (int i = 0; i < t; i++){
       if(upperPart > i){
           continue;
       }
       for(int x= 0;x< w;x++){
            cout << " ";
        }
        if(t - h < 1){
            for(int q = 0; q< h2;q++){
                cout << " ";
            }
        }
        for (int k = i; k < t; k++)
            {
                
                cout <<" ";
            }
   cout << "*";
   
   for(int  j= 0; j< i;j++){
       cout <<"**";
   }
   cout <<"\n"; 
   
   }
   //bottom
   
   for (int i = t; i > 0; i--){
       cout << " ";
       for(int x= 0;x< w;x++){
            cout << " ";
        }
        if(t - h < 1){
            for(int q = 0; q< h2;q++){
                cout << " ";
            }
        }
        for (int k = i; k < t; k++)
            {
                cout <<" ";
            }
   cout << "*";
   
   for(int  j= i; j > 1;j--){
       cout <<"**";
   }
   cout <<"\n"; 
   
   }
}
int main()
{
    int h, b, w, t;
    do{
    cout<< "Enter h, b, w, t: ";
    cin>> h >> b >> w >> t;
    }while((2*t - 1) >( 2*h + 3) || h < 1|| b < 2 || w < 1 || t < 2);

    head(h, w);
    body(b,w, h);
    tails(t, w,h);
    return 0;
    
}