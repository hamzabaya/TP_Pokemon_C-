#include "PokemonCard.h"

#include <iostream.h>

using namespace std;

PokemonCard::PokemonCard(){}

PokemonCard::PokemonCard(const string& name, const string& pokemonType, const string& familyName, const int& evolutionLevel,
const int& maxHp, const vector<tuple<int,int,string,int>>& attacks) : Card(name),pokemonType(pokemonType),
familyName(familyName),evolutionLevel(evolutionLevel), maxHP(maxHP),attacks(attacks){}

void PokemonCard::displayInfo() {
        cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
            << ", Family: " << familyName << ", Evolution Level: " << evolutionLevel
            << ", HP: " << hp << "/" << maxHP << endl;
    }


void PokemonCard::takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }


void PokemonCard::heal(int amount) {
        hp += amount;
        if (hp > maxHP) hp = maxHP;
    }
