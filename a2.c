#include  <stdio.h>
#include <stdlib.h>

static char *** bubbleSort(char ** arr, int n){
	char ** temp;

}

int main()
{
	char *  buffer;
	FILE * fp;
	size_t len = 0;
	ssize_t read;
	fp = fopen("all_month.csv", "r");
	if(fp == NULL)
	{
	exit(EXIT_FAILURE);

	while((read = getline(&buffer, &len,fp)) != -1){

	printf("retrieved line of length %zu :\n",read);
	printf("%s",buffer);
	
	}

	fclose(fp);

    return 0;
}
}
