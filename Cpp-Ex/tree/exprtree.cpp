#include "exptree.h"
#include <iostream>
using namespace std;


void initExprTreeNode(ExprTreeNode *root, char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr) {
    root->dataItem = elem;
    root->left = leftPtr;
    root->right = rightPtr;
}

void clearSub(ExprTreeNode *root) {
    if(root) {
        clearSub(root->left);
        clearSub(root->right);
        delete root;
    }
}

void clear(ExprTreeNode *root) {
    if (root) {
        root->dataItem = NULL;
        clear(root->left);
        clear(root->right);
    }
}


void initExprTree(ExprTreeNode *root) {
    root->dataItem = 0;
    root->left = NULL;
    root->right = NULL;
}


void DeExprTree(ExprTreeNode *root) {
    clearSub(root->left);
    clearSub(root->right);
    root->dataItem = 48;
    root->left = NULL;
    root->right = NULL;
    delete root;
}


void build(ExprTreeNode *root) {

    char user_input;
    cin >> user_input;

    if (user_input>='0'&&user_input<='9') {
        root->dataItem = user_input;
        root->left = NULL;
        root->right = NULL;
    } else {
        root->dataItem = user_input;
        struct ExprTreeNode *left = new ExprTreeNode;
        struct ExprTreeNode *right = new ExprTreeNode;
        root->left = left;
        root->right = right;
        build(root->left);
        build(root->right);

    }
}


void expression(ExprTreeNode *root) {
    if(root) {
        cout << "(";
        expression(root->left);
        cout << root->dataItem;
        expression(root->right);
        cout << ")";
    }
}


int evaitems[100];
int evatop = 0;
void evaSub(ExprTreeNode *root) {
    if (root) {
        evaitems[evatop] = root->dataItem;
        evatop++;
        evaSub(root->left);
        evaSub(root->right);
    }
}
float evaluate(ExprTreeNode *root) {
    evaSub(root);
    char items[100];
    float operands[100];
    int itop = 0;
    int otop = 0;
    for (int i=0; i<evatop; i++) {
        operands[otop] = float(evaitems[i]);
        otop++;
    }

    while(otop!=1) {
        for(int j=0; j<otop; j++) {
            if(operands[j]<'0'&&operands[j+1]>='0'&&operands[j+2]>='0') {

                float result;
                switch (char(operands[j])) {
                    case '+': result = operands[j+1] + operands[j+2] - 96.0; break;
                    case '-': result = operands[j+1] - operands[j+2]; break;
                    case '*': result = (operands[j+1]-48.0)*(operands[j+2]-48.0); break;
                    case '/': result = (operands[j+1]-48.0)/(operands[j+2]-48.0); break;
                }

                operands[j] = result+48;
                for(int k=j+1; k<otop-2; k++) {
                    operands[k] = operands[k+2];
                }
                otop-=2;
            }

        }
    }
    return float(operands[0]-48);
}


int copyitems[100];
int copytop = 0;
void copySub(ExprTreeNode *root) {
    if (root) {
        copyitems[copytop] = root->dataItem;
        copytop++;
        copySub(root->left);
        copySub(root->right);
    }
}
void buildcopy(ExprTreeNode *root) {
    int user_input = copyitems[0];

    for(int i=0; i<copytop-1; i++) {
        copyitems[i] = copyitems[i+1];
    }
    copytop-=1;

    if (user_input>='0'&&user_input<='9') {
        root->dataItem = char(user_input);
        root->left = NULL;
        root->right = NULL;
    } else {
        root->dataItem = char(user_input);
        struct ExprTreeNode *left = new ExprTreeNode;
        struct ExprTreeNode *right = new ExprTreeNode;
        root->left = left;
        root->right = right;
        buildcopy(root->left);
        buildcopy(root->right);

    }
}
ExprTreeNode * ExprTreeCopy(ExprTreeNode *T) {
    copySub(T);
    struct ExprTreeNode *newcopy = new struct ExprTreeNode;
    buildcopy(newcopy);
    return newcopy;
}

void commute(ExprTreeNode *root) {
    if (root) {
        struct ExprTreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        commute(root->left);
        commute(root->right);
    }
}