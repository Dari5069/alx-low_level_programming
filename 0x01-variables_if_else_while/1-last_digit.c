#include<stdlib.h>
#include<time.h>
#include<stdio.h>
/**
 * main - Enrty point
 * checking for the last digit of random numbers
 * Return: always 0 if successful
 */
int main(void)
{
	int n;
	int ld;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld = n % 10;
	if (ld > 5)
	{
		printf("last digit of %d is %d and is greater than 5\n", n, ld);
	}
	else if (n == 0)
	{
		printf("last digit of %d is %d and is equal 0\n", n, ld);
	}
	else if (n < 6 && n != 0)
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", n, ld);
	}
	return (0);
}
