#include <iostream>
#include <string>
using namespace std;
template <typename T>
class node {
public: T data;
		node<T>* next,*head;
};
template <typename T>
class linklist {
private: node<T> *header, *tailer;
     public:
		 linklist():header(nullptr), tailer(nullptr) {};
	 void add() {
		 T indata;
		 node<T>* current = new node<T>();
		 cin >> indata;
		 current->data = indata;
		 if (header == nullptr&&tailer == nullptr)//if it is the first input, set head and tail both equial to current node
		 {
			 header = current;
			 tailer = current;
		 }
		 else {
			 tailer->next = current;
			 current->head = tailer;
			 tailer = current;
		 }
	};
	 void showall() {
		 node<T>*current=header;
		 while (current!=tailer) {
			 cout << current->data << endl;
			 current = current->next;
		 }
		 cout << current->data << endl;
	 }
};