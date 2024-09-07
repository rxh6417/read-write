#include <stdio.h>
#include <string.h>

#define NAME 100  // file name buffer storage
#define size 32   // size of each string in the array
#define num_demon 62 // number of demons

// Function to remove the newline character from a string
void trim(char str[]){
    int length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = 0; // replacing the last newline character with null terminator
    }
}

// Function to write demon details to the console and a CSV file
int write_demon_to_csv(
    char name[][size],   // array to store demon names
    char type[][size],   // array to store demon types
    int hp[],            // array to store demon HP values
    int AC[],            // array to store demon AC values
    int STR[],           // array to store demon Strength values
    int DEX[],           // array to store demon Dexterity values
    int CON[],           // array to store demon Constitution values
    int num_demons) {    // number of demons

    // Open the file for writing
    FILE *file = fopen("write.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the header to the CSV file
    fprintf(file, "Name,Type,HP,AC,STR,DEX,CON\n");

    // Loop through each demon and write its information to the CSV file and the console
    for (int i = 0; i < num_demons; i++) {
        // Write to console
        printf("\nDemon %d:\n", i + 1);
        printf("Name: %s\n", name[i]);
        printf("Type: %s\n", type[i]);
        printf("HP: %d, AC: %d, STR: %d, DEX: %d, CON: %d\n", hp[i], AC[i], STR[i], DEX[i], CON[i]);

        // Write to CSV file
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d\n", name[i], type[i], hp[i], AC[i], STR[i], DEX[i], CON[i]);
    }

    // Close the file
    fclose(file);
    printf("\nDemon details written to write.csv successfully!\n");

    return 0;  // return 0 to indicate successful execution
}

int main() {
    // Arrays to hold demon data
    char name[num_demon][size];
    char type[num_demon][size];
    int hp[num_demon];
    int AC[num_demon];
    int STR[num_demon];
    int DEX[num_demon];
    int CON[num_demon];

    int num_demons;

    // Prompt the user for the number of demons
    printf("Enter the number of demons (max %d): ", num_demon);
    scanf("%d", &num_demons);
    getchar();  // clear the newline character left by scanf

    // Make sure the number of demons is within bounds
    if (num_demons > num_demon || num_demons <= 0) {
        printf("Invalid number of demons.\n");
        return 1;
    }

    // Loop to get details for each demon
    for (int i = 0; i < num_demons; i++) {
        printf("\nEnter details for Demon %d:\n", i + 1);

        // Get demon name
        printf("Enter name: ");
        fgets(name[i], size, stdin);
        trim(name[i]);  // remove newline character

        // Get demon type
        printf("Enter type: ");
        fgets(type[i], size, stdin);
        trim(type[i]);  // remove newline character

        // Get demon stats
        printf("Enter HP: ");
        scanf("%d", &hp[i]);

        printf("Enter AC: ");
        scanf("%d", &AC[i]);

        printf("Enter STR: ");
        scanf("%d", &STR[i]);

        printf("Enter DEX: ");
        scanf("%d", &DEX[i]);

        printf("Enter CON: ");
        scanf("%d", &CON[i]);

        getchar();  // clear the newline character left by scanf
    }

    // Call the write_demon_to_csv function to print the details and write to CSV
    write_demon_to_csv(name, type, hp, AC, STR, DEX, CON, num_demons);

    return 0;
}
