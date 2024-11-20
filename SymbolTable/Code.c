#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

struct Symbol{
    char symbol;
    char Type[20];
};
int main(){
    //Declaration of the necessary variables
    struct Symbol SymbolTable[MAX/2];
    char Buffer[MAX];
    int i =0,n=0,index=0;


    //Input 
    printf("Enter the Expressions : ");
    while((Buffer[i++]=getchar())!='\n');
    Buffer[i]='\0';
    n=i;

    //Display the Expression to the User
    printf("THe given expression is found to be : %s\n",Buffer);

    //Symbol Table Creation
    for(i =0;i<n;i++){
        char c = Buffer[i];
        bool Flag=false;
        // Check if it is already Present
        for(int j=0;j<index;j++){
            if(c==SymbolTable[j].symbol){
                Flag=true;
            }
        }
        if(Flag) continue;

        //If not Create a new One
        SymbolTable[index].symbol=c;
        if(isalpha(c)){
            strcpy(SymbolTable[index].Type,"Identifiers");
        }
        else{
            strcpy(SymbolTable[index].Type,"Operators");
        }
        index++;
    } 

    for(i =0;i<index-1;i++){
        printf("%c\t%s\n",SymbolTable[i].symbol,SymbolTable[i].Type);
    }

    return 0;
}