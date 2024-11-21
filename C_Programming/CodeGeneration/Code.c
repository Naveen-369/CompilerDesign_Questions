#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Quadraple Creation */
struct Quadraple{
    int Id;
    char Operator;
    char Arg1[10];
    char Arg2[10];
    char Res[10];
};

/* Global Variable Declaration */
struct Quadraple Table[20];
int TableCount=0;
int RegisterValue=0;

/* Precedence Declaration */
int Precedence(char c){
    return (c=='^') ? 3 : (c=='*'||c=='/') ? 2 : (c=='+'||c=='-') ? 1 : -1;
}

/*Function to add the Quadraple to the Table*/
void addQuads(int *ref,char OperatorStack[],char OperandsStack[][3],int *OperatorTop,int *OperandTop){
    //Create a Struct Instance
    struct Quadraple Q;
    Q.Id=(*ref)++;
    Q.Operator=OperatorStack[(*OperatorTop)--];
    strcpy(Q.Arg1,OperandsStack[(*OperandTop)--]);
    strcpy(Q.Arg2,OperandsStack[(*OperandTop)--]);
    sprintf(Q.Res,"t%d",RegisterValue++);
    //Modify Global Vartiables
    Table[TableCount++]=Q;
    //Add the Result to the Operands Stack
    strcpy(OperandsStack[++(*OperandTop)],Q.Res);
}

/* Function to Generate the Table */
void GenerateQuadrapleTable(char Input[]){
    // Declaration of Stacks
    char OperatorStack[30];
    char OperandStack[60][3];
    int OperatorTop=-1;
    int OperandTop=-1;
    int Ref=0;
    
    for(int i =0;Input[i]!='\0';i++){
        //Variable
        if(isalnum(Input[i])){
            //Add to the Operand Stack
            OperandStack[++OperandTop][0]=Input[i];
            OperandStack[OperandTop][1]='\0';
        }
        
        //Parenthesis
        else if(Input[i]=='('){
            //Add to Operator Stack
            OperatorStack[++OperatorTop]=Input[i];
            
        }else if(Input[i]==')'){
            //While not )
            while(OperatorTop!=-1 && OperatorStack[OperatorTop]!='('){
                addQuads(&Ref,OperatorStack,OperandStack,&OperatorTop,&OperandTop);
            }
        OperatorTop--;
        }
        
        //Opertors
        else{
            //While Precedence of the ToS >= input[i]
            while(OperatorTop!=-1 && Precedence(OperatorStack[OperatorTop])>=Precedence(Input[i])){
                addQuads(&Ref,OperatorStack,OperandStack,&OperatorTop,&OperandTop);
            }
            OperatorStack[++OperatorTop]=Input[i];
        }
        
    }
    
    while(OperatorTop!=-1){
        addQuads(&Ref,OperatorStack,OperandStack,&OperatorTop,&OperandTop);
    }
    
}


/* Function to Generate the Code from the Table */
void GenerateMachineCode(){
    for(int i=0;i<TableCount;i++){
        if(Table[i].Operator=='='){
            printf("MOV %s %s\n",Table[i].Arg2,Table[i].Arg1);
        }else{
            printf("MOV R%d %s\n",i*2,Table[i].Arg1);
            printf("MOV R%d %s\n",(i*2)+1,Table[i].Arg2);
            printf("%s R%d R%d\n",Table[i].Operator=='+' ? "ADD" : 
            Table[i].Operator=='-' ? "SUB" : Table[i].Operator=='*' ? "MUL" :
            Table[i].Operator=='/'?"DIV":"INVALID",i*2,(i*2)+1);
            //Result
            printf("MOV %s R%d\n",Table[i].Res,i*2);
        }
    }
}


/* Main Function*/
int main(){
    
    //Input the Data
    char input[100];
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    printf("Input is found to be : %s\n",input);
    //Fucntion Call
    GenerateQuadrapleTable(input);
    GenerateMachineCode();
    return 0;
}