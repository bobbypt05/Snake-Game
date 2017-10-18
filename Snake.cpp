//A simple Snake game made using C++
//Bobby Gurudas Patil
//National Institute of Technology , Karnataka
//Department of computer science and engineering

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

bool isOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum Direction{STOP=0 , UP , DOWN , LEFT , RIGHT };
Direction dir;

void setup()
{
    isOver=false;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%width;
    score=0;

}

void draw()
{
    system("cls");
    cout<<"Simple Snake Game!!!"<<endl;
    cout<<"Created By Bobby Patil"<<"\n";
    cout<<"W: UP S: DOWN A: LEFT D: RIGHT\n\n";
    for(int i=0 ; i <= width ;i++)
        cout<<"#";
    cout<<endl;
    for(int i=0;i <= height ; i++)
    {
        for(int j=0 ; j<= width ; j++)
        {
            if(j==0||j==width)
                cout<<"#";
            else if(i == y && j == x)
                cout<<"O";
            else if(i == fruitY && j == fruitX )
                cout<<"@";
            else
            {
                bool print=false;
                for(int k = 0 ;k < nTail ; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                    cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=0; i<= width ;i++)
        cout<<"#";
    cout<<endl;
    cout<<"SCORE : "<<score<<endl;
}

void input()
{
       fflush(stdin);
       switch(getch())
       {
          case 'w':
                   dir=UP;
                   break;
          case 's':
                   dir=DOWN;
                   break;
          case 'a':
                   dir=LEFT;
                   break;
          case 'd':
                   dir=RIGHT;
                   break;
          case 'x':
                   isOver=true;
                   break;
       }
}

void logic()
{

      int prevX=tailX[0];   //To maintain tail of the snake
      int prevY=tailY[0];
      int prev2X,prev2Y;
      tailX[0]=x;tailY[0]=y;  //adding one circle to tail

      for(int i = 1 ; i < nTail ; i++ )  //To move tail to the which follows the previous tail positions
      {
          prev2X=tailX[i];
          prev2Y=tailY[i];
          tailX[i]=prevX;
          tailY[i]=prevY;
          prevX=prev2X;
          prevY=prev2Y;
      }

      switch(dir)
      {
          case UP:
                  y--;
                  break;
          case DOWN:
                    y++;
                    break;
          case LEFT:
                   x--;
                   break;
          case RIGHT:
                    x++;
                    break;
      }

      if(x == 0 || x == width || y == -1 || y == height+1)
        isOver=true;

      for(int k = 0; k < nTail ; k++ )
        if(tailX[k] == x && tailY[k] == y)
            isOver=true;

      if(x==fruitX && y== fruitY)
      {
          cout<<"\a";
          score+=10;
          fruitX=rand()%width;
          fruitY=rand()%height;
          nTail++;
      }


}

/*void delay()
{
    for(int i = 0 ; i < 1000 ;i++)
    {
        for(int j = 0; j < 1000 ; j++)
        {
            ;
        }
    }
}*/

void finalP()
{
    system("cls");
    cout<<"##############################################"<<endl;
    cout<<"#              GAME OVER!!                   #"<<endl;
    cout<<"#            Score="<<score<<"                       #"<<endl;
    cout<<"##############################################"<<endl;
}

int main()
{
    setup();
    while(!isOver)
    {
          draw();
          input();
          logic();
          //delay();
    }
    finalP();
    return 0;
}
