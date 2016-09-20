#ifndef BTREE_H
#define BTREE_H
#include "btreenode.h"
class BTree
{
    BTreeNode *root;
    int range;
public:
    BTree(int degree){root = 0; range = degree;}
    BTreeNode* buscar(int key){
        if(root == 0)
            return 0;
        else
            return root->buscar(key);
    }
    void insertar(int key);
};
#endif // BTREE_H
