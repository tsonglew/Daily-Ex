#include "logitree.h"
#include "exptree.h"
#include <iostream>


int logiitems[100];
int logitop = 0;
void logiSub(ExprTreeNode *root) {
    if (root) {
        logiitems[logitop] = root->dataItem;
        logitop++;
        logiSub(root->left);
        logiSub(root->right);
    }
}
int evaluatelogitree(ExprTreeNode *root) {
    logiSub(root);
    char items[100];
    int operands[100];
    int itop = 0;
    int otop = 0;
    for (int i=0; i<logitop; i++) {
        operands[otop] = int(logiitems[i]);
        otop++;
    }

    while(otop!=1) {
        for(int j=0; j<otop; j++) {
            if(operands[j]<'0'&&operands[j+1]>='0'&&operands[j+2]>='0') {

                int result;
                switch (char(operands[j])) {
                    case '+': result = (operands[j+1]-48 | operands[j+2]-48); break;
                    case '-': result = (1^(operands[j+2]-48)); break;
                    case '*': result = (operands[j+1]-48)&(operands[j+2]-48); break;
                }

                operands[j] = result+48;
                for(int k=j+1; k<otop-2; k++) {
                    operands[k] = operands[k+2];
                }
                otop-=2;
            }

        }
    }
    return int(operands[0]-48);
}
