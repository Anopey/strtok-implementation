#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char * last = NULL;

char* str_tok(const char * inp, const char * delim){
    if(inp == NULL){
        //try to continue from last.
        inp = last;
    }
    if(inp == NULL){
        //last was null too ;_;
        return NULL;
    }
    int len = 0;
    last = inp;
    while(inp != NULL){
        last++;
        if(inp[len] == *delim){
            bool y = true;
            int j = 0;
            for(int i = len; delim[i - len] != '\0'; i++)//check if this really is delim.
            {
                if(inp[i] != delim[i - len] || inp[i] == '\0'){
                    y = false;
                    len += i - len;
                    last += i - len - 1;
                    break;
                }
                j++;
            }
            if(y)
            {
                //we really have reached the delim!
                len+= j;
                last += j - 1;
                break;
            }
        }
        if(inp[len] == '\0'){
            //reached end of char array. 
            last = NULL;
            break;
        }
        len++;
    }
    //construct new pointer/array
    char * returned = calloc(sizeof(char), len + 1); //+1 as we need the \0 operator
    for(int i = 0; i < len; i++){
        returned[i] = inp[i]; 
    }
    returned[len] = '\0';
    return returned;
}

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

