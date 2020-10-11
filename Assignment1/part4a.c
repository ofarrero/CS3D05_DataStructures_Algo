/**
 * Name: Róisín O'Farrell
 * Student Number: 18322044
 * Date: 06/10/2020
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Create struct with pokemon info
struct pokemon{
	char* num;
	char* Name;
	char* Type1;
	char* Type2;
	char* Total;
	char* HP;
	char* Attack;
	char* Defense;
	char* SpAtk;
	char* SpDef;
	char* Speed;
	char* Generation;
	char* Legendary;
	char* PokedexEntry;
};

/**
 * @brief This function does reads through a file character by character
 *        and adds each charater to a buffer until it reaches a comma, 
 *        quotation mark or a new line.
 * @param fp file to be read.
 * @param buffer value of current field added character by charater.
 * @return 0 if reached comma.
 * @return 1 if reached end of line or end of file.
 */

int new_field(FILE* fp, char* buffer){
    int i = 0;
    static int quote=0;
    int c;
    
    //Until the end of the file
    while((c=fgetc(fp))!= EOF){
        if(c==',' && quote%2==0){
            /**
             * Add \0 to buffer to end string and return 0 if c is a comma
             * and if its not in the middle of a quote
             */
            buffer[i]= '\0';
            return 0;
        }
        else if(c=='\n'){
            // Add \0 to buffer to end string and return 1 if c is a \n
            buffer[i]= '\0';
            return 1;
        }
        // Count quotation mark
        else if(c=='"')quote++;
        else {
            // Add c to buffer and continue
            buffer[i] = c;
            i++;
        }
    }   
   return 1;
}

/**
 * @brief This function calculates average attack strength
 * @param charater structure of pokemon
 * @return avg average attack strength
 */
float avg_attack(struct pokemon *character){
    float sum, avg = 0;

    // Add each pokemons attack strength
    for(int j = 0; j<649; j++){ 
		sum+=atol(character[j].Attack);
	}

    // Average the sum of the attack strengths
	avg = (float)(sum/649); 

    return avg;
}
int main(int argc, char *argv[]){
    FILE *fp;
    int length = 600;
    char buffer [length];
    int fieldMarker = 0;
    float avg = 0;
    int index = 0;
    char c;
    struct pokemon character[649];
   
    // Open file
    fp = fopen("pokemon.csv","r");
    // Read in first line
    while((c=fgetc(fp))!= '\n');
   
    //Call new_field for each new field until end of the file
    do{
        int field = new_field(fp,  buffer);
        if(field == 0){
            // Print field
            printf("%s\n", &buffer[0]);
            switch (fieldMarker)
            {
            case 0:
                // Copy buffer str to charater num
                character[index].num = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].num, &buffer[0]);
                fieldMarker++;
                break;
            case 1:
                // Copy buffer str to charater Name
                character[index].Name = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Name, &buffer[0]);
                fieldMarker++;
                break;
            case 2:
                // Copy buffer str to charater Type 1
                character[index].Type1 = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Type1, &buffer[0]);
                fieldMarker++;
                break;
            case 3:
                // Copy buffer str to charater Type2
                character[index].Type2 = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Type2, &buffer[0]);
                fieldMarker++;
                break;
            case 4:
                // Copy buffer str to charater Total
                character[index].Total = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Total, &buffer[0]);
                fieldMarker++;
                break;
            case 5:
                // Copy buffer str to charater HP
                character[index].HP = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].HP, &buffer[0]);
                fieldMarker++;
                break;
            case 6:
                // Copy buffer str to charater Attack
                character[index].Attack = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Attack, &buffer[0]);
                 fieldMarker++;
                break;
             case 7:
                // Copy buffer str to charater Defense
                character[index].Defense = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Defense, &buffer[0]);
                fieldMarker++;
                break;
            case 8:
                // Copy buffer str to charater num SpAtk
                character[index].SpAtk = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].SpAtk, &buffer[0]);
                fieldMarker++;
                break;
            case 9:
                // Copy buffer str to charater SpDef
                character[index].SpDef = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].SpDef, &buffer[0]);
                fieldMarker++;
                break;
            case 10:
                // Copy buffer str to charater Speed
                character[index].Speed = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Speed, &buffer[0]);
                fieldMarker++;
                break;
            case 11:
                // Copy buffer str to charater Generation
                character[index].Generation = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Generation, &buffer[0]);
                fieldMarker++;
                break;
            case 12:
                // Copy buffer str to charater Legendary
                character[index].Legendary = (char*)malloc(sizeof(char)*length);
                strcpy(character[index].Legendary, &buffer[0]);
                fieldMarker++;
                break;
            default:
                break;
            }
        }else if(field == 1){
            // Print last field on a line
            printf("%s\n\n", &buffer[0]);
            // Copy buffer str to charater PokedexEntry
            character[index].PokedexEntry = (char*)malloc(sizeof(char)*length);
            strcpy(character[index].PokedexEntry, &buffer[0]);
            // Reset marker
            fieldMarker=0;
            // Move index forward
            index++;
        }
    } while(feof(fp)==0);

    // Print pokemon info
    printf("%s\n", character[67].Name);
    printf("%s\n", character[2].PokedexEntry);
    printf("%s\n", character[499].Speed);

    //Calculate Avg Attack
    avg=avg_attack(character);
    // Print avg attack strength 
	printf("Avg Attack Strength: %f\n", avg); 

    // Close file
	fclose(fp);
    return 0;
}   