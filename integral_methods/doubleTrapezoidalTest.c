#include <stdio.h>
#include <stdlib.h>
#include "numericalIntegration.h"
#include "testFunction.h"

int main() {
	int x_n;
	int y_n;
	double x_start;
	double x_end;
	double y_start;
	double y_end;
	scanf("%lf%lf%lf%lf%d%d", &x_start, &x_end, &y_start, &y_end, &x_n, &y_n);
	printf("%lf\n", doubleTrapezoidal(inv_x_plus_y, x_start, x_end, y_start, y_end, x_n, y_n));
	return 0;
}
