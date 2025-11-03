#include <stdio.h>
#include <string.h>
#include <ctype.h>

void user_input(char*text, int size);
int get_option();


int main(){

    // max size of text
    const int MAX_LENGTH = 1000;
    // array for text
    char text[MAX_LENGTH];

    // user_input(text, MAX_LENGTH);

    int run=1;
    while(run){
        int option_num= get_option();

        switch (option_num)
        {
        case 1:
            // func call
            break;
        case 3:
            break;
            // func call
        case 4:
            break;
            // func call
        case 5:
            break;
            // func call
        case 6:
            break;
            // func call
        case 7:
            break;
            // func call
        case 8:
            break;
            // func call
        case 9:
            printf("Exititng Program");
            run=0;
            break;

        default:
            printf("Invalid Option");
        }

    }
    
    return 0;
 
}

int get_option(){
    int option_num;
    int result;

    printf("\n1.first\n2.second\n3.third\n4.fourth\n5.fifth\n6.sixth\n7.seven\n8.eigth\n9.exit");

    while(1){
        printf("\nChoose Option: ");
        result= scanf("%d",&option_num);

        if (result != 1){
            // scanf failed (user didn't enter a number)
            printf("Invalid input! Please enter a number between 1 and 9.\n");

            // clear leftover characters from input buffer
            while (getchar() != '\n');
                continue; // ask again
        }

        if (option_num>=1 && option_num<=9)
            break;
        else{printf("Invalid! Please enter between 1 and 9");}

    }
    return option_num;

}

void user_input(char*text,int size){
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
