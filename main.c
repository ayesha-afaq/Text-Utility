#include <stdio.h>
#include <string.h>

void get_user_input(char*text, int size);

int main(){

    // max size of text
    const int MAX_LENGTH = 1000;
    // array for text
    char text[MAX_LENGTH];

    get_user_input(text, MAX_LENGTH);

    // printf("you wrote this: \n");
    // printf(text);
    
    return 0;
 
}

void get_user_input(char*text,int size){
    char line[512];
    // initialize to an empty string
    text[0]='\0';  

    printf("Enter Your Text (press Enter on an empty line to finish): ");

    while(1){
        if(fgets(line,sizeof(line),stdin)==NULL)
            break; //any input error

        if (strcmp(line,"\n")==0 || strcmp(line,"\r\n")==0)
            break; // empty line

        if (strlen(text)+ strlen(line) >= size-1){
            printf("Warning: Max Text limit reached ! \n");
            break;
        }
        //adds the line to text
        strcat(text,line);
        
    }


}