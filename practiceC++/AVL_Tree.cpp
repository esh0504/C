#include<stdio.h>
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
void insertBST(Tree* T, int newKey);
int height(Node* n);
int noNodes(Node* n);
Node* search(Node* n, int key, Node* p, Node*& q);
void deleteBST(Tree* T, int deleteKey);
Node* maxNode(Node* n);
Node* minNode(Node* n);
int updateBF(Tree* T);
void rotateLL(Node* x);
void rotateLR(Node* x);
void rotateRR(Node* x);
void rotateRL(Node* x);

void inorderAVL(Tree T);
Node* getNode() {
    Node* newNode = new Node();
    return newNode;
}

void insertBST(Tree* T, int newKey) {
    Node* p; Node* q;
    Node* newNode;
    p = *T;
    if (p != NULL) {
        if (p->key == newKey) {
            return;
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
    }
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

Node* search(Node* n, int key, Node* p, Node*& q) {
    while (p != NULL) {
        if (p->key == key) {
            return p;
        }
        else if (p->key > key) {
            q = p; p = p->left;
        }
        else {
            q = p; p = p->right;
        }
    }
    return NULL;
}
void deleteBST(Tree* T,int deleteKey) {
    Node* p, * q, * r;
    bool flag = false;
    p = *T;
    q = NULL;
    p = search(*T, deleteKey, p, q);
    if (p == NULL) {
        return;
    }if (p->left == NULL && p->right == NULL) {
        if (q != NULL) {
            if (q->left == p) {
                q->left = NULL;
            }
            else {
                q->right = NULL;
            }
        }
        else {
            *T = NULL;
        }
    }
    else if (p->left == NULL || p->right == NULL) {
        if (q != NULL) {
            if (p->left != NULL) {
                if (q->left == p) {
                    q->left = p->left;
                }
                else {
                    q->right = p->left;
                }
            }
            else {
                if (q->left == p) {
                    q->left = p->right;
                }
                else {
                    q->right = p->right;
                }
            }
        }
        else {
            if (p->left != NULL) {
                *T = p->left;
            }
            else {
                *T = p->right;
            }
        }
    }
    else {
        if (height(p->left) > height(p->right)) {
            r = maxNode(p->left);
            flag = false;
        }
        else if (height(p->left) < height(p->right)) {
            r = minNode(p->right);
            flag = true;
        }
        else{
            if (noNodes(p->left) >= noNodes(p->right)) {
                r = maxNode(p->left);
                flag = false;
            }
            else {
                r = minNode(p->right);
                flag = true;
            }
        }
        p->key = r->key;
        if (!flag) {
            deleteBST(&p->left, r->key);
        }
        else {
            deleteBST(&p->right, r->key);
        }
    }
}

Node* maxNode(Node* n) {
    if (n->right == NULL) return n;
    return maxNode(n->right);
}

Node* minNode(Node* n) {
    if (n->left == NULL) return n;
    return minNode(n->left);
}


Node* updateBF(Tree* T,Node* y) {
    
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
        updateBF(T,p->left);
        updateBF(T,p->right);
    }
}

void rotateLL(Node* x) {
    Node* child = x->left;
    x->left = child->right;
    child->right = x;
    return;
}

void rotateRR(Node* x) {
    Node* child = x->right;
    x->right = child->left;
    child->left = x;
    return;
}

void rotateLR(Node* x) {
    Node* child = x->left;
    rotateRR(child);
    return rotateLL(x);
}

void rotateRL(Node* x) {
    Node* child = x->right;
    rotateLL(child);
    return rotateRR(x);
}

rotationType insertAVL(Tree* T, int newKey) {
    insertBST(T, newKey);
    Node* p = updateBF(T, *T);
    if (p == nullptr) {
        return NO;
    }
    if (p->bf == 2) {
        if (height(p->left) - height(p->right) == 2) {
            return LL;
        }
        else {
            return LR;
        }
    }
    else if (p->bf == -2) {
        if (height(p->left) - height(p->right) == -2) {
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
    deleteBST(T, deleteKey);
    Node* p = updateBF(T, *T);
    if (p == nullptr) {
        return NO;
    }
    if (p->bf == 2) {
        if (height(p->left) - height(p->right) == 2) {
            return LL;
        }
        else {
            return LR;
        }
    }
    else if (p->bf == -2) {
        if (height(p->left) - height(p->right) == -2) {
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