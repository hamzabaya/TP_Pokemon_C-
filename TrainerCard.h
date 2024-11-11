#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"

#include <string>
using namespace std;

class TrainerCard : public Card {
    private:
        string trainEffect;

    public:     
        TrainerCard();
        TrainerCard(const string& name, const string& trainEffect);
        void displayInfo() override;

};


#endif