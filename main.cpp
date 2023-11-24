#include <iostream>
#include <vector>
#include <random>

class Particle {
public:
    Particle(double x, double y, double z, double vx, double vy, double vz)
            : position{x, y, z}, velocity{vx, vy, vz}, active(true) {}

    void update(double dt) {
        if (!active) return;

        position[0] += velocity[0] * dt;
        position[1] += velocity[1] * dt;
        position[2] += velocity[2] * dt;

        if (position[0] < 0 || position[0] > 10 || position[1] < 0 || position[1] > 10
        || position[2] < 0 || position[2] > 10) {
            active = false;
            std::cout << "Particle collided and deactivated at (" << position[0]
            << ", " << position[1] << ", " << position[2] << ")\n";
        }
    }

    bool is_active() const {
        return active;
    }

private:
    std::vector<double> position;
    std::vector<double> velocity;
    bool active;
};

Particle generate_particle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0);

    return Particle(dis(gen), dis(gen), dis(gen), dis(gen), dis(gen), dis(gen));
}

int main() {
    std::vector<Particle> particles;

    for (int i = 0; i < 10; ++i) {
        particles.push_back(generate_particle());
    }

    double dt = 0.1;
    for (int t = 0; t < 100; ++t) {
        for (auto& particle : particles) {
            particle.update(dt);
        }

        particles.push_back(generate_particle());
    }

    return 0;
}
