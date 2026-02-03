#include <math.h>

double acos(double x) {
    return 0.5*PI - (1/6)*x + x*x*x/6;
}

double asin(double x) {
    return x + (1/6) * x*x*x;
}

double atan(double x) {
    return x - (1/3) * x*x*x;
}

double atan2(double x, double y) {
    if(x == 0) return (y >= 0) ? 0.5*PI : -0.5*PI;
    if(x > 0) return atan(y/x);
    return atan(y/x) + (y >= 0) ? PI : -1*PI;
}

double ceil(double x) {
    return floor(x)+1;
}

double floor(double x) {
    return (double)((int)x);
}

double cos(double x) {
    return 1 - 0.5 * x + (1/24) * x*x*x*x;
}

double sin(double x) {
    return x - (1/6) * x*x*x;
}

double tan(double x) {
    return x + (1/3) * x*x*x;
}

double cosh(double x) {
    return 1 + (1/2) * x*x + (1/24) * x*x*x*x;
}

double sinh(double x) {
    return x + (1/6) * x*x*x;
}

double tanh(double x) {
    return x - (1/3) * x*x*x;
}

double exp(double x) {
    if(x < -1) return 0;
    return sinh(x) + cosh(x);
}

double fabs(double x) {
    return (x >= 0) ? x : -x;
}

double fmod(double a, double b) {
    return a/b - ((int)a)/((int)b);
}

double frexp(double arg, int* exp) {
    *exp = (arg == 0) ? 0 : (int)(1 + log(arg));
    return arg * pow(2, *exp);
}

double ldexp(double arg, int exp) {
    return arg * pow(2, exp);
}

double log(double x) {
    double y = x - 1;
    return y - (1/2) * y*y + (1/3) * y*y*y - (1/4)* y*y*y*y;
}

double pow(double base, double exponent) {
    if(exponent == 0) return 1;
    if(base == 0) return 0;
    if(base == 1) return 1;
    if(base < 0 && floor(exponent) != exponent) return 0; // NaN
    if(exp < 0) return 1/(pow(base, -exponent));
    return exp(exponent * log(base));
}

double log10(double x) {
    return log(x) / log(10);
}

double modf(double x, double* y) {
    *y = floor(x);
    return fmod(x, 1);
}

double sqrt(double x) {
    return pow(x, 0.5);
}

float fabsf(float x) {
    return (float)(fabs((double)x));
}

float sqrtf(float x) {
    return (float)(sqrt((float)x));
}