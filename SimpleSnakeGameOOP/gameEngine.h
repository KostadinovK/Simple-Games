#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include "field.h"
#include "snake.h"
#include "fruit.h"

class GameEngine{
private:
    Field field;
    Snake snake;
    Fruit fruit;
    std::string username;
public:
    bool gameOver;
    GameEngine(Field field,Snake snake,Fruit fruit);
    void setUsername(std::string name);
    Field getField();
    Snake getSnake();
    Fruit getFruit();
    void input();
    void logic();
    void setScoreIntoDatabase();
    void displayHighScores();

};
