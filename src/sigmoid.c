#include <math.h>
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}
double sigmoid_derivative(double x) {
    double fx = sigmoid(x);
    return fx * (1.0 - fx);
}
