//Nama : Daniel Lee Runtuwene
//NIM : 2502030971
//Kelas : LA20 - LAB

//Create Binary Search Tree
//DATA PEGAWAI KANTOR

//ADD LIBRARY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct node{
	long long nomor_pendaftar;
	
	char nama_pegawai[255];
	char jenis_kelamin[255];
	
	int umur;
	
	char alamat[255];
	char email[255];
	char nomor_telpon[255];
	
	struct node *left;
	struct node *right;
};

struct node* newNode(long long nomor_pendaftar, char nama_pegawai[], char jenis_kelamin[], int umur, char alamat[], char email[], char nomor_telpon[]){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->nomor_pendaftar = nomor_pendaftar;
	
	strcpy(temp->nama_pegawai, nama_pegawai);
	strcpy(temp->jenis_kelamin, jenis_kelamin);
	
	temp->umur = umur;
	
	strcpy(temp->alamat, alamat);
	strcpy(temp->email, email);
	strcpy(temp->nomor_telpon, nomor_telpon);
	
	temp->left = temp->right = NULL;
	
	printf("\n > Data berhasil ditambahkan !");
	getch();
	
	return temp;
}

struct node* insert(struct node* node, long long nomor_pendaftar, char nama_pegawai[], char jenis_kelamin[], int umur, char alamat[], char email[], char nomor_telpon[]){
	if(node == NULL){
		// Buat root baru
        return newNode(nomor_pendaftar, nama_pegawai, jenis_kelamin, umur, alamat, email, nomor_telpon);
	} else if(nomor_pendaftar < node->nomor_pendaftar){
		// Insert ke anak kiri
		node->left = insert(node->left, nomor_pendaftar, nama_pegawai, jenis_kelamin, umur, alamat, email, nomor_telpon);
	} else if(nomor_pendaftar > node->nomor_pendaftar){
		// Insert ke anak kanan
		node->right = insert(node->right, nomor_pendaftar, nama_pegawai, jenis_kelamin, umur, alamat, email, nomor_telpon);
	} else{
		// Jika data sama, maka tampilkan : data sudah ada
		printf("\n > Data Sudah Ada !");
		getch();
	}
	
	return node;
}

// Buat cari anak kiri paling bawah
struct node* nilaiMinimal(struct node* node){
	struct node *temp = node; 
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	
	return temp;
}

struct node* delet(struct node* node, long long nomor_pendaftar){
	if(node == NULL){
    	printf("\n");
		printf(" > Data tidak ditemukan!");
    	return node;
	}
	
	if(nomor_pendaftar < node->nomor_pendaftar){
		node->left = delet(node->left, nomor_pendaftar);	
	}
    else if(nomor_pendaftar > node->nomor_pendaftar){
    	node->right = delet(node->right, nomor_pendaftar);	
	}
    else{
    	// satu anak / tidak punya anak
    	if(node->left == NULL){
            struct node *temp = node->right;
            free(node);
            printf("\n > Data berhasil dihapuskan !");
			getch();
            return temp;
        }
		else if(node->right == NULL){
        	struct node *temp = node->left;
            free(node);
            printf("\n > Data berhasil dihapuskan !");
			getch();
            return temp;
        }
        // jika punya 2 anak / lebih
        struct node* temp = nilaiMinimal(node->right);
        
        // Place the InOrder successon in position of te node to be deleted
        node->nomor_pendaftar = temp->nomor_pendaftar;
	
		strcpy(node->nama_pegawai, temp->nama_pegawai);
		strcpy(node->jenis_kelamin, temp->jenis_kelamin);
		
		node->umur = temp->umur;
		
		strcpy(node->alamat, temp->alamat);
		strcpy(node->email, temp->email);
		strcpy(node->nomor_telpon, temp->nomor_telpon);
		
		// Delete the InOrder successor
        node->right = delet(node->right, temp->nomor_pendaftar);
    }
    
    return node;
}

struct node* search(struct node* node, long long nomor_pendaftar){
	if(node == NULL){
    	printf("\n");
		printf(" > Data tidak ditemukan!");
    	return node;
	}
	
	// Ke anak kanan
	if(nomor_pendaftar < node->nomor_pendaftar){
		node->left = search(node->left, nomor_pendaftar);
	} // ke anak kiri
	else if(nomor_pendaftar > node->nomor_pendaftar){
    	node->right = search(node->right, nomor_pendaftar);		
	} else{
		printf("\n");
		printf(" >  Nomor Pendaftar : %lld\n", node->nomor_pendaftar);
		printf(" -  Nama Pegawai    : %s\n", node->nama_pegawai);
		printf(" -  Jenis Kelamin   : %s\n", node->jenis_kelamin);
		printf(" -  Umur            : %d\n", node->umur);
		printf(" -  Alamat Ruamh    : %s\n", node->alamat);
		printf(" -  Alamat Email    : %s\n", node->email);
		printf(" -  Nomor Telepon   : %s\n", node->nomor_telpon);
		printf("\n");
		printf(" > Data berhasil ditampilkan!");
	}
	
	return node;
}

// Display preOrder
void preOrder(struct node *tree){
	if(tree != NULL){
		fflush(stdin);
		
		printf("\n");
		printf(" >  Nomor Pendaftar : %lld\n", tree->nomor_pendaftar);
		printf(" -  Nama Pegawai    : %s\n", tree->nama_pegawai);
		printf(" -  Jenis Kelamin   : %s\n", tree->jenis_kelamin);
		printf(" -  Umur            : %d\n", tree->umur);
		printf(" -  Alamat Rumah    : %s\n", tree->alamat);
		printf(" -  Alamat Email    : %s\n", tree->email);
		printf(" -  Nomor Telepon   : %s\n", tree->nomor_telpon);
		
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

// Display InOrder
void inOrder(struct node *tree){
	if(tree != NULL){
		fflush(stdin);
		
		inOrder(tree->left);
		
		printf("\n");
		printf(" >  Nomor Pendaftar : %lld\n", tree->nomor_pendaftar);
		printf(" -  Nama Pegawai    : %s\n", tree->nama_pegawai);
		printf(" -  Jenis Kelamin   : %s\n", tree->jenis_kelamin);
		printf(" -  Umur            : %d\n", tree->umur);
		printf(" -  Alamat Rumah    : %s\n", tree->alamat);
		printf(" -  Alamat Email    : %s\n", tree->email);
		printf(" -  Nomor Telepon   : %s\n", tree->nomor_telpon);
		
		inOrder(tree->right);
	}
}

// Display PostOrder
void postOrder(struct node *tree){
	if(tree != NULL){
		fflush(stdin);
		
		postOrder(tree->left);
		postOrder(tree->right);
	
		printf("\n");
		printf(" >  Nomor Pendaftar : %lld\n", tree->nomor_pendaftar);
		printf(" -  Nama Pegawai    : %s\n", tree->nama_pegawai);
		printf(" -  Jenis Kelamin   : %s\n", tree->jenis_kelamin);
		printf(" -  Umur            : %d\n", tree->umur);
		printf(" -  Alamat Rumah    : %s\n", tree->alamat);
		printf(" -  Alamat Email    : %s\n", tree->email);
		printf(" -  Nomor Telepon   : %s\n", tree->nomor_telpon);
	}
}

void clear_screen(){
	system("cls||clear");
}

int main(){
	// Deklarasi tree = NULL
	struct node* tree = NULL;
	
	// Deklarasi untuk input pegawai
	long long nomor_pendaftar;
	
	char nama_pegawai[255];
	char jenis_kelamin[255];
	
	int umur;
	
	char alamat[255];
	char email[255];
	char nomor_telpon[255];

	// Deklarasi menu untuk memilih menu
	int menu = 0;
	
	// Deklarasi tampil untuk pilihan menampilkan
	int tampil = 0;

	do{
		do{
			clear_screen();
			
			printf("\t\n # Binary Search Tree - Data Pegawai Kantor\n");
			printf("\n");
			printf(" 1. Tambah\n");
			printf(" 2. Hapus\n");
			printf(" 3. Cari\n");
			printf(" 4. Tampilkan\n");
			printf(" 5. Exit\n");
			printf("\n");
			printf(" > Input : ");
			scanf("%d", &menu);
		} while(menu < 1 || menu > 5);
		
		switch(menu){
			case 1:
				clear_screen();
				printf("\t\n # Binary Search Tree - Tambahkan Data Pegawai Baru\n");
				printf("\n");
				printf(" > Input Nomor Pendaftar : "); scanf("%lld", &nomor_pendaftar); fflush(stdin);
				printf(" > Input Nama Pegawai    : "); scanf("%[^\n]s", nama_pegawai); fflush(stdin);
				printf(" > Input Jenis Kelamin   : "); scanf("%[^\n]s ", jenis_kelamin); fflush(stdin);
				printf(" > Input Umur            : "); scanf("%d", &umur); fflush(stdin);
				printf(" > Input Alamat          : "); scanf("%[^\n]s ", alamat); fflush(stdin);
				printf(" > Input Email           : "); scanf("%s", email); fflush(stdin);
				printf(" > Input Nomor Telepon   : "); scanf("%s", nomor_telpon); fflush(stdin);
				tree = insert(tree, nomor_pendaftar, nama_pegawai, jenis_kelamin, umur, alamat, email, nomor_telpon);
				break;
			case 2:
				if(tree == NULL){
					printf("\n > Tidak ada data !");
					getch();
				} else{
					clear_screen();
					printf("\t\n # Binary Search Tree - Hapus Data Pegawai\n");
					printf("\n");
					printf(" > Input Nomor Pendaftar : "); scanf("%lld", &nomor_pendaftar);
					tree = delet(tree, nomor_pendaftar);
					getch();
				}
				break;
			case 3:
				if(tree == NULL){
					printf("\n > Tidak ada data !");
					getch();
				} else{
					clear_screen();
					printf("\t\n # Binary Search Tree - Cari Data Pegawai\n");
					printf("\n");
					printf(" > Input Nomor Pendaftar : "); scanf("%lld", &nomor_pendaftar);
					search(tree, nomor_pendaftar);
					getch();
				}
				break;
			case 4:
				clear_screen();
				printf("\t\n # Binary Search Tree - Tampilkan Data Pegawai\n");
				printf("\n");
				printf(" 1. Tampilkan : Pre-Order\n");
				printf(" 2. Tampilkan : In-Order\n");
				printf(" 3. Tampilkan : Post-Order\n");
				printf("\n");
				printf(" > Input : ");
				scanf("%d", &tampil);
				
				switch(tampil){
					case 1:
						if(tree == NULL){
							printf("\n > Tidak ada data !");
							getch();
						} else{
							clear_screen();
							printf("\t\n # Binary Search Tree - Tampilkan : Pre-Order\n");
							preOrder(tree);
							printf("\n > Data berhasil ditampilkan !");
							getch();
						}
						break;
					case 2:
						if(tree == NULL){
							printf("\n > Tidak ada data !");
							getch();
						} else{
							clear_screen();
							printf("\t\n # Binary Search Tree - Tampilkan : In-Order\n");
							inOrder(tree);
							printf("\n > Data berhasil ditampilkan !");
							getch();
						}
						break;
					case 3:
						if(tree == NULL){
							printf("\n > Tidak ada data !");
							getch();
						} else{
							clear_screen();
							printf("\t\n # Binary Search Tree - Tampilkan : Post-Order\n");
							postOrder(tree);
							printf("\n > Data berhasil ditampilkan !");
							getch();
						}
						break;
					default:
						printf("\n > Input : 1-3 !");
						getch();
				}
				break;
			case 5:
				exit(0);
				break;
		}
	} while(menu != 5);

	return 0;
}
