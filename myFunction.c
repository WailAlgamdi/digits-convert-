#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* This function take a one digit and convert it to array of three chars and return it.  */
char* digit_to_letter(int digit) {
char* table[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"}; 
    
if (digit >= 2) 
return table[digit - 2]; 
 else 
return ""; 

}

/* This will check if the word exist on the file (wrods.txt) or not. */
int is_word_in_file(char* word, char* file) {
/* Read the file */
FILE* fp = fopen(file, "r");
if (fp == NULL) {
printf("Error: Cannot open file %s\n", file);
return 0;
}
/* This loop will compare each line It will stop when find the word or when read all the wrod in the file */
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

/* This function will convert the number to one word by using previous functions the */
int number_to_one_word(char *word, int number, char *file) {
char *letters[8];
int index = 6;
/* This loop will store all numbers as array of char in two dimensional array */
while (number > 0) {
int digit = number % 10;
letters[index] = digit_to_letter(digit);
number = number / 10;
index--;
}
/* Loops to try all chances to find meaningfull word has seven letters */
int i1,i2,i3,i4,i5,i6,i7;
for (i1 = 0; i1 < 3; i1++) {
word[0] = letters[0][i1];
for (i2 = 0; i2 < 3; i2++) {
word[1] = letters[1][i2];
for (i3 = 0; i3 < 3; i3++) {
word[2] = letters[2][i3];
for (i4 = 0; i4 < 3; i4++) {
word[3] = letters[3][i4];
for (i5 = 0; i5 < 3; i5++) {
word[4] = letters[4][i5];
for (i6 = 0; i6 < 3; i6++) {
word[5] = letters[5][i6];
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

/* This function will convert the number to two words 3 letters to 4 letters */
int number_to_two_words_3Letters_4Letters(char *word,int number,char *file){
char *letters[8];
int index = 6;
/* This loop will store all numbers as array of char in two dimensional array */
while (number > 0) {
int digit = number % 10;
letters[index] = digit_to_letter(digit);
number = number / 10;
index--;
}
/* Loops to try all chances to find meaningfull word  has three letters */
int i1,i2,i3;
for (i1 = 0; i1 < 3; i1++) {
word[0] = letters[0][i1];
for (i2 = 0; i2 < 3; i2++) {
word[1] = letters[1][i2];
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
word[3] = '-';
char second_word[5];
word[3] = '-';
/* Loops to try all chances to find meaningfull word  has four letters */
int i4,i5,i6,i7;
for (i4 = 0; i4 < 3; i4++) {
second_word[0] = letters[3][i4];
for (i5 = 0; i5 < 3; i5++) {
second_word[1] = letters[4][i5];
for (i6 = 0; i6 < 3; i6++) {
second_word[2] = letters[5][i6];
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


/* This function will convert the number to two words 4 letters to 3 letters */
int number_to_two_words_4Letters_3Letters(char *word,int number,char *file){
char *letters[8];
int index = 6;
/* This loop will store all numbers as array of char in two dimensional array */
while (number > 0) {
int digit = number % 10;
letters[index] = digit_to_letter(digit);
number = number / 10;
index--;
}
/* Loops to try all chances to find meaningfull word  has four letters */
int i1,i2,i3,i4;
for (i1 = 0; i1 < 3; i1++) {
word[0] = letters[0][i1];
for (i2 = 0; i2 < 3; i2++) {
word[1] = letters[1][i2];
for (i3 = 0; i3 < 3; i3++) {
word[2] = letters[2][i3];
for (i4 = 0; i4 < 3; i4++) {
word[3] = letters[3][i4];
word[4] = '\0';
if (is_word_in_file(word,file)) 
goto second_Word;
}
}
}
}
return 0;
                
second_Word:
word[4] = '-';
char second_word[6];
/* Loops to try all chances to find meaningfull word  has three letters */
int i5,i6,i7;
for (i5 = 0; i5 < 3; i5++) {
second_word[0] = letters[4][i5];
for (i6 = 0; i6 < 3; i6++) {
second_word[1] = letters[5][i6];
for (i7 = 0; i7 < 3; i7++) {
second_word[2] = letters[6][i7];
second_word[3] = '\0';

if (is_word_in_file(second_word,file)){
strcat(word,second_word);
return 1;
}
}
}
}

   
   
return 0;
}

