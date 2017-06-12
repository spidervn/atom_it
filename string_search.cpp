
#include <stdlib.h>
#include <iostream>
#include <memory.h>

using namespace std;

int bruce_force(const char* str, const char* pattern) {
	int n = strlen(str);
	int m = strlen(pattern);

	for (int i=0;i<n;i++) {
		for (int j=0;j<m && i+j<n;j++) {
			if (str[i+j]!=pattern[j]) 
				break;
		}

		if (j==m) {
			// Matching
			return 0;
		}
	}

	// Fail matching
	return 1;
}

// Correctly calculates a mod b even if a < 0
int int_mod(int a, int b) {
	return (a%b + b) % b;
}

int rabin_karp(const char* str, const char* pattern) {
	int h;

	int n = strlen(str);			// n length of str, m = length of pattern
	int m = strlen(pattern);
	
	// int M = ; // Big Enough Prime number

	// Hash function
	for (int i=0;i<m;i+) {
		h += (int)(str[i]) * b[m-1-i];
	}

	int hp = 0;
	int ht = 0;
	int (int i=0;i<m;i++) {
		hp = int_mod(hp*B + pattern[i], M);
	}

	for (int i=0;i<m;i++) {
		ht = int_mod(ht * B + str[i], M);
	}

	if (ht == hp) {
		// Matched
		return 0;
	}

	for (int i=m;i<n;i++) {
		ht = int_mod(ht - int_mod(str[i-m] * E, M), M);
		ht = int_mod(ht*B, M);
		ht = int_mod(ht + str[i], M);

		if (ht == hp) {
			// matched
			return 0;
		}
	}
	return 1;
}

int main(int argc, char**argv) {
	const char* str = "Cong hoa xa hoi chu nghia viet nam";
	const char* pattern = "hoi";
	printf("Matching %d\r\n", bruce_force(str, pattern));
}
