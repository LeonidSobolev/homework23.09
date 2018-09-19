#include <iostream>

int main(){
  int mass[5] = {5,4,3,2,1};
  int tmp;
  int* ptr = mass;
  bool flag = true;

  while (flag) {
    flag = false;
    for(int i = 0; i <= 3; i++){
      if( *(ptr + i) > *(ptr + (i + 1))) {
        flag = true;
        tmp = *(ptr + i);
        *(ptr + i) = *(ptr + i + 1);
        *(ptr + i + 1) = tmp;
        break;
      }
    }

  }

  for(int i = 0; i <=4; i++) std::cout << mass[i] << " ";





}
