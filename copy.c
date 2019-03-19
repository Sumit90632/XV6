#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"//THIS IS FOR THE COMMANDS LIKE OPEN()
char buf[512];

int
main(int argc, char *argv[])
{
  //ARGC WOULD RETURN THE COUNT OF ARGUMENTS PRESENT INCLUDING THE COMMAND ITSELF AND ARGV IS A VECTOR/ARRAY OF THE ARGUMENS INCLUDING THE COMMAND
  int fd0,fd1,n;

  if(argc <= 1)
  {
   	printf(1,"Nothing Typed! ");
    	exit();
  }


 if(argc <= 2)
  {
   	printf(1,"You need to Type atleast 2 files names. First to be copied and the other to be copied to. ");
    	exit();
  }

 if((fd0=open(argv[1],O_RDONLY))<0)//THE OPEN COMMAND TAKES THE ARGUMENT1(WHICH IS THE FILE NAME) AND OPENS IT AND GIVES IT ONLY THE PERMISSION TO READ AND FINALLY STORES THE FILEDESCRIPTOR VALUE IN FD0
 {
	printf(1,"There was an error reading the File %s \n",argv[1]);
	exit();
 }

if((fd1=open(argv[2],O_CREATE|O_RDWR))<0)//THE OPEN COMMAND TAKES THE ARGUMENT1(WHICH IS THE FILE NAME) AND OPENS IT AND GIVES IT THE PERMISSION TO READ/write and create  AND FINALLY STORES THE FILEDESCRIPTOR VALUE IN FD1
 {
  	printf(1,"There was an error reading the File %s \n",argv[2]);
  	exit();
 }

//TILL HERE WE HAVE STORED THE FILE DESCRIPTORS IN FD0 AND FD1.

while((n=read(fd0,buf,sizeof(buf)))>0 ) //THE READ COMMAND ACCEPTS THE FILEDES TO BE READ AND STORES THE READ STRING INTO BUFFER AND TAKES THE SIZEOF TO SEE IF THE SIZEOFBUFFENOUGH IT RETURNS 0 ON ERROR OR EOF.
	write(fd1,buf,n);//n is the bytes read above, the write using the file descriptor writes the output buf on that file.
close(fd0);//WE CLOSE BOTH THE FILES USING THE FILE DESCRIPTOR.
close(fd1);
exit();
}
