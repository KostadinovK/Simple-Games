#include <iostream>
#include <windows.h>
#include "snake.h"
#include "fruit.h"
#include "field.h"
#include "gameEngine.h"
using namespace std;

int main(){
    Snake snake;
    Fruit fruit;
    Field field;
    GameEngine game(field,snake,fruit);
    string username;
    cout << "          Simple Snake Game"<<endl;
    cout <<"Username: ";
    cin >> username;
    game.setUsername(username);
    while(!game.gameOver){
        game.getField().draw(game.getFruit(),game.getSnake());
        game.input();
        game.logic();
        Sleep(50);
    }
    game.setScoreIntoDatabase();
    game.displayHighScores();
    return 0;
}
