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
		node* addPosition=roof;
		bool finded;

		if (roof == nullptr) {
			addPosition = new node();
			addPosition->data = indata;
			roof = addPosition;
		}
		else
			while (!finded) {
				if (indata >= addPosition->data) {
					if (addPosition->secondSon == nullptr) {
						addPosition->secondSon = new node();
						addPosition->secondSon->parent = addPosition;
						addPosition->data = indata;
						finded = true;
					}
					else addPosition = addPosition->secondSon;
				}
				else {
					if (addPosition->firstSon == nullptr) {
						addPosition->firstSon = new node();
						addPosition->firstSon->parent = addPosition;
						addPosition->data = indata;
						finded = true;
					}
					else addPosition = addPosition->firstSon;
				}
			}
	}
	void TreeSearch() {};
};
int main() {
	tree a;
	a.add(20);
	a.add(10);
	a.add(30);
	a.add(40);
	cout >> a.TreeSearch(20);
	return 0;
}