#include "snake.h"
using namespace std;
Snake::Snake(){
    this->headX = 10;
    this->headY = 10;
    this->nTail = 0;
    dir = STOP;

}

int Snake::getX(){
    return this->headX;
}
int Snake::getY(){
    return this->headY;
}
int Snake::getTails(){
    return this->nTail;
}
void Snake::setX(int x){
    this->headX = x;
}
void Snake::setY(int y){
    this->headY = y;
}
void Snake::setTails(int tails){
    this->nTail = tails;
}
void Snake::increaseTail(){
    this->nTail++;
}
void Snake::setDir(char dir){
    switch(dir){
    case 'S':
        this->dir = STOP;
        break;
    case 'L':
        this->dir = LEFT;
        break;
    case 'R':
        this->dir = RIGHT;
        break;
    case 'U':
        this->dir = UP;
        break;
    case 'D':
        this->dir = DOWN;
        break;
    }
}
void Snake::move(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = this->headX;
    tailY[0] = this->headY;
    for(int i = 1;i < nTail;i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir){
    case LEFT:
        this->headX--;
        break;
    case RIGHT:
        this->headX++;
        break;
    case UP:
        this->headY--;
        break;
    case DOWN:
        this->headY++;
        break;
    }
    if(this->headX >= 19){
        this->headX = 1;
    }else if(this->headX <= 0){
        this->headX = 18;
    }
    if(this->headY >= 20){
        this->headY = 0;
    }else if(this->headY <= -1){
        this->headY = 19;
    }
}
