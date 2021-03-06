#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20
struct Book{
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
void menu();
void displayInventory(const struct Book book[], const int size);
void addBook(struct Book book[], int *size);
void flushKeyboard(void);
int searchInventory(const struct Book book[], const int isbn, const int size);
void checkPrice(const struct Book book[], const int size);
int main(void){
	struct Book book[MAX_BOOKS];
	int size=0;
	int option;
	printf("Welcome to the Book Store\n=========================\n");
	do{
		menu();
		printf("\nSelect: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				displayInventory(book, size);
				break;
			case 2:
				addBook(book,&size);
				break;
			case 3:
				checkPrice(book,size);
				break;
			case 0:
				printf("Goodbye!\n");
				return 0;
			default:
				printf("Invalid input, try again:\n");
		}
	}while(option>=0);
	return 0;
}
void menu(){
	printf("Please select from the following options:\n1) Display the inventory.\n2) Add a book to the inventory.\n3) Check price.\n0) Exit.\n");
	return;
}
void displayInventory(const struct Book book[], const int size){
	int i;
	if(size == 0){
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}else{
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n"
			"---------+-------------------+----+-------+--------\n");
	      
		for(i=0;i<size;i++){
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book[i]._isbn,book[i]._title,book[i]._year,book[i]._price,book[i]._qty);
		
		}
	printf("===================================================\n\n");
	}
	return;
}
void addBook(struct Book book[], int *size){
	int qty;
	if(*size < MAX_BOOKS ){
		printf("ISBN:");
		scanf("%d",&book[*size]._isbn);
		if(searchInventory(book, book[*size]._isbn, *size)!= -1){
			printf("Quantity:");
			scanf("%d",&qty);
			book[searchInventory(book, book[*size]._isbn, *size)]._qty += qty;
			printf("The book exists in the repository, quantity is updated.\n\n");
		}else{
			printf("Quantity:");
			scanf("%d",&book[*size]._qty);
			flushKeyboard();
			printf("Title:");
			scanf("%[^\n]",book[*size]._title);
			flushKeyboard();
			printf("Year:");
			scanf("%d",&book[*size]._year);
			printf("Price:");
			scanf("%f",&book[*size]._price);
			printf("The book is successfully added to the inventory.\n\n");
			*size = *size +1;
		}
	}else{
		printf("ERROR!!! Book Inventory is full.\n");
	}
	return;
}
void flushKeyboard(void){
	while(getchar() != '\n');
}
int searchInventory(const struct Book book[], const int isbn, const int size){
	int flag =-1;
	int i;
	for(i=0;i<size;i++){
		if(book[i]._isbn == isbn)
			flag =i;
	}
	return flag;
}
void checkPrice(const struct Book book[], const int size){
	int isbn;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d",&isbn);
	if(searchInventory(book,isbn,size) != -1){
		printf("Book %d costs $%.2f\n\n",isbn,book[searchInventory(book,isbn,size)]._price);
	}else{
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
}
