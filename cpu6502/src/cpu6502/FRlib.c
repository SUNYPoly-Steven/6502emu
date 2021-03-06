/*
*  PROGRAM NAME: File Read Library 
*  PROGRAM DESCRIPTION: This program is used to run an emulator for the-
**                      6502 CPU. This is the library file used to store the-
**                      emulator's file reading function declarations. 
* PROGRAM DEVELOPERS: Jesse Lembo + Lukas Mallory;
* DATE STARTED: MARCH 26, 2018;
* DATE COMPLETED: N/A
 */

//#include "include/6502lib.h"
#include "include/FRlib.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

//EMULATOR FUNCTION DECLARATIONS

int test_file(struct stat fileStat){

    int max_byte_size = 64000;

    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n\n",fileStat.st_size);
    printf("Number of Links: \t%ld\n\n",fileStat.st_nlink);
    printf("File inode: \t\t%ld\n\n\n",fileStat.st_ino);



    return !(fileStat.st_size > max_byte_size); //if fileStat.st_size > max_byte_size is true return 0, else return 1

}


void read_file(FILE *infile){
  char a;
  char line[256];

  while((a = fgetc(infile)) != EOF){
    handle_file(line, infile);
  }
}


void handle_file(char *line, FILE *infile){
  while(infile && fgets(line, sizeof(line), infile)){
    if (strstr(line, "LDX")){
            printf("\n%s\n", line);
    }
    /*else if (strstr(line, "STX")){
            printf("\n%s\n", line);
    }*/
  }
}
