#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"

#include <string>
#include <vector>

using namespace std;

class Player {
    private:
    string playerName;
    vector <Card*> benchCards;
    vector <PokemonCard*> actionCards;

    public:
        Player(){};
        Player(const string& playerName);
        void addCardToBench(Card* card);
        void displayBench();
        void displayAction();
        void activatePokemonCard(int index);
        void attachEnergyCard(int energyIndex, int pokemonIndex);
        void useTrainer(int trainerIndex);
        void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex); 

};
#endif