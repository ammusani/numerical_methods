#include <stdio.h>
#include <math.h>

double x_square(double x) {
	return x * x;
}

double x_cube(double x) {
	return x * x * x;
}

double x_inverse (double x) {
	return 1 / x;
}

double log_x (double x) {
	return log(x);
}

double poly1 (double x) {
	return 2 * pow(x, 2) - 3 * pow(x, 1) + 4 * pow(x, 0);
}

double xy_square(double x, double y) {
	return x * x * y * y;
}

double x_plus_y (double x, double y) {
	return x + y;
}

double exp_x_y (double x, double y) {
	return exp (x * y);
}

double inv_x_plus_y (double x, double y) {
	return 1 / (x + y);
}
