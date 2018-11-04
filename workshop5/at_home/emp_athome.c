#include <stdio.h>
#define SIZE 4
struct employee{
	int id;
	int age;
	double salary;
};
int main(void){
	struct employee emp[SIZE];
	int option;
	int i=0,j=-1,a=-1;
	int idupdate, idremove;
	
	printf("---=== EMPLOYEE DATA ===---\n");
	do{
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");
		printf("\nPlease select from the above options: ");
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 1:
				printf("EMP ID  EMP AGE EMP SALARY\n======  ======= ==========\n");
				for(i=0;i<SIZE;i++){
					if(emp[i].id != 0){
						printf("%6d%9d%11.2lf\n",emp[i].id, emp[i].age, emp[i].salary);
					}
				}
				break;
			case 2:
				if(i<SIZE){
					printf("Adding Employee\n===============\n");
					printf("Enter Employee ID: ");
					scanf("%d",&emp[i].id);
					printf("Enter Employee Age: ");
					scanf("%d",&emp[i].age);
					printf("Enter Employee Salary: ");
					scanf("%lf",&emp[i].salary);
					i=i+1;
				}else{
					printf("Adding Employee\n===============\nERROR!!! Maximum Number of Employees Reached\n");
				}
				break;
			case 3: 
				do{
					printf("Update Employee Salary\n======================\n");
					printf("Enter Employee ID: ");
					scanf("%d",&idupdate);
					for(i=0;i<SIZE;i++){
						if(emp[i].id == idupdate){
							j=i;
							printf("The current salary is %.2lf\n",emp[j].salary);
							printf("Enter Employee New Salary: ");
							scanf("%lf",&emp[j].salary);
						}
					}
				}while(j<0);    
				break;
			case 4: 
				do{
					printf("Remove Employee\n===============\n");
					printf("Enter Employee ID: ");
					scanf("%d",&idremove);
					for(i=0;i<SIZE;i++){
						if(emp[i].id == idremove){
							a=i;
							emp[a].id=0;
							printf("Employee %d will be removed\n",idremove);      
						}
					}
				}while(a<0);
				break;
			case 0:
				printf("Exiting Employee Data Program. Good Bye!!!\n");
				return 0;
			default:
				printf("ERROR: Incorrect Option: Try Again\n");
			}
	}while(option>=0);

   
	
return 0;
}
