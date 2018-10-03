#include<iostream>
using namespace std;
int board[1000][1000]={0}; //set all to 0
int queen[1000];    //queen[0] --- first row queen
bool solExist=false;


bool IsSafe(int row,int col,int n){

    //Row Safety
    if(queen[row]!=-1)
      return false;

    //Col Safety
    for(int i=0;i<n;i++){
        if(queen[i]==col)
        return false;
    }

    //Diagonal slope +1 Safety
      for(int i=0;i<n;i++){
        if(queen[i]!=-1){
            if(i+queen[i]==row+col)
            return false;}
    }

    //Diagonal slope -1 Safety
      for(int i=0;i<n;i++){
        if(queen[i]!=-1){
            if(i-queen[i]==row-col)
            return false;}
    }

    return true;
}



void NQueen(int n,int row){
   static int queensPlaced=0;

   if(queen[n-1]!=-1){

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
         cout<<board[i][j]<<" ";
        }
     cout<<endl;
    }
    cout<<endl;
    //queen[n-1]=-1;
    solExist=true;
    return ;
   }



   for(int i=0;i<n;i++){
      if(IsSafe(row,i,n)){
           board[row][i]=1;
           queen[row]=i;
           queensPlaced++;

         /*for(int i=0;i<n;i++){   Uncomment to see working
           for(int j=0;j<n;j++){
           cout<<board[i][j]<<" ";
            }
            cout<<endl;
            }
           cout<<endl; */

           NQueen(n,row+1);

           board[row][i]=0;
           queen[row]=-1;
           queensPlaced--;

         /*for(int i=0;i<n;i++){  Uncomment to see working
           for(int j=0;j<n;j++){
           cout<<board[i][j]<<" ";
            }
            cout<<endl;
            }
           cout<<endl; */


         }
   }

   return ;

}

int main(){
   int n;

   cout<<"Enter n : ";
   cin>>n;

   for(int i=0;i<1000;i++)
   queen[i]=-1;

   NQueen(n,0);

   if(!solExist)
   cout<<"No Solution";


  return 0;
}





