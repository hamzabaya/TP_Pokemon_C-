#include "TrainerCard.h"

#include <iostream.h>

using namespace std;


using namespace std;

TrainerCard::TrainerCard(){}

TrainerCard::TrainerCard(const string& name, const string& trainEffect): Card(name), trainEffect(trainEffect){}

void TrainerCard::displayInfo(){
        cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainEffect << endl;
    }
