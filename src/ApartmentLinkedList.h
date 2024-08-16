#ifndef ASS2_APARTMENTLINKEDLIST_H
#define ASS2_APARTMENTLINKEDLIST_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "FlatLinkedList.h"
using namespace std;


class ApartmentNode{
public:
    string name;
    int maxBandwidth = 0;
    int currentBandwith = 0;
    FlatLinkedList flatLinkedList;
    ApartmentNode* next;
    ApartmentNode(string name, int maxBandwith);
};


class ApartmentLinkedList {
public:
    ApartmentNode* head;
    string output = "";
    ApartmentLinkedList();
    void add_apartment(string apartmentName, string position, string maxBandwith);
    void remove_apartment(string apartmentName);
    void add_flat(string apartmentName, string index, string bandWith, string flatID);
    void make_flat_empty(string apartmentName, string flatID);
    void find_sum_of_max_bandwidth();
    void merge_two_apartments(string firstApartment, string secondApartment);
    void list_apartments();
};










#endif //ASS2_APARTMENTLINKEDLIST_H