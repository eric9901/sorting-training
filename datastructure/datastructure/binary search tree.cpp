#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int data;
	node* firstSon, *secondSon, *parent;
	node() :data(0), firstSon(nullptr), secondSon(nullptr), parent(nullptr) {};

};
class tree {
private:
	node* roof;
public:
	tree() :roof(nullptr) {};
	void add(int indata) {
		node* addPosition;
		bool finded;

		if (roof == nullptr) {
			addPosition = new node();
			addPosition->data = indata;
			roof = addPosition;
		}
		else
			while (!finded) {
				if (indata >= roof->data) {
		

				};
			}
	}
	void levelorder() {};
	void basorder() {};
};