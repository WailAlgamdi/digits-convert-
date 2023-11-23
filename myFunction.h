#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


char* digit_to_letter(int digit);
int is_word_in_file(char* word, char* file);
int number_to_one_word(char *word, int number, char *file);
int number_to_two_words_3Letters_4Letters(char *word,int number,char *file);
int number_to_two_words_4Letters_3Letters(char *word,int number,char *file);
