#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define OS_Windows
#endif

int max_data = 0;

struct data{
	char link[125];
	char note[20];
	struct data *next;
};

void config();

void pause();

void clear_screen();

void set_max();

void menu_program();

bool is_empty(struct data* temp);

bool is_overflow(struct data* temp, int max_data);

struct data* push(struct data* temp, char link[], char note[]);

struct data* pop(struct data* temp);

struct data peek(struct data* temp);

void print_data(struct data* temp);

int main(){
	config();
	set_max();
	menu_program();
	
	return 0;
}

void config(){
	#ifdef OS_Windows
		system("title STACK PROGRAM");
		system("mode con:cols=125 lines=30");
	#endif
}

void pause(){
	#ifdef OS_Windows
		fflush(stdin);
		getch();
	#endif
}

void clear_screen(){
	// cls   = untuk windows (clear screen)
	// clear = untuk unix (clear screen)
	system("cls||clear");
}

void set_max(){
	
	do{
		clear_screen();
		
		printf("\n [#] CONFIG PROGRAM");
		printf("\n  |");
		printf("\n  +--[>] Set Max Data di Stack : [5-100] ");
		
		scanf("%d", &max_data);
	} 
	while(max_data < 5 || max_data > 100);
}

void menu_program(){
	struct data *temp = NULL;
	
	int pilih_menu;
	
	int inc;
	
	char link[125];
	char note[20];
	
	do{
		do{
			for(inc = 0; inc < 125; inc++){
				link[inc] = '\0';
			}
			
			for(inc = 0; inc < 20; inc++){
				note[inc] = '\0';
			}
			clear_screen();
			
			printf("\n  +--[ MENU PROGRAM ]");
			printf("\n  |");
			printf("\n  |  [1] Push Stack   [3] Peek Stack");
			printf("\n  |  [2] Pop Stack    [4] Print Data");
			printf("\n  |");
			printf("\n  |  [5] Exit Program");
			printf("\n  |");
			printf("\n  +--[?] Pilih Menu : ");
			
			scanf("%d", &pilih_menu);
		} while(pilih_menu < 1 || pilih_menu > 5);
		
		switch(pilih_menu){
			case 1:
				if(is_overflow(temp, max_data)){
					printf("      |\n");
					printf("     [!] Data Penuh, Anda harus pilih menu 2 (hapus data) dahulu!");
				} else{
					printf("      |\n");
					printf("      +--[?] Input Link : ");
					scanf(" %s", link);
					
					fflush(stdin);
					
					printf("      +--[?] Input Note : ");
					scanf(" %[^\n]s", note);
					
					temp = push(temp, link, note);
				}
				pause();
				break;
			case 2:
				if(temp == NULL){
					printf("      |\n");
					printf("     [!] Data Kosong, Tidak ada data yang dihapus!");
				} else{
					temp = pop(temp);
				}
				pause();
				break;
			case 3:
				if(temp == NULL){
					printf("      |\n");
					printf("     [!] Data Kosong, Tidak ada data yang ditampilkan!");
				} else{
					struct data ptr = peek(temp);
					
					printf("      |\n");
					printf("     [#] Data Paling Atas Adalah :\n");
					printf("      |\n");
					printf("      +--[>] Link : %s\n", ptr.link);
					printf("      +--[>] Note : %s", ptr.note);
				}
				pause();
				break;
			case 4:
				print_data(temp);
				
				pause();
				
				break;
			
			case 5:
			
				exit(0);
			
				break;
			// user input random
			default:
			
				break;
		}
		
	} 
	while(pilih_menu != 5);
}

bool is_empty(struct data* temp){

	if(temp == NULL){

		return true;
	} else {

		return false;
	}
}

bool is_overflow(struct data* temp, int max_data){

	int result = 0;
	
	struct data* ptr = temp;
	
	if(is_empty(temp)){

		return false;
	} else{
		while(ptr != NULL){
	
			ptr = ptr->next;
	
			result++;
		}
		
	
		return (result == max_data);
	}
}

struct data* push(struct data* temp, char link[], char note[]){

	if(is_empty(temp)){

		temp = (struct data*)malloc(sizeof(struct data));
		
		strcpy(temp->link, link);

		strcpy(temp->note, note);
		
		temp->next = NULL;
	} else{
		struct data* ptr = (struct data*)malloc(sizeof(struct data));
		
		strcpy(ptr->link, link);
		
		strcpy(ptr->note, note);
		
		ptr->next = temp;
		
		temp = ptr;
	}
	
	return temp;
}

struct data* pop(struct data *temp){

	if(temp->next == NULL){

		free(temp);
		temp = NULL;
	} else{
		struct data *ptr = temp;
		
		temp = temp->next;
	
		free(ptr);
	}
	
	return temp;
}

struct data peek(struct data *temp){

	return *temp;
}

void print_data(struct data* temp){

	struct data *ptr = temp;
	
	printf("\n   +------------------------------------------+----------------------+\n");
	
	if(is_empty(ptr)){
		printf("   |                                          |                      |\n");
	} else {
		while(ptr != NULL){
	
			if(ptr == temp){
				printf("   | %-40s | %-20s |   <- Atas\n", ptr->link, ptr->note);
			} else{
				printf("   | %-40s | %-20s |\n", ptr->link, ptr->note);
			}
			
			ptr = ptr->next;
		}
	}
	
	printf("   ===================================================================\n");
	printf("   |                   LINK                   |         NOTE         |\n");
	printf("   ===================================================================");
}

