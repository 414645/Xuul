#include <iostream>
#include <cstring>
//#include <vector>

#include "item.h"

using namespace std;

Item::Item() {
  //never called
}

Item::Item(char* newName) {
  strcpy(name, newName);
  cout << name << endl;
}

char* Item::getName() {
  return name;
}
