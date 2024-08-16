#include <iostream>
#include <string>
#include "ApartmentLinkedList.h"
using namespace std;


ApartmentNode::ApartmentNode(string name, int maxBandwith) {
    this->name = name;
    this->maxBandwidth = maxBandwith;
}


ApartmentLinkedList::ApartmentLinkedList() {
    this->head = nullptr;
}

void ApartmentLinkedList::add_apartment(string apartmentName, string position, string maxBandwith) {

    int max = stoi(maxBandwith);
    ApartmentNode* newApartment;
    newApartment = new ApartmentNode(std::move(apartmentName), max);

    if (position == "head") {
        this->head = newApartment;
        newApartment->next = this->head;
    }
    else{
        string temp = position.substr(0, position.find('_'));
        position.erase(0,position.find('_') + 1);

        if(temp == "before"){
            ApartmentNode* apartment = this->head;
            while (apartment->next->name != position){
                apartment = apartment->next;
            }
            if(apartment->next == this->head){
                newApartment->next = apartment;
                apartment->next = newApartment;
                this->head = newApartment;
            }
            else{
                newApartment->next = apartment->next;
                apartment->next = newApartment;
            }
        }
        else if (temp == "after"){
            ApartmentNode* apartment = this->head;
            while (apartment->name != position){
                apartment = apartment->next;
            }
                newApartment->next = apartment->next;
                apartment->next = newApartment;
        }
    }
}

void ApartmentLinkedList::remove_apartment(string apartmentName) {

    ApartmentNode* apartment = this->head;
    ApartmentNode* prevApartment;

    if(apartment != nullptr){
        //Finding given apartment node
        do{
            prevApartment = apartment;
            apartment = apartment->next;
        }
        while (apartment->name != apartmentName);

        //Deleting all flat nodes of given apartment
        apartment->flatLinkedList.remove_flat();
        //Deleting given apartment
        prevApartment->next = apartment->next;
        if(this->head == apartment){
            this->head = apartment->next;
        }
        delete apartment;
    }
    else{
        cout << "No apartments";
    }
}

void ApartmentLinkedList::add_flat(string apartmentName, string index, string bandWith, string flatID) {
    //Finding given apartment node
    ApartmentNode* apartment = this->head;
    while (apartment->name != apartmentName){
        apartment = apartment->next;
    }

    int i = stoi(index);
    int band = stoi(bandWith);
    int ID = stoi(flatID);
    if(apartment->currentBandwith + band > apartment->maxBandwidth){
        band = apartment->maxBandwidth - apartment->currentBandwith;
    }
    //Adding flat to the flat linked list of the apartment

    apartment->flatLinkedList.add_flat(i, band, ID);
    //cout << apartment->flatLinkedList.head->initialBandwith;
    apartment->currentBandwith += band;
}

void ApartmentLinkedList::make_flat_empty(string apartmentName, string flatID) {
    //Finding given apartment node
    ApartmentNode* apartment = this->head;
    while (apartment->name != apartmentName){
        apartment = apartment->next;
    }
    int ID = stoi(flatID);

    int band = apartment->flatLinkedList.make_flat_empty(ID);
    apartment->currentBandwith -= band;
}

void ApartmentLinkedList::find_sum_of_max_bandwidth() {
    int sum = 0;

    ApartmentNode* apartment = this->head;
    do{
        sum += apartment->maxBandwidth;
        apartment = apartment->next;
    }while (apartment != this->head);

    to_string(sum);
    this->output += "sum of bandwidth: ";
    this->output += to_string(sum);
    this->output += "\n\n";
}

void ApartmentLinkedList::merge_two_apartments(string first, string second) {
    ApartmentNode* firstApartment;
    ApartmentNode* secondApartment;
    ApartmentNode* temp = this->head;

    do{
        if(temp->name == first){
            firstApartment = temp;
        }
        else if(temp->name == second){
            secondApartment = temp;
        }
        temp = temp->next;
    }while (temp != this->head);

    FlatNode* firstFlat = firstApartment->flatLinkedList.head;
    FlatNode* secondFlat = secondApartment->flatLinkedList.head;

    if(firstFlat == nullptr){
        firstApartment->flatLinkedList.head = secondFlat;
    }
    else if(secondFlat == nullptr){
    }
    else{
        while (firstFlat->next != nullptr){
            firstFlat = firstFlat->next;
        }
        firstFlat->next = secondFlat;
        secondFlat->prev = firstFlat;
    }

    while (firstFlat->next != nullptr){
        firstFlat = firstFlat->next;
    }
    firstApartment->flatLinkedList.tail = firstFlat;
    firstApartment->maxBandwidth += secondApartment->maxBandwidth;
    secondApartment->flatLinkedList.head = nullptr;

    remove_apartment(secondApartment->name);
}

void ApartmentLinkedList::list_apartments() {
    ApartmentNode* apartment = this->head;

    do{
        this->output += apartment->name;
        this->output += "(";
        this->output += to_string(apartment->maxBandwidth);
        this->output += ")\t";
        FlatNode* flat = apartment->flatLinkedList.head;

        do{
            if(flat != nullptr){
                this->output += "Flat";
                this->output += to_string(flat->id);
                this->output += "(";
                this->output += to_string(flat->initialBandwith);
                this->output += ")\t";
                flat = flat->next;
            }
        }while (flat != nullptr);
        this->output += "\n";
        apartment = apartment->next;
    }while(apartment != this->head);
    this->output += "\n";
}