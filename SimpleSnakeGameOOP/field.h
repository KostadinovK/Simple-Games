#pragma once
#include "fruit.h"
#include "snake.h"

class Field{
private:
    int width;
    int height;
    int score;
public:
    Field();
    int getWidth();
    int getHeight();
    int getScore();
    void setWidth(int width);
    void setHeight(int height);
    void setScore(int score);
    void updateScore(int score);
    void draw(Fruit fruit,Snake snake);
};
