#include <stdio.h>

/**
 * is_prime - Check if a number is prime
 * @num: The number to check
 *
 * Return: 1 if prime, and 0 otherwise
 */

int is_prime(int num)
{
	int i;

	if (num < 2)
		return (0);

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return (0);
	}

	return (1);
}

/**
 * factorize - Factorize a number into two smaller numbers
 * @num: The number to factorize
 *
 * Return: Nothing
 */

void factorize(long long num)
{
	if (num < 2)
	{
		printf("%lld=%lld*%lld\n", num, num, 1LL);
		return;
	}

	for (long long i = 2; i <= num / 2; i++)
	{
		if (is_prime(i) && num % i == 0)
		{
			printf("%lld=%lld*%lld\n", num, i, num / i);
			return;
		}
	}

	printf("%lld=%lld*%lld\n", num, num, 1LL);
}

int main(int argc, char *argv[])
{
	long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>", argv[0]);
		return (0);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file\n");
		return (0);
	}

	while (fscanf(file, "%lld", &num) != EOF)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}
