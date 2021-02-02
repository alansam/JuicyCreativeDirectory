#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

class Shape {
public:
  virtual std::string display() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double length = 0, double breadth = 0);
  virtual ~Rectangle() = default;
  virtual std::string display() const override;
  virtual double area() const override final;
  virtual double perimeter() const override final;

protected:
  //  hide implementation details from the interface
  double length_;
  double breadth_;
};

class Square final : public Rectangle {
public:
  Square(double length = 0);
  virtual ~Square() = default;
  std::string display() const override final;
};

class Triangle : public Shape {
public:
  Triangle(double base = 0, double height = 0);
  virtual ~Triangle() = default;
  virtual std::string display() const override;
  virtual double perimeter() const override;
  double area() const override;

protected:
  double base_;
  double height_;
};

class Circle final : public Shape {
public:
  Circle(double radius = 0);
  virtual ~Circle() = default;
  std::string display() const override;
  double area() const override;
  double perimeter() const override;
  double circumference() const;

private:
  double radius_;
};

class RightTriangle final : public Triangle {
public:
  RightTriangle(double base = 0, double height = 0);
  virtual ~RightTriangle() = default;
  std::string display() const override;
  double perimeter() const override;

private:
  double hypotenuse_;
};

class EquilateralTriangle final : public Triangle {
public:
  EquilateralTriangle(double base = 0);
  virtual ~EquilateralTriangle() = default;
  std::string display() const override;
  double perimeter() const override;
  double area() const override;
};

int main() {
  auto rshape = Rectangle(54.3, 21.09);
  auto sshape = Square(45.6);
  auto tshape = Triangle(3., 4.);
  auto cshape = Circle(10.0);
  auto xshape = RightTriangle(3., 4.);
  auto qshape = EquilateralTriangle(4.0);

  std::cout << "Rectangle            : "
            << rshape.display() << '\n';
  std::cout << "Square               : "
            << sshape.display() << '\n';
  std::cout << "Triangle             : "
            << tshape.display() << '\n';
  std::cout << "Circle               : "
            << cshape.display() << '\n';
  std::cout << "Right Triangle       : "
            << xshape.display() << '\n';
  std::cout << "Equilateral Triangle : "
            << qshape.display() << '\n';
  std::cout << std::endl;

  return 0;
}

Rectangle::Rectangle(double length, double breadth)
  : length_(length), breadth_(breadth) {}

std::string Rectangle::display() const {
  std::ostringstream disp;
  disp << "length "<< length_
        << ", breadth " << breadth_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

double Rectangle::area() const {
  return length_ * breadth_;
}

double Rectangle::perimeter() const {
  return 2 * (length_ + breadth_);
}

Square::Square(double length) {
  length_ = length;
  breadth_ = length;
}

std::string Square::display() const {
  std::ostringstream disp;
  disp << "length " << length_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

Triangle::Triangle(double base, double height)
  : base_(base), height_(height) {}


std::string Triangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
        << ", height " << height_
        << ", area " << std::fixed << area();
  return disp.str();
}

double Triangle::perimeter() const {
  //  TODO: calculate perimeter
  return NAN;
}

double Triangle::area() const {
  return (base_ / 2.0) * height_;
}

Circle::Circle(double radius)
  : radius_(radius) {}

std::string Circle::display() const {
  std::ostringstream disp;
  disp << "radius " << radius_
        << ", circumference " << circumference()
        << ", area " << area();
  return disp.str();
}

double Circle::area() const {
  return M_PI * (radius_ * radius_);
}

double Circle::perimeter() const {
  return circumference();
}

double Circle::circumference() const {
  return M_PI * (radius_ * 2.0);
}

RightTriangle::RightTriangle(double base, double height) {
  base_ = base;
  height_ = height;
  hypotenuse_ = std::sqrt((base_ * base_) + (height_ * height_));
}

std::string RightTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
        << ", height " << height_
        << ", hypotenuse " << hypotenuse_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

double RightTriangle::perimeter() const {
  return hypotenuse_ + base_ + height_;
}

  EquilateralTriangle::EquilateralTriangle(double base) {
    base_ = base;
    height_ = sqrt(3.0) / 2 * base_;
  }

  std::string EquilateralTriangle::display() const {
    std::ostringstream disp;
    disp << "base " << base_
         << ", height " << height_
         << ", perimeter " << perimeter()
         << ", area " << std::fixed << area();
    return disp.str();
  }

  double EquilateralTriangle::perimeter() const {
    return base_ + base_ + base_;
  }

  double EquilateralTriangle::area() const {
    return sqrt(3.0) / 4 * (base_ * base_);
  }
