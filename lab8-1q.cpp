
#include <iostream>
using namespace std;

class Character {
public:
    virtual void attack() {}
};

class Warrior : public Character {
    int strength = 10;
public:
    void attack() override {
        cout << "Warrior damage: " << 20 + 2 * strength << endl;
    }
};

class Archer : public Character {
    int agility = 15;
public:
    void attack() override {
        cout << "Archer damage: " << 15 + 3 * agility << endl;
    }
};

int main() {
    Warrior w;
    Archer a;
    w.attack();
    a.attack();
    return 0;
}
