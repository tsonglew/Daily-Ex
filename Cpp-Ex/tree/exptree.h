#ifndef TREE_EXPTREE_H
#define TREE_EXPTREE_H
struct ExprTreeNode {
    char dataItem;
    struct ExprTreeNode *left, *right;
};

void initExprTreeNode (ExprTreeNode *root, char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr);
void initExprTree(ExprTreeNode *root);
void DeExprTree(ExprTreeNode *root);
void build(ExprTreeNode *root);
void expression(ExprTreeNode *root);
float evaluate(ExprTreeNode *root);
void clear(ExprTreeNode *root);
void showStructure(ExprTreeNode *root);
void showSub(ExprTreeNode *root);
void evaSub(ExprTreeNode *root);
ExprTreeNode * ExprTreeCopy(ExprTreeNode *T);
void commute(ExprTreeNode *root);
#endif //TREE_EXPTREE_H
