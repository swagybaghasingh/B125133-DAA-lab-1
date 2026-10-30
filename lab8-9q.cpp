
#include <iostream>
using namespace std;

class Robot {
public:
    virtual void move(double distance) {}
};

class WheeledRobot : public Robot {
public:
    void move(double distance) override {
        cout << "Wheeled robot time: "
             << distance / 2 << " seconds" << endl;
    }
};

class TrackedRobot : public Robot {
public:
    void move(double distance) override {
        cout << "Tracked robot time: "
             << distance / 1.2 << " seconds" << endl;
    }
};

int main() {
    WheeledRobot w;
    TrackedRobot t;

    Robot *p;

    p = &w;
    p->move(10);

    p = &t;
    p->move(10);

    return 0;
}
