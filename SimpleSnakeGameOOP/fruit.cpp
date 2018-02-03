#include "fruit.h"

Fruit::Fruit(){
    this->x = rand() % 20;
    this->y = rand() % 20;
}
int Fruit::getX(){
    return this->x;
}
int Fruit::getY(){
    return this->y;
}
void Fruit::setCords(){
    this->x = rand()%20;
    this->y = rand()%20;
}
