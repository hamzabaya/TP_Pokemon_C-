#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"

#include <string>
using namespace std;

class EnergyCard : public Card {
    private :
        string energyType;

    public :
        EnergyCard();
        EnergyCard(const string& name, const string& type);
        void displayInfo() override;

};
#endif