#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <stdlib.h>
 
int main (void)
{
    int fd1, sz,fd2;
    char *c = (char *) calloc(100, sizeof(char));
    char buf1[12] = "hello world";
    char buf2[12];
 
    // assume foobar.txt is already created
    fd1 = open("footbar.txt", O_RDWR);        
    write(fd1, buf1, strlen(buf1));
    close(fd1);
   
    fd2 = open("footbar.txt", O_RDWR);
    sz = read(fd1, c, 12);
    c[sz] = '\0';
    printf("%s\n", c);    
    close(fd2);
 
    return 0;
}


