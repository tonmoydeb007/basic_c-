#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Fighter {
public:
    Fighter(std::string name, int health, int attack) 
        : name(name), health(health), attack(attack) {}

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isDefeated() const { return health <= 0; }

private:
    std::string name;
    int health;
    int attack;
};

class Game {
public:
    Game() : player("Player", 100, 20), enemy("Enemy", 100, 15) {
        srand(time(0));  // Seed the random number generator
    }

    void play() {
        std::cout << "Welcome to the Simple Fighting Game!\n";
        
        while (!player.isDefeated() && !enemy.isDefeated()) {
            printStatus();
            playerTurn();
            if (!enemy.isDefeated()) {
                enemyTurn();
            }
        }

        announceWinner();
    }

private:
    Fighter player;
    Fighter enemy;

    void printStatus() {
        std::cout << "\n" << player.getName() << " HP: " << player.getHealth() 
                  << " | " << enemy.getName() << " HP: " << enemy.getHealth() << "\n";
    }

    void playerTurn() {
        std::cout << "\nYour turn! Choose an action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Defend\n";
        
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "You attack!\n";
                enemy.takeDamage(player.getAttack());
                break;
            case 2:
                std::cout << "You defend, reducing next attack damage.\n";
                // Implement defend logic here
                break;
            default:
                std::cout << "Invalid choice. You hesitate and lose your turn.\n";
        }
    }

    void enemyTurn() {
        std::cout << "\nEnemy's turn!\n";
        if (rand() % 2 == 0) {
            std::cout << "Enemy attacks!\n";
            player.takeDamage(enemy.getAttack());
        } else {
            std::cout << "Enemy defends.\n";
            // Implement enemy defend logic here
        }
    }

    void announceWinner() {
        if (player.isDefeated()) {
            std::cout << "\nGame Over. You were defeated.\n";
        } else {
            std::cout << "\nCongratulations! You defeated the enemy!\n";
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}