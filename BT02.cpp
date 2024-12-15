
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void printLevel2(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        if (root->left->left != NULL) {
            printf("%d ", root->left->left->data);
        }
        if (root->left->right != NULL) {
            printf("%d ", root->left->right->data);
        }
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) {
            printf("%d ", root->right->left->data);
        }
        if (root->right->right != NULL) {
            printf("%d ", root->right->right->data);
        }
    }
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Cac dinh o lop 2 la: ");
    printLevel2(root);
    return 0;
}
