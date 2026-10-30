
#include <iostream>
using namespace std;

class SecurityScanner {
public:
    virtual void scan(int threats) {}
};

class BasicScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        cout << "Detected threats: " << threats << endl;
    }
};

class AdvancedScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        cout << "Detected threats: " << threats << endl;
        cout << "Remaining threats: " << threats * 0.1 << endl;
    }
};

int main() {
    BasicScanner b;
    AdvancedScanner a;
    b.scan(100);
    a.scan(100);
    return 0;
}
