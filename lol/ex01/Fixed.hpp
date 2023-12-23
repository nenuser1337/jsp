
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int fractional_bits = 8;

public:
    Fixed(); // Default constructor
    Fixed(const int int_value); // New constructor taking an integer
    Fixed(const float float_value); // New constructor taking a float
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const; // New member function to convert to float
    int toInt() const; // New member function to convert to integer
};

// Now let's overload the << operator to output the value of Fixed objects
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP
