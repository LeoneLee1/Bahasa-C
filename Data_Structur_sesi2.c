#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include <windows.h>
#include <unistd.h>


struct Hewan{
	char  nama_hewan[60];
	char jenis_hewan[30];
	int umur;
	
	struct Hewan *next;
}*head, *tail, *current;

void pushHead(char nama_hewan[], char jenis_hewan[], int umur);
void pushTail(char nama_hewan[], char jenis_hewan[], int umur);
void popHead();
void popTail();
void print();
void clrscr();

int main(){
	int input, i, temp;

	char nama[60];
	char jenis[30];
	int umur;

    int pilih;
	int pilihan;
	int hapus;

	clrscr();
	
	print();
	
	printf("\n\n   [1] Tambah Data Baru");
	printf("\n   [2] Hapus Data");
	printf("\n   [3] Exit");
	printf("\n\n   [>] Input Menu : ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
	    printf("\n  Masukkan Jumlah Data : (Min. 3) ");
    	scanf("%d", &input);
    
    	if(input < 3){
    		main();
    	}

    	for(i = 1; i <= input; i++){
    		printf("\n  Isi data ke-%d\n", i);
    		
    		printf("\n   Nama hewan    : ");
    		scanf(" %[^\n]s", nama);
    		
    		printf("   Jenis Hewan (1 : Anjing, 0 : Kucing) ");
    		scanf(" %d", &temp);
    
    		if(temp < 0 && temp > 1){
    			main();
    		}
    
    		if(temp == 1){
    			strcpy(jenis, "Anjing");
    		} else if(temp == 0){
    			strcpy(jenis, "Kucing");
    		}
    
    		fflush(stdin);
    		printf("   Umur hewan    : ");
    		scanf(" %d", &umur);
    		
    		if(head == NULL){
    			pushHead(nama, jenis, umur);
    		}else{
    			printf("\n   [1] Isi data ke Depan\n   [2] Belakang\n\n   Input : (1/2) ");
    			scanf("%d", &pilih);
    
    			if(pilih == 1){
    				pushHead(nama, jenis, umur);
    			} else{
    				pushTail(nama, jenis, umur);
    			}
    		}
    	}
    	
    	main();
	} else if(pilihan == 2){
	    if(head == NULL){
	        main();
	    } else{
	        printf("\n   [1] Hapus Depan\n   [2] Hapus Belakang\n\n   Input : (1/2) ");
	        scanf("%d", &hapus);
    
    			if(hapus == 1){
    				popHead();
    			} else{
    				popTail();
    			}
	    }
	    main();
	} else{
	    exit(0);
	}
	
	return(0);
}

void clrscr(){
	system("@cls||clear");
}

void pushHead(char nama_hewan[], char jenis_hewan[], int umur){
	current = (struct Hewan*)malloc(sizeof(struct Hewan));

	strcpy(current->nama_hewan, nama_hewan);
	strcpy(current->jenis_hewan, jenis_hewan);

	current->umur = umur;
	
	if(head == NULL){
		head = tail = current;
	}
	else {
		current->next = head;
		head = current;
	}
}

void pushTail(char nama_hewan[], char jenis_hewan[], int umur){
	current = (struct Hewan*)malloc(sizeof(struct Hewan));

	strcpy(current->nama_hewan, nama_hewan);
	strcpy(current->jenis_hewan, jenis_hewan);

	current->umur = umur;
	
	if(head == NULL){
		head = tail = current;
	}
	else{
		tail->next = current;
	}

	tail->next = NULL;
}

void popHead(){
	current=head;

	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		head=head->next;
		free(current);
	}
}

void popTail(){
	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		struct Hewan *temp = head;

		while(temp->next != tail){
			temp = temp->next;
		}
		
		current = tail;
		tail = temp;

		free(current);
		tail->next = NULL;
	}
}

void print(){
	int i = 0;

	printf("\n  +-------+--------------------------+------------------+------------+\n");
	printf("  |  No   |        Nama Hewan        |   Jenis hewan    |    Umur    |\n");
	printf("  +-------+--------------------------+------------------+------------+\n");

	if(head!=NULL){
		current = head;

		while(current !=NULL){
			i++;
			printf("  | %-5d | %-24s | %-16s | %10d |\n", i, current->nama_hewan, current->jenis_hewan, current->umur);
			current = current->next;
		}
	}else{
		printf("  |       |                          |                  |            |\n");
	}

	printf("  +-------+--------------------------+------------------+------------+\n");
}
