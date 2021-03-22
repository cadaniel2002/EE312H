/* 
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

String invName = StringCreate("inventory");
Customer invStock = {invName, 0, 0, 0};

String bottles = StringCreate("Bottles");
String diapers = StringCreate("Diapers");
String rattles = StringCreate("Rattles");

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */

bool sufficientStock(String type, int amnt){
	if (StringIsEqualTo(&type, &bottles) && amnt > invStock.bottles) {
		return false;
	} else if (StringIsEqualTo(&type, &diapers) && amnt > invStock.diapers) {
		return false;
	} else if(StringIsEqualTo(&type, &rattles) && amnt > invStock.rattles) {
		return false;
	}
	return true;
}

void reset(void) {
	invStock.bottles = 0;
	invStock.diapers = 0;
	invStock.rattles = 0;

	String empty = StringCreate("");
	for(int i = 0; i < num_customers; i++){
		customers[i].bottles = 0;
		customers[i].diapers = 0;
		customers[i].rattles = 0;
		StringDestroy(&customers[i].name);
	}
	num_customers = 0;
	StringDestroy(&empty);
}

void processSummarize() {
	printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", invStock.bottles, invStock.diapers, invStock.rattles);
	printf("we have had a total %d different customers\n", num_customers);

	int maxBottles = 0;
	int maxDiapers = 0;
	int maxRattles = 0;
	int bottleCus = -1;
	int diaperCus = -1;
	int rattleCus = -1;

	for(int i = 0; i < num_customers; i++){
		if(customers[i].bottles > maxBottles){
			maxBottles = customers[i].bottles;
			bottleCus = i;
		}
	}

	for(int i = 0; i < num_customers; i++){
		if(customers[i].diapers > maxDiapers){
			maxDiapers = customers[i].diapers;
			diaperCus = i;
		}
	}

	for(int i = 0; i < num_customers; i++){
		if(customers[i].rattles > maxRattles){
			maxRattles = customers[i].rattles;
			rattleCus = i;
		}
	}

	if(bottleCus == -1){
		printf("no one has purchased any Bottles\n");
	}
	else{
		StringPrint(&customers[bottleCus].name);
		printf(" has purchased the most Bottles (%d)\n", customers[bottleCus].bottles);
	}

	if(diaperCus == -1){
		printf("no one has purchased any Diapers\n");
	}
	else{
		StringPrint(&customers[diaperCus].name);
		printf(" has purchased the most Diapers (%d)\n", customers[diaperCus].diapers);
	}

	if(rattleCus == -1){
		printf("no one has purchased any Rattles\n");
	}
	else{
		StringPrint(&customers[rattleCus].name);
		printf(" has purchased the most Rattles (%d)\n", customers[rattleCus].rattles);
	}
}





void processPurchase() {

	String currName;
	readString(&currName);

	String type;
	readString(&type);

	int amnt;
	readNum(&amnt);

	int currCus = 0;
	if(sufficientStock(type, amnt) && amnt > 0){

		while(currCus < num_customers && !(StringIsEqualTo(&customers[currCus].name, &currName))){
			currCus++;
		}
		if(currCus == num_customers){
			customers[currCus].name = currName;
			num_customers++;
		}
		else{
			StringDestroy(&currName);
		}


		if (StringIsEqualTo(&type, &bottles)) {
			customers[currCus].bottles += amnt;
			invStock.bottles -= amnt;
		} else if (StringIsEqualTo(&type, &diapers)) {
			customers[currCus].diapers += amnt;
			invStock.diapers -= amnt;
		} else if(StringIsEqualTo(&type, &rattles)) {
			customers[currCus].rattles += amnt;
			invStock.rattles -= amnt;
		}
	}
	else if(amnt > 0){

		if (StringIsEqualTo(&type, &bottles)) {
			printf("Sorry "); StringPrint(&currName); printf(" we only have %d Bottles\n", invStock.bottles);
		} else if (StringIsEqualTo(&type, &diapers)) {
			printf("Sorry "); StringPrint(&currName); printf(" we only have %d Diapers\n", invStock.diapers);
		} else if(StringIsEqualTo(&type, &rattles)) {
			printf("Sorry "); StringPrint(&currName); printf(" we only have %d Rattles\n", invStock.rattles);
		}
		StringDestroy(&currName);
	}
	StringDestroy(&type);
}





void processInventory() {
	String type;
	readString(&type);

	int amnt;
	readNum(&amnt);

	if (StringIsEqualTo(&type, &bottles)) {
		invStock.bottles += amnt;
	} else if (StringIsEqualTo(&type, &diapers)) {
		invStock.diapers += amnt;
	} else if(StringIsEqualTo(&type, &rattles)) {
		invStock.rattles += amnt;
	}
	StringDestroy(&type);

}
