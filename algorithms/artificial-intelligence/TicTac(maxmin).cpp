#include<iostream>
#include<random>
using namespace std;
const int M = 3;
const int N = 3;
int c=0;
struct Move
{
	int row, col;
};
bool isMovesLeft(string Game[M][N])
{
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
			if (Game[i][j]==" ")
				return true;
	return false;
}
int evaluate(string b[M][N])
{
	for (int row = 0; row<M; row++)
	{
		if (b[row][0]==b[row][1] &&
			b[row][1]==b[row][2])
		{
			if (b[row][0]=="O")
				return +10;
			else if (b[row][0]=="x")
				return -10;
		}
	}

	for (int col = 0; col<N; col++)
	{
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			if (b[0][col]=="O")
				return +10;

			else if (b[0][col]=="x")
				return -10;
		}
	}

	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		if (b[0][0]=="O")
			return +10;
		else if (b[0][0]=="x")
			return -10;
	}

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		if (b[0][2]=="O")
			return +10;
		else if (b[0][2]=="x")
			return -10;
	}

	return 0;
}
int minimax(string Game[M][N], int depth, bool isMax)
{
	int score = evaluate(Game);
	if (score == 10)
		return score;
	if (score == -10)
		return score;
	if (isMovesLeft(Game)==false)
		return 0;
	if (isMax)
	{
		int best = -9999;
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (Game[i][j]==" ")
				{
					Game[i][j] = "O";
					best = max( best,
						minimax(Game, depth+1, !isMax) );
					Game[i][j] = " ";
				}
			}
		}
		return best;
	}
	else
	{
		int best = 9999;
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (Game[i][j]==" ")
				{
					Game[i][j] = "x";
					best = min(best,
						minimax(Game, depth+1, !isMax));
					Game[i][j] = " ";
				}
			}
		}
		return best;
	}
}

Move findBestMove(string Game[M][N])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (Game[i][j]== " ")
			{
				Game[i][j] = "O";
				int moveVal = minimax(Game, 0, false);
				Game[i][j] = " ";
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
				}
			}
		}
	}
	return bestMove;
}
void display(string Game[M][N])
{
      cout << " " << Game[0][0] << " | " << Game[0][1] << " | " << Game[0][2] << " " << endl
        << "---+---+---" << endl
        << " " << Game[1][0] << " | " << Game[1][1] << " | " << Game[1][2] << " " << endl
        << "---+---+---" << endl
        << " " << Game[2][0] << " | " << Game[2][1] << " | " << Game[2][2] << " " << endl;
}
int main()
{
    string Game[M][N];
    int l,m;
    int b=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            Game[i][j]=" ";
        }
    }
    display(Game);
    for(int k=0;k>=0;k++)
    {
       if(b==0)
       {
           cout<<"Enter the move of Player 1(write Rowno. and ColNo.) "<<endl;
           cin>>l>>m;
           if(Game[l-1][m-1]==" ")
           {
              Game[l-1][m-1]="x";
              c++;
              b++;
              display(Game);
              if((Game[0][0]=="x" && Game[0][1]=="x" && Game[0][2]=="x" )|| (Game[1][0]=="x" && Game[1][1]=="x" && Game[1][2]=="x") || (Game[2][0]=="x" && Game[2][1]=="x" && Game[2][2]=="x") || (Game[0][2]=="x" && Game[1][2]=="x" && Game[2][2]=="x") || (Game[0][1]=="x" && Game[1][1]=="x" && Game[2][1]=="x") || (Game[0][0]=="x" && Game[1][0]=="x" && Game[2][0]=="x") || (Game[0][0]=="x" && Game[1][1]=="x" && Game[2][2]=="x") || (Game[0][2]=="x" && Game[1][1]=="x" && Game[2][0]=="x"))
              {
                 cout<<"Player 1 Wins"<<endl;
                 break;
              }
              else if((Game[0][0]=="O" && Game[0][1]=="O" && Game[0][2]=="O" )|| (Game[1][0]=="O" && Game[1][1]=="O" && Game[1][2]=="O") || (Game[2][0]=="O" && Game[2][1]=="O" && Game[2][2]=="O") || (Game[0][2]=="O" && Game[1][2]=="O" && Game[2][2]=="O") || (Game[0][1]=="O" && Game[1][1]=="O" && Game[2][1]=="O") || (Game[0][0]=="O" && Game[1][0]=="O" && Game[2][0]=="O") || (Game[0][0]=="O" && Game[1][1]=="O" && Game[2][2]=="O") || (Game[0][2]=="O" && Game[1][1]=="O" && Game[2][0]=="O"))
              {
                 cout<<"Computer Wins"<<endl;
                 break;
              }
              else if(c==9)
              {
                 cout<<"Match Draws "<<endl;
                 break;
              }
              continue;
           }
           else
           {
              cout<<"Don't repeat the Move"<<endl;
           }
       }
       if(b==1)
       {
             if(c>4)
             {
                 Move bestMove = findBestMove(Game);
                 int k=bestMove.row;
                 int l=bestMove.col;
                 Game[k+1][l+1]="O";
             }
             else
                 {
                     {
                        srand(time(0));
                        int computer= (rand()%9)+1;
                        int row=(computer-1)/3;
                        int col=(computer-1)%3;
                        if(Game[row][col]=="x" || Game[row][col]=="O")
                        {
                           continue;
                        }
                        else
                        {
                           Game[row][col]="O";
                        }
                     }
                 }

              c++;
              b--;
              display(Game);
              if((Game[0][0]=="x" && Game[0][1]=="x" && Game[0][2]=="x" )|| (Game[1][0]=="x" && Game[1][1]=="x" && Game[1][2]=="x") || (Game[2][0]=="x" && Game[2][1]=="x" && Game[2][2]=="x") || (Game[0][2]=="x" && Game[1][2]=="x" && Game[2][2]=="x") || (Game[0][1]=="x" && Game[1][1]=="x" && Game[2][1]=="x") || (Game[0][0]=="x" && Game[1][0]=="x" && Game[2][0]=="x") || (Game[0][0]=="x" && Game[1][1]=="x" && Game[2][2]=="x") || (Game[0][2]=="x" && Game[1][1]=="x" && Game[2][0]=="x"))
              {
                 cout<<"Player 1 Wins"<<endl;
                 break;
              }
              else if((Game[0][0]=="O" && Game[0][1]=="O" && Game[0][2]=="O" )|| (Game[1][0]=="O" && Game[1][1]=="O" && Game[1][2]=="O") || (Game[2][0]=="O" && Game[2][1]=="O" && Game[2][2]=="O") || (Game[0][2]=="O" && Game[1][2]=="O" && Game[2][2]=="O") || (Game[0][1]=="O" && Game[1][1]=="O" && Game[2][1]=="O") || (Game[0][0]=="O" && Game[1][0]=="O" && Game[2][0]=="O") || (Game[0][0]=="O" && Game[1][1]=="O" && Game[2][2]=="O") || (Game[0][2]=="O" && Game[1][1]=="O" && Game[2][0]=="O"))
              {
                 cout<<"Computer Wins"<<endl;
                 break;
              }
              else if(c==9)
              {
                 cout<<"Match Draws "<<endl;
                 break;
              }
             continue;
       }
  }

}


