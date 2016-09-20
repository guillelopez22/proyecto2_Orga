#include "btree.h"
#include "btreenode.h"


void BTree::insertar(int key){
    if(root == 0){
        root = new BTreeNode(range, true);
        root->keys[0] = key;
        root->current_keynum;
    }else{
        if(root->current_keynum == 2*range - 1){
            BTreeNode *newRoot = new BTreeNode(range, false);
            newRoot->hijos[0] == root;
            newRoot->partirNodo(0,root);
            int pos = 0;
            if(newRoot->keys[0] < key)
                pos++;
            newRoot->hijos[pos]->insertar(key);
            root = newRoot;
        }else{
            root->insertar(key);
        }
    }
}
