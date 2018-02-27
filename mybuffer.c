#include <stdio.h>

int main(int argc, char *argv[])
{
	char buffer[256];
	printf("%p\n", buffer);
	strcpy(buffer, argv[1]);
	printf("%s\n", buffer);
	return 0;
}
