#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person;
    person.name = "tonmoy";
    person.age = 22;
    person.display();
    return 0;
}
