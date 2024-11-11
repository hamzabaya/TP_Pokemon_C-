#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <string>
#include <tuple>
#include <vector>
using namespace std;

#include "Card.h";

class PokemonCard : public Card{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int,int,string,int>> attacks; // Cout en energie, cout en energie actuel, description de l'attaque, degats de l'attaque

    public:
        PokemonCard();
        PokemonCard(const string& name, const string& pokemonType, const string& familyName, const int& evolutionLevel,
        const int& maxHp, const vector<tuple<int,int,string,int>>& attacks);
        void displayInfo() override;
        void takeDamage(int damage);
        void heal(int amount); 
};
#endif