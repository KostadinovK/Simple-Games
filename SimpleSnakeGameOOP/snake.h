#pragma once
#include <string>
using namespace std;

enum Direction{STOP = 0,LEFT,RIGHT,UP,DOWN};
class Snake{
private:
    Direction dir;
    int headX;
    int headY;
    int nTail;
public:
    int tailX[1000];
    int tailY[1000];
    Snake();
    int getX();
    int getY();
    int getTails();
    void setX(int x);
    void setY(int y);
    void move();
    void setDir(char dir);
    void setTails(int tails);
    void increaseTail();
};
