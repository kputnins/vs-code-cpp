#include <iostream>
#include <string>

#include "Vector.h"

using namespace std;

int main() {
  cout << "Defining the first vector" << endl;
  Vector vectorOne;
  cin >> vectorOne;
  cout << vectorOne;

  cout << "Defining the second vector" << endl;
  Vector vectorTwo;
  cin >> vectorTwo;
  cout << vectorTwo;

  cout << "Vector1 < Vector2: " << (vectorOne < vectorTwo) << endl;
  cout << "Vector1 > Vector2: " << (vectorOne > vectorTwo) << endl;

  cout << "Vector1 <= Vector2: " << (vectorOne <= vectorTwo) << endl;
  cout << "Vector1 >= Vector2: " << (vectorOne >= vectorTwo) << endl;

  cout << "Vector1 == Vector2: " << (vectorOne == vectorTwo) << endl;
  cout << "Vector1 != Vector2: " << (vectorOne != vectorTwo) << endl;
  std::cout << endl;

  cout << "Vector1 + Vector2" << endl;
  Vector vectorSum = vectorOne + vectorTwo;
  cout << vectorSum;

  cout << "Vector1 - Vector2" << endl;
  Vector vectorDifference = vectorOne - vectorTwo;
  cout << vectorDifference;

  cout << "Vector1 * Vector2" << endl;
  Vector vectorProduct = vectorOne * vectorTwo;
  cout << vectorProduct;
}