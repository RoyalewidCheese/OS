#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  struct stat buf;
  int exists;
  DIR *d;
  struct dirent *de;

  d = opendir(".");
  if (d == NULL) {
    fprintf(stderr, "Couldn't open \".\"\n");
    exit(1);
  }

  for (de = readdir(d); de != NULL; de = readdir(d)) {
    exists = stat(de->d_name, &buf);
    if (exists < 0) {
      fprintf(stderr, "%s not found\n", de->d_name);
    } else {
      printf("%s %ld\n", de->d_name, buf.st_size);
    }
  }
  closedir(d);
  return 0;
}


