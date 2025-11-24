#include <stdio.h>
int sum(int number);
int main(){
	int number;
printf("Enter an integer: ");
    scanf("%d", &number);

 
    printf("The sum of digits of %d is: %d\n", number, sum(number));

    return 0;
	}
	int sum(int number){
		
		if(number==0){
			return 0;
		}
       
       return number%10+sum(number/10);
	
	}
