/*
 * Aplica a TDC sobre a matriz, aplica a inversa e
 * compara a original com a inversa obtida.
 *
 * Compile com:
 * gcc test_tdc_itdc.c tdc.c -lm -o test_tdc_itdc
 *
 * Execute com:
 * ./test_tdc_itdc
 *
 * */

#include <malloc.h>
#define TDC_H

#include <stdlib.h>
#include <assert.h>
#include <math.h>

// metade da raiz de 2
#define r2_2 0.707106781



float C(char c){
	return c == 0? r2_2 : 1;
}

// recebe ponteiro para vetor in de bytes
// guarda os valores da tdc no vetor out de floats
int i, j, u, v;
float sum;
void blocktdc(float **out, unsigned char **in){


	// janela de 8 x 8
	for(u=0;u<8;u++) {
	  for(v=0;v<8;v++) {
			sum = 0;
			for(i = 0; i < 8; i++){
				for(j = 0; j < 8; j++){
					sum += cos( (( 2*i+1 )*u*M_PI) / 16 ) * cos( (( 2*j+1 )*v*M_PI) / 16 ) * (*in)[i*8 + j];
				}
			}

			(*out)[u*8 + v] = ((C(u) * C(v))/4) * sum;
     }
   }
}

// recebe ponteiro para vetor in de floats
// guarda os valores da inversa no vetor out de bytes

void blockitdc(unsigned char **out, float **in){


	// janela de 8 x 8
	for(i=0;i<8;i++) {
	  for(j=0;j<8;j++) {
			sum = 0;
			for(u = 0; u < 8; u++){
				for(v = 0; v < 8; v++){
					sum += ((C(u) * C(v))/4) * cos( (( 2*i+1 )*u*M_PI) / 16 ) * cos( (( 2*j+1 )*v*M_PI) / 16 ) * (*in)[u*8 + v];
				}
			}
			(*out)[i*8 + j] = sum;
     }
   }
}

// aplica tdc
void tdc(float **out, unsigned char **input, int size){
	register int i, j, k, l;
    // quantidade de blocos 8 x 8
    int numblocks = size / 64;

	// quantidade de blocos na vertical e na horizontal
	register int vblocks = pow(numblocks, 0.5);
	register int hblocks = pow(numblocks, 0.5);

	// vetores temporarios para blocos 8 x 8
	unsigned char *tempin = malloc(64);
	float *tempout = malloc(sizeof(float)*64);

	// para cada bloco
	for(i = 0; i < vblocks; i++){
		for(j = 0; j < hblocks; j++){

			// copia o bloco da entrada
			for(k = 0; k < 8; k++){
				for(l = 0; l < 8; l++){
					tempin[k * 8 + l] = (*input)[ i*(size / vblocks) + j*8 + k*8*hblocks + l ];
				}
			}

			// aplica a tdc sobre o bloco
			blocktdc(&tempout, &tempin);

			// copia o bloco para a saida da tdc
			for(k = 0; k < 8; k++){
				for(l = 0; l < 8; l++){
					(*out)[ i*(size / vblocks) + j*8 + k*8*hblocks + l ] = tempout[k * 8 + l];
				}
			}

		} // proximo hblock
	} // proximo vblock
} // fim tdc

// aplica tdc
void itdc(unsigned char **inv, float **input, int size){
	register int i, j, k, l;

	// quantidade de blocos 8 x 8
	register int numblocks = size / 64;

	// quantidade de blocos na vertical e na horizontal
	register int vblocks = pow(numblocks, 0.5);
	register int hblocks = pow(numblocks, 0.5);

	// vetores temporarios para blocos 8 x 8
	float *tempin = malloc(sizeof(float) * 64);
	unsigned char *tempout = malloc(64);

	// para cada bloco
	for(i = 0; i < vblocks; i++){
		for(j = 0; j < hblocks; j++){

			// copia o bloco da entrada
			for(k = 0; k < 8; k++){
				for(l = 0; l < 8; l++){
					tempin[k * 8 + l] = (*input)[ i*(size / vblocks) + j*8 + k*8*hblocks + l ];
				}
			}

			// aplica a inversa da tdc sobre o bloco
			blockitdc(&tempout, &tempin);

			// copia o bloco para a saida da itdc
			for(k = 0; k < 8; k++){
				for(l = 0; l < 8; l++){
					(*inv)[ i*(size / vblocks) + j*8 + k*8*hblocks + l ] = tempout[k * 8 + l];
				}
			}

		} // proximo hblock
	} // proximo vblock

} // fim itdc



int main(){

	// matriz exemplo
	unsigned char input[] = {
		140, 144, 147, 140, 140, 155, 179, 175,
		144, 152, 140, 147, 140, 148, 167, 179,
		152, 155, 136, 167, 163, 162, 152, 172,
		168, 145, 156, 160, 152, 155, 136, 160,
		162, 148, 156, 148, 140, 136, 147, 162,
		147, 167, 140, 155, 155, 140, 136, 162,
		136, 156, 123, 167, 162, 144, 140, 147,
		148, 155, 136, 155, 152, 147, 147, 136
	};
/*
	unsigned char input[] = {
		140, 144, 147, 140, 140,
		144, 152, 140, 147, 140,
		152, 155, 136, 167, 163,
		168, 145, 156, 160, 152,
		162, 148, 156, 148, 140
	};*/

	float *out = malloc(sizeof(float) * sizeof(input));
	unsigned char *inv = malloc(sizeof(input));
	unsigned char *in = input;
    printf("begin.\n");
	tdc(&out, &in, sizeof(input));
	itdc(&inv, &out, sizeof(input));
	//conf(&in, &inv, sizeof(input));
    printf("endy.\n");
	return 0;
}
