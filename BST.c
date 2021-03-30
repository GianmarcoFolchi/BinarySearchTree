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
Node * insertNode(Node * root, int value);
int sumOfTree(Node * root);
void inOrderPrint(Node * root);
void printArray(int *arr, int size);
void postOrderPrint(Node * root); 

int main() {
    printf("\n"); 
    srand(time(0)); 
    int n, i, num = 10, sum; 
    n = 20; 
    Node * root = NULL; 
    int *arr = calloc(n, sizeof(int)); 
    for (i = 0; i < n; i++) { 
        num = (rand() % 1000);
        sum += num; 
        arr[i] = num; 
        root = insertNode(root, num);  
    }
    printf("The numbers inserted into the tree: ");
    printArray(arr, n); 
    printf("\n\n");
    printf("The numbers in order = ");  
    inOrderPrint(root); 
    printf("\n\n");
    printf("The numbers in post order = ");
    postOrderPrint(root); 
    printf("\n\n");
    printf("The sum of the values = %d \n", sumOfTree(root)); 

    return 0; 
}

Node * insertNode(Node * root, int value) { 
    Node * node = createNode(value); 
    if (root == NULL) {
        return node;
    }
    if (node->value == root->value) {
        return root; 
    } 
    if (node->value > root->value) {
        root->right = insertNode(root->right, value); 
    } else { 
        root->left = insertNode(root->left, value); 
    }
    return root; 
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
    printf("%d ", root->value); 
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

int sumOfTree(Node * root) {
    if (root == NULL)
        return 0; 
    int sum = root->value + sumOfTree(root->left) + sumOfTree(root->right); 
    return sum; 
}