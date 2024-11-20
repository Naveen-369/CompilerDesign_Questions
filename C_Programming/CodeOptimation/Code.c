/* Eliminating Common Sub Expression */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Declararion of the Global Variable 
#define BufferSize 50
int Count=0;

//Declaration of the Structure
struct Expressions{
    char variable[10];
    char Expression[50];
};

//Declaration o fthe function to chek if the given rhs is already in the Tables
bool checkOptimality(struct Expressions exp[],char *rhs){
    for(int i =0;i<Count;i++){
        if(strcmp(exp[i].Expression,rhs)==0)
            return true;
    }
    return false;
}

//Driver Code
int main(){
    int n;
    printf("Number of Expressions : ");
    scanf("%d",&n);
    //Creation of the Expressions array
    struct Expressions inputBuffer[n];
    char Buffer[n][BufferSize];
    printf("Enter Expressions : \n");
    for(int i=0;i<n;i++){
        scanf("%s",Buffer[i]);
    }

    //Logic
    for(int i =0 ;i<n;i++){
        char *lhs=strtok(Buffer[i],"=");
        char *rhs=strtok(NULL,"=");
        if(!checkOptimality(inputBuffer,rhs)){
            strcpy(inputBuffer[Count].variable,lhs);
            strcpy(inputBuffer[Count].Expression,rhs);
            Count++;
        }
    }

    printf("Optimal Code - Eliminating the Sub Expression . . . . .\n");
    for(int i=0;i<Count;i++){
        printf("%s\t%s\n",inputBuffer[i].variable,inputBuffer[i].Expression);
    }
    return 0;

}