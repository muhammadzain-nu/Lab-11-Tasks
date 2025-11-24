#include <stdio.h>
#include <string.h>
void count(char string[], int n, int i){
	if(string[n]=='a'|| string[n]=='A' || string[n]=='e'|| string[n]=='E'|| string[n]=='i'
	|| string[n]=='I'|| string[n]=='o'|| string[n]=='O'|| string[n]=='u'|| string[n]=='U'){
		i++;
	}
	if(n==0){
		printf("There are %d vowels", i);
		return 0;
	}
	return count(string, n-1,i);
}
int main(){
	char string[50];
	printf("Enter your text");
	scanf("%[^\n]", string);
	count(string, strlen(string), 0);
	
}
