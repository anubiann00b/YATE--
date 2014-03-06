#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
FILE *f;void end(int signal){fclose(f);exit(0);}int main(int n,char *a[]){if (n!=2)return -1;if ((f=fopen(a[1],"w"))==NULL)return -1;signal(SIGINT,end);char c;while(1){if ((c=getchar())!=-1){fprintf(f,"%c",c);}}}