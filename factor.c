#include "factor.h"

/**
 * factorize - factorize a number
 * @buf: pointer to the address of the number
 *
 * Return: zero
 */
int factorize(char *buf)
{

	u_int32_t digt;
	u_int32_t i;

	digt = atoi(buf);


	for (i = 2; i < digt; i++)
	{
		if (digt % i == 0)
		{
			printf("%d=%d*%d\n",digt,digt/i,i);
			break;
		}
	}

return 0;

}

/**
 * main - main function
 *
 * Return: zero
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	size_t i;
	ssize_t line;
	char *buf = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((line = getline(&buf, &i, fp)) != -1)
	{
		factorize(buf);
	}
return 0;
}
