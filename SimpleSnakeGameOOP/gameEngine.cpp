#include "gameEngine.h"

GameEngine::GameEngine(Field field,Snake snake,Fruit fruit){
    this->field.setWidth(field.getWidth());
    this->field.setHeight(field.getHeight());
    this->field.setScore(field.getScore());

    this->snake.setX(10);
    this->snake.setY(10);
    this->snake.setTails(0);
    this->snake.setDir('S');

    this->fruit = fruit;
}

Field GameEngine::getField(){
    return this->field;
}
Snake GameEngine::getSnake(){
    return this->snake;
}
Fruit GameEngine::getFruit(){
    return this->fruit;
}
void GameEngine::setUsername(string name){
    this->username = name;
}
void GameEngine::input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            snake.setDir('L');
            break;
        case 'd':
            snake.setDir('R');
            break;
        case 'w':
            snake.setDir('U');
            break;
        case 's':
            snake.setDir('D');
            break;
        case 'x':
            this->gameOver = true;
            break;
        case 'k':
            this->field.updateScore(20);
            break;
        case 'n':
            this->fruit.setCords();
            //fruitX = rand() % width-1 + 1;
            //fruitY = rand() % height-1 +1;
            break;
        }
    }
}
void GameEngine::logic(){
    this->snake.move();

    if(this->fruit.getX() >= this->field.getWidth()-1 || this->fruit.getX() <= 0 || this->fruit.getY() >= this->field.getHeight() || this->fruit.getY() <= -1){
        this->fruit.setCords();
    }

    if(this->snake.getX()== this->fruit.getX() && this->snake.getY() == this->fruit.getY()){
        this->field.updateScore(10);
        this->snake.increaseTail();
        //fruitX = rand() % width-2 + 1;
        //fruitY = rand() % height-2 +1;
        this->fruit.setCords();
    }
    for(int i = 0;i < this->snake.getTails();i++){
        if(this->snake.getX() == this->snake.tailX[i] && this->snake.getY() == this->snake.tailY[i]){
            this->gameOver = true;
            cout << "Game Over"<<endl;
        }
    }
}

void GameEngine::setScoreIntoDatabase(){
    ofstream write;
    write.open("scores.txt",fstream::app);
    write << this->username<<" "<<this->field.getScore()<<endl;
    write.close();
}

void GameEngine::displayHighScores(){
    system("cls");
    map<int,vector<string>> scores;
    vector<int> nums;
    cout << "Your score: "<<this->field.getScore()<<endl;
    cout << endl;
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
    sort(nums.begin(), nums.end(), std::greater<int>());
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
    cout << endl;
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
