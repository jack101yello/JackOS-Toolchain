#include <math.h>

double intpow(double base, int power) {
	int count = 1;
	while(power-- > 0) {
		count *= base;
	}
	return count;
}
