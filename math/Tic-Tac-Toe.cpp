#include<bits/stdc++.h>
using namespace std;
char a[3][3];
int count1=0;
int player=1;
void turn1(int x,int y)
{
    if(a[x][y]=='X'||a[x][y]=='O')
{printf("space is not vacant try another position\n");
}
else
{a[x][y]='O';
count1++;
player++;
}

}
void turn2(int x,int y)
{
     if(a[x][y]=='X'||a[x][y]=='O')
{printf("space is not vacant try another position\n");
}
else
{a[x][y]='X';
}
count1++;
player--;
}
int result()
{if((a[0][0]=='O'&a[0][1]=='O'&a[0][2]=='O')||(a[1][0]=='O'&a[1][1]=='O'&a[1][1]=='O')||(a[2][0]=='O'&a[2][1]=='O'&a[2][2]=='O')||(a[0][0]=='O'&a[1][0]=='O'&a[1][0]=='O')||(a[0][1]=='O'&a[1][1]=='O'&a[2][1]=='O')||(a[0][2]=='O'&a[1][2]=='O'&a[2][2]=='O')||(a[0][0]=='O'&a[1][1]=='O'&a[2][2]=='O')||(a[0][2]=='O'&a[1][1]=='O'&a[2][0]=='O'))
return 1;
else if((a[0][0]=='X'&a[0][1]=='X'&a[0][2]=='X')||(a[1][0]=='X'&a[1][1]=='X'&a[1][1]=='X')||(a[2][0]=='X'&a[2][1]=='X'&a[2][2]=='X')||(a[0][0]=='X'&a[1][0]=='X'&a[1][0]=='X')||(a[0][1]=='X'&a[1][1]=='X'&a[2][1]=='X')||(a[0][2]=='X'&a[1][2]=='X'&a[2][2]=='X')||(a[0][0]=='X'&a[1][1]=='X'&a[2][2]=='X')||(a[0][2]=='X'&a[1][1]=='X'&a[2][0]=='X'))
return 2;
else
    return 0;
}
int main()
{ int i,j;
    for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
{a[i][j]='_';

}

}

printf("let's play tic-tac-toe\n");
while(!result()&count1!=9)
{
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
{
cout<<a[i][j]<<" ";
}
cout<<"\n";
}
    int x,y;
if(player == 1)
{printf("Turn Of First Player\n");

printf("enter the position where to place your chance\n");
scanf("%d %d",&x,&y);
turn1(x,y);
}

else
{printf("Turn Of second Player\n");
printf("enter the position where to place your chance\n");
scanf("%d %d",&x,&y);
turn2(x,y);
}
}
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
{
cout<<a[i][j]<<" ";
}
cout<<"\n";
}
int c=result();
if(c==1)
printf("first player wins\n");
else if(c==2)
printf("second player wins\n");
else
printf("match draw\n");
return 0;
}

