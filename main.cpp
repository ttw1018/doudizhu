#include "infer.hpp"
#include <iostream>

using namespace std;

int main () {
  card v1 = {13, 13,13, 13, 9, 9, 7 , 6, 5, 4, 3, 3}, v2 = {15, 15, 15, 11, 10, 9, 8 , 8, 7, 6, 5, 4};
  Cards user(v1), system(v2);
  cout << infer(user, system, 1, card()) << endl;
}



