#include <iostream>


struct Particle {
    double x, y, z;
    bool stuck;

    Particle(double x, double y, double z) : x(x), y(y), z(z), stuck(false) {}
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
