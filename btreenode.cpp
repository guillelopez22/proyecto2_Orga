#include "btreenode.h"
#include "btree.h"
using namespace std;
BTreeNode::BTreeNode(int rango, bool leaf){
    range = rango;
    isleaf = leaf;
    keys = new int[2*range - 1];
    hijos = new BTreeNode *[2*range];
    current_keynum = 0;
}
 BTreeNode *BTreeNode::buscar(int llave){
     int busqueda = 0;
     while(busqueda < current_keynum && llave > keys[busqueda])
         busqueda++;
     if(keys[busqueda] == llave)
         return this;
     if(isleaf == true)
         return 0;
 }
 void BTreeNode::insertar(int llave){
     int index = current_keynum-1;
     if(isleaf == true){
         while(index >= 0 && keys[index] > llave){
             keys[index +1] = keys[index];
             index--;
         }
         keys[index +1] = llave;
         current_keynum = current_keynum +1;
     }else{
         while(index >=0 && keys[index] > llave){
             index--;
         }
         if(hijos[index+1]->current_keynum == 2*range-1){
             partirNodo(index+1, hijos[index+1]);
             if(keys[index+1] < llave)
                 index++;
         }
         hijos[index+1]->insertar(llave);
     }
 }
 void BTreeNode::partirNodo(int index, BTreeNode *hijo){
     BTreeNode *temp = new BTreeNode(hijo->range, hijo->isleaf);
     temp->current_keynum = range -1;
     for(int i = 0; i < range -1;i++)
         temp->keys[i] = hijo->keys[i+range];
     if(hijo->isleaf == false){
         for(int j = 0; j < range; j++)
             temp->hijos[j] = hijo->hijos[j+range];
     }
     hijo->current_keynum = range-1;//reduce el numero de llaves en hijo
     for(int i = current_keynum; i >= index+1; i--)
         hijos[i+1] = hijos[i];
     hijos[index+1] = temp;
     for(int j = current_keynum-1; j>= index; j--)
         keys[j+index] = keys[j];
     keys[index] = hijo->keys[range-1];
     current_keynum = current_keynum+1;
 }
