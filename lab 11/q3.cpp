#include <iostream>
#include <exception>

class InvalidTemperatureException : public std::exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9/5) + 32;
}

int main() {
    try {
        std::cout << "Attempting to convert -300C...\n";
        double fahrenheit = convertToFahrenheit(-300.0);
    } catch (const InvalidTemperatureException&) {
        std::cout << "Caught InvalidTemperatureException - what(): std::exception\n";
    }

    return 0;
}
