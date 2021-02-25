#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int binarySearch(vector<int> &collection, int left, int right, int searchKey);

vector<int> linearSearch(vector<int> &list, int searchItem);

int main() {

  int keyword = 44;

  vector<int> list{44, 22, 666, 444, 0, 222, 444, 112, 545, 44};
  vector<int> foundedValues = linearSearch(list, keyword);
  if (!foundedValues.empty()) {
    for (int index : foundedValues) {
      std::cout << "founded at index = " << index << ", value = " << list.at(index) << std::endl;
    }
  } else {
    cout << "no results found by keyword = " << keyword << endl;
  }

  int foundeValueIndex = binarySearch(list, 0, (int)list.size() - 1, keyword);

  if(foundeValueIndex != -1) {
    cout << "Binary search Founded at index = " << foundeValueIndex << ", " << keyword << endl;
  }else {
    cout << "no results found by keyword = " << keyword << endl;
  }


  return 0;


}

vector<int> linearSearch(vector<int> &list, int searchItem) {
  vector<int> temp;
  for (int i = 0; i < list.size(); ++i) {
    if (list.at(i) == searchItem) {
      temp.emplace_back(i);
    }
  }
  return temp;
}


int binarySearch(vector<int> &collection, int left, int right, int searchKey){


  std::sort(collection.begin(), collection.end());
  // left = 0
  // right = 10 - 1 => 9

  while(left <= right){
    int middle = left + (right - left) / 2; // 0 + (9 - 0) / 2 => 4

    if(collection[middle] == searchKey){
      return middle;
    }
    if(collection[middle] < searchKey){
      left = middle + 1; // we go to right =>
    } else{
      right = middle - 1; // we go to left <=
    }
  }
  return -1;
}