#include <stdio.h>
#include <stdlib.h>
#include "numericalIntegration.h"
#include "testFunction.h"

int main() {
	int n = 10000;
	double start = 3;
	double end = 3.1;
	FILE *fp;
	fp = fopen("simpOut1.txt", "w");

	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, simpsonOneThird(x_cube, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);
	fp = fopen("simpOut2.txt", "w");
	end  = 3.1;
	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, simpsonOneThird(log_x, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);
	fp = fopen("simpOut3.txt", "w");
	end = 3.1;
	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%lf\t%lf\n", end, simpsonOneThird(poly1, start, end, n));
		end = end + 0.001;
	}
	fclose(fp);


	return 0;
}
