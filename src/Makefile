output: main.o ApartmentLinkedList.o FlatLinkedList.o Network.o
	g++ -std=c++11 main.o ApartmentLinkedList.o FlatLinkedList.o Network.o -o networkmap 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ApartmentLinkedList.o: ApartmentLinkedList.cpp ApartmentLinkedList.h
	g++ -std=c++11 -c ApartmentLinkedList.cpp ApartmentLinkedList.h

FlatLinkedList.o: FlatLinkedList.cpp FlatLinkedList.h
	g++ -std=c++11 -c FlatLinkedList.cpp FlatLinkedList.h

Network.o: Network.cpp Network.h
	g++ -std=c++11 -c Network.cpp Network.h

clean:
	rm *.o