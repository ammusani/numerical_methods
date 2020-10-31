#include <stdio.h>
#include <stdlib.h>

double trapezoidal(double (*cal)(double), double start, double end, long n) {
	int flag = 1;
	
	if (n < 1) {
		printf("Logical Error: number of divisions less than 1");
		exit(-1);
	}

	if (end < start) {
		start += end;
		end = start - end;
		start = start - end;
		flag = -1;
	}
	
	double h = (end - start) / n;
	double sum = (*cal)(start);
	sum += (*cal)(end);
	
	// printf("%lf %lf %lf %lf\n", h, sum, start, end);

	for (int i = 1; i < n; i++) {
		start += h;
		sum += 2 * (*cal)(start);
	}
	return (h / 2) * sum * flag;
}
