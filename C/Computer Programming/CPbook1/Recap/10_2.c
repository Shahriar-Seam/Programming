#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	int i, root;
	
	root =  sqrt(n);
	
	if (n == 2) {
		return 1;
	}
	
	else if (n % 2 == 0) {
		return 0;
	}
	
	for (i = 3; i <= root; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int n;
	
	while (1) {
		printf("Enter a number (Enter 0 to exit): ");
		scanf("%d", &n);
		
		if (n == 0) break;
		
		else if (is_prime(n)) {
			printf("%d is a prime number.\n", n);
		}
		
		else {
			printf("%d is not a prime number.\n", n);
		}
	}
	
	return 0;
}