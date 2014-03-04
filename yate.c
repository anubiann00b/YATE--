#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
FILE *fp;
void end(int signal){
	fclose(fp);
	exit(0);
}
int main(int argc, char *argv[]){
	if (argc != 2)
		return -1;
	fp = fopen(argv[1],"a");
	if (fp == NULL)
		return -1;
	signal(SIGINT, end);
	char c;
	while(1){
		c = getchar();
		fprintf(fp,"%c",c);
	}
}
