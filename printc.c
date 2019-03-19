#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
char buf[512];

int
main(int argc, char *argv[])
{
  
  int fd0,n;

  if(argc <= 1)
  {
   	printf(1,"Nothing Typed! ");
    	exit();
  }


 if((fd0=open(argv[1],O_RDONLY))<0)//WE STORED THE FILEDES OF THE FILE TO BE DISPLAYED ON FD0
{
	printf(1,"There was an error reading the File %s \n",argv[1]);
	exit();
 }

while((n=read(fd0,buf,sizeof(buf)))>0 ) 
	write(1,buf,n);//WE GAVE THE FILE DESCRIPTOR 1 MEANING THE STANDARD OUTPUT I.E IS THE SCREEN/TERMINAL.
close(fd0);//WE CLOSE BOTH THE FILES USING THE FILE DESCRIPTOR.
exit();
}
