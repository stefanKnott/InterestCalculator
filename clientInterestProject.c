/*Author: stefanknott
 * Created on December 25, 2013, 4:57 PM
 */

#include "clientInterestProject.h"

List *List_create(){
	return (List *)(malloc(sizeof(List)));
}

int printListToFile(List * list){
	if(!list){return 0;}
	FILE * fp;
	fp = fopen("Clients.txt", "w");
	Person * first = (Person *)(malloc(sizeof(Person)));
	first = list->head;
	int i = 0;
	while(i < list->count){
		fprintf(fp, "Client Name: %s \n", first->name);
		fprintf(fp, "Balance: %lf \n", first->balance);
		fprintf(fp, "Compounds: %d \n", first->compounds);
		fprintf(fp, "Interest Rate: %lf \n", first->rate);
		fprintf(fp, "Estimate after Interest: %lf \n \n", 									first->estimate);
		first = first->next;
		i++;
	}
	return 1;
}

int info(Person * p){
	if(!p){return 0;}

	char name[20];
	double bal, rat;
	int comp, i = 0;

	printf("The client's name: \n");
	scanf("%s", name);
	printf("The client's balance: \n");
	scanf("%lf", &bal);
	printf("Client's amount of compounds per yeari (-1 for continuous co								mpound): \n");
	scanf("%d", &comp);
	printf("Client's compounding rate: \n");
	scanf("%lf", &rat);
	while((name[i] != '\0') && (name[i] != 0)){ //Copies name to p->name
		p->name[i] = name[i];
		i++;
	}
	p->balance = bal;
	p->compounds = comp;
	p->rate= rat;
	return 1;
} 

int calcBalanceEst(List * list){
	if(!list){return 0;}
	double estimate, t;
	Person * start = (Person*)(malloc(sizeof(Person)));
	start = list->head;
	int i = 0;
	while(i < list->count){
		if(start->compounds > 0){//Effective Annual Rate
			double base = 1 + (start->rate)/(start->compounds);
			start-> estimate = start->balance * pow(base, 								start->compounds);
		}
		if(start->compounds == -1){
			printf("Years of continuous compounding: ");
			scanf("%lf", &t);
			start->rate = exp(start->rate)-1;
			estimate = start->balance * pow(start->rate + 1,t);
			start->estimate = estimate;
		}
		start = start->next;
		i++;
	}
	return 1;
}

int end(List * list){
	int choice = 0;

	printf("1. To Quit \n");
	printf("2. To Add More Clients \n");
	printf("3. To Print List of Clients \n");
	printf("4. To Print List of Clients and Balance Estimates \n");

	scanf("%d", &choice);

	if(choice == 1){
		return 0;
	}

	else if(choice == 2){
		Person * client = (Person *)(malloc(sizeof(Person)));
		if(list->head == NULL){
			list->head = client;
			list->tail = client;
		}
		else{

			list->tail->next = client;
			client->prev = list->tail;
			list->tail = client;
		}
		list->count++;
		info(client);
	}
	
	else if(choice == 3){
		printListToFile(list);
	}
	else if(choice == 4){
		calcBalanceEst(list);
		printListToFile(list);
	}
        else
        {   printf("Please choose a valid option.");
            end(list);
        }
	
	return 1;
}

int deleteList(List * list){
	if(list->head == NULL){return 0;}

	Person * n = (Person *)(malloc(sizeof(Person)));
	
	n = list->head;
	if(n->next == NULL){
		free(n);
		return 1;
	}
	n = list->head->next;
	while(n != NULL ){
		free(n->prev);	
		n = n->next;
	}
	return 1;
}

int main(void){
	List * list = List_create();
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;

	while(end(list) == 1);

	deleteList(list);

	return 0;
}


