#include <stdio.h>
#include <string.h>

#define NAME 100  // file name buffer storage
#define size 32   // size of each string in the array
#define num_demon 62 // number of demons

// Function to remove the newline character from a string
void trim(char str[]){
    int length = strlen(str);
    str[length - 1] = 0; // replacing the last newline character with null terminator
}

// Declaration and definition of the write_demon function
int write_demon(
    char name[][size],   // array to store demon names
    char type[][size],   // array to store demon types
    int hp[],            // array to store demon HP values
    int AC[],            // array to store demon AC values
    int STR[],           // array to store demon Strength values
    int DEX[],           // array to store demon Dexterity values
    int CON[],           // array to store demon Constitution values
    int num_demons) {    // number of demons

    // Loop through each demon and print its information
    for (int i = 0; i < num_demons; i++) {
        printf("Demon %d:\n", i + 1);
        printf("Name: %s\n", name[i]);
        printf("Type: %s\n", type[i]);
        printf("HP: %d, AC: %d, STR: %d, DEX: %d, CON: %d\n", hp[i], AC[i], STR[i], DEX[i], CON[i]);
    }
    return 0;  // return 0 to indicate successful execution
}