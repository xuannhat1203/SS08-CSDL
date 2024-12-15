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
void postoder(Node* root){
	if(root != NULL){
		printf("%d \t",root->data);
		preOrder(root->left);
		preOrder(root->right);	
	}
}
int main(){
	Node* root = NULL;
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,6);
	preOrder(root);
	inorder(root);
	postoder(root);
}

