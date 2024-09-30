#include <iostream>
using namespace std;

// Base class for a generic weapon
class Weapon {
public:
    // Method to shoot
    virtual void shoot() {
        cout << "Weapon shooting!" << endl;
    }

    // Overloaded method to shoot with different power levels
    void shoot(int power) {
        cout << "Weapon shooting with power level: " << power << endl;
    }
};

// Derived class for a specific type of weapon
class LaserGun : public Weapon {
public:
    // Overriding the shoot method
    void shoot() override {
        cout << "LaserGun shooting!" << endl;
    }
};

int main() {
    Weapon w;
    LaserGun lg;

    // Using the base class object
    w.shoot();          // Calls Weapon's shoot
    w.shoot(5);         // Calls overloaded shoot with power level

    // Using the derived class object
    lg.shoot();         // Calls LaserGun's shoot (overridden method)
    lg.shoot(10);       // Calls overloaded shoot with power level (inherited from Weapon)

    return 0;
}
