#include <stdio.h>

int main(int argc, char **argv){
	//it has to prompt for user name
	//
	char name[50];
	printf("What is your name?\n");
	scanf("%s", name);
	printf("Hello, %s!\n",name);
	return 0;

}
