#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
void convert_to_uppercase(char* text) {


    //to use the func call convert_to_uppercase(text); for ayesha 
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = toupper((unsigned char) text[i]);
    }
    printf("\nConverted Text in Capital Letters:\n");
    printf("%s\n", text);
}

void analyze_text(const char* text) {
    // to use the func call analyze_text(text); for ayesha
    int word_count = 0;
    int sentence_count = 0;
    int char_count = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (!isspace((unsigned char)ch)) {
            char_count++;
        }

        if (ch == '.' || ch == '?' || ch == '!') {
            sentence_count++;
        }

        if (!isspace((unsigned char)ch)) {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    printf("\nWord Count: %d", word_count);
    printf("\nSentence Count: %d", sentence_count);
    printf("\nCharacter Count (non-space): %d\n", char_count);
}
