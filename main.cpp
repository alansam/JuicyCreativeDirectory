//
//  main.cpp
//  JuicyCreativeDirectory
//
//  Created by Alan Sampson on 2/2/21.
//  2021-02-02 03:23:35.0492
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>

//  MARK: - Definitions.
/*
 *  MARK: Class Shape
 */
class Shape {
public:
  virtual std::string display() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::tuple<double, double, double, double>
    dimensions() const = 0;
};

/*
 *  MARK: Class Rectangle
 */
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

/*
 *  MARK: Class Square
 */
class Square final : public Rectangle {
public:
  Square(double length = 0);
  virtual ~Square() = default;
  std::string display() const override final;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;
};

/*
 *  MARK: Class Triangle
 */
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
  double sideA_;
  double sideB_;
};

/*
 *  MARK: Class Circle
 */
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

/*
 *  MARK: Class RightTriangle
 */
class RightTriangle : public Triangle {
public:
  RightTriangle(double base = 0, double height = 0);
  virtual ~RightTriangle() = default;
  std::string display() const override;
//  double perimeter() const override;

protected:
  double hypotenuse_;
};

/*
 *  MARK: Class IsoscelesTriangle
 */
class IsoscelesTriangle : public Triangle {
public:
  IsoscelesTriangle(double base = 0, double height = 0);
  virtual ~IsoscelesTriangle() = default;
  std::string display() const override;
//  double perimeter() const override;
};

/*
 *  MARK: Class EquilateralTriangle
 */
class EquilateralTriangle final : public IsoscelesTriangle {
public:
  EquilateralTriangle(double base = 0);
  virtual ~EquilateralTriangle() = default;
  virtual std::string display() const override;
//  virtual double perimeter() const override;
  virtual double area() const override;
//  virtual std::tuple<double, double, double, double>
//    dimensions() const override;
};

//  MARK: - Implementation.
/*
 *  MARK: main()
 */
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
    std::cout << "Shape - Rectangle\n";
    auto [length, breadth, d3, d4] = rshape.dimensions();
    std::cout << "length " << length
              << ", breadth " << breadth << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Square\n";
    auto [length, d2, d3, d4] = sshape.dimensions();
    std::cout << "length " << length << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Circle\n";
    auto [radius, d2, d3, d4] = cshape.dimensions();
    std::cout << "radius " << radius << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Triangle\n";
    auto [base, height, sideA, sideB] = tshape.dimensions();
    std::cout << "base " << base
              << ", height " << height << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - RightTriangle\n";
    auto [base, height, sideA, sideB] = xshape.dimensions();
    std::cout << "base " << base
              << ", height " << height
              << ", hypotenuse " << (sideB != height ? sideB : sideA) << '\n';
    std::cout << "perimiter " << xshape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - EquilateralTriangle\n";
    auto [base, height, sideA, sideB] = qshape.dimensions();
    std::cout << "base " << base
              << "\nheight " << height << '\n';
    std::cout << "perimiter " << qshape.IsoscelesTriangle::perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - IsoscelesTriangle\n";
    auto [base, height, sideA, sideB] = ishape.dimensions();
    std::cout << "base " << base
              << " sides " << sideA
              << "\nheight " << height << '\n';
    std::cout << "perimiter " << ishape.perimeter() << '\n';
    std::cout << std::endl;
  }

  return 0;
}

//  MARK: - Class Rectangle Implementation.
/*
 *  MARK: Rectangle::Rectangle() - default c'tor
 */
Rectangle::Rectangle(double length, double breadth)
  : length_(length), breadth_(breadth) {}

/*
 *  MARK: Rectangle::dimensions()
 */
std::tuple<double, double, double, double>
Rectangle::dimensions() const {
  auto rt = std::make_tuple(length_, breadth_, NAN, NAN);
  return rt;
}

/*
 *  MARK: Rectangle::display()
 */
std::string
Rectangle::display() const {
  std::ostringstream disp;
  disp << "length "<< length_
        << ", breadth " << breadth_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

/*
 *  MARK: Rectangle::area()
 */
double
Rectangle::area() const {
  return length_ * breadth_;
}

/*
 *  MARK: Rectangle::perimeter()
 */
double
Rectangle::perimeter() const {
  return 2 * (length_ + breadth_);
}

//  MARK: - Class Square Implementation.
/*
 *  MARK: Square::Square() - default c'tor
 */
Square::Square(double length) {
  length_ = length;
  breadth_ = length;
}

/*
 *  MARK: Square::dimensions()
 */
std::tuple<double, double, double, double>
Square::dimensions() const {
  auto rt = std::make_tuple(length_, NAN, NAN, NAN);
  return rt;
}

/*
 *  MARK: Square::display()
 */
std::string
Square::display() const {
  std::ostringstream disp;
  disp << "length " << length_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

//  MARK: - Class Triangle Implementation.
/*
 *  MARK: Triangle::Triangle() - default c'tor
 */
Triangle::Triangle(double base, double height)
  : base_(base), height_(height), sideA_(NAN), sideB_(NAN) {}

/*
 *  MARK: Triangle::dimensions()
 */
std::tuple<double, double, double, double>
Triangle::dimensions() const {
  auto rt = std::make_tuple(base_, height_, sideB_, sideB_);
  return rt;
}

/*
 *  MARK: Triangle::display()
 */
std::string
Triangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
        << ", height " << height_
        << ", area " << std::fixed << area();
  return disp.str();
}

/*
 *  MARK: Triangle::perimeter()
 */
double
Triangle::perimeter() const {
  //  TODO: calculate perimeter
  double perim;
  if (std::isnan(base_) || std::isnan(sideA_) || std::isnan(sideB_)) {
    perim = NAN;
  }
  else {
    perim = base_ + sideA_ + sideB_;
  }
  return perim;
}

/*
 *  MARK: Triangle::area()
 */
double
Triangle::area() const {
  return (base_ / 2.0) * height_;
}

//  MARK: - Class Circle Implementation.
/*
 *  MARK: Circle::Circle() - default c'tor
 */
Circle::Circle(double radius)
  : radius_(radius) {}

/*
 *  MARK: Circle::dimensions()
 */
std::tuple<double, double, double, double>
Circle::dimensions() const {
  auto rt = std::make_tuple(radius_, NAN, NAN, NAN);
  return rt;
}

/*
 *  MARK: Circle::display()
 */
std::string
Circle::display() const {
  std::ostringstream disp;
  disp << "radius " << radius_
        << ", circumference " << circumference()
        << ", area " << area();
  return disp.str();
}

/*
 *  MARK: Circle::area()
 */
double
Circle::area() const {
  return M_PI * (radius_ * radius_);
}

/*
 *  MARK: Circle::perimeter()
 */
double
Circle::perimeter() const {
  return circumference();
}

/*
 *  MARK: Circle::circumference()
 */
double
Circle::circumference() const {
  return M_PI * (radius_ * 2.0);
}

//  MARK: - Class RightTriangle Implementation.
/*
 *  MARK: RightTriangle::RightTriangle() - default c'tor
 */
RightTriangle::RightTriangle(double base, double height) {
  base_  = base;
  sideA_ = height_ = height;
  sideB_ = hypotenuse_ = std::sqrt((base_ * base_) + (height_ * height_));
}

/*
 *  MARK: RightTriangle::display()
 */
std::string
RightTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
       << ", height " << height_
       << ", hypotenuse " << hypotenuse_
       << ", perimeter " << perimeter()
       << ", area " << std::fixed << area();
  return disp.str();
}

///*
// *  MARK: RightTriangle::perimeter()
// */
//double
//RightTriangle::perimeter() const {
//  return hypotenuse_ + base_ + height_;
//}

//  MARK: - Class EquilateralTriangle Implementation.
/*
 *  MARK: EquilateralTriangle::EquilateralTriangle() - default c'tor
 */
EquilateralTriangle::EquilateralTriangle(double base) {
  sideA_ = sideB_ = base_ = base;
  height_ = sqrt(3.0) / 2 * base_;
  //height_ = sqrt( (base * base) - ((base / 2) * (base / 2)) );
  //height_ = sqrt( (base * base) - (base * base / 4) );
}

/*
 *  MARK: EquilateralTriangle::display()
 */
std::string
EquilateralTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
        << ", height " << height_
        << ", perimeter " << perimeter()
        << ", area " << std::fixed << area();
  return disp.str();
}

///*
// *  MARK: EquilateralTriangle::dimensions()
// */
//std::tuple<double, double, double, double>
//EquilateralTriangle::dimensions() const {
//  auto rt = std::make_tuple(base_, height_, NAN, NAN);
//  return rt;
//}

///*
// *  MARK: EquilateralTriangle::perimeter()
// */
//double
//EquilateralTriangle::perimeter() const {
//  return sideA_ + sideB_ + base_;
//}

/*
 *  MARK: EquilateralTriangle::area()
 */
double
EquilateralTriangle::area() const {
  return sqrt(3.0) / 4 * (base_ * base_);
}

//  MARK: - Class IsoscelesTriangle Implementation.
/*
 *  MARK: IsoscelesTriangle::IsoscelesTriangle() - default c'tor
 */
IsoscelesTriangle::IsoscelesTriangle(double base, double height) {
  base_ = base;
  height_ = height;
  sideA_ = sideB_ = sqrt((base_ * base_ / 4) + (height_ * height_));
}

/*
 *  MARK: IsoscelesTriangle::display()
 */
std::string
IsoscelesTriangle::display() const {
  std::ostringstream disp;
  disp << "base " << base_
       << ", height " << height_
       << ", side length " << sideA_
       << ", perimeter " << perimeter()
       << ", area " << std::fixed << area();
  return disp.str();
}

///*
// *  MARK: IsoscelesTriangle::perimeter()
// */
//double
//IsoscelesTriangle::perimeter() const {
//  return sideA_ + sideB_ + base_;
//}
