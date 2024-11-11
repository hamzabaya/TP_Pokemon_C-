#include "EnergyCard.h"
#include "Card.h"

#include <iostream.h>

using namespace std;

EnergyCard::EnergyCard(){}

EnergyCard::EnergyCard(const string& name, const string& type): Card(name),energyType(type){}

void EnergyCard::displayInfo(){
    cout << "Energy Card Name: " << cardName << ", Type: " << energyType << endl;
}