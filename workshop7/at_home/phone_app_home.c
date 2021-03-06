#include <stdio.h>
#define SIZE 3
long long phoneNumber[SIZE]={0LL,0LL,0LL};
void decompose(long long num,int *a, int *p, int *l);
void display(int a, int b, int c);
int addphonenum(int i);
int isValid(long long number);
int main(void){
	int option,i;
	int j=0;
	int area, prefix, line;
	printf("---=== Phone Numbers ===---\n");
	do{
		printf("\n1. Display Phone List\n2. Add a Number\n0. Exit\n");
		printf("\nPlease select from the above options: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\nPhone Numbers\n==============\n");
				for(i=0;i<SIZE;i++){
					decompose(phoneNumber[i],&area,&prefix,&line);
					display(area,prefix,line);
				}
				break;
			case 2:
				printf("\nAdd a Number\n============\n");
				j = addphonenum(j);
				break;
			case 0:
				printf("\nExiting Phone Number App. Good Bye!!!\n");
				return 0;
			default:
				printf("\nERROR!!!: Incorrect Option: Try Again\n");
		}
	}while(option >= 0);
return 0;
}
void display(int a, int b, int c){
	if(a >0){
	printf("(%3d)-%3d-%4d\n",a,b,c);
	}
	return;
}
int addphonenum(int i){
	long long phone=0LL;
	if( i<SIZE){
		scanf("%lld",&phone);
		if(isValid(phone) >0){
			phoneNumber[i]=phone;
			i++;
		}else{
			printf("ERROR!!! Phone Number is not Valid\n");                       
		}
	}else{
		printf("ERROR!!! Phone Number List is Full\n");        
	}
	return i;
}
void decompose(long long num,int *a, int *p, int *l){ 
	*a = num/10000000;
	*p = num % 10000000 /10000;
	*l = num %10000000 % 10000;
	return;
} 
int isValid(long long number){
	int flag=-1;
	int ar, pr;
	ar = number /10000000;
	pr = number % 10000000 / 10000;
	if((ar == 416 || ar == 647 || ar == 905) && pr > 100 && pr <999){
		flag =1;
	}
	return flag;
}
