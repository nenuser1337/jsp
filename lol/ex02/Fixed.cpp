#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int int_value)
    : value(int_value << fractional_bits) {}

Fixed::Fixed(const float float_value)
    : value(static_cast<int>(roundf(float_value * (1 << fractional_bits)))) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat(); // Assuming toFloat() is a public member function that converts to float
    return os;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat() const { return static_cast<float>(this->value) / (1 << fractional_bits); }

int Fixed::toInt() const { return this->value >> fractional_bits; }

bool Fixed::operator>(const Fixed& other) const { return this->value > other.value; }
bool Fixed::operator<(const Fixed& other) const { return this->value < other.value; }
bool Fixed::operator>=(const Fixed& other) const { return this->value >= other.value; }
bool Fixed::operator<=(const Fixed& other) const { return this->value <= other.value; }
bool Fixed::operator==(const Fixed& other) const { return this->value == other.value; }
bool Fixed::operator!=(const Fixed& other) const { return this->value != other.value; }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    operator++();
    return old;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    operator--();
    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
