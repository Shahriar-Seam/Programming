#include <stdio.h>

int is_prime(int n)
{
	int i;
	
	if (n < 2) {
		return 0;
	}
	
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	if (is_prime(n)) {
		printf("%d is a prime.\n", n);
	}
	else {
		printf("%d is not a prime.\n", n);
	}
	
	return 0;
}