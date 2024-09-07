#include <stdio.h>

#include "functions.h"


int main(){
char file_name[NAME] = {0};
FILE *poi;
poi = NULL;  // setting it to null, means it does not points anything yet.

printf("Give me a file name: "); //promt the user to get file name

fgets(file_name,NAME,stdin);  // storage vairalbe "name", "buffer" size, "stdin" to get input from keyboard

trim(file_name); // eliminates the newline when the user taps enter key. I made it from functions.h

//Now we need to open the file then edit csv.h file in order to do that we need a file pointer  =  fopen.

poi = fopen(file_name,"w");
if(poi == NULL){
    printf("couldn't open the file please try again\n");
    return 1; // return 1 usually used when a unsuccessfull or false things happens .

    // print the contents. anything that csv file has.

    while(fgets(file_name,NAME,poi)){ // loop while to read info line by line from "opend csv" file using that pointer "poi"
        trim(file_name); // to get rid of newlines from csv file while printing
        printf("%s",file_name);

    }

}
    fclose(poi); // lastly closing the file


    return 0;
}


