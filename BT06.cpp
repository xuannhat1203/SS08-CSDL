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
int isBST(Node* root, int min, int max) {
    if (root == NULL) {
        return 1; 
    }

    if (root->data <= min || root->data >= max) {
        return 0;
    }
	printf("%d",max);
	printf("%d",min);
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main(){
	Node* root = NULL;
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,6);
	if (isBST(root, -100000, 100000)) {
        printf("Cay nhi phan tim kiem (BST)\n");
    } else {
        printf("Khong phai cây nhi phan tim kiem (BST)\n");
    }
}

