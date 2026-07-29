#ifndef __math_H
#define __math_H

#define FP_INFINITE 0x01
#define FP_NAN 0x02
#define FP_NORMAL 0x04
#define FP_SUBNORMAL 0x08
#define FP_ZERO 0x10
#define PI 3.141592653

double acos(double);
double asin(double);
double atan(double);
double atan2(double, double);
double ceil(double);
double cos(double);
double sin(double);
double tan(double);
double cosh(double);
double sinh(double);
double tanh(double);
double exp(double);
double fabs(double);
double floor(double);
double fmod(double, double);
double frexp(double, int*);
double ldexp(double, int);
double log(double);
double log10(double);
double modf(double, double*);
double intpow(double, int);
double pow(double, double);
double sqrt(double);
float fabsf(float);
float sqrtf(float);

#endif
