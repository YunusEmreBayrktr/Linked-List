#include "Network.h"
using namespace std;

int main(int argc, char* args[]) {

    Network network = Network(args[1], args[2]);
    network.create_network();

    return 0;
}