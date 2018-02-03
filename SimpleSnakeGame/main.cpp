#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;
int x,y,fruitX,fruitY,score;
enum Direction {STOP = 0, UP, DOWN, LEFT, RIGHT};
Direction dir;
int tailX[1000];
int tailY[1000];
int nTail;
string username;

void Setup(){
    gameOver = false;
    x = width / 2;
    y = height / 2;
    //fruitX = rand() % width-2 + 3;
    //fruitY = rand() % height-2 +2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    dir = STOP;
    cout << "Enter username: ";
    getline(cin,username);
    score = 0;
}

void Draw(){
    system("cls");
    for(int i = 0; i< width+2;i++){
        cout << "#";
    }
    cout << endl;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            if(j == 0) cout << "#";
            if(i == y && j == x)cout << "O";
            else if(i == fruitY && j == fruitX)cout << "F";
            else{
                bool print = false;
                for(int k = 0; k < nTail;k++){
                    if(tailY[k] == i && tailX[k] == j){
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
    cout << "Score = "<<score<<endl;
}

void Logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
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
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    if(x >= width-1){
        x = 1;
    }else if(x <= 0){
        x = width-2;
    }
    if(y >= height){
        y = 0;
    }else if(y <= -1){
        y = height-1;
    }
    if(fruitX >= width-1 || fruitX <= 0){
        fruitX = rand()%width-2 + 1;
    }
    if(fruitY >= height || fruitY <= -1){
        fruitY = rand()%height-2 + 1;
    }

    if(x== fruitX && y == fruitY){
        score += 10;
        nTail++;
        //fruitX = rand() % width-2 + 1;
        //fruitY = rand() % height-2 +1;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    for(int i = 0;i < nTail;i++){
        if(x == tailX[i] && y == tailY[i]){
            gameOver = true;
            cout << "Game Over"<<endl;
        }
    }


}

void Input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'k':
            score += 20;
            break;
        case 'n':
            fruitX = rand() % width-1 + 1;
            fruitY = rand() % height-1 +1;
            break;
        }
    }
}
void setScoreInTheDatabase(){
    ofstream write;
    write.open("scores.txt",fstream::app);
    write << username<<" "<<score<<endl;
    write.close();
}
bool comparing(int i,int j){return (i>j);}
void displayHighScores(){
    system("cls");
    map<int,vector<string>> scores;
    vector<int> nums;
    cout << "Your score: "<<score<<endl;
    ifstream read;
    read.open("scores.txt");
    if(read.is_open()){
        string name;
        int num;
        while(read>>name>>num){
            scores[num].push_back(name);
            nums.push_back(num);
        }
    }else{
        cout << "Error"<<endl;
    }
    sort(nums.begin(),nums.end(),comparing);
    vector<int> refined;
    for(int i = 0;i < 10;i++){
        refined.push_back(nums[i]);
    }
    read.close();
    int amount = 1;
    for(int i = 0;i < refined.size();i++){
        for(auto j = scores.begin();j != scores.end();j++){
            if(j->first == refined[i]){
                for(int k = 0;k < (j->second).size();k++){
                    cout << amount<<"."<<j->second[k] <<" - "<<j->first<<endl;
                    amount++;
                    if(amount > 10){
                        break;
                    }
                }
            }
            if(amount > 10){
                break;
            }
        }
        if(amount > 10){
            break;
        }
    }
    cout << "Do you want to delete all scores? (Y/N):"<<endl;
    char choice;
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        if( remove( "scores.txt" ) != 0 )
            cout << "Error deleting file"<<endl;
        else
            cout <<"File successfully deleted"<<endl;
        cout << "Thanks for playing! :)"<<endl;
    }else{
        cout << "Thanks for playing! :)"<<endl;
    }
}
int main(){
    srand(time(NULL));
    cout << "                         Simple Snake game"<<endl;
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    setScoreInTheDatabase();
    displayHighScores();
    return 0;
}
