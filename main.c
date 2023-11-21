#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

char* digit_to_letter(int digit) {
    char* table[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
    
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

    char line[100];
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


int number_to_one_word(char *word, int number, char *file) {
  char *letters[8];
  int index = 6;
  while (number > 0) {
    int digit = number % 10;
    letters[index] = digit_to_letter(digit);
    number = number / 10;
    index--;
  }
  int i1;
  for (i1 = 0; i1 < 3; i1++) {
    word[0] = letters[0][i1];
    int i2;
    for (i2 = 0; i2 < 3; i2++) {
      word[1] = letters[1][i2];
      int i3;
      for (i3 = 0; i3 < 3; i3++) {
        word[2] = letters[2][i3];
        int i4;
        for (i4 = 0; i4 < 3; i4++) {
          word[3] = letters[3][i4];
          int i5;
          for (i5 = 0; i5 < 3; i5++) {
            word[4] = letters[4][i5];
            int i6;
            for (i6 = 0; i6 < 3; i6++) {
              word[5] = letters[5][i6];
              int i7;
              for (i7 = 0; i7 < 3; i7++) {
                word[6] = letters[6][i7];
                word[7] = '\0';
                if (is_word_in_file(word,file)) 
                  return 1;
                
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


int number_to_two_words_3_4(char *word,int number,char *file){
  char *letters[8];
  int index = 6;
  while (number > 0) {
    int digit = number % 10;
    letters[index] = digit_to_letter(digit);
    number = number / 10;
    index--;
  }
  int j;
  for(j=0;j<8;j++)
  puts(letters[j]);
  
  int i1;
  for (i1 = 0; i1 < 3; i1++) {
    word[0] = letters[0][i1];
    int i2;
    for (i2 = 0; i2 < 3; i2++) {
      word[1] = letters[1][i2];
      int i3;
      for (i3 = 0; i3 < 3; i3++) {
        word[2] = letters[2][i3];
        word[3] = '\0';
        if (is_word_in_file(word,file)) 
          goto second_Word;
          }
        }
      }
   return 0;
                
   second_Word:
   char second_word[5];
   second_word[3] = '-';
    int i4;
    for (i4 = 0; i4 < 3; i4++) {
      second_word[0] = letters[3][i4];
      int i5;
      for (i5 = 0; i5 < 3; i5++) {
        second_word[1] = letters[4][i5];
        int i6;
        for (i6 = 0; i6 < 3; i6++) {
          second_word[2] = letters[5][i6];
          int i7;
          for (i7 = 0; i7 < 3; i7++) {
            second_word[3] = letters[6][i7];
            second_word[4] = '\0';
            if (is_word_in_file(second_word,file)){
              strcat(word,second_word);
              return 1;
             }
           }
         }
       }
     }
   
   
   return 0;
           

}


int main(){
    char word[9];
    char file[] = "words.txt";
    int number;
    printf("Enter a Seven-digit number: "); 
    scanf("%d", &number);
  int result = number_to_two_words_3_4(word,number, file);
    
    if (result) 
    printf("The word is: %s\n", word);
    else 
    printf("No word found for the number.\n");




    return 0;
}
