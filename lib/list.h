#ifndef LIST_H
#define LIST_H

#include "geometrys.h"

struct Node {
    FlatGeometryFig* fig;
    Node *next;
};

class List {
private:
    Node *head, *tail;
    int size;
public:
    List();
    ~List();

    void addList(FlatGeometryFig* new_obj);
    FlatGeometryFig *getElem(int ind);
    Node *getNode(int ind);
    int getSize();
    void deleteElem(int i);
    void deleteList();
    int printList();
};

#endif // LIST_H
