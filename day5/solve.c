#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check(char a, char A) {

    if ((A+32 == a) || (a+32==A)) {
        //printf("%c, %c\n", a, A);
        return 1;   
    }
    else {
        return 0;
    }
    return 0;
}



char* react(char* string) {

    char* old = malloc(sizeof(char)*strlen(string)+1);
    strcpy(old, string);
    char* new = malloc(sizeof(char)*strlen(string)+1);
    strcpy(new, string);

    
    int idx = 0;
    
    while(string[idx] != '\0') {
        new[idx] = *(string+idx);
        idx++;
    }

    idx = 0;

    while(new[idx] != '\0') {
        if(check(new[idx], new[idx+1])) {
            new[idx] = '_';
            new[idx+1] = '_';
            idx+=2;
        }
        idx++;
    }


    while(strcmp(new, old) != 0) {

        strcpy(old, new);
        idx = 0;
        while(new[idx] != '\0') {
            if(check(new[idx], new[idx+1])) {
                new[idx] = '_';
                new[idx+1] = '_';
                idx+=2;
            }
        idx++;
        }

        idx = 0;
        int i = 0;

        char* temp = malloc(sizeof(char)*strlen(new)+1);

        while(new[idx] != '\0') {
            if(new[idx] != '_') {
                temp[i] = *(new+idx);
                i++;
            }
            idx++;
        }

        strcpy(new, temp);
        new[idx] = '\0';
        free(temp);
    }
    
    return new;
}




int main() {

    FILE *input;
    input = fopen("input.txt", "r");

    char* string = (char*)malloc(sizeof(char)*100000);
    int i=0;
    int c;

    while((c = getc(input)) != EOF) {
        //putchar(c);
        string[i] = (char)c;
        i++;
    }
    string[i] = '\0';

    string = (char*)realloc(string, sizeof(char)*i);


    printf("---------------\n");
    printf(react(string));
    printf("\n---------------\n");
    //printf(string);


}