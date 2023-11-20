#include <stdio.h>
 #include <stdlib.h> 
 #include <string.h>

 char* digit_to_word(int digit) {
     char* table[10] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY", "Z", " "}; // Return the word corresponding to the digit 
     return table[digit];
      }

int is_word_in_file(char* word, char* file) { 
     FILE* fp = fopen(file, "r"); 
     if (fp == NULL) { printf("Error: Cannot open file %s\n", file);
      return 0; 
      } 
       char line[100];
        while (fgets(line, 100, fp) != NULL) { 
         line[strcspn(line, "\n")] = 0; 
         if (strcmp(word, line) == 0) {
             fclose(fp); return 1; } } 
             fclose(fp); return 0; 
             }


 char* number_to_word(int number, char* file) { 
    char* word = (char*)malloc(8 * sizeof(char)); 
    int i;
    for ( i = 6; i >= 0; i--) { 
     int digit = number % 10; 
     char* letter = digit_to_word(digit); 
     strncpy(word + i, letter, 1); 
      number = number / 10; } 
       if (is_word_in_file(word, file)) {
          return word; 
          } else {
             return ""; 
             } 
             }

int main() {
      int number; 
      printf("Enter a seven-digit number: "); 
      scanf("%d", &number); 
      char* word = number_to_word(number, "words.txt"); 
   
       if (strlen(word) > 0) { 
       printf("The word is: %s\n", word);
        } 
        else {
             printf("No word found for the number.\n");
              } 
              free(word); 
              return 0;
               }
