#include <iostream>
#include "FlatLinkedList.h"

FlatNode::FlatNode(int id, int initialBandwith) {
    this->id = id;
    this->initialBandwith = initialBandwith;
}

FlatLinkedList::FlatLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void FlatLinkedList::add_flat(int index, int bandWith, int flatID) {
    FlatNode *newFlat;
    newFlat = new FlatNode(flatID, bandWith);
    if(this->head != nullptr) {
        FlatNode* current = this->head;
        FlatNode* previous ;

        if(index == 0){
            newFlat->next = current;
            newFlat->prev = current->prev;
            current->prev = newFlat;
            this->head = newFlat;
            return;
        }
        else{
            int pos = 0;
            while(pos < index){
                previous = current;
                current = current->next;
                if(current == nullptr)
                    break;
                pos++;
            }
            if(current == nullptr){
                newFlat->next = current;
                newFlat->prev = previous;
                previous->next = newFlat;
                this->tail = newFlat;
            }
            else{
                newFlat->next = current;
                newFlat->prev = previous;
                current->prev = newFlat;
                previous->next = newFlat;
            }
        }
    }
    else{
        this->head = newFlat;
        this->tail = newFlat;
    }
}

void FlatLinkedList::remove_flat() {

    FlatNode* flat = this->head;

    if(flat != nullptr){
        while (flat->next != nullptr){
            flat = flat->next;
            delete this->head;
            this->head = flat;
        }
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
}

int FlatLinkedList::make_flat_empty(int flatID) {

    FlatNode* flat = this->head;
    while (flat->id != flatID){
        flat = flat->next;
    }
    int band = flat->initialBandwith;
    flat->isEmpty = 1;
    flat->initialBandwith = 0;

    return band;
}