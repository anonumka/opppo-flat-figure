#include "list.h"
#include "mainprocess.h"

List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List() {
    deleteList();
}

void List::addList(FlatGeometryFig* new_obj) {
    Node *tmp = new Node;
    tmp->next = head;
    tmp->fig = new_obj;

    if (head != nullptr) {
        tail->next = tmp;
        tail = tmp;
    }
    else {
        head = tmp;
        tail = tmp;
    }
    size++;
}

void List::deleteElem(int i) {
    if (size <= i) {
        throw std::out_of_range("Out of range");
    }

    if (i == 0) {
        head = head->next;
        size--;
        return;
    }

    int tmp_size = 0;
    Node *tmp_elem = head;
    while (tmp_size != i - 1) {
        tmp_elem = tmp_elem->next;
        tmp_size++;
    }

    if (tmp_size + 2 < size) {
        Node *tmp_node = tmp_elem->next;
        tmp_elem->next = tmp_elem->next->next;
        delete tmp_node;
    }
    else {
        Node *tmp_node = tmp_elem->next;
        tmp_elem->next = head;
        delete tmp_node;
    }
    size--;

    return;
}

void List::deleteList() {
    while (size != 0) {
        Node *tmp_head = head->next;
        delete head;
        head = tmp_head;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}

int List::printList() {
    Node *tmp_head = head;
    int tmp_size = size;

    if (tmp_size == 0) {
        return static_cast<int>(ERROR_TYPE::LIST_EMPTY);
    }

    while (tmp_size != 0) {
        tmp_head->fig->print();
        tmp_head = tmp_head->next;
        tmp_size--;
    }

    return static_cast<int>(ERROR_TYPE::OK);
}

FlatGeometryFig* List::getElem(int ind) {
    FlatGeometryFig* obj = nullptr;

    Node *tmp_elem = head;
    for (int i = 0; i < ind; i++) {
        tmp_elem = tmp_elem->next;
    }

    obj = tmp_elem->fig;
    return obj;
}

Node* List::getNode(int ind) {
    FlatGeometryFig* obj = nullptr;

    Node *tmp_elem = head;
    for (int i = 0; i < ind; i++) {
        tmp_elem = tmp_elem->next;
    }

    return tmp_elem;
}

int List::getSize() {
    return size;
}
