#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define alpha 0.95

char *help_msg = "\"Random\" coefficient generator for IMDCT.\n\
	Usage: %s <num_coeff>.\n";

int main(int argc, char **argv)
{
	double x, num, denom, rand2, power;
	int i, size=0;
	
	if (argc != 2) {
		printf(help_msg, argv[0]);
		return -1;
	}
	size = atoi(argv[1]);
	
	srand(time(NULL));
	
	for (i=0; i < size; i++) {
		num = (rand() % 5) * (double) rand() * pow(alpha, i);
		denom = rand();
		x = num / denom;
		fprintf(stdout, "%.10f\n", x);
	}
}
