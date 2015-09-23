#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *x;
double *y;

char *help_msg = "IMDCT - Inverse Modified Cosine Transform.\nUsage: %s <input_file> <num. of coef.>.\n\
	The input file should contain the ordered coefficients, one per line.\n";

int main(int argc, char **argv)
{
	if (argc != 1) {
		printf(help_msg, argv[0]);
		return -1;
	}

	char *filename = "input.txt";
	int input_size = 10;
	int output_size = 2 * input_size;
	
	x = malloc(sizeof(double)*input_size);
	y = malloc(sizeof(double)*output_size);
	
	/* Reads input file. */
	FILE *input_file = fopen(filename, "r");
	char buffer[22] = {'\0'};
	int i;
	for (i = 0; i < input_size; i++) {
		fgets(buffer, 21, input_file);
		x[i] = atof(buffer);
	}
	fclose(input_file);
	
#ifdef DEBUG
	fprintf(stderr, "Input = {");

	for (i = 0; i < input_size-1; i++) {
		fprintf(stderr, "%.10f, ", x[i]);
	}
	fprintf(stderr, "%.10f}\n", x[input_size-1]);
#endif

	/** Evaluates y */
	int j;
	for(i = 0; i < output_size; i++) {
		y[i] = 0;
		for (j = 0; j < input_size - 1; j++) {
			y[i] += x[j] * cos(M_PI/input_size * (i + 1/2 + input_size/2) * (j + 1/2));
		}
		y[i] = y[i] * 1/input_size;
	}
	
	fprintf(stderr, "Output = ");

	for (i = 0; i < output_size-1; i++) {
		printf("%.10f,", y[i]);
	}
	printf("%.10f\n", y[output_size-1]);
	
}
