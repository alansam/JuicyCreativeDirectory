#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>

class Shape {
public:
  virtual std::string display() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::tuple<double, double, double, double>
    dimensions() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double length = 0, double breadth = 0);
  virtual ~Rectangle() = default;
  virtual std::string display() const override;
  virtual double area() const override final;
  virtual double perimeter() const override final;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

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
  virtual std::tuple<double, double, double, double>
    dimensions() const override;
};

class Triangle : public Shape {
public:
  Triangle(double base = 0, double height = 0);
  virtual ~Triangle() = default;
  virtual std::string display() const override;
  virtual double perimeter() const override;
  virtual double area() const override;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

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
  std::tuple<double, double, double, double>
    dimensions() const override;

private:
  double radius_;
};

class RightTriangle : public Triangle {
public:
  RightTriangle(double base = 0, double height = 0);
  virtual ~RightTriangle() = default;
  std::string display() const override;
  double perimeter() const override;

protected:
  double hypotenuse_;
};

class EquilateralTriangle final : public Triangle {
public:
  EquilateralTriangle(double base = 0);
  virtual ~EquilateralTriangle() = default;
  std::string display() const override;
  double perimeter() const override;
  double area() const override;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;
};

class IsoscelesTriangle final : public RightTriangle {
public:
  IsoscelesTriangle(double base = 0, double height = 0); 
  virtual ~IsoscelesTriangle() = default;
  std::string display() const override;
  double perimeter() const override;
};

int main() {
  auto rshape = Rectangle(54.3, 21.09);
  auto sshape = Square(45.6);
  auto tshape = Triangle(3., 4.);
  auto cshape = Circle(10.0);
  auto xshape = RightTriangle(3., 4.);
  auto qshape = EquilateralTriangle(4.0);
  auto ishape = IsoscelesTriangle(6., 4.);

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
  std::cout << "Isosceles Triangle   : "
            << ishape.display() << '\n';
  std::cout << std::endl;

  {
    auto [length, breadth, d3, d4] = rshape.dimensions();
    std::cout << "length " << length
              << ", breadth " << breadth << '\n';
    std::cout << std::endl;
  }

  {
    auto [length, d2, d3, d4] = sshape.dimensions();
    std::cout << "length " << length << '\n';
    std::cout << std::endl;
  }

  {
    auto [base, height, d3, d4] = tshape.dimensions();
    std::cout << "nase " << base
              << ", height " << height << '\n';
    std::cout << std::endl;
  }

  {
    auto [radius, d2, d3, d4] = cshape.dimensions();
    std::cout << "radius " << radius << '\n';
    std::cout << std::endl;
  }

  {
    auto [base, height, d3, d4] = xshape.dimensions();
    std::cout << "base " << base
              << ", height " << height << '\n';
    std::cout << "perimiter " << qshape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    auto [base, height, d3, d4] = qshape.dimensions();
    std::cout << "base " << base
              << "\nheight " << height << '\n';
    std::cout << std::endl;
  }

  {
    auto [base, height, d3, d4] = ishape.dimensions();
    std::cout << "base " << base
              << "\nheight " << height << '\n';
    std::cout << std::endl;
  }

  return 0;
}

Rectangle::Rectangle(double length, double breadth)
  : length_(length), breadth_(breadth) {}

std::tuple<double, double, double, double>
  Rectangle::dimensions() const {
  auto rt = std::make_tuple(length_, breadth_, NAN, NAN);
  return rt;
}

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

std::tuple<double, double, double, double>
  Square::dimensions() const {
  auto rt = std::make_tuple(length_, NAN, NAN, NAN);
  return rt;
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

std::tuple<double, double, double, double>
  Triangle::dimensions() const {
  auto rt = std::make_tuple(base_, height_, NAN, NAN);
  return rt;
}

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

std::tuple<double, double, double, double>
  Circle::dimensions() const {
  auto rt = std::make_tuple(radius_, NAN, NAN, NAN);
  return rt;
}

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
  //height_ = sqrt( (base * base) - ((base / 2) * (base / 2)) );
  //height_ = sqrt( (base * base) - (base * base / 4) );
}

std::string EquilateralTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
        << ", height " << height_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

std::tuple<double, double, double, double>
  EquilateralTriangle::dimensions() const {
  auto rt = std::make_tuple(base_, height_, NAN, NAN);
  return rt;
}

double EquilateralTriangle::perimeter() const {
  return base_ + base_ + base_;
}

double EquilateralTriangle::area() const {
  return sqrt(3.0) / 4 * (base_ * base_);
}

IsoscelesTriangle::IsoscelesTriangle(double base, double height) {
  base_ = base;
  height_ = height;
  hypotenuse_ = sqrt((base_ * base_ / 4) + (height_ * height_));
}

std::string IsoscelesTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
       << ", height " << height_
       << ", hypotenuse " << hypotenuse_
       << ", perimeter " << perimeter()
       << ", area " << std::fixed << area();
  return disp.str();
}

double IsoscelesTriangle::perimeter() const {
  return hypotenuse_ + hypotenuse_ + base_;
}
