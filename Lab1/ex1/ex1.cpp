#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int convert(char p) {
	int a = 0;
	if (p >= '0' && p <= '9')
		a = p - '0';
	else a = 787687;

	return a;
}

int main() {

	int i, numar = 0, q = 0;
	long sum = 0;

	FILE* f;
	f = fopen("in.txt", "r");

	char s[50];
	while (fgets(s, 50, f)) {
		numar = 0;

		for (i = 0; i < strlen(s); i++)
		{
			q = convert(s[i]);
			if (q >= 0 && q <= 9)
				numar = numar * 10 + q;
		}
		sum += numar;
	}

	printf("%d\n", sum);

}