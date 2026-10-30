
#include <iostream>
using namespace std;

class ParkingSlot {
public:
    virtual void calculateFee(int hours) {}
};

class TwoWheelerSlot : public ParkingSlot {
public:
    void calculateFee(int hours) override {
        double fee = hours * 10;
        if (hours > 5)
            fee *= 0.9;
        cout << "Two-wheeler fee: Rs. " << fee << endl;
    }
};

class FourWheelerSlot : public ParkingSlot {
public:
    void calculateFee(int hours) override {
        double fee = hours * 30;
        if (hours > 5)
            fee *= 0.9;
        cout << "Four-wheeler fee: Rs. " << fee << endl;
    }
};

int main() {
    TwoWheelerSlot t;
    FourWheelerSlot f;
    t.calculateFee(6);
    f.calculateFee(6);
    return 0;
}
