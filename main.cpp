#include <iostream>
#include <string>

#include "Vector.h"

using namespace std;

int main() {
  Vector vectorOne;
  cin >> vectorOne;
  cout << vectorOne;

  Vector vectorTwo;
  cin >> vectorTwo;
  cout << vectorTwo;

  cout << "Vector1 < Vector2: " << (vectorOne < vectorTwo) << endl;
  cout << "Vector1 > Vector2: " << (vectorOne > vectorTwo) << endl;

  cout << "Vector1 <= Vector2: " << (vectorOne <= vectorTwo) << endl;
  cout << "Vector1 >= Vector2: " << (vectorOne >= vectorTwo) << endl;

  cout << "Vector1 == Vector2: " << (vectorOne == vectorTwo) << endl;
  cout << "Vector1 != Vector2: " << (vectorOne != vectorTwo) << endl;
}