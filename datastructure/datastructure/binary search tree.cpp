#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int key;
	node* firstSon, *secondSon, *parent;//firstson for smaller key,second for greater key
	node() :key(0), firstSon(nullptr), secondSon(nullptr), parent(nullptr) {};
	~node() { delete firstSon, secondSon, parent; }
};
class tree {
private:
	node* roof;//head of the tree
public:
	tree() :roof(nullptr) {};
	~tree() { delete roof; };
	void add(int indata) {
		node* addPosition = roof;
		bool finded = false;

		if (roof == nullptr) {//if tree is empty, make a new roof 
			addPosition = new node();
			addPosition->key = indata;
			roof = addPosition;
		}
		else
			while (!finded) {
				if (indata >= addPosition->key) {//if bigger
					if (addPosition->secondSon == nullptr) {
						addPosition->secondSon = new node();
						addPosition->secondSon->parent = addPosition;
						addPosition->secondSon->key = indata;
						finded = true;
					}
					else addPosition = addPosition->secondSon;
				}
				else {//if smaller
					if (addPosition->firstSon == nullptr) {
						addPosition->firstSon = new node();
						addPosition->firstSon->parent = addPosition;
						addPosition->firstSon->key = indata;
						finded = true;
					}
					else addPosition = addPosition->firstSon;
				}
			}
		//self-balancing code
		if (addPosition->parent->parent->firstSon == nullptr || addPosition->parent->parent->secondSon == nullptr)
		{
			int temp=0;
			int reorder[3] = { addPosition->key,addPosition->parent->key,addPosition->parent->parent->key };
			for(int i =0;i<3;i++)
				for (int i = 3; i > 0; i--)
					for (int j = 0; j < i; j++) {
						if (reorder[j] > reorder[j + 1]) {
							temp = reorder[j + 1];
							reorder[j + 1] = reorder[j];
							reorder[j] = temp;
						}
					};
			delete addPosition->parent->parent, addPosition->parent,addPosition;
			add(reorder[1]);
			add(reorder[0]);
			add(reorder[2]);
		}
	}
	int TreeSearch(int key) {
		cout << "roof is " << roof->key << endl;
		if (roof == nullptr)
			return -1;
		else {
			node* findposition = roof;
			bool find = false;
			while (!find) {
				if (findposition==nullptr) {
					return -1;
					break;
				}
				if (key == findposition->key) {
					return findposition->key;
				}
				else if (key > findposition->key)
					findposition = findposition->secondSon;
				else
					findposition = findposition->firstSon;
				
			}
		}
	};
};
int main() {
	tree a;;
	a.add(30);
	a.add(20);
	a.add(10);
	a.add(40);
	cout << a.TreeSearch(40) << endl;
	system("pause");
	return 0;
}