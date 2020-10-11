/**
 * Name: Róisín O'Farrell
 * Student Number: 18322044
 * Date: 06/10/2020
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief This function does reads through a file character by character
 *        and adds each charater to a buffer until it reaches a comma or a
 *        new line.
 * @param length maximum length of buffer.
 * @param fp file to be read.
 * @param buffer value of current field added character by charater.
 * @return 0 if reached comma.
 * @return 1 if reached end of line or end of file.
 */
int new_field(int length, FILE* fp, char* buffer){
    int i = 0;
    int c;

    //Until the end of the file
    while((c=fgetc(fp))!= EOF){
        if(c==','){
            // Add \0 to buffer to end string and return 0 if c is a comma
            buffer[i]= '\0';
            return 0;
        }
        else if(c=='\n'){
            // Add \0 to buffer to end string and return 1 if c is a \n
            buffer[i]= '\0';
            return 1;
        }
        else {
            // Add c to buffer and continue
            buffer[i] = c;
            i++;
        }
    }
    return -1;   
}

int main(int argc, char *argv[]){
    FILE *fp;
    int length = 600;
    char buffer [length];
    char c;

    // Open file
    fp = fopen("students.csv","r");
    // Read in first line
    while((c=fgetc(fp))!= '\n');
   
    //Call new_field for each new field until end of the file
    do{
        int field = new_field( length, fp,  buffer);
        if(field == 0){
            // Print field
            printf("%s\n", &buffer[0]);
        }else if(field == 1){
            // Print last field on a line
            printf("%s\n\n", &buffer[0]);
        }else{
            printf("End of data set");
        }
    } while(feof(fp)==0);
    
    // Close file
	fclose(fp);

    return 0;
}           