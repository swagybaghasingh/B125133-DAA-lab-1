
#include <iostream>
using namespace std;

class Recommender {
public:
    virtual void generateRecommendation(int rating, int popularity) {}
};

class PersonalizedRecommender : public Recommender {
public:
    void generateRecommendation(int rating, int popularity) override {
        cout << "Personalized score: "
             << 0.7 * rating + 0.3 * popularity << endl;
    }
};

class TrendingRecommender : public Recommender {
public:
    void generateRecommendation(int rating, int popularity) override {
        cout << "Trending score: "
             << 0.3 * rating + 0.7 * popularity << endl;
    }
};

int main() {
    PersonalizedRecommender p;
    TrendingRecommender t;

    Recommender *r;

    r = &p;
    r->generateRecommendation(80, 60);

    r = &t;
    r->generateRecommendation(80, 60);

    return 0;
}
