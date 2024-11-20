%{
	#include <stdio.h>
	int vowelCount=0;
	int consonantsCount=0;
%}

%%
[aeiouAEIOU] {vowelCount++;}
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {consonantsCount++;}
. ;
%%

int main(){
	printf("Enter the String : ");
	char inputBuffer[100];
	fgets(inputBuffer,sizeof(inputBuffer),stdin);
	yy_scan_string(inputBuffer);
	yylex();
	printf("Vowels Count : %d\n",vowelsCount);
	printf("Consonants Count : %d\n",consonantsCount);
	return 0;
}
int yywrap(){
	return 1;
}