#ifndef BTREENODE_H
#define BTREENODE_H

class BTreeNode
{
    int *keys;
    int range; //rango de las keys
    BTreeNode **hijos;
    int current_keynum;
    bool isleaf;
public:
    BTreeNode(int rango, bool hoja);
    void insertar(int llave); // asume que el nivel no esta lleno
    void partirNodo(int index, BTreeNode *hijo);
    BTreeNode *buscar(int llave);
    friend class BTree;
};

#endif // BTREENODE_H
