#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

int main() {
    // Horizontal reference line y = constant
    const double y_line = 1.0;

    // Initial car state
    Point car{0.0, 0.0};
    const double v = 1.0;    // forward speed
    const double d_h = 5.0;  // lookahead distance
    const double dt = 1.0;   // time step (seconds)

    std::cout << "Starting Challenge 1 Simulation\n";
    std::cout << "-----------------------------------\n";

    int t = 0;
    while (t < 15) {

        // 1) Signed lateral distance to the reference line
        double dist = car.y - y_line;

        // 2) Steering law (simple proportional control with atan)
        double theta = std::atan(-(dist / d_h));

        // 3) Velocity components in world coordinates
        double vx = v * std::cos(theta);
        double vy = v * std::sin(theta);

        // 4) Integrate car position
        car.x += vx * dt;
        car.y += vy * dt;

		t++;

        // Log state
        std::cout << "t=" << t
                  << "   Car=(" << car.x << ", " << car.y << ")"
                  << "   Dist=" << dist
                  << "   Theta=" << theta
                  << "\n";
    }

    std::cout << "-----------------------------------\n";
    std::cout << "End of Challenge 1!\n";
    return 0;
}
