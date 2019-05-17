#include <stdio.h>

int main() {
	int i = 1;
	int N = 100;
	Start:
	if (i <= N) {
		printf("%d \n", i);
		i++;
		goto Start;
	}
}
