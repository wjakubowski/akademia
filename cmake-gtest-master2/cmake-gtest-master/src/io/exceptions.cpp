#include <iostream>
#include <fstream>

int main() {
    std::ifstream in;
    in.exceptions(std::ios::failbit); // throw exceptions when operation sets failbit 
    try {
        in.open("/does/not/exist");
    } catch (const std::ios::failure& e) { // base class for IO exceptions
        std::cerr << "Failed to open file: " << e.what() << std::endl;
    }
}
