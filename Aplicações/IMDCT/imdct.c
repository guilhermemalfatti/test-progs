#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//double *x;
//double *y;
//int i,j;
//int input_size;
//int output_size;
char *help_msg = "IMDCT - Inverse Modified Cosine Transform.\nUsage: %s <input_file> <num. of coef.>.\n\
	The input file should contain the ordered coefficients, one per line.\n";

int main(int argc, char **argv)
{

    register double *x;
    register double *y;
    register int i,j;
    register int input_size;
    register int output_size;
	if (argc != 3) {
		printf(help_msg, argv[0]);
		return -1;
	}

	char *filename = argv[1];
	input_size = atoi(argv[2]);
	output_size = 2 * input_size;

	x = malloc(sizeof(double)*input_size);
	y = malloc(sizeof(double)*output_size);

	/* Reads input file. */
	FILE *input_file = fopen(filename, "r");
	char buffer[22] = {'\0'};
	for ( i = 0; i < input_size; i++) {
		fgets(buffer, 21, input_file);
		x[i] = atof(buffer);
	}
	fclose(input_file);



	/** Evaluates y */
	for( i = 0; i < output_size; i++) {
		y[i] = 0;
		for ( j = 0; j < input_size - 1; j++) {
            if(x[j] != 0.0000000000)
                y[i] += x[j] * cos(M_PI/input_size * (i + 1/2 + input_size/2) * (j + 1/2));
		}
		y[i] = y[i] * 1/input_size;
	}

	fprintf(stderr, "Output = \n");
	/*for ( i = 0; i < output_size-1; i++) {
		printf("%.10f,", y[i]);
	}*/
	//printf("%.10f\n", y[output_size-1]);

}
