#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble(vector<int> unsort) {
	int temp,count=0;
	for (int i = unsort.size()-1; i > 0; i--)
		for (int j = 0; j < i; j++) {
			if (unsort[j] > unsort[j + 1]) {
				temp = unsort[j + 1];
				unsort[j + 1] = unsort[j];
				unsort[j] = temp;
			}
			count += 1;
		};
	return unsort;
}
int main() {
	vector<int> unsort, sorted;
	int x=0;
	cin >> x;
	while (x != -1) {	
		unsort.push_back(x);
		cin >> x;
	};
	sorted=bubble(unsort);
	for(int i=0;i<unsort.size();i++)
	cout<< sorted[i]<<" "<<endl ;
	system("pause");
	return 0;
}
