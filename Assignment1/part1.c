/**
 * Name: Róisín O'Farrell
 * Student Number: 18322044
 * Date: 06/10/2020
 */
# include <stdio.h>

int main(int argc, char *argv[]){
    char name[20];
    int age;

    printf("Name:");
    scanf("%s", name);
    printf("Age:");
    scanf("%d", &age);

    printf("Hello %s (%d)\n", name, age);
    return 0;
}