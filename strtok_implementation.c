#include <stdio.h>

int main(){
    // initialize array string
    char string[] = "This is a sentence with 7 tokens";
    char *tokenPtr;

    printf("%s\n%s\n\n%s\n",
    "The string to be tokenized is:", string,
    "The tokens are:"
    );

    tokenPtr = str_tok(string, " "); //begin tokenizing sentence

    // continue tokenizing sentence until tokenPtr becomes NULL
    while(tokenPtr != NULL){
        printf("%s\n", tokenPtr);
        tokenPtr = str_tok(NULL, " ");
    }//end while

    return 0;
}//end main

char* str_tok(char * inp, char * tok){

}