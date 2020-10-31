#include <stdio.h>
#include <stdlib.h>
#include "numericalIntegration.h"
#include "testFunction.h"

int main() {
	int n;
	float start;
	float end;
	scanf("%f%f%d", &start, &end, &n);
	printf("%f\n", trapezoidal(x_square, start, end, n));
	return 0;
}
