#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card {
    protected:
        string cardName;

    public:
        Card();
        Card(const string& name);
        virtual void displayInfo() = 0;

};
#endif
