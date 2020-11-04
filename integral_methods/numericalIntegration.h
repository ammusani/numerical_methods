#include <stdio.h>
#include <stdlib.h>

double trapezoidal(double (*cal)(double), double start, double end, long n) {
	int flag = 1;
	
	if (n < 1) {
		printf("Logical Error: Number of Divisions less than 1\n");
		exit(-1);
	}

	if (end < start) {
		double temp;
		temp = start;
		start = end;
		end = temp;
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

double doubleTrapezoidal(double (*cal)(double, double), double x_start, double x_end, double y_start, double y_end, long x_n, long y_n) {
	int x_flag = 1;
	int y_flag = 1;

	if (x_n < 1) {
		printf("Logical Error: Number of Divisions for x, less than 1\n");
		exit(-1);
	}
	if (x_end < x_start) {
		double temp;
		temp = x_start;
		x_start = x_end;
		x_end = temp;
		x_flag = -1;
	}

	if (y_n < 1) {
		printf("Logical Error: Number of Divisions for y, less than 1\n");
		exit(-1);
	}

	if (y_end < y_start) {
		double temp;
		temp = y_start;
		y_start = y_end;
		y_end = temp;
		y_flag = -1;
	}

	double x_h = (x_end - x_start) / x_n;
	double y_h = (y_end - y_start) / y_n;
	
	double sum = 0;
	double curr_sum;

	double x_val = x_start;
	double y_val = y_start;

	for (int i = 0; i <= x_n; i++) {

		y_val = y_start;

		for (int j = 0; j <= y_n; j++) {
			curr_sum = (*cal)(x_val, y_val);

			if (i != 0 && i != x_n) curr_sum = curr_sum * 2;
			if (j != 0 && j != y_n) curr_sum = curr_sum * 2;

			sum = sum + curr_sum;
			y_val = y_val + y_h;
		}

		x_val = x_val + x_h;
	}

	return (x_h * y_h / 4) * sum * x_flag * y_flag;

}

double simpsonOneThird (double (*cal)(double), double start, double end, long n) {
	int flag = 1;
	
	if (n < 2) {
		printf("Logical Error: Number of Divisions less than 1\n");
		exit(-1);
	}

	if (n % 2) {
		printf("Logical Error: Number of Divisions should be Even\n");
		exit(-1);
	}

	if (end < start) {
		double temp;
		temp = start;
		start = end;
		end = temp;
		flag = -1;
	}
	
	double h = (end - start) / n;
	double sum = (*cal)(start);
	sum += (*cal)(end);
	
	// printf("%lf %lf %lf %lf\n", h, sum, start, end);

	for (int i = 1; i < n; i++) {
		start += h;
		if (i % 2) sum += 4 * (*cal)(start);
		else sum += 2 * (*cal)(start);
	}
	return (h / 3) * sum * flag;
}

double doubleSimpsonOneThird(double (*cal)(double, double), double x_start, double x_end, double y_start, double y_end, long x_n, long y_n) {
	int x_flag = 1;
	int y_flag = 1;

	if (x_n < 2) {
		printf("Logical Error: number of divisions for x, less than 1");
		exit(-1);
	}
	if (x_n % 2) {
		printf("Logical Error: Number of Divisions for x should be Even\n");
		exit(-1);
	}
	if (x_end < x_start) {
		double temp;
		temp = x_start;
		x_start = x_end;
		x_end = temp;
		x_flag = -1;
	}
	
	if (y_n < 2) {
		printf("Logical Error: number of divisions for y, less than 1\n");
		exit(-1);
	}
	if (y_n % 2) {
		printf("Logical Error: Number of Divisions for y should be Even\n");
		exit(-1);
	}
	if (y_end < y_start) {
		double temp;
		temp = y_start;
		y_start = y_end;
		y_end = temp;
		y_flag = -1;
	}

	double x_h = (x_end - x_start) / x_n;
	double y_h = (y_end - y_start) / y_n;
	
	double sum = 0;
	double curr_sum;

	double x_val = x_start;
	double y_val = y_start;

	for (int i = 0; i <= x_n; i++) {

		y_val = y_start;

		for (int j = 0; j <= y_n; j++) {
			curr_sum = (*cal)(x_val, y_val);

			if (i != 0 && i != x_n) {
				if (i % 2) curr_sum = curr_sum * 2;
				curr_sum = curr_sum * 2;
			}
			if (j != 0 && j != y_n) {
				if (j % 2) curr_sum = curr_sum * 2;
				curr_sum = curr_sum * 2;
			}

			sum = sum + curr_sum;
			y_val = y_val + y_h;
		}

		x_val = x_val + x_h;
	}

	return (x_h * y_h / 9) * sum * x_flag * y_flag;

}
