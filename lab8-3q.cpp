
#include <iostream>
using namespace std;

class Compressor {
public:
    virtual void compress(double fileSize) {}
};

class TextCompressor : public Compressor {
public:
    void compress(double fileSize) override {
        cout << "Text compressed size: "
             << fileSize * 0.4 << " MB" << endl;
    }
};

class ImageCompressor : public Compressor {
public:
    void compress(double fileSize) override {
        cout << "Image compressed size: "
             << fileSize * 0.7 << " MB" << endl;
    }
};

int main() {
    TextCompressor t;
    ImageCompressor i;

    cout << "Original size: 100 MB" << endl;
    t.compress(100);
    i.compress(100);
    return 0;
}
