#include <iostream>


class Particle {
public:
    Particle(double x, double y, double z, double velocity)
            : x_(x), y_(y), z_(z), velocity_(velocity) {}

    void move(double dt) {
        x_ += velocity_ * dt;
        y_ += velocity_ * dt;
        z_ += velocity_ * dt;
    }

    bool checkCollision(double surfaceZ) const {
        return z_ <= surfaceZ;
    }

    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

private:
    double x_;
    double y_;
    double z_;

    double velocity_;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
