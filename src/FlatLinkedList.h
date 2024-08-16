#ifndef ASS2_FLATLINKEDLIST_H
#define ASS2_FLATLINKEDLIST_H
#include <iostream>
using namespace std;


class FlatNode{
public:
    int id;
    int isEmpty = 0;
    FlatNode* next = nullptr;
    FlatNode* prev = nullptr;
    FlatNode(int id, int initialBandwith);
    int initialBandwith = 0;

};


class FlatLinkedList {
public:
    FlatNode* head;
    FlatNode* tail;
    FlatLinkedList();
    void add_flat(int index, int bandWith, int flatID);
    void remove_flat();
    int make_flat_empty(int flatID);
};

#endif //ASS2_FLATLINKEDLIST_H