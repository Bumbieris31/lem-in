#include <stdio.h>
#include "includes/lem-in.h"

int main(void)
{
	char *str = "##";
	char *str2 = "F";
	int num;

	num = hashing_funct(str);
	printf("\n%d\n", num);
	num = hashing_funct(str2);
	printf("\n%d\n", num);
	return (0);
}