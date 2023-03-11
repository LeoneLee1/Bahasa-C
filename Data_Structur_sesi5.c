#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct antrian{
	char name[40];
	char noantri[5];
struct antrian *next;
}*head, *tail, *curr, *del, *newNode;

int maksimalAntrian = 5;

int countdata(){
	if(head == NULL){
		return 0;
	}
	else{
		int banyak = 0;
		curr = head;
		while (curr != NULL){
			curr = curr->next;
			banyak++;
		}
		return banyak;
	}
}

bool isFulldata(){
	if(countdata() == maksimalAntrian){
		return true;
	}
	else{
		return false;
	}
}

bool isEmptydata(){
	if(countdata() == 0){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(char noantri [], char name[]){
	
	if( isFulldata()){
		printf("===== FULL QUEUE !! =====\n");
	}
	else{
		if( isEmptydata()){
			head = (struct antrian*)malloc(sizeof(struct antrian));
			
			strcpy(head->noantri, noantri);
			strcpy(head->name, name);
			head->next = NULL;
			tail = head;
		}
		else{
			newNode = (struct antrian*)malloc(sizeof(struct antrian));
			
			strcpy(newNode->noantri, noantri);
			strcpy(newNode->name, name);
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
	}
}

void dequeue(){
	if(isEmptydata()){
		printf("\n\n===== EMPTY QUEUE !! =====\n");
	}
	else{
		del = head;
		head = head->next;
		del->next = NULL;
		free(del);
		printf("\n\n======= QUEUE SUCCESSFULLY ISSUED !! ==========\n");
	}
}

void display(){
	printf(" [#] Queue data :\n");
	if(isEmptydata()){
		printf("\n\n===== EMPTY QUEUE !! =====\n");
	}
	else{
		printf("[>] Lots of queue data : %d data\n", countdata());
		curr = head;
		int nomor = 1;
		printf("\n==============================\n");
		printf("|%s|%s|%s|\n","No","Nomor Meja","Customer's Name");
		printf("==============================\n");
		while(nomor <= maksimalAntrian){
			
			if(curr != NULL){
				printf("|%d | %-8s | %-13s|\n", nomor, curr->noantri, curr->name);
				curr = curr->next;
			}
			else{
				printf("|%d | %s | %-12s |\n", nomor, "(EMPTY)", "(EMPTY)");
			}
			nomor++;
		}
		printf("==============================");
	}
	printf("\n");
}

void hapussemualist(){
	if(isEmptydata()){
		printf("\n\n===== EMPTY QUEUE !! =====\n");
	}
	else{
		curr = head;
		while(curr != NULL){
			del = curr;
			curr = curr->next;
			del->next = NULL;
			free(del);
		}
		head = NULL;
		tail = NULL;
		printf("\n\n========== The List has been successfully cleared !! ==========\n");
	}
}

int main(){
	
	char noantri[5];
	char name[40];
	int menu;
	
	while(1){
		mainmenu :
		system("cls");
		printf("=========================\n");
		printf(" [1]. Enqueue\n");
		printf(" [2]. Dequeue\n");
		printf(" [3]. Clear List\n");
		printf(" [4]. Display\n");
		printf(" [5]. Exit\n");
		printf("=========================");
		printf("\n [>] Enter Your Choice: ");
		scanf("%d", &menu);
		switch(menu){
			case 1 :
				printf("\n\n [#] Fill in the data below :\n");
				printf("\n [>] Table number = ");
				scanf("%s", noantri);
				printf(" [>] Name = ");
				scanf("%s", name);
				enqueue(noantri, name);
				system("pause");
				goto mainmenu;
				break;
				
			case 2 :
				dequeue();
				printf("\n\n [>] Press Enter to return to menu [<]\n");
				system("pause");
				break;
				
			case 3 :
				hapussemualist();
				printf("\n\n [>] Press Enter to return to menu [<]\n");
				system("pause");
				break;
				
			case 4 :
				system("cls");
				display();
				printf("\n\n [>] Press Enter to return to menu [<]\n");
				system("pause");
				break;
			
			case 5 :
				system("cls");
	        	printf("============================\n");
	        	printf("==========THANK YOU=========\n");
	        	printf("============================\n");
	        	system("pause");
	        	exit(1);
	        
	        default:
	        	printf(" Invalid Input!\n");
	        	system("pause");
		}
	}
}
