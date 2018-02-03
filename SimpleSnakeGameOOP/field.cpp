#include <iostream>
#include "field.h"
using namespace std;

Field::Field(){
    this->width = 20;
    this->height = 20;
    this->score = 0;
}
int Field::getHeight(){
    return this->height;
}
int Field::getWidth(){
    return this->width;
}
int Field::getScore(){
    return this->score;
}
void Field::setHeight(int height){
    this->height = height;
}
void Field::setWidth(int width){
    this->width = width;
}
void Field::setScore(int score){
    this->score = score;
}
void Field::updateScore(int score){
    if(score != 20){
        this->score += 10;
    }else{
        this->score += 20;
    }

}
void Field::draw(Fruit fruit, Snake snake){
    system("cls");
    for(int i = 0; i< width+2;i++){
        cout << "#";
    }
    cout << endl;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            if(j == 0) cout << "#";
            if(i == snake.getY() && j == snake.getX())cout << "O";
            else if(i == fruit.getY() && j == fruit.getX())cout << "F";
            else{
                bool print = false;
                for(int k = 0; k < snake.getTails();k++){
                    if(snake.tailY[k] == i && snake.tailX[k] == j){
                        cout <<"o";
                        print = true;
                    }

                }
                if(!print)cout << " ";

            }

            if(j == width-1){
                cout << "#";
            }
        }
        cout << endl;
    }
    for(int i = 0; i<width+2;i++){
        cout << "#";
    }
    cout << endl;
    cout << "Score = "<<this->score<<endl;
}

