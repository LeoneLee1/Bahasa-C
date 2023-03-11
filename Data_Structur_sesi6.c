#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct dataKtp {
    char nama[50];
    char alamat[50];
    char golongandarah[2];
    
	struct dataKtp *next, *prev;
};

struct dataKtp *awal=NULL,*akhir=NULL,*bantu,*baru,*hapus;

void inputDatadepan(){
    baru = (struct dataKtp*)malloc(sizeof(struct dataKtp));
    
	baru->next = NULL;
    baru->prev = NULL;
    
    fflush(stdin);
    
	printf("\n[>] Nama            : ") ;
    scanf("%s", baru->nama);
    
    fflush(stdin);
    
	printf("[>] Alamat          : ");
    scanf("%s", baru->alamat);
    
    fflush(stdin);
    
	printf("[>] Golongan darah  : ");
    scanf("%s", baru->golongandarah);
    
	if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system ("cls");
}

void inputDatabelakang(){
    baru = (struct dataKtp*)malloc(sizeof(struct dataKtp));
    
	baru->next = NULL;
    baru->prev = NULL;
    
    fflush(stdin);
    
	printf("\n[>] Nama            : ") ;
    scanf("%s", baru->nama);
    
    fflush(stdin);
    
	printf("[>] Alamat          : ");
    scanf("%s", baru->alamat);
    
    fflush(stdin);
    
	printf("[>] Golongan darah  : ");
    scanf("%s", baru->golongandarah);
    
	if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
    system ("cls");
}

void hapusDatadepan(){
    if(awal->next == NULL){
        awal=akhir=NULL;
        printf("Data sudah kosong !");
    }else{
        hapus = awal;
        awal = awal->next;
        awal->prev = NULL;
    }
}

void outputData (){
    bantu = awal;
    
	while (bantu != NULL){
        printf("\nNama            : %s", bantu->nama);
        printf("\nAlamat          : %s", bantu->alamat);
        printf("\nGolongan darah  : %s\n\n", bantu->golongandarah);
        
		bantu = bantu->next;
    }
}

int main(){
    int pilihan;
    
	do{
        printf("\n----------DOUBLE LINKED LIST-----------\n");
        printf("\n\n[#] Pilih menu : \n");
        printf("[1]. Input data di depan\n");
        printf("[2]. Input data di belakang\n");
        printf("[3]. Hapus data di depan\n");
        printf("[4]. Output data\n") ;
        printf("[5]. Lain-lain >> EXIT\n");
        printf("\n[>] Pilihan : ");
        scanf("%d", &pilihan);
        switch (pilihan){
        case 1 :
            inputDatadepan();
            break;
        case 2 :
            inputDatabelakang();
            break;
        case 3 :
            if(awal == NULL){
            	printf("\nData masih kosong !\n");
			} else{
				hapusDatadepan();
				printf("\nData berhasil di hapus !\n");
			}
			fflush(stdin);
			getch();
            break;
        case 4 :
            if(awal == NULL){
                printf("\nData masih kosong !\n");
            	fflush(stdin);
				getch();
			}
            else {
                outputData();
			}
            break;
        default :
            printf("\n\n--------EXIT---------\n");
            printf("---God Bless You-----");
            break;
        }
    }while(pilihan <= 4);
    
    fflush(stdin);
	getch();
    
    return 0;
}
