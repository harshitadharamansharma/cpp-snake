#include <iostream>
#include <conio.h>
#include <windows.h>
// #include<bits/stdc++.h>
using namespace std;

bool gameOver;
const int height = 20, width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100],tailY[100],nTail;
enum eDirection { STOP = 0,UP,DOWN,LEFT,RIGHT} dir;

void Setup(){gameOver = false; dir = STOP; x = width / 2; y = height / 2; fruitX = rand() % width; fruitY = rand() % height;}

void Draw()
{ system("CLS");
    for (int i = 0; i < width; i++) cout << "#"; cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1) cout << "#";
            else if (i == j && j == x) cout << "O";
            else if (i == fruitY && j == fruitX) cout << "F";
            else{ bool print = false;  for (int k;k<nTail;k++)  
                {
                    if(i==tailY[k] && j==tailX[k]){ cout<<"O"; print = true; }
                }if(!print)cout << " ";}
        }cout << endl;
    }
    for (int i = 0; i < width; i++) cout << "#";
    cout <<"\n\n"<<"Score: "<<score<<endl;
}

void Input() { if (_kbhit()) { switch (_getch()) { case 'w': dir = UP; break; case 'a': dir = LEFT; break; case 's': dir = DOWN; break; case 'd': dir = RIGHT; break; default: break;} } }

void Logic()
{
    int prevX = tailX[0], prevY = tailY[0],  prev2X,prev2Y;
    tailX[0]=x; tailY[0]=y;

    for(int i=1;i<nTail;i++){ prev2X = tailX[i]; prev2Y = tailY[i]; tailX[i] = prevX; tailY[i] = prevY; prevX = prev2X; prevY = prev2Y; }
    
    switch (dir) { case UP: y--; break; case DOWN: y++; break; case LEFT: x--; break; case RIGHT: x++; break; default: break; }

    if (x < 0 || x > width || y < 0 || y > height) gameOver = true;

    for(int i =0;i<nTail;i++) if(x==tailX[i] && y==tailY[i]) gameOver = true;
    
    if (x == fruitX && y == fruitY) { score += 10; fruitX = rand() % width; fruitY = rand() % height; nTail++;}
}

int main()
{ Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(40);
    }
    return 0;
}
// hahahaha