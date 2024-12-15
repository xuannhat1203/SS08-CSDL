#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* createNode(int data){
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insert(Node* root, int data){
	if(root == NULL){
		return createNode(data);
	}
	if(data < root->data){
		root->left = insert(root->left,data);
	}else if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}
void preOrder(Node* root){
	if(root != NULL){
		printf("%d \t",root->data);
		preOrder(root->left);
		preOrder(root->right);	
	}
}
void inorder(Node* root){
	if(root != NULL){
		preOrder(root->left);
		printf("%d \t",root->data);
		preOrder(root->right);	
	}
}
int findData(Node* root, int data) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == data) {
        return 1; 
    }
    return findData(root->left, data) || findData(root->right, data);
}

int main(){
	Node* root = NULL;
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,6);
	int choice;
	do{
		printf("\n----------MENU----------\n");
		printf("1. Duyet cay theo thu tu inorder\n");
		printf("2. Tim kiem gia tri trong cay\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice);
		int data;
		switch(choice){
			case 1: 
				inorder(root);
				break;
			case 2: 
				printf("Nhap gia tri tim kiem: ");
				scanf("%d", &data);
				if (findData(root, data)) {
					printf("Gia tri % d co ton tai trong cay\n",data);
				} else {
					printf("Gia tri %d khong ton tai trong cay\n",data);
				}	
				break;
			default:
				printf("Lua chon khong hop le");
				break;
		}
	}while(1==1);
}

