#include<stdio.h>
#include<iostream>

using namespace std;


typedef struct Node {
    int key, bf;
    struct Node* left, * right;
}Node;

typedef Node* Tree;

Node* getNode() {
    Node* newNode = new Node();
    return newNode;
}

void insertBST(Tree* T, int newKey) {
    Node* newNode = getNode();
    newNode->key = newKey;
    if (T == NULL) {
        *T = newNode;
        return;
    }
    Node* getNode = *T;
    if (newKey < getNode->key) {
        insertBST(&getNode->left, newKey);
    }
    else {
        insertBST(&getNode->right, newKey);
    }
    return;
}
​

void deleteBST(Tree* T, int deleteKey) {

}

Node* updateBF(Tree* T, Node* y) {
    /* write your code here */

}
​
void rotateLL(Node* x) {
    Node* child = x->left;
    x->left = child->right;
    child->right = x;
    return child;
}
​
void rotateRR(Node* x) {
    /* write your code here */
    Node* child = x->right;
    x->right = child->left;
    child->left = x;
    return child;
}
​
void rotateLR(Node* x) {
    /* write your code here */
    Node* child = x->left;
    x->left = rotateRR(child);
    return rotateLL(x);
}

void rotateRL(Node* x) {
    Node* child = x->right;
    x->right = rotateLL(child);
    return rotateRR(parent);
}

rotationType insertAVL(Tree* T, int newKey) {
    /* write your code here */
}
​
rotationType deleteAVL(Tree* T, int deleteKey) {
    /* write your code here */
}
​
void inorderAVL(Tree T) {
    /* write your code here */
}

int main() {
    /* do not modify the code below */
    ​
    int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };
    ​
    const char* rotationTypes[] = { "LL", "RR", "LR", "RL" };
    ​
    Tree T = NULL;
    ​
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[insertAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
    ​
    // deletion
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[deleteAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }

    T = NULL;
    ​
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[insertAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
    ​
    // redeletion
    for (int i = 19; 0 <= i; i--) { printf("%d %s : ", testcase[i], rotationTypes[deleteAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
}