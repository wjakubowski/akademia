#include <iostream>
#include <iomanip>  // for manipulators


int main() {
    int value = 27, other = 13;

    std::cout << std::showbase;
    std::showbase(std::cout); // same as the above - std::showbase is a function

    // That's what's actually being done by std::showbase function
    std::cout.setf(std::ios::showbase);

    std::cout << "Octal  : " << std::oct << value << ", " << other << std::endl;
    std::cout << "Hex    : " << std::hex << value << ", " << other << std::endl;
    std::cout << "Decimal: " << std::dec << value << ", " << other << std::endl;

    // std::endl is a normal function
    using simple_manip = std::ostream& (&)(std::ostream&);
    simple_manip eol = std::endl;

    std::cout << "Hello!" << eol;

    // Right-aligned numbers
    // std::setw only affects the next output operation!
    std::cout << "Number 1: " << std::setw(10) << 15 << std::endl;
    std::cout << "Number 2: " << std::setw(10) << 2345678 << std::endl;

    // Floating point formatting
    double val = 10.0 / 3; // 3.(3)
    std::cout << "Default precision: " << std::cout.precision() << std::endl;
    std::cout << "Default: " << val << std::endl;
    std::cout << "10     : " << std::setprecision(10) << val << std::endl;
    std::cout << "2      : " << std::setprecision(2) << val << std::endl;
    // Without manipulator
    std::cout << "15     : ";
    std::cout.precision(15);
    std::cout << val << std::endl;
}
