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
int preOrder(Node* root){
	if (root == NULL) {
        return 0;
    }
    int leftHeight = preOrder(root->left); 
    int rightHeight = preOrder(root->right); 
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int main(){
	Node* root = NULL;
	root = insert(root,1);
	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,5);
	printf("chieu cao cua cay: %d",preOrder(root));
}

