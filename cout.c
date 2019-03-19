#include<stdio.h>
/*#include "types.h"
#include "stat.h"
#include "user.h"*/

char buf[512];
int main(int argc, char *argv[])
{
	int i;
	if(argc <= 1){
		printf(1, "PLEASE TYPE YOUR NAME : ");
		exit();
	}
	for(i = 1; i < argc; i++){
		printf(1, " %s ", argv[i]);
    }
  	printf(1,"\n");
  	//exit();
}
