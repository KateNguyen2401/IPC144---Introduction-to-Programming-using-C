// -------------------------------------------
//  Name:
//  ID:
//  Email:
//  Description: Milestone #2
// -------------------------------------------

#include <stdio.h>

// Copy your milestone #1 source code below
// - Add new function prototypes and definitions
//   for milestone #2 as per the directions
#include <stdlib.h>
#define LINEAR 1
#define FORM 0
const double TAX = 0.13;
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
void GroceryInventorySystem(void);
int menu(void);
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21

void displayItem(struct Item item, int linear);
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);
/* struct Item GI[21] = {
  { 4.4,275,0,10,2,"Royal Gala Apples" },
  { 5.99,386,0,20,4,"Honeydew Melon" },
  { 3.99,240,0,30,5,"Blueberries" },
  { 10.56,916,0,20,3,"Seedless Grapes" },
  { 2.5,385,0,5,2,"Pomegranate" },
  { 0.44,495,0,100,30,"Banana" },
  { 0.5,316,0,123,10,"Kiwifruit" },
  { 4.49,355,1,20,5,"Chicken Alfredo" },
  { 5.49,846,1,3,5,"Veal Parmigiana" },
  { 5.29,359,1,40,5,"Beffsteak Pie" },
  { 4.79,127,1,30,3,"Curry Checken" },
  { 16.99,238,1,10,2,"Tide Detergent" },
  { 10.49,324,1,40,5,"Tide Liq. Pods" },
  { 10.99,491,1,50,5,"Tide Powder Det." },
  { 3.69,538,1,1,5,"Lays Chips S&V" },
  { 3.29,649,1,15,5,"Joe Org Chips" },
  { 1.79,731,1,100,10,"Allen's Apple Juice" },
  { 6.69,984,1,30,3,"Coke 12 Pack" },
  { 7.29,350,1,50,5,"Nestea 12 Pack" },
  { 6.49,835,1,20,2,"7up 12 pack" }
};
int GNoOfRecs = 20;
*/  

	     
void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
	return;
}
void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
	return;
}
void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal > 0){
		printf("                                           Grand Total: |%12.2lf\n",gTotal);
	}
	return;
}
void flushKeyboard(void){
	while(getchar() != '\n');
}
void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}
int getInt(void){
	int in;
	char ch = 'x';
	scanf("%d%c",&in,&ch);
	while(ch != '\n'){
		flushKeyboard();
		printf("Invalid integer, please try again: ");
		scanf("%d%c",&in,&ch);
	}
	return in;
}
int getIntLimited(int lowerLimit, int upperLimit){
	int inte;
	scanf("%d",&inte);
	while(inte <= 10 || inte >= 20){
		flushKeyboard();
		printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		scanf("%d",&inte);
	}
	return inte;
}
double getDouble(void){
	double doub;
	char cha;
	scanf("%lf%c",&doub,&cha);
	while( cha != '\n'){
		flushKeyboard();
		printf("Invalid number, please try again: ");
		scanf("%lf%c",&doub,&cha);
	}
	return doub;
}
double getDoubleLimited(double lowerLimit, double upperLimit){
	double doubl;
	scanf("%lf",&doubl);
	while( doubl >= upperLimit || doubl <= lowerLimit){
		flushKeyboard();
		printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		scanf("%lf",&doubl);
	}
	return doubl;
}
int yes(void){
	int i;
	char c;
	
	scanf("%c",&c);
	flushKeyboard();
	while( c != 'y' && c!= 'Y' && c!='n' && c!='N'){
		
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c",&c);
	}
	if(c=='y' || c=='Y')
		i=1;
	if(c=='n' || c=='N')
		i=0;
	return i;
}
int menu(void){
	int choice;
	printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n4- Stock an item\n5- Add new item or update item\n6- Delete item\n7- Search by name\n0- Exit program\n");
	printf("> ");
	scanf("%d",&choice);
	while( choice > 7 || choice < 0){
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d",&choice);
	}
	return choice;
}
void GroceryInventorySystem(void){
	int option;
	char s;
	welcome();
	do{
		option = menu();
		switch(option){
			case 1:
				printf("List Items under construction!\n");
				pause();
				printf("\n");
				break;        
			case 2:        
				printf("Search Items under construction!\n");
				pause();
				printf("\n");
				break;
			case 3:        
				printf("Checkout Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 4:       
				printf("Stock Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 5:       
				printf("Add/Update Item under construction!\n");
				pause();
				printf("\n");
				break;
			case 6:        
				printf("Delete Item under construction!\n");
				pause();
				printf("\n");
				break;        
			case 7:
				printf("Search by name under construction!\n");
				pause();
				printf("\n");
				break;
			case 0:
				flushKeyboard();
				printf("Exit the program? (Y)es/(N)o: ");
				scanf("%c",&s);
				if( s == 'y' || s=='Y')
					return;
				if( s =='n' || s=='N')
					break;
				yes();
				if(yes()==1)
					return;
				if(yes() ==0)
					break;
				break;       
		}        
	}while(option >= 0);
	return;
}
double totalAfterTax(struct Item item){
	double total=0.0;
	total = item.price * item.quantity ;
	if(item.isTaxed == 1)
		total = total + total * TAX;
	return total;
}
int isLowQuantity(struct Item item){
	int flag=0;
	if(item.quantity < item.minQuantity)
		flag=1;
	return flag;
}
struct Item itemEntry(int sku){
	struct Item i;
	printf("        SKU: %d\n",sku);
	i.sku = sku;
	printf("       Name: ");
	
	scanf("%[^\n]",i.name);
	flushKeyboard();
	printf("      Price: ");
	scanf("%lf",&i.price);
	printf("   Quantity: ");
	scanf("%d",&i.quantity);
	printf("Minimum Qty: ");
	scanf("%d",&i.minQuantity);
	printf("   Is Taxed: ");
	flushKeyboard();
	i.isTaxed = yes();
	return i;
}
void displayItem(struct Item item, int linear){
	char* c[3];
	double total;
	if(item.isTaxed == 0){
			* c = "No";
			total = item.price * item.quantity;
	}else{
			* c = "Yes";
			total = item.price * item.quantity;
			total = total + total * 0.13;
	}
	if(linear == 1){
		printf("|%3d|%-20s|%8.2lf|%5s|%4d | %3d | %11.2lf|",item.sku,item.name,item.price,*c,item.quantity,item.minQuantity,total);
		if(item.quantity < item.minQuantity){        
			printf("***\n");
		}else{
			printf("\n");
		}
	}else{
		printf("        SKU: %d\n"
		"       Name: %s\n"
		"      Price: %.2lf\n"
		"   Quantity: %d\n"
		"Minimum Qty: %d\n"
		"   Is Taxed: %s\n",item.sku,item.name,item.price,item.quantity,item.minQuantity,*c);
		if(item.quantity < item.minQuantity || item.quantity == 0)
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		
		    
	}
	
	return;
}
void listItems(const struct Item item[], int noOfItems){
	int i;
	char* c[3];
	double total;
	double gtotal =0.0;
	printTitle();
	for(i=0;i<noOfItems;i++){
		if(item[i].isTaxed ==0){
			* c = "No";
			total = item[i].price * item[i].quantity;
		}else{
			* c = "Yes";
			total = item[i].price * item[i].quantity;
			total = total + total *0.13;
		}
		printf("%-4d|%3d|%-20s|%8.2lf|%5s|%4d | %3d | %11.2lf|",i+1,item[i].sku,item[i].name,item[i].price,*c,item[i].quantity,item[i].minQuantity,total);
		if(item[i].quantity < item[i].minQuantity)
			printf("***\n");
		else
			printf("\n");
		gtotal =  gtotal + total;
	}
	printFooter(gtotal);
	return;
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
	int i;
	int value =0;
	for(i=0;i<NoOfRecs;i++){
		if(sku == item[i].sku){
			*index = i;
			value =1;
		}
	}
	return value;
}
void search(const struct Item item[], int NoOfRecs){
	int sku, searchIndex;
	char* c[4];
	printf("Please enter the SKU: ");
	scanf("%d",&sku);
	flushKeyboard();
	if(locateItem(item, NoOfRecs, sku, &searchIndex) > 0){
		if(item[searchIndex].isTaxed == 0)
			* c = "No";
		else
			* c = "Yes";
		printf("        SKU: %d\n"
		"       Name: %s\n"
		"      Price: %.2lf\n"
		"   Quantity: %d\n"
		"Minimum Qty: %d\n"
		"   Is Taxed: %s\n",sku,item[searchIndex].name,item[searchIndex].price,item[searchIndex].quantity,item[searchIndex].minQuantity,*c);
	}else{
		printf("Item not found!\n");
	}
}
void updateItem(struct Item* itemptr) {
	struct Item item;
	printf("Enter new data:\n");
	item = itemEntry((*itemptr).sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes() > 0) {
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}
void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item it;
	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		it = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		if (yes() == 1) {
			item[*NoOfRecs] = it;
			printf("--== Added! ==--\n");
			*NoOfRecs = *NoOfRecs + 1;
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}
void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int sku, i;
	
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	flushKeyboard();
	if (locateItem(item, *NoOfRecs, sku, &i) > 0) {
		displayItem(item[i], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes() == 1) {
			
			updateItem(&item[i]);
		}
		else{
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, sku);
	}
}
void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
	int sku, i, MAX_QTY, num;
	char* c[12];
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	if (locateItem(item, NoOfRecs, sku, &i) == 0) {
		printf("SKU not found in storage!\n");
	}
	else {
		displayItem(item[i], FORM);
		if (stock == 1) {
			* c = "to stock";
			MAX_QTY = 999 - item[i].quantity;
		}
		else {
			* c = "to checkout";
			MAX_QTY = item[i].quantity;
		}
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", *c, MAX_QTY);
		scanf("%d", &num);
		if (num == 0) {
			printf("--== Aborted! ==--\n");
		}
		else {
			if (stock == 1) {
				item[i].quantity = item[i].quantity + num;
				printf("--== Stocked! ==--\n");
			}
			else {
				item[i].quantity = item[i].quantity - num;
				printf("--== Checked out! ==--\n");
			}
			if (item[i].quantity < item[i].minQuantity)
				printf("Quantity is low, please reorder ASAP!!!\n");
		}
	}
}
