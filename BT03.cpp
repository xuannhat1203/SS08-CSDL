#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) {
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* root, int data) {
	if(root == NULL) {
		return createNode(data);
	}
	if(data < root->data) {
		root->left = insert(root->left, data);
	} else if(data > root->data) {
		root->right = insert(root->right, data);
	}
	return root;
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

int main() {
	Node* root = NULL;
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 6);

	int data;
	printf("Nhap gia tri tim kiem: ");
	scanf("%d", &data);
	if (findData(root, data)) {
		printf("FOUND\n");
	} else {
		printf("NOT FOUND\n");
	}

	return 0;
}

