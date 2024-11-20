#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
    Question
    E -> TE' 
    E' -> +TE' | ε 
    T -> FT' 
    T' -> *FT' | ε 
    F -> (E) | id

*/

/* Global Variable Declaration */

int Position=0;
char inputString[100];
char LookAhead; //Denotes the character at that position in the input

/* Declaration of the necessary functions */

void Match(char c); // Increaments the Position 
//For every Non Terminal
void E(); //E
void T(); //T
void EPrime(); //E'
void TPrime(); //T'
void F(); //F

/* Declaration of the Drive Method  */

int main(){
    int i =0;
    //input
    while((inputString[i++]=getchar())!='$');
    printf("The String to be Parsed : %s\n",inputString);
    LookAhead=inputString[Position];
    E();//Starting node call
    if(LookAhead=='$')
        printf("The given String has parsed Successfully the defined grammer\n");
    else
        printf("The given String did not make up to the Defined Grammer ! ! ! !");
    return 0;
}



/* Definitions of the Grammer Methods */

void Match(char c){
    Position++;
    LookAhead=inputString[Position];
}
void E(){
    T();
    EPrime();
}
void T(){
    F();
    TPrime();
}
void EPrime(){
    if(LookAhead=='+'){
        Match('+');
        T();
        EPrime();
    }
}
void TPrime(){
    if(LookAhead=='*'){
        Match('*');
        F();
        TPrime();
    }
}
void F(){
    if(LookAhead=='('){
        Match('(');
        E();
        Match(')');
    }else if(isalpha(LookAhead)){
        Match(LookAhead);
    }
    else{
        printf("Invalid Input ! ! ! !");
        exit(-1);
    }
}