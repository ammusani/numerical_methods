#include <stdio.h>
#include <stdlib.h>
#include "numericalIntegration.h"
#include "testFunction.h"

int main() {
	int x_n = 1000;
	double x_start = 2.987;
	double x_end = 3.11;
	int y_n = 1000;
	double y_start = 1.11;
	double y_end = 5.12121;
	
	FILE *fp[4];
	fp[0] = fopen("Trapez1.txt", "w");
	fp[1] = fopen("Trapez2.txt", "w");
	fp[2] = fopen("Trapez3.txt", "w");
	fp[3] = fopen("Trapez4.txt", "w");
	
	for (int i = 0; i < 100; i++) {
		y_end = 5.12121;
		for (int j = 0; j < 100; j++) {
			fprintf(fp[0], "%lf\t%lf\t%lf\n", x_end, y_end, doubleTrapezoidal(x_plus_y, x_start, x_end, y_start, y_end, x_n, y_n));
			fprintf(fp[1], "%lf\t%lf\t%lf\n", x_end, y_end, doubleTrapezoidal(xy_square, x_start, x_end, y_start, y_end, x_n, y_n));
			fprintf(fp[2], "%lf\t%lf\t%lf\n", x_end, y_end, doubleTrapezoidal(exp_x_y, x_start, x_end, y_start, y_end, x_n, y_n));
			fprintf(fp[3], "%lf\t%lf\t%lf\n", x_end, y_end, doubleTrapezoidal(inv_x_plus_y, x_start, x_end, y_start, y_end, x_n, y_n));
	
			y_end = y_end + 0.01;
		}
		x_end = x_end + 0.01;
	}

	fclose(fp[0]);
	fclose(fp[1]);
	fclose(fp[2]);
	fclose(fp[3]);

	return 0;
}
