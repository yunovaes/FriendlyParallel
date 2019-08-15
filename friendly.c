#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

long int *the_num;
long int *num;
long int *den;
long int *friendlyNumbers;
int amountOfFriendlyNumbers;

int gcd(int u, int v) {
	if (v == 0)
		return u;
	return gcd(v, u % v);
}

void friendly_numbers(long int start, long int end) {
	long int last = end - start + 1;
	amountOfFriendlyNumbers = 0;

	the_num = (long int*) malloc(sizeof(long int) * last);
	num = (long int*) malloc(sizeof(long int) * last);
	den = (long int*) malloc(sizeof(long int) * last);
	friendlyNumbers = (long int*) malloc(sizeof(long int) * last * 5);

	long int i, j, factor, ii, sum, done, n;

	for (i = start; i <= end; i++) {
		ii = i - start;
		sum = 1 + i;
		the_num[ii] = i;
		done = i;
		factor = 2;
		while (factor < done) {
			if ((i % factor) == 0) {
				sum += (factor + (i / factor));
				if ((done = i / factor) == factor)
					sum -= factor;
			}
			factor++;
		}
		num[ii] = sum;
		den[ii] = i;
		n = gcd(num[ii], den[ii]);
		num[ii] /= n;
		den[ii] /= n;
	} // end for

	#pragma omp parallel for
	for (i = 0; i < last; i++) {
		for (j = i + 1; j < last; j++) {
			if ((num[i] == num[j]) && (den[i] == den[j])) {
				friendlyNumbers[amountOfFriendlyNumbers++] = the_num[i];
				friendlyNumbers[amountOfFriendlyNumbers++] = the_num[j];
			}
		}
	}

	for (i = 0; i < amountOfFriendlyNumbers; i+=2) {
		printf("%ld and %ld are FRIENDLY\n", friendlyNumbers[i], friendlyNumbers[i+1]);
	}
	
	free(friendlyNumbers);
	free(the_num);
	free(num);
	free(den);
}

int main(int argc, char **argv) {
	long int start;
	long int end;

	while (1) {
		scanf("%ld %ld", &start, &end);
		if (start == 0 && end == 0)
			break;
		printf("Number %ld to %ld\n", start, end);
		friendly_numbers(start, end);
	}

	return EXIT_SUCCESS;
}
