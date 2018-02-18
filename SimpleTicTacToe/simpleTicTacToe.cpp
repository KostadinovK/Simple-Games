#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<char>> matrix  {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
char player = 'X';
void Draw();
void Input();
void TogglePlayer();
char Win();
int main(){
    int turns = 0;
    bool gameOver = false;
    Draw();
    while(1){
        Input();
        Draw();
        if(Win() == 'X'){
            cout << "X player wins!"<<endl;
            break;
        }else if(Win() == 'O'){
            cout << "O player wins!"<<endl;
            break;
        }
        TogglePlayer();
        turns++;
        if(turns == 9){
            gameOver = true;
            break;
        }
    }
    if(gameOver == true)cout << "It is draw!"<<endl;

    return 0;
}
void Draw(){
    system("cls");
    cout << "Tic Tac Toe v1.0"<<endl;
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[i].size();j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }

}
void Input(){
    cout << player<<" player turn."<<endl;
    int a;
    cout << "Enter the number of the field you want to: ";
    cin >> a;
    switch(a){
    case 1:
        if(matrix[0][0] == '1'){
            matrix[0][0] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 2:
        if(matrix[0][1] == '2'){
            matrix[0][1] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 3:
        if(matrix[0][2] == '3'){
            matrix[0][2] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 4:
        if(matrix[1][0] == '4'){
            matrix[1][0] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 5:
        if(matrix[1][1] == '5'){
            matrix[1][1] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 6:
        if(matrix[1][2] == '6'){
            matrix[1][2] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 7:
        if(matrix[2][0] == '7'){
            matrix[2][0] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 8:
        if(matrix[2][1] == '8'){
            matrix[2][1] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;
    case 9:
        if(matrix[2][2] == '9'){
            matrix[2][2] = player;
        }else{
            cout << "This field is invalid!Try Again!"<<endl;
            Input();
        }
        break;

    default:
        cout << "Invalid field!Try again!"<<endl;
        Input();
        break;
    }
}
void TogglePlayer(){
    if(player == 'X'){
        player = 'O';
    }else{
        player = 'X';
    }
}
char Win(){
    /// X X X
    if(matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X'){
        return 'X';
    }else if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X'){
        return 'X';
    }else if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }
    /// X
    /// X
    /// X
    if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X'){
        return 'X';
    }else if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X'){
        return 'X';
    }else if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }
    /// X diagonals
    if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }else if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X'){
        return 'X';
    }

    ///O O O
    if(matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O'){
        return 'O';
    }else if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O'){
        return 'O';
    }else if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O'){
        return 'O';
    }

    if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O'){
        return 'O';
    }else if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O'){
        return 'O';
    }else if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O'){
        return 'O';
    }

    if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O'){
        return 'O';
    }else if(matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O'){
        return 'O';
    }
    return '/';
}
