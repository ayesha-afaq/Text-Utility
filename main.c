#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

void user_input(char*text, int size);
int get_option();
void remove_extra_spaces(char*text);
void convert_to_uppercase(char *text);
void analyze_text(const char *text);
void convert_to_lowercase(char*text);
void count_word_frequency(const char *text);
void appendString(char *original, const char *toAppend) ;
void findAndReplace(char *str, const char *oldWord, const char *newWord) ;

int main(){
    // max size of text
    const int MAX_LENGTH = 1000;
    // array for text
    char text[MAX_LENGTH];

    user_input(text, MAX_LENGTH);

    int run=1;
    while(run){
        int option_num= get_option();

        switch (option_num)
        {
        case 1:
            remove_extra_spaces(text);
            break;
        case 2:
            convert_to_uppercase(text);
            break;
        case 3:
            analyze_text(text);
            break;
            // func call
        case 4:
            convert_to_lowercase(text);
            break;
            // func call
        case 5:
            count_word_frequency(text);
            break;
            // func call
        case 6:
            printf("Enter text to append: ");
            fgets(add, sizeof(add), stdin);
            add[strcspn(add, "\n")] = '\0';  
            appendString(text,add) 
            break;
            // func call
        case 7:
            printf("Enter the word to find: ");
            scanf("%s", find);

            printf("Enter the word to replace with: ");
            scanf("%s", replace);

            findAndReplace(text, find, replace) ;
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

    printf("\n1.Remove Extra Spaces\n2.Convert to Uppercase\n3.Analyze Text\n4.fourth\n5.fifth\n6.sixth\n7.seven\n8.eigth\n9.exit");

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

void remove_extra_spaces(char *text){

    int i = 0, j = 0;
    int space_found = 0;

    // Skip leading spaces
    while (isspace((unsigned char)text[i]))
        i++;

    // Process each character
    for (; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            text[j++] = text[i];
            space_found = 0;
        }
        else if (!space_found)
        {
            // copy one space between words
            text[j++] = ' ';
            space_found = 1;
        }
    }

    // remove trailing space
    if (j > 0 && text[j - 1] == ' ')
        j--;

    text[j] = '\0'; // terminate string

    printf("\nText after removing extra spaces:\n%s\n", text);
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


void convert_to_lowercase(char*text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower((unsigned char) text[i]);
    }
    printf("\nConverted Text in Lowercase Letters:\n");
    printf("%s\n", text);
}

void count_word_frequency(const char *text) {
    char temp[1000];
    strcpy(temp, text);

    // convert whole text to lowercase
    for (int i = 0; temp[i]; i++)
        temp[i] = tolower((unsigned char)temp[i]);

    // arrays for words and counts
    char words[200][50];
    int freq[200] = {0};
    int wc = 0;

    // split into words
    char *token = strtok(temp, " .,!?;:\n\t");

    while (token) {
        int found = 0;

        // check if already counted
        for (int i = 0; i < wc; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {  // new word
            strcpy(words[wc], token);
            freq[wc] = 1;
            wc++;
        }

        token = strtok(NULL, " .,!?;:\n\t");
    }

    // print result
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wc; i++)
        printf("%s : %d\n", words[i], freq[i]);
}
void findAndReplace(char *str, const char *oldWord, const char *newWord) 
{
    char result[MAX];
    int i = 0, j = 0;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);

    while (str[i] != '\0') 
    {
        if (strstr(&str[i], oldWord) == &str[i]) 
        {
            strcpy(&result[j], newWord);
            j += newLen;
            i += oldLen;
        } 
        else 
        {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';
    strcpy(str, result); 
}
void appendString(char *original, const char *toAppend) 
{
    int len = strlen(original);

    if (len > 0 && original[len - 1] != ' ') 
    {
        strcat(original, " ");
    }

    strcat(original, toAppend);
}


