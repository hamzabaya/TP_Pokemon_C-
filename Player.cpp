#include "Player.h"

#include <iostream.h>

Player::Player(){};

Player::Player(const string& name) : playerName(name) {};

void Player::addCardToBench(Card* card){
            benchCards.push_back(card);
}

void Player::displayBench(){
    cout << "Player: " << playerName << "Bench Cards:" << endl;
    for (auto& card : benchCards){
        card -> displayInfo();
    }
}

void Player::displayAction() {
    cout << "Player: " << playerName << " Action Cards:" << endl;
    for (auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
            benchCards.erase(benchCards.begin() + index);
            cout << "Activated Pokemon Card: " << pokemonCard->cardName << endl;
        } else {
                cout << "The selected card is not a Pokemon Card." << endl;
        }
    } else {
            cout << "Invalid index." << endl;
    }
}

void Player::attachEnergyCard(int energyIndex, int pokemonIndex) {
    if (energyIndex >= 0 && energyIndex < benchCards.size() && pokemonIndex >= 0 && pokemonIndex < actionCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if (energyCard) {
            cout << "Attached Energy Card: " << energyCard->cardName << " to Pokemon: " << actionCards[pokemonIndex]->cardName << endl;
            benchCards.erase(benchCards.begin() + energyIndex);
        } else {
            cout << "The selected card is not an Energy Card." << endl;
        }
    } else {
        cout << "Invalid index." << endl;
    }
}


void Player::useTrainer(int trainerIndex) {
    if (trainerIndex >= 0 && trainerIndex < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[trainerIndex]);
        if (trainerCard) {
            cout << "Used Trainer Card: " << trainerCard->cardName << " - Effect: " << trainerCard->trainEffect << endl;
            benchCards.erase(benchCards.begin() + trainerIndex);
            for (auto& pokemon : actionCards) {
                pokemon->heal(20);  // Heal each Pokemon by 20 HP
            }
        } else {
            cout << "The selected card is not a Trainer Card." << endl;
        }
    } else {
        cout << "Invalid index." << endl;
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size()) {
        PokemonCard* attacker = actionCards[attackerIndex];
        if (targetIndex >= 0 && targetIndex < opponent.actionCards.size()) {
            PokemonCard* target = opponent.actionCards[targetIndex];
            if (attackIndex >= 0 && attackIndex < attacker->attacks.size()) {
                auto [energyCost, currentEnergy, description, damage] = attacker->attacks[attackIndex];
                cout << "Attacking with " << attacker->cardName << " using " << description << " for " << damage << " damage." << endl;
                target->takeDamage(damage);
            } else {
                cout << "Invalid attack index." << endl;
            }
        } else {
            cout << "Invalid target index." << endl;
        }
    } else {
        cout << "Invalid attacker index." << endl;
    }
}
