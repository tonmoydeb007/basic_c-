#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Fighter {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Fighter(std::string n, int h, int ap) : name(n), health(h), attackPower(ap) {}

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isDefeated() const { return health <= 0; }
};

class Game {
private:
    Fighter player;
    Fighter enemy;

public:
    Game() : player("Player", 100, 20), enemy("Enemy", 100, 18) {}

    void playTurn() {
        // Player's turn
        int playerDamage = rand() % player.getAttackPower();
        enemy.takeDamage(playerDamage);
        std::cout << player.getName() << " deals " << playerDamage << " damage to " << enemy.getName() << std::endl;

        if (enemy.isDefeated()) return;

        // Enemy's turn
        int enemyDamage = rand() % enemy.getAttackPower();
        player.takeDamage(enemyDamage);
        std::cout << enemy.getName() << " deals " << enemyDamage << " damage to " << player.getName() << std::endl;
    }

    void playGame() {
        std::cout << "Fight begins!" << std::endl;
        while (!player.isDefeated() && !enemy.isDefeated()) {
            playTurn();
            std::cout << player.getName() << " Health: " << player.getHealth() << std::endl;
            std::cout << enemy.getName() << " Health: " << enemy.getHealth() << std::endl;
            std::cout << std::endl;
        }

        if (player.isDefeated()) {
            std::cout << "Game Over! " << enemy.getName() << " wins!" << std::endl;
        } else {
            std::cout << "Congratulations! " << player.getName() << " wins!" << std::endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    Game game;
    game.playGame();
    return 0;
}