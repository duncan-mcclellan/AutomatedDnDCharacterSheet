#ifndef TOSTRING_H_INCLUDED
#define TOSTRING_H_INCLUDED

template <typename T>
void vToString(vector<T> vec){
  cout << "[";
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i);
    if(i != vec.size() - 1){
      cout << ", ";
    }
  }
  cout << "]" << endl << endl;
}

void toString(int* arr){
  cout << "[";
  for(int i = 0; i < 6; i++){
    cout << *(arr + i);
    if(i != 5){
      cout << ", ";
    }
  }
  cout << "]" << endl << endl;
}

#endif
