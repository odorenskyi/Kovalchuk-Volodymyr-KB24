#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

void calculate_and_print(double x, double y, double z) {
    try{
        if (y == 0) {
        throw invalid_argument("Error: y cannot be zero.");
    }
    double S = sqrt(z * z * (0.5 * y)) + (M_PI * x + exp(y)) / y;
    cout << "Result S = " << S << endl;
    } catch (const exception& e) {
        cout << "Error: " <<
        e.what() << endl;
    }
}
