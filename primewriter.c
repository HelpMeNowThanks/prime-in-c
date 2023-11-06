#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(unsigned long long int num) {
	if(num<=1) {return 0;} // 1 and lower aren't primes
	unsigned long int sqrtnum = ceil(sqrt(num));
	for(unsigned long long int i = 2; i<=sqrtnum; i++) {
		if(num==i) {
			return 1;
		}
		if(num%i==0) { //loop through
			printf("%u\n", i);
			return 0;
		}
	}
	return 1;
}

int main() {
	FILE* fptr;
	fclose(fopen("primes.txt", "w"));
	
	for(unsigned long long int i = 2; i < 18446744073709551609; i++) {
		if(i%2==0) {
			i++;
		}
		if(isPrime(i)==1) {
			fptr = fopen("primes.txt", "a");
			fprintf(fptr, "%d\n", i);
			fclose(fptr);
		}
	}
	return 0;
}