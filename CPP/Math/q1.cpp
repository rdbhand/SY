#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Function to calculate the directional derivative of a given function at a point in a given direction
double directional_derivative(double x, double y, double z, function<double(double, double, double)> phi, double a_x, double a_y, double a_z) {
    // Gradient of the function phi at point (x, y, z)
    double phi_x = (phi(x + 0.0001, y, z) - phi(x, y, z)) / 0.0001;
    double phi_y = (phi(x, y + 0.0001, z) - phi(x, y, z)) / 0.0001;
    double phi_z = (phi(x, y, z + 0.0001) - phi(x, y, z)) / 0.0001;

    // Unit vector a = <a_x, a_y, a_z> / |<a_x, a_y, a_z>|
    double mag_a = sqrt(a_x * a_x + a_y * a_y + a_z * a_z);
    double unit_a_x = a_x / mag_a;
    double unit_a_y = a_y / mag_a;
    double unit_a_z = a_z / mag_a;

    // Calculate directional derivative
    double dir_derivative = phi_x * unit_a_x + phi_y * unit_a_y + phi_z * unit_a_z;

    return dir_derivative;
}

// Sample function phi = x^2 + y^2 + z^2
double phi(double x, double y, double z) {
    return x * x + y * y + z * z;
}

int main() {
    double x = 1, y = 1, z = 1; // Point (1, 1, 1)
    double a_x = 1, a_y = -1, a_z = 1; // Direction vector <1, -1, 1>

    double result = directional_derivative(x, y, z, phi, a_x, a_y, a_z);

    cout << "Directional derivative of phi(x, y, z) = x^2 + y^2 + z^2 at (1, 1, 1) in the direction of <1, -1, 1> is: " << result << endl;

    return 0;
}