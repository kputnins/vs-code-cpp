#ifndef Vector_H
#define Vector_H

#include <iostream>

class Vector {
  friend std::istream& operator>>(std::istream&, Vector&);
  friend std::ostream& operator<<(std::ostream&, const Vector&);

 private:
  // Array of 6 integers to store the coordinates of the vector
  // [x1, y1, z1, x2, y2, z2]
  int* coordinates;

 public:
  Vector();
  ~Vector();

  int getComponentX() const;
  int getComponentY() const;
  int getComponentZ() const;
  float getLength() const;

  bool operator>(const Vector&) const;
  bool operator<(const Vector&) const;

  bool operator>=(const Vector&) const;
  bool operator<=(const Vector&) const;

  bool operator==(const Vector&) const;
  bool operator!=(const Vector&) const;

  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;

  Vector operator*(const Vector&) const;

  void operator=(const Vector&);

 private:
  std::string getCoordinateName(int i) const;
};

#endif  // Vector_H