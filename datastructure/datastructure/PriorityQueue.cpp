#include <iostream>
#include <string>
using namespace std;

class PriorityQueue {
  private: 
	  string data[100];
	  int Priority[100];
  public:
	  PriorityQueue();
	  void add(string indata, int inPriority) {
		  for(int i =0;i<100;i++)
			  if (data[i] == "") {
				  data[i] = indata[i];
				  Priority[i] = inPriority;
				  break;
			  }
		  cout << "the Queue is full, please delete some data first" << endl;
	  };
	  string popByFIFO() {
		  string output;
	  for(int i=0;i<100;i++)
		  if (data[i] != "") {
			  output = data[i];
			  for (int j = i; j < 100 - i; j++)
				  if (data[j - 1] != "")
					  data[j] = data[j - 1];
		  }
	  return output;
	  };//get by first in first out
	  string popByPriority();
};