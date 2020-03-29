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

char * last = NULL;

char* str_tok(char * inp, const char * delim){
    if(inp == NULL){
        //try to continue from last.
        inp = last;
    }
    int len;
    for(len = 0; inp[len] != '\0' && inp[len] != *delim; len++); //search until we reach end of array or the delim character
    last = inp + len;
    //construct new pointer/array
    char * returned = calloc(sizeof(char), len + 1); //+1 as we need the \0 operator
    for(int i = 0; i < len; i++){
        returned[i] = inp[i]; 
    }
    returned[len] = '\0';
    return returned;
}