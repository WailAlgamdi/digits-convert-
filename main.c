#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

char* digit_to_letter(int digit) {
    char* table[10] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
    
    if (digit >= 2) {
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

    char line[8];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strcasecmp(word, line) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}


int number_to_word(char *word, int number, char* file) {
  char *letters[7];
  int index = 6;
  while (number > 0) {
    int digit = number % 10;
    letters[index] = digit_to_letter(digit);
    number = number / 10;
    index--;
  }
  int result = 0;
  int i;
  for (i = 0; i < 3; i++) {
    word[0] = letters[0][i];
    int j;
    for (j = 0; j < 3; j++) {
      word[1] = letters[1][j];
      int k;
      for (k = 0; k < 3; k++) {
        word[2] = letters[2][k];
        int l;
        for (l = 0; l < 3; l++) {
          word[3] = letters[3][l];
          int m;
          for (m = 0; m < 3; m++) {
            word[4] = letters[4][m];
            int n;
            for (n = 0; n < 3; n++) {
              word[5] = letters[5][n];
              int o;
              for (o = 0; o < 3; o++) {
                word[6] = letters[6][o];
                word[7] = '\0';
                result = is_word_in_file(word,file);
                if (result == 1) {
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



int main() {
    char word[8];
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
