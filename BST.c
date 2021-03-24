#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node; 
typedef struct BST BST;  

struct Node {
    int value;  
    Node * right;
    Node * left;
};

struct BST {
    Node * root; 
};

Node * createNode(int value);
void inOrderPrint(Node * root);
void insertNode(Node * root, int value);
void printArray(int *arr, int size);
void postOrderPrint(Node * root); 

int main() {
    printf("\n"); 
    srand(time(0)); 
    int n, i, num = 10; 
    n = 20; 
    Node * root = createNode(23); 
    int *arr = calloc(n, sizeof(int)); 
    for (i = 0; i < n; i++) { 
        num = (rand() % 1000);
        arr[i] = num; 
        insertNode(root, num);  
    }
    printf("The numbers inserted into the tree: ");
    printArray(arr, n); 

    printf("\n\n");

    printf("The numbers in order = ");  
    inOrderPrint(root); 

    printf("\n\n");

    printf("The numbers in post order = ");
    postOrderPrint(root); 

    return 0; 
}

void insertNode(Node * root, int value) { 
    Node * node = createNode(value); 
    if (root == NULL) {
        root = node; 
    }
    if (root->value > value) {
        if(root->left == NULL) {
            root->left = node;
            return; 
        }
        insertNode(root->left, value); 
    } else if (root->value < value) {
        if(root->right == NULL) {
            root->right = node;
            return; 
        }
        insertNode(root->right, value); 
    } else { 
        return; 
    }

}

Node * createNode(int value) { 
    Node * ret = calloc(1, sizeof(Node)); 
    ret->value = value; 
    ret->left = NULL; 
    ret->right = NULL; 

    return ret; 
}

void inOrderPrint(Node * root) {
    //printf("inside of inOrderoprint\n"); 
    if (root == NULL) {
        return; 
    }
    inOrderPrint(root->left);
    printf("%d    ", root->value); 
    inOrderPrint(root->right); 
}

void postOrderPrint(Node * root) {
    if (root == NULL) {
        return; 
    }
    postOrderPrint(root->left); 
    postOrderPrint(root->right); 
    printf("%d ", root->value); 
}

void printArray(int *arr, int size) {
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 

}