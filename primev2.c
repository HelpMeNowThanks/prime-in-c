#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(unsigned long long int num) {
	if(num<=1) {return 0;}
	unsigned long int sqrtnum = ceil(sqrt(num));
	for(unsigned long long int i = 2; i<=sqrtnum; i++) {
		if(num==i) {
			return 1;
		}
		if(num%i==0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv) {
	clock_t begin = clock();
	char* ptr;
	unsigned long long int num = strtoull(argv[1], &ptr, 10);
	num = isPrime(num);
	if(num==1) {
		printf("PRIME\n");
	}
	if(num==0) {
		printf("NOT PRIME\n");
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.6lf", time_spent);
}
