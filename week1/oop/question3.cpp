#include <iostream> 

using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};

Character::Character() {
    // STUDENT ANSWER
    this->hp = 0;
    this->x = 0;
    this->y = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;
}

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    int d1 = this->x - other->getX();
    d1 = d1 < 0 ? 0 - d1 : d1;
    int d2 = this->y - other->getY();
    d2 = d2 < 0 ? 0 - d2 : d2;
    return d1 + d2;
}

int main() {
    Character* ch31 = new Character(100, 1, 2);
    Character* ch32 = new Character(100, -3, 4);
    cout << ch31->getManhattanDistTo(ch32);
    delete ch31;
    delete ch32;
    return 0;
}