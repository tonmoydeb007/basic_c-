#include <iostream>
using namespace std;


double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}


double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}


double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheitToCelsius(fahrenheit) + 273.15);
}


double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}


double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}


int main() {
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
                cout << "Enter temperature in Celsius: ";
                cin >> temperature;
                result = celsiusToFahrenheit(temperature);
                cout << "Temperature in Fahrenheit: " << result << " °F" << endl;
                break;

            case 2:
                cout << "Enter temperature in Celsius: ";
                cin >> temperature;
                result = celsiusToKelvin(temperature);
                cout << "Temperature in Kelvin: " << result << " K" << endl;
                break;

            case 3:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temperature;
                result = fahrenheitToCelsius(temperature);
                cout << "Temperature in Celsius: " << result << " °C" << endl;
                break;

            case 4:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temperature;
                result = fahrenheitToKelvin(temperature);
                cout << "Temperature in Kelvin: " << result << " K" << endl;
                break;

            case 5:
                cout << "Enter temperature in Kelvin: ";
                cin >> temperature;
                result = kelvinToCelsius(temperature);
                cout << "Temperature in Celsius: " << result << " °C" << endl;
                break;

            case 6:
                cout << "Enter temperature in Kelvin: ";
                cin >> temperature;
                result = kelvinToFahrenheit(temperature);
                cout << "Temperature in Fahrenheit: " << result << " °F" << endl;
                break;

            case 7:
                cout << "Exiting the application." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
