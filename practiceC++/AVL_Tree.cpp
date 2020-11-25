#include<stdio.h>
#include <tuple>
#include<iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

typedef struct Node {
    int key, bf;
    struct Node* left, * right;
}Node;
typedef Node* Tree;
typedef enum { LL, RR, LR, RL ,NO} rotationType;

Node* getNode();
Node* insertBST(Tree* T, int newKey);
int height(Node* n);
int noNodes(Node* n);
Node* search(Node* n, int key, Node* p, Node*& q);
Node* deleteBST(Tree* T, int deleteKey);
Node* maxNode(Node* n);
Node* minNode(Node* n);
Node* updateBF(Tree* T, Node* y, Node** x, Node** P);
void rotateLL(Tree* T, Node* x, Node* P);
void rotateLR(Tree* T, Node* x, Node* P);
void rotateRR(Tree* T, Node* x, Node* P);
void rotateRL(Tree* T, Node* x, Node* P);
tuple<Node*,Node*> searchNear(Tree* T, int newKey);
void inorderAVL(Tree T);

Node* getNode() {
    Node* newNode = new Node();
    return newNode;
}

Node* insertBST(Tree* T, int newKey) {
    Node* p; Node* q;
    Node* newNode;
    p = *T;
    if (p != NULL) {
        if (p->key == newKey) {
            return p;
        }
        q = p;
        if (p->key > newKey) {
            insertBST(&p->left, newKey);
        }
        else {
            insertBST(&p->right, newKey);
        }
    }
    else {
        newNode = getNode();
        newNode->key = newKey;
        *T = newNode;
        return *T;
    }
}

Node* searchParentNode(Tree* T, Node* n) {
    Node* tmp = *T;
    Node* P = tmp;
    while (tmp!=NULL){
        if (tmp->key > n->key) {
            P = tmp;
            tmp = tmp->right;
        }
        else if (tmp->key < n->key) {
            P = tmp;
            tmp = tmp->left;
        }
        else {
            return P;
        }
    }
    return P;
}

int height(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    int leftHeight = height(n->left) + 1;
    int rightHeight = height(n->right) + 1;
    return MAX(leftHeight, rightHeight);
}

int noNodes(Node* n) {
    if (n == NULL) return 0;
    return noNodes(n->left) + noNodes(n->right) + 1;
}

Node* deleteBST(Tree* T,int deleteKey) {
    Node* parent, * q;
    parent = *T;
    q = NULL;
    while (parent != NULL && parent->key!=deleteKey) {
        if (parent->key > deleteKey) {
            q = parent;
            parent = parent->left;
        }
        else {
            q = parent;
            parent = parent->right;
        }
    }
    if (parent == NULL) {
        return parent;
    }if (parent->left == NULL && parent->right == NULL) {
        if (q != NULL) {
            if (q->left == parent) {
                q->left = NULL;
            }
            else {
                q->right = NULL;
            }
        }
        else {
            *T = NULL;
        }
    }else if (parent->left == NULL || parent->right == NULL) {
        if (q != NULL) {
            if (parent->left != NULL) {
                if (q->left == parent) {
                    q->left = parent->left;
                }
                else {
                    q->right = parent->left;
                }
            }
            else {
                if (q->left == parent) {
                    q->left = parent->right;
                }
                else {
                    q->right = parent->right;
                }
            }
        }else {
            if (parent->left != NULL) {
                *T = parent->left;
            }
            else {
                *T = parent->right;
            }
        }
    }else {
        bool flag = false;
        Node* changeNode;
        if (height(parent->left) > height(parent->right)) {
            changeNode = maxNode(parent->left);
        }
        else if (height(parent->left) < height(parent->right)) {
            flag = true;
            changeNode = minNode(parent->right);
        }
        else{
            if (noNodes(parent->left) >= noNodes(parent->right)) {
                changeNode = maxNode(parent->left);
            }
            else {
                flag = true;
                changeNode = minNode(parent->right);
            }
        }
        parent->key = changeNode->key;
        if (!flag) {
            deleteBST(&parent->left, changeNode->key);
        }
        else {
            deleteBST(&parent->right, changeNode->key);
        }
        
    }
    return parent;
}

Node* maxNode(Node* n) {
    if (n->right == NULL) return n;
    return maxNode(n->right);
}

Node* minNode(Node* n) {
    if (n->left == NULL) return n;
    return minNode(n->left);
}


Node* updateBF(Tree* T, Node* y, Node** x, Node** P) {
    Node* p = y;
    if (p == nullptr) {
        return p;
    }
    if (p->right == NULL && p->left == NULL) {
        p->bf = 0;
    }
    else if (p->left == NULL) {
        p->bf = -height(p->right);
    }
    else if(p->right==NULL){
        p->bf = height(p->left);
    }
    else {
        p->bf = height(p->left) - height(p->right);
    }
    if (p->bf == 2 || p->bf==-2) {
        return p;
    }
    else {
        updateBF(T,p->left,x,P);
        updateBF(T,p->right,x,P);
    }
}

void rotateLL(Tree* T, Node* x, Node* P) {
    P->left = x->right;
    x->right = P;
    return;
}

void rotateRR(Tree* T, Node* x, Node* P) {
    P->right = x->left;
    x->left = P;
    return;
}

void rotateLR(Tree* T, Node* x, Node* P) {
    rotateRR(T, x->right, x);
    return rotateLL(T,x,P);
}

void rotateRL(Tree* T, Node* x, Node* P) {
    rotateLL(T,x->left,x);
    return rotateRR(T,x,P);
}

rotationType insertAVL(Tree* T, int newKey) {
    Node* n=insertBST(T, newKey);
    Node* p=searchParentNode(T, n);
    Node* q = updateBF(T, n, &n,&p);
    if (p == nullptr) {
        return NO;
    }
    if (p->bf == 2) {
        if (p->left->key>newKey) {
            return LL;
        }
        else {
            return LR;
        }
    }
    else if (p->bf == -2) {
        if (p->right->key<newKey) {
            return RR;
        }
        else {
            return RL;
        }
    }
    else {
        return NO;
    }
    
}

rotationType deleteAVL(Tree* T, int deleteKey) {
    Node* n=deleteBST(T, deleteKey);
    Node* P = searchParentNode(T, n);
    Node* p = updateBF(T, *T,&n,&P);
    if (p == nullptr) {
        return NO;
    }
    if (p->bf == 2) {
        if (p->left->bf < 0) {
            return LR;
        }
        return LL;
    }
    else if (p->bf == -2) {
        if (p->right->bf > 0) {
            return RL;
        }
        return RR;
    }
    else {
        return NO;
    }
}

void inorderAVL(Tree T) {
    if (T != NULL)
    {
        inorderAVL(T->left);
        cout << T->key << " ";
        inorderAVL(T->right);
    }
}

int main() {
    int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };
    const char* rotationTypes[] = { "LL", "RR", "LR", "RL","NO"};
    Tree T = NULL;
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[insertAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[deleteAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }

    T = NULL;
    for (int i = 0; i < 20; i++) { printf("%d %s : ", testcase[i], rotationTypes[insertAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
    for (int i = 19; 0 <= i; i--) { printf("%d %s : ", testcase[i], rotationTypes[deleteAVL(&T, testcase[i])]); inorderAVL(T); printf("\n"); }
}