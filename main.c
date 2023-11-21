#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digit_to_word(int digit) {
    char* table[10] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY", "Z", " "};
    
    if (digit >= 2 && digit <= 9) {
        return table[digit - 2]; 
    } else {
        return ""; 
    }
}


int is_word_in_file(char* word, char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", file);
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(word, line) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

char* number_to_word(char *word, int number, char* file) {
    int i;
    for(i = 5; i >= 0; i--) {
        int digit = number % 10;
        char* letter = digit_to_word(digit);
        strncpy(word + i, letter, 1);
        number = number / 10;
    }

    word[6] = '\0';
    
    return word;
}



int main() {
    char word[7];
    int number;
    printf("Enter a six-digit number: "); 
    scanf("%d", &number);
    number_to_word(word,number, "words.txt");
    
    if (word != NULL) {
    printf("The word is: %s\n", word);
} else if (strlen(word) > 0) {
    printf("The word is: %s\n", word);
} else {
    printf("No word found for the number.\n");
}



    if (strlen(word) > 0) {
        printf("The word is: %s\n", word);
    } else {
        printf("No word found for the number.\n");
    }

    return 0;
}
