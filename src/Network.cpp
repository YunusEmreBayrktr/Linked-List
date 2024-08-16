#include "Network.h"

Network::Network(string input, string output) {
    this->input = input;
    this->output = output;
}

void Network::create_network() {

    fstream file;
    file.open(this->input, ios::in);
    string line;
    ApartmentLinkedList street = ApartmentLinkedList();

    while (std::getline(file, line)) {
        vector<string> text = split(line, '\t');


        if(text[0] == "add_apartment"){
            street.add_apartment(text[1], text[2], text[3]);

        }
        else if(text[0] == "add_flat"){
            street.add_flat(text[1], text[2], text[3], text[4]);

        }
        else if(text[0] == "remove_apartment"){
            street.remove_apartment(text[1]);

        }
        else if(text[0] == "merge_two_apartments"){
            street.merge_two_apartments(text[1], text[2]);

        }
        else if(text[0] == "find_sum_of_max_bandwidths"){
            street.find_sum_of_max_bandwidth();

        }
        else if(text[0] == "list_apartments"){
            street.list_apartments();

        }
        else if(text[0] == "make_flat_empty"){
            street.make_flat_empty(text[1], text[2]);

        }
        else if(text[0] == "relocate_flats_to_same_apartment"){

        }
    }
    file.close();

    fstream out;
    out.open(this->output, ios::out);
    out << street.output;
    out.close();
}

vector<string> Network::split(const string &text, char sep) {

    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(text.substr(start, end - start));
        }
        start = end + 1;
    }
    if (end != start) {
        tokens.push_back(text.substr(start));
    }
    return tokens;
}