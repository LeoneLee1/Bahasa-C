
// Push untuk menambah data.
//	* PushHead - Menambah data ke barisan paling awal
//  * PushTail - Menambah data ke barisan paling akhir
//	* PushMid  - Menambah dataa ke barisan di tengah(sorting)

// Pop untuk menghapus data.
//	* PopHead - Menghapus data paling awal
//	* Poptail - Menghapus data paling akhir
//	* PopMid  - Menghapus data di tengah(sesuai parameter value)

//==============================================================================

// DEKLARASI STRUCT //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
	//menampung integer umur
	int age;
	//menampung nama manusia
	char name[30];
	//menampung alamat dari data selanjutnya
	struct human *next;
}*head, *tail, *current;
//head adalah pointer yang menyimpan alamat data pertama
//tail adalah pointer yang menyimpan alamat data terakhir
//current adalah pointer yang digunakan sebagai temporary variabel


// PUSH HEAD //
void pushHead(int age, char name[]){
	//alokasi memory untuk data baru
	current = (struct human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		current->next = head;
		head = current;
	}	
}


// PUSH TAIL //

void pushTail(int age, char name[]){
	//alokasi memory untuk data baru
	current = (struct human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		tail->next = current;
		tail = current;
	}
	tail->next = NULL;
}


// PUSH MID //
void pushMid(int age, char name[]){
	//alokasi memory untuk data baru
	current = (struct human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//jika umur data yang barusan dimasukkan lebih kecil dari umur data pertama (head)
	else if(current->age < head->age){
		pushHead(age, name);
	}
	//jika umur data yang barusan dimasukkan lebih besar dari umur data terakhir (tail)
	else if(current->age > tail->age){
		pushTail(age, name);
	}
	//push ditengah-tengah
	else{
		struct human *temp = head;
		//mencari posisi data yang sesuai untuk diselipkan
		while(temp->next->age < current->age){
			temp = temp->next;
		}
		current->next = temp->next;
		//mengarahkan penunjuk ke alamat data baru
		temp->next = current;
	}
}



// POP HEAD //
void popHead(){
	//inisialisasi current sebagai head
	current=head;
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//set head menjadi data selanjutnya dari head
		head=head->next;
		//hapus data current (head)
		free(current);
	}
}


// POP TAIL //
void popTail(){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		struct human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi tail
		current=tail;
		//set tail menjadi 1 data sebelum tail (hasil looping)
		tail=temp;
		//hapus data current (tail)
		free(current);
		//data setelah next dikosongkan/pointer next punya tail diberi NULL
		tail->next=NULL;
	}
}


// POP MID //
//kita akan menghapus data sesuai dengan umurnya.
void popMid(int age){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		printf("No data");
	//jika umur si head(data pertama) sama dengan data umur yang mau dihapus
	}else if(head->age==age){
		//pop head
		popHead();
	//jika umur si tail(data terakhir) sama dengan data umur yang mau dihapus
	}else if(tail->age==age){
		//pop tail
		popTail();
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		struct human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next->age!=age && temp!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi data selanjutnya dari temp
		current=temp->next;
		//data selanjutnya dari temp diubah menjadi 2 data setelah temp
		temp->next=temp->next->next;
		//hapus data current
		free(current);
	}
}

// POP MID //
void popAll(){
	while(head!=NULL){
		popHead();
	}
}


// PRINT DATA //
void print(){
	current = head;
	while(current != NULL){
		printf("%s - %d\n",current->name,current->age);
		current = current->next;
	}
}

// MAIN FUNCTION //
int main(){
	pushMid(18, "hery");
	pushMid(17, "mahirkoding");
	pushTail(22, "andi");
	pushHead(15, "tono");
	pushMid(11, "vandoro");
	pushMid(23, "budi");
	popHead();
	popTail();
	popMid(15);
        //popAll();
	print();
	getchar();
	return 0;
}



