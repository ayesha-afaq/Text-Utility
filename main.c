#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

// Function declarations
void user_input(char*text, int size);
int get_option();
void remove_extra_spaces(char*text);
void convert_to_uppercase(char *text);
void analyze_text(const char *text);
void convert_to_lowercase(char*text);
void count_word_frequency(const char *text);
void appendString(char *text);
void findAndReplace(char *text, const char *oldWord, const char *newWord);

int main(){
    // max size of text
    const int MAX_LENGTH = 1000;
    // array for storing user text
    char text[MAX_LENGTH];

    // calling function to take multiline input
    user_input(text, MAX_LENGTH);

    // arrays for storing words to find and replace
    char find[200], replace[200];

    int run = 1; // loop controller
    while(run){
        // get user's menu option
        int option_num = get_option();

        // switch-case to handle menu operations
        switch (option_num)
        {
        case 1:
            // remove extra spaces in text
            remove_extra_spaces(text);
            break;
        case 2:
            // convert all characters to uppercase
            convert_to_uppercase(text);
            break;
        case 3:
            // analyze word, sentence, and character count
            analyze_text(text);
            break;
        case 4:
            // convert text to lowercase
            convert_to_lowercase(text);
            break;
        case 5:
            // count frequency of each word
            count_word_frequency(text);
            break;
        case 6:
            // append additional string to existing text
            appendString(text);
            break;
        case 7:
            // find a word and replace it with another
            findAndReplace(text, find, replace);
            break;
        case 8:
            // exit the program
            printf("Exititng Program");
            run = 0;
            break;
        default:
            // invalid option handling
            printf("Invalid Option");
        }
    }
    
    return 0;
}

int get_option(){
    int option_num;
    int result;

    // display menu options
    printf("\n1.Remove Extra Spaces\n2.Convert to Uppercase\n3.Analyze Text\n4.Convert to lower case\n5.Count word frequency\n6.Append string\n7.Find and Replace\n8.exit");

    while(1){
        printf("\nChoose Option: ");
        result = scanf("%d", &option_num);

        if (result != 1){
            // scanf failed (user didn't enter a number)
            printf("Invalid input! Please enter a number between 1 and 9.\n");

            // clear leftover characters from input buffer
            while (getchar() != '\n');
            continue; // ask again
        }

        // validate range
        if (option_num >= 1 && option_num <= 9)
            break;
        else{
            printf("Invalid! Please enter between 1 and 9");
        }
    }
    return option_num;
}

void user_input(char*text,int size){
    char line[512]; // buffer to store each input line

    // initialize string to empty
    text[0] = '\0';  

    printf("Enter Your Text (press Enter on an empty line to finish): ");

    while(1){
        // read a line of input
        if(fgets(line, sizeof(line), stdin) == NULL)
            break; // any input error

        // check for empty line (end signal)
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0)
            break;

        // prevent text overflow
        if (strlen(text) + strlen(line) >= size - 1){
            printf("Warning: Max Text limit reached ! \n");
            break;
        }

        // append line to main text
        strcat(text, line);
    }
}

void remove_extra_spaces(char *text){

    int i = 0, j = 0;
    int space_found = 0;

    // punctuation characters that must NOT have space before them
    char punct[] = ".,!?;:";

    // Skip leading spaces
    while (isspace((unsigned char)text[i]))
        i++;

    for (; text[i] != '\0'; i++)
    {
        // 1. Remove space BEFORE punctuation
        if (strchr(punct, text[i]) != NULL && j > 0 && text[j - 1] == ' ')
        {
            j--; // remove extra space
        }

        // 2. Remove space AFTER opening quotes
        if ((text[j - 1] == '"' || text[j - 1] == '\'') &&
            text[i] == ' ')
        {
            continue;
        }

        //3. Remove space BEFORE closing quotes
        if ((text[i] == '"' || text[i] == '\'') &&
            j > 0 && text[j - 1] == ' ')
        {
            j--;
        }
        // 5. Normal character handling
        if (!isspace((unsigned char)text[i]))
        {
            text[j++] = text[i];
            space_found = 0;
        }
        else if (!space_found)
        {
            text[j++] = ' ';
            space_found = 1;
        }
    }

    // Remove trailing space
    if (j > 0 && text[j - 1] == ' ')
        j--;

    text[j] = '\0';

    printf("\nText after cleanup:\n%s\n", text);
}

void convert_to_uppercase(char* text) {

    // loop through each character and convert to uppercase
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = toupper((unsigned char) text[i]);
    }

    printf("\nConverted Text in Capital Letters:\n");
    printf("%s\n", text);
}

void analyze_text(const char* text) {
    int word_count = 0;
    int sentence_count = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Count words
        if (isalnum((unsigned char)ch) || ch == '\'' || ch == '-') {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }

        // Count sentences
        if (ch == '.' || ch == '!' || ch == '?') {
            // Skip repeated punctuation like "..." or "!!!"
            int j = i + 1;
            while (text[j] == ch) j++;
            // Check if next character is space, newline, or end-of-string
            if (text[j] == '\0' || isspace((unsigned char)text[j])) {
                sentence_count++;
                i = j - 1;  // Skip repeated punctuation
            }
        }
    }

    printf("\n=== Text Analysis ===\n");
    printf("Word Count: %d\n", word_count);
    printf("Sentence Count: %d\n", sentence_count);
}

void convert_to_lowercase(char*text) {
    // convert characters to lowercase
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower((unsigned char) text[i]);
    }

    printf("\nConverted Text in Lowercase Letters:\n");
    printf("%s\n", text);
}

void count_word_frequency(const char *text) {
    char temp[1000];

    // copy text so original is not modified
    strcpy(temp, text);

    // convert whole text to lowercase
    for (int i = 0; temp[i]; i++)
        temp[i] = tolower((unsigned char)temp[i]);

    // arrays for words and counts
    char words[200][50];
    int freq[200] = {0};
    int wc = 0; // word counter

    // tokenize words using delimiters
    char *token = strtok(temp, " .,!?;:\n\t");

    while (token) {
        int found = 0;

        // check if word already exists
        for (int i = 0; i < wc; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // new word found
        if (!found) {
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
    // prompt user to enter word to find
    printf("Enter the word to find: ");
    scanf("%s", oldWord);

    // prompt user for replacement word
    printf("Enter the word to replace with: ");
    scanf("%s", newWord);

    char result[MAX]; // buffer for updated string
    int i = 0, j = 0;
    int oldLen = strlen(oldWord); // length of word to find
    int newLen = strlen(newWord); // length of replacement word

    // loop through original string
    while (str[i] != '\0') 
    {
        // check if oldWord occurs at current position
        if (strstr(&str[i], oldWord) == &str[i]) 
        {
            // copy newWord into result
            strcpy(&result[j], newWord);
            j += newLen;   // move index by length of newWord
            i += oldLen;   // skip oldWord in original
        } 
        else 
        {
            // copy regular characters
            result[j++] = str[i++];
        }
    }

    result[j] = '\0'; // terminate string

    // update original text
    strcpy(str, result); 
    printf("Updated text: %s\n", str);
}

void appendString(char *original)
{
    char toAppend[200]; // buffer for additional text

    // clear leftover newline from previous scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // prompt user for string to append
    printf("Enter text to append: ");
    fgets(toAppend, sizeof(toAppend), stdin);

    // remove newline characters from both strings
    original[strcspn(original, "\n")] = '\0';
    toAppend[strcspn(toAppend, "\n")] = '\0';

    int len = strlen(original);

    // add space between original and new text if needed
    if (len > 0 && original[len - 1] != ' ')
        strcat(original, " ");

    // append new text
    strcat(original, toAppend);

    printf("Updated text: %s\n", original);
}
