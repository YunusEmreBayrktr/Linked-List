#ifndef ASS2_NETWORK_H
#define ASS2_NETWORK_H
#include <iostream>
#include <fstream>
#include <vector>
#include "ApartmentLinkedList.h"
#include "FlatLinkedList.h"


class Network {
public:
    string input;
    string output;
    Network(string input, string output);
    void create_network();
    vector<string> split(const string &text, char sep);
    vector<int> make_list(string str);
};


#endif //ASS2_NETWORK_H
