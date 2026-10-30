
#include <iostream>
using namespace std;

class IrrigationSystem {
public:
    virtual void calculateWater(double moisture) {}
};

class DripIrrigation : public IrrigationSystem {
public:
    void calculateWater(double moisture) override {
        cout << "Drip water: "
             << 2 * (100 - moisture) << " litres" << endl;
    }
};

class SprinklerIrrigation : public IrrigationSystem {
public:
    void calculateWater(double moisture) override {
        cout << "Sprinkler water: "
             << 3 * (100 - moisture) << " litres" << endl;
    }
};

int main() {
    DripIrrigation d;
    SprinklerIrrigation s;
    d.calculateWater(40);
    s.calculateWater(40);
    return 0;
}
