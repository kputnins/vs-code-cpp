#include "Vector.h"

#include <cmath>
#include <iomanip>
#include <iostream>

Vector::Vector() {
  // Initialize coordinate array to zeros
  for (int i = 0; i < 6; ++i) {
    coordinates[i] = 0;
  }

  std::cout << "Vector created" << std::endl;
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

int Vector::getLength() const {
  return sqrt(pow(getComponentX(), 2) + pow(getComponentY(), 2) +
              pow(getComponentZ(), 2));
}

std::ostream& operator<<(std::ostream& output, const Vector& vector) {
  output << "Coordinates: {" << vector.coordinates[0] << ", "
         << vector.coordinates[1] << ", " << vector.coordinates[2] << "}, {"
         << vector.coordinates[3] << ", " << vector.coordinates[4] << ", "
         << vector.coordinates[5] << "}" << std::endl;

  output << "Length: " << vector.getLength() << std::endl;

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