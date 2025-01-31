#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"

int main() {
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, {{2, 2, "Thunderbolt", 20}, {3, 2, "Thunderstorm", 30}}));
    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);
    player1.displayBench();
    player1.displayAction();

    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, {{2, 1, "Leech Seed", 15}, {3, 1, "Vine Whip", 25}}));
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);
    player2.displayBench();
    player2.displayAction();

    player1.attack(0, 0, player2, 0);
    player2.useTrainer(0);
    player2.displayAction();

    return 0;
}