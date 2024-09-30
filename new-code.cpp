#include <iostream>
using namespace std;

// Base class for Temperature Conversion
class TemperatureConverter {
public:
    virtual double convert(double temp) = 0; // Pure virtual function for conversion
    virtual void displayConversion(double input, double output) = 0; // To display results
};

// Derived class for Celsius to Fahrenheit conversion
class CelsiusToFahrenheit : public TemperatureConverter {
public:
    double convert(double celsius) override {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    void displayConversion(double input, double output) override {
        cout << input << " °C is " << output << " °F" << endl;
    }
};

// Derived class for Celsius to Kelvin conversion
class CelsiusToKelvin : public TemperatureConverter {
public:
    double convert(double celsius) override {
        return celsius + 273.15;
    }

    void displayConversion(double input, double output) override {
        cout << input << " °C is " << output << " K" << endl;
    }
};

// Derived class for Fahrenheit to Celsius conversion
class FahrenheitToCelsius : public TemperatureConverter {
public:
    double convert(double fahrenheit) override {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    void displayConversion(double input, double output) override {
        cout << input << " °F is " << output << " °C" << endl;
    }
};

// Derived class for Fahrenheit to Kelvin conversion
class FahrenheitToKelvin : public TemperatureConverter {
public:
    double convert(double fahrenheit) override {
        return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
    }

    void displayConversion(double input, double output) override {
        cout << input << " °F is " << output << " K" << endl;
    }
};

// Derived class for Kelvin to Celsius conversion
class KelvinToCelsius : public TemperatureConverter {
public:
    double convert(double kelvin) override {
        return kelvin - 273.15;
    }

    void displayConversion(double input, double output) override {
        cout << input << " K is " << output << " °C" << endl;
    }
};

// Derived class for Kelvin to Fahrenheit conversion
class KelvinToFahrenheit : public TemperatureConverter {
public:
    double convert(double kelvin) override {
        return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
    }

    void displayConversion(double input, double output) override {
        cout << input << " K is " << output << " °F" << endl;
    }
};

// Main function with menu
int main() {
    TemperatureConverter* converter = nullptr;
    int choice;
    double temperature, result;

    do {
        cout << "\nTemperature Converter\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Celsius to Kelvin\n";
        cout << "3. Fahrenheit to Celsius\n";
        cout << "4. Fahrenheit to Kelvin\n";
        cout << "5. Kelvin to Celsius\n";
        cout << "6. Kelvin to Fahrenheit\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                converter = new CelsiusToFahrenheit();
                break;
            case 2:
                converter = new CelsiusToKelvin();
                break;
            case 3:
                converter = new FahrenheitToCelsius();
                break;
            case 4:
                converter = new FahrenheitToKelvin();
                break;
            case 5:
                converter = new KelvinToCelsius();
                break;
            case 6:
                converter = new KelvinToFahrenheit();
                break;
            case 7:
                cout << "Exiting the application." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }

        if (choice >= 1 && choice <= 6) {
            cout << "Enter temperature: ";
            cin >> temperature;
            result = converter->convert(temperature);
            converter->displayConversion(temperature, result);
            delete converter;  // Free the allocated memory
        }

    } while (choice != 7);

    return 0;
}
