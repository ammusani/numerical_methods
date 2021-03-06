#include <stdio.h>
#include <stdlib.h>
#include "numericalIntegration.h"
#include "testFunction.h"

int main() {
	int n = 10000;
	double start = 3;
	double end = 3.1;
	FILE *fp;
	fp = fopen("TrapezOut1.txt", "w");

	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, trapezoidal(x_cube, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);
	fp = fopen("TrapezOut2.txt", "w");
	end = 3.1;
	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, trapezoidal(log_x, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);
	fp = fopen("TrapezOut3.txt", "w");
	end = 3.1;
	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, trapezoidal(poly1, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);


	return 0;
}
