#include "Vector.h"

#include <cmath>
#include <iomanip>
#include <iostream>

Vector::Vector() {
  coordinates = new int[6];

  // Initialize coordinate array to zeros
  for (int i = 0; i < 6; ++i) {
    coordinates[i] = 0;
  }
}

Vector::~Vector() {
  delete[] coordinates;
}

int Vector::getComponentX() const {
  return coordinates[3] - coordinates[0];
}

int Vector::getComponentY() const {
  return coordinates[4] - coordinates[1];
}

int Vector::getComponentZ() const {
  return coordinates[5] - coordinates[2];
}

float Vector::getLength() const {
  return sqrt(pow(getComponentX(), 2) + pow(getComponentY(), 2) +
              pow(getComponentZ(), 2));
}

std::ostream& operator<<(std::ostream& output, const Vector& vector) {
  output << "Vector: {" << vector.getComponentX() << ", "
         << vector.getComponentY() << ", " << vector.getComponentZ() << "}"
         << std::endl;

  output << "Coordinates: {" << vector.coordinates[0] << ", "
         << vector.coordinates[1] << ", " << vector.coordinates[2] << "}, {"
         << vector.coordinates[3] << ", " << vector.coordinates[4] << ", "
         << vector.coordinates[5] << "}" << std::endl;

  output << "Length: " << vector.getLength() << std::endl;
  output << std::endl;

  return output;
}

std::string Vector::getCoordinateName(int i) const {
  switch (i) {
    case 0:
      return "x1";
    case 1:
      return "y1";
    case 2:
      return "z1";
    case 3:
      return "x2";
    case 4:
      return "y2";
    case 5:
      return "z2";
    default:
      return "";
  }
}

std::istream& operator>>(std::istream& input, Vector& vector) {
  for (int i = 0; i < 6; ++i) {
    bool validInput = false;

    do {
      std::cout << "Enter the " << vector.getCoordinateName(i)
                << " coordinate:" << std::endl;
      std::string line;
      getline(input, line);
      std::stringstream timeInputStream(line);

      timeInputStream >> vector.coordinates[i];

      if (timeInputStream.fail()) {
        std::cout << "Invalid input, please enter an integer coordinate"
                  << std::endl;
        input.clear();
      } else {
        validInput = true;
      }
    } while (!validInput);
  }

  std::cout << std::endl;

  return input;
};

bool Vector::operator>(const Vector& vector) const {
  return getLength() > vector.getLength();
}

bool Vector::operator<(const Vector& vector) const {
  return getLength() < vector.getLength();
}

bool Vector::operator>=(const Vector& vector) const {
  return getLength() >= vector.getLength();
}

bool Vector::operator<=(const Vector& vector) const {
  return getLength() <= vector.getLength();
}

bool Vector::operator==(const Vector& vector) const {
  return getLength() == vector.getLength();
}

bool Vector::operator!=(const Vector& vector) const {
  return getLength() != vector.getLength();
}

Vector Vector::operator+(const Vector& vector) const {
  Vector result;

  for (int i = 0; i < 6; ++i) {
    result.coordinates[i] = coordinates[i] + vector.coordinates[i];
  }

  return result;
}

Vector Vector::operator-(const Vector& vector) const {
  Vector result;

  for (int i = 0; i < 6; ++i) {
    result.coordinates[i] = coordinates[i] - vector.coordinates[i];
  }

  return result;
}

Vector Vector::operator*(const Vector& vector) const {
  Vector result;

  int resultComponentX = getComponentY() * vector.getComponentZ() -
                         getComponentZ() * vector.getComponentY();
  int resultComponentY = -(getComponentX() * vector.getComponentZ() -
                           getComponentZ() * vector.getComponentX());
  int resultComponentZ = getComponentX() * vector.getComponentY() -
                         getComponentY() * vector.getComponentX();

  result.coordinates[0] = 0;
  result.coordinates[1] = 0;
  result.coordinates[2] = 0;
  result.coordinates[3] = resultComponentX;
  result.coordinates[4] = resultComponentY;
  result.coordinates[5] = resultComponentZ;

  return result;
}