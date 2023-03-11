#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int nomor;
	char nama[30];
	struct node *left;
	struct node *right;
};

typedef struct node* mynode;

mynode create_node (char nama[30], int nomor){
	mynode new_node = (mynode)malloc(sizeof(struct node));
	strcpy(new_node->nama, nama);
	new_node->nomor=nomor;
	new_node->left=NULL;
	new_node->right=NULL;
	
	return(new_node);
}


mynode insert(struct node* root, char nama[30], int nomor){
	if (root==NULL){
		root = create_node(nama, nomor);
	} else {
		int is_left = 0;
		mynode cursor = root;
		mynode prev = NULL;
		
		while (cursor!=NULL){
			prev = cursor;
			if (nomor<cursor->nomor){
				is_left = 1;
				cursor = cursor->left;
			} else if (nomor> cursor->nomor){
				is_left = 0;
				cursor = cursor->right;
			}
		}
		
		if (is_left==1){
			prev->left = create_node(nama, nomor);
		} else {
			prev->right = create_node(nama, nomor);
		}
		
		return root;
	}
	

};

 void displayPre(struct node *node){
 	if(node==NULL)
 		return;
 	
 	printf("Nomor Absen : %d, Nama Mahasiswa : %s\n", node->nomor, node->nama);
 	displayPre(node->left);
 	displayPre(node->right);
 	
	}

void displayIn(struct node *node){
	if(node==NULL)
		return;
	
	displayIn(node->left);
	printf("Nomor Absen : %d, Nama Mahasiswa : %s\n", node->nomor, node->nama);
	displayIn(node->right);
	
	return(node);
}
	
	void displayPost(struct node *node){
		if(node==NULL)
			return;
		
		displayPost(node->left);
		displayPost(node->right);
		printf("Nomor Absen : %d, Nama Mahasiswa : %s\n", node->nomor, node->nama);
		return(node);
	}
	
	void search_node(struct node* root, int nomor){
		mynode cursor = root;
		
		while (cursor->nomor != nomor){
			if(cursor!=NULL){
				if(nomor>cursor->nomor){
					cursor=cursor->right;
				} else {
					cursor = cursor->left;
				}
				
				if (cursor==NULL){
					printf("\nNode %d tidak ditemukan", nomor);
				}
			}
		}
		printf("\nNode %d ditemukan\n", nomor);
		return;
	}
	
	
	mynode delete_node(struct node* root, int nomor){
		if (root==NULL)
		return;
		
		mynode cursor;
		if(nomor>root->nomor)
			root->right=delete_node(root->right, nomor);
		else if(nomor<root->nomor){
			root->left = delete_node(root->left, nomor);
		} else {
			if(root->left==NULL){
				cursor=root->right;
				free(root);
				root = cursor;
			} else if(root->right == NULL){
				cursor = root->left;
				free(root);
				root = cursor;
			} else {
				cursor = root->right;
				while(cursor->left!=NULL){
					cursor = cursor->left;
				}
				root->nomor = cursor->nomor;
				root->right = delete_node(root->right, cursor->nomor);
			}
		}
		
		return root;
	}
	int main() {
		mynode root = NULL;
		root = insert(root, "Ani", 3);
		root = insert(root, "Beta", 1);
		root = insert(root, "Caca", 5);
		
		
		
		displayIn(root);
		delete_node(root,3);
		printf("\n");
		displayIn(root);
		
		
		return 0;
	}
	













