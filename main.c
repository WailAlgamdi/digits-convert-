#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "myFunction.h"

int main(){
char word1[8];
char word2[9];
char word3[0];
char file[] = "words.txt";
int number;

do{
printf("Enter a Seven-digit number(It should not include 0 or 1): \n"); 
printf("Enter the number(or 0 to end): "); 
scanf("%d", &number);
if(number == 0)
return 0;

if (number_to_one_word(word1,number,file)) 
printf("The word is: %s\n", word1);
else if(number_to_two_words_3Letters_4Letters(word2,number,file))
printf("The word is: %s\n", word2);
else if(number_to_two_words_4Letters_3Letters(word3,number,file))
printf("The word is: %s\n", word3);
else
printf("No word found for the number.\n");


}while(number != 0);
return 0;
}
