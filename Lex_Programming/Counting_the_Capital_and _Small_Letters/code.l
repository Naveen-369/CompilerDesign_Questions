%{
	#include <stdio.h>
	int smallCount=0;
	int bigCount=0;
%}

%%
[a-z] {smallCount++;}
[A-Z] {bigCount++;}
. ;
%%

int main(){
	printf("Enter the String : ");
	char inputBuffer[100];
	fgets(inputBuffer,sizeof(inputBuffer),stdin);
	yy_scan_string(inputBuffer);
	yylex();
	printf("Small Count : %d\n",smallCount);
	printf("Big Count : %d\n",bigCount);
	return 0;
}
int yywrap(){
    return 1;   
}