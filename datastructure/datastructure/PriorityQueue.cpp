#include <iostream>
#include <string>
using namespace std;

class PriorityQueue {
  private: 
	  string data[100];
	  int Priority[100];
	  int highestPri, tailer;
  public:
	  PriorityQueue() :tailer(0),highestPri(0) {};
	  void add(string indata, int inPriority) {
		  if (tailer >= 100) {
			  cout << "the Queue is full, please delete some data first" << endl;
			  
		  }
		  else {
			  data[tailer] = indata;
			  if (inPriority > highestPri)
				  highestPri = inPriority;
			  Priority[tailer] = inPriority;
			  tailer += 1;
		  }  
		  
	  };
	  string popByFIFO() {
		  string output;
	  for(int i=0;i<100;i++)
		  if (data[i] != "") {
			  output = data[i];
			  for (int j = i; j < 100 - i; j++)
				  if (data[j - 1] != "") {
					  data[j] = data[j - 1];
					  Priority[j] = Priority[j - 1];
					  if (Priority[j] > highestPri)
						  highestPri = Priority[j];
				  }
		  }
	  return output;
	  };//gedt by first in first out
	  string popByPriority() {
		  string output;
	  for(int i=0;i<=100;i++)
		  if (Priority[i] == highestPri) {
			  output = data[i];
			  highestPri = 0;
			  for (int j = i; j < 100 - i; j++)
				  if (data[j - 1] != "") {
					  data[j] = data[j - 1];
					  Priority[j] = Priority[j - 1];
					  if (Priority[j] > highestPri)
						  highestPri = Priority[j];
				  }
			  return output;
		  }
	  };
};