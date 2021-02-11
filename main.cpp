//
//  main.cpp
//  JuicyCreativeDirectory
//
//  Created by Alan Sampson on 2/2/21.
//  2021-02-02 03:23:35.0492
//
//  MARK: - References.
//  @see: https://www.cprogramming.com/tutorial/virtual_inheritance.html
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>

using namespace std::literals::string_literals;

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

protected:
  static
  bool debug_;
};

/*
 *  MARK: Class Quadrilateral.
 */
class Quadrilateral : public virtual Shape {
public:
  Quadrilateral(double baseA = NAN, double sideA = NAN,
                double baseB = NAN, double sideB = NAN);
  virtual ~Quadrilateral() = default;
  virtual double perimeter() const override;

protected:
  //  hide implementation details from the interface
  double baseA_;
  double baseB_;
  double sideA_;
  double sideB_;
};

/*
 *  MARK: Class Rectangle
 */
class Rectangle : public virtual Quadrilateral {
public:
  Rectangle(double length = 0, double breadth = 0);
  virtual ~Rectangle() = default;
  virtual std::string display() const override;
  virtual double area() const override final;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

protected:
  //  hide implementation details from the interface
};

/*
 *  MARK: Class Square
 */
class Square final : public virtual Rectangle {
public:
  Square(double length = 0);
  virtual ~Square() = default;
  virtual std::string display() const override final;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;
};

class Parallelogram final : public virtual Quadrilateral {
public:
  Parallelogram(double height = 0, double base = 0, double side = 0);
  virtual ~Parallelogram() = default;
  std::string display() const override final;
  virtual double area() const override final;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

protected:
  //  hide implementation details from the interface
  double height_;
};

/*
 *  MARK: Class Triangle
 */
class Triangle : public virtual Shape {
public:
  Triangle(double base = 0, double height = 0, double sideA = NAN, double sideB = NAN);
  virtual ~Triangle() = default;
  virtual std::string display() const override;
  virtual double perimeter() const override;
  virtual double area() const override;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

protected:
  //  hide implementation details from the interface
  double base_;
  double height_;
  double sideA_;
  double sideB_;
};

/*
 *  MARK: Class RightTriangle
 */
class RightTriangle : public virtual Triangle {
public:
  RightTriangle(double base = 0, double height = 0);
  virtual ~RightTriangle() = default;
  std::string display() const override;

protected:
  //  hide implementation details from the interface
  double hypotenuse_;
};

/*
 *  MARK: Class IsoscelesTriangle
 */
class IsoscelesTriangle : public virtual Triangle {
public:
  IsoscelesTriangle(double base = 0, double height = 0);
  virtual ~IsoscelesTriangle() = default;
  std::string display() const override;
  virtual std::tuple<double, double, double, double>
    dimensions() const override;

protected:
  double ibase_;
  double iheight_;
  double iside_;
};

/*
 *  MARK: Class EquilateralTriangle
 */
class EquilateralTriangle final : public virtual IsoscelesTriangle {
public:
  EquilateralTriangle(double base = 0);
  virtual ~EquilateralTriangle() = default;
  virtual std::string display() const override;
  virtual double area() const override;
};

/*
 *  MARK: Class RightIsoscelesTriangle
 */
class RightIsoscelesTriangle final
  : public virtual IsoscelesTriangle, public virtual RightTriangle {
public:
  RightIsoscelesTriangle(double height = 0);
  virtual ~RightIsoscelesTriangle() = default;
  std::string display() const override;

protected:
    //  hide implementation details from the interface
    double height2_;
};

/*
 *  MARK: Class Circle
 */
class Circle final : public virtual Shape {
public:
  Circle(double radius = 0);
  virtual ~Circle() = default;
  std::string display() const override;
  double area() const override;
  double perimeter() const override;
  double circumference() const;
  std::tuple<double, double, double, double>
    dimensions() const override;

protected:
  //  hide implementation details from the interface
  double radius_;
};

//  MARK: - Implementation.
/*
 *  MARK: main()
 */
int main() {
  auto rshape = Rectangle(3., 4.);
  auto sshape = Square(4.);
  auto pshape = Parallelogram(4., 3., 5.);
  auto cshape = Circle(10.0);
  auto tshape = Triangle(3., 4.);
  auto xshape = RightTriangle(3., 4.);
  auto qshape = EquilateralTriangle(4.0);
  auto ishape = IsoscelesTriangle(6., 4.);
  auto jshape = RightIsoscelesTriangle(5.);

  std::cout << "Rectangle                : "s
            << rshape.display() << '\n';
  std::cout << "Square                   : "s
            << sshape.display() << '\n';
  std::cout << "Parallelogram            : "s
            << pshape.display() << '\n';
  std::cout << "Circle                   : "s
            << cshape.display() << '\n';
  std::cout << "Triangle                 : "s
            << tshape.display() << '\n';
  std::cout << "Right Triangle           : "s
            << xshape.display() << '\n';
  std::cout << "Equilateral Triangle     : "s
            << qshape.display() << '\n';
  std::cout << "Isosceles Triangle       : "s
            << ishape.display() << '\n';
  std::cout << "Right Isosceles Triangle : "s
            << jshape.display() << '\n';
  std::cout << std::endl;

  {
    std::cout << "Shape - Rectangle\n"s;
    Shape & shape = rshape;
    auto [length, breadth, d3, d4] = shape.dimensions();
    std::cout << "length "s << length
              << ", breadth "s << breadth << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Square\n"s;
    Shape & shape = sshape;
    auto [length, d2, d3, d4] = shape.dimensions();
    std::cout << "length "s << length << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Parallelogram\n"s;
    Shape & shape = pshape;
    auto [height, base, side, d4] = shape.dimensions();
    std::cout << "base "s << base
              << ", height "s << height
              << ", side "s << side << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Circle\n"s;
    Shape & shape = cshape;
    auto [radius, d2, d3, d4] = shape.dimensions();
    std::cout << "radius "s << radius << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - Triangle\n"s;
    Shape & shape = tshape;
    auto [base, height, sideA, sideB] = shape.dimensions();
    std::cout << "base "s << base
              << ", height "s << height << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - RightTriangle\n"s;
    Shape & shape = xshape;
    auto [base, height, sideA, sideB] = shape.dimensions();
    std::cout << "base "s << base
              << ", height "s << height
              << ", hypotenuse "s << (sideB != height ? sideB : sideA) << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - EquilateralTriangle\n"s;
    Shape & shape = qshape;
    auto [base, height, sideA, sideB] = shape.dimensions();
    std::cout << "base "s << base
              << "\nheight "s << height << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - IsoscelesTriangle\n"s;
    Shape & shape = ishape;
    auto [base, height, sideA, sideB] = shape.dimensions();
    std::cout << "base "s << base
              << " sides "s << sideA
              << "\nheight "s << height << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "Shape - RightIsoscelesTriangle\n"s;
    Shape & shape = jshape;
    auto [base, height, sideA, sideB] = shape.dimensions();
    std::cout << "base "s << base
              << " sides "s << sideA << ", "s << sideB
              << "\nheight "s << height << '\n';
    std::cout << "perimiter "s << shape.perimeter() << '\n';
    std::cout << std::endl;

    std::cout << "..... - IsoscelesTriangle\n"s;
    std::cout << jshape.IsoscelesTriangle::display() << '\n';
    auto [ibase, iheight, isideA, isideB] = jshape.IsoscelesTriangle::dimensions();
    std::cout << "base "s << ibase
              << " sides "s << isideA << ", "s << isideB
              << "\nheight "s << iheight << '\n';
    std::cout << "perimiter "s << jshape.IsoscelesTriangle::perimeter() << '\n';
    std::cout << std::endl;

    std::cout << "..... - RightTriangle\n"s;
    std::cout << jshape.RightTriangle::display() << '\n';
    auto [rbase, rheight, rsideA, rsideB] = jshape.RightTriangle::dimensions();
    std::cout << "base "s << rbase
              << " sides "s << rsideA << ", "s << rsideB
              << "\nheight "s << rheight << '\n';
    std::cout << "perimiter "s << jshape.RightTriangle::perimeter() << '\n';
    std::cout << std::endl;
  }

  return 0;
}

//  MARK: - Class Shape Implementation.
bool Shape::debug_ = true;

//  MARK: - Class Quadrilateral Implementation.
/*
 *  MARK: Quadrilateral::Quadrilateral() - default c'tor
 */
Quadrilateral::Quadrilateral(double baseA, double sideA, double baseB, double sideB)
  : baseA_(baseA), sideA_(sideA), baseB_(baseB), sideB_(sideB) {
  if (debug_) {
    std::cout << "Quadrilateral::Quadrilateral"s
              << std::setw(6) << sideA
              << std::setw(6) << baseA
              << std::setw(6) << sideB
              << std::setw(6) << baseB << " - "
              << std::setw(6) << sideA_
              << std::setw(6) << baseA_
              << std::setw(6) << sideB_
              << std::setw(6) << baseB_
              << std::endl;
  }
}

/*
 *  MARK: Quadrilateral::perimeter()
 */
double Quadrilateral::perimeter() const {
  return baseA_ + sideA_ + baseB_ + sideB_;
}

//  MARK: - Class Rectangle Implementation.
/*
 *  MARK: Rectangle::Rectangle() - default c'tor
 */
Rectangle::Rectangle(double length, double breadth)
  : Quadrilateral(length, breadth, length, breadth) {
  if (debug_) {
    std::cout << "Rectangle::Rectangle"s
              << std::setw(6) << length
              << std::setw(6) << breadth << " - "s
              << std::setw(6) << sideA_
              << std::setw(6) << baseA_
              << std::setw(6) << sideB_
              << std::setw(6) << baseB_
              << std::endl;
  }
}

/*
 *  MARK: Rectangle::dimensions()
 */
std::tuple<double, double, double, double>
Rectangle::dimensions() const {
  std::cout << "Rectangle::"s << __func__ << std::endl;
  auto rt = std::make_tuple(baseA_, sideA_, NAN, NAN);
  return rt;
}

/*
 *  MARK: Rectangle::display()
 */
std::string
Rectangle::display() const {
  std::ostringstream disp;
  disp << "length "s << baseA_
        << ", breadth "s << sideA_
        << ", perimeter "s << perimeter()
        << ", area "s << std::fixed << area();
  return disp.str();
}

/*
 *  MARK: Rectangle::area()
 */
double
Rectangle::area() const {
  return baseA_ * sideA_;
}

//  MARK: - Class Square Implementation.
/*
 *  MARK: Square::Square() - default c'tor
 */
Square::Square(double length)
  : Rectangle(length, length)
  , Quadrilateral(length, length, length, length) {
  if (debug_) {
    std::cout << "Square::Square"s
              << std::setw(6) << length << " - "
              << std::setw(6) << sideA_
              << std::setw(6) << baseA_
              << std::setw(6) << sideB_
              << std::setw(6) << baseB_
              << std::endl;
  }
}

/*
 *  MARK: Square::dimensions()
 */
std::tuple<double, double, double, double>
Square::dimensions() const {
  std::cout << "Square::"s << __func__ << std::endl;
  auto rt = std::make_tuple(baseA_, NAN, NAN, NAN);
  return rt;
}

/*
 *  MARK: Square::display()
 */
std::string
Square::display() const {
  std::ostringstream disp;
  disp << "length "s << baseA_
        << ", perimeter "s << perimeter()
        << ", area "s << std::fixed << area();
  return disp.str();
}

//  MARK: - Class Parallelogram Implementation.
/*
 *  MARK: Parallelogram::Parallelogram() = default c'tor
 */
Parallelogram::Parallelogram(double height, double base, double side)
  : Quadrilateral(base, side, base, side), height_(height) {
  if (debug_) {
    std::cout << "Parallelogram::Parallelogram"s
              << std::setw(6) << sideA_
              << std::setw(6) << baseA_
              << std::setw(6) << sideB_
              << std::setw(6) << baseB_
              << std::endl;

  }
}

std::string Parallelogram::display() const {
  std::ostringstream disp;
  disp << "base "s << baseA_
       << ", side "s << sideA_
       << ", height "s << height_
       << ", perimeter "s << perimeter()
       << ", area "s << std::fixed << area();
  return disp.str();
}

/*
 *  MARK: Parallelogram::area()
 */
double Parallelogram::area() const {
  return baseA_ * height_;
}

/*
 *  MARK: Parallelogram::dimensions()
 */
std::tuple<double, double, double, double>
Parallelogram::dimensions() const {
  std::cout << "Parallelogram::"s << __func__ << std::endl;
  auto rt = std::make_tuple(baseA_, height_, sideA_, NAN);
  return rt;
}


//  MARK: - Class Triangle Implementation.
/*
 *  MARK: Triangle::Triangle() - default c'tor
 */
Triangle::Triangle(double base, double height, double sideA, double sideB)
  : base_(base), height_(height), sideA_(sideA), sideB_(sideB) {
  if (debug_) {
    std::cout << "Triangle::Triangle"s
              <<  std::setw(8) << height
              <<  std::setw(8) << base
              <<  std::setw(8) << sideA
              <<  std::setw(8) << sideB << " - "s
              <<  std::setw(8) << height_
              <<  std::setw(8) << base_
              <<  std::setw(8) << sideA_
              <<  std::setw(8) << sideB_
              <<  std::endl;
  }
}

/*
 *  MARK: Triangle::dimensions()
 */
std::tuple<double, double, double, double>
Triangle::dimensions() const {
  std::cout << "Triangle::"s << __func__ << std::endl;
  auto rt = std::make_tuple(base_, height_, sideA_, sideB_);
  return rt;
}

/*
 *  MARK: Triangle::display()
 */
std::string
Triangle::display() const {
  std::ostringstream disp;
  disp << "base "s << base_
        << ", height "s << height_
        << ", area "s << std::fixed << area();
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

//  MARK: - Class RightTriangle Implementation.
/*
 *  MARK: RightTriangle::RightTriangle() - default c'tor
 */
RightTriangle::RightTriangle(double base, double height)
: Triangle(base, height, height) {
//  base_  = base;
//  sideA_ = height_ = height;
  sideB_ = hypotenuse_ = std::hypot(base_, height_);
  if (debug_) {
    std::cout << "RightTriangle::RightTriangle"s
    <<  std::setw(8) << height
    <<  std::setw(8) << base << " - "s
    <<  std::setw(8) << height_
    <<  std::setw(8) << base_
    <<  std::setw(8) << sideA_
    <<  std::setw(8) << sideB_
    <<  std::setw(8) << hypotenuse_
    <<  std::endl;
  }
}

/*
 *  MARK: RightTriangle::display()
 */
std::string
RightTriangle::display() const {
  std::ostringstream disp;
  disp << "base "s << base_
       << ", height "s << height_
       << ", hypotenuse "s << hypotenuse_
       << ", perimeter "s << perimeter()
       << ", area "s << std::fixed << area();
  return disp.str();
}

//  MARK: - Class EquilateralTriangle Implementation.
/*
 *  MARK: EquilateralTriangle::EquilateralTriangle() - default c'tor
 */
EquilateralTriangle::EquilateralTriangle(double base)
  : Triangle(base, NAN, base, base),
    IsoscelesTriangle(base, NAN) {
  height_ = std::sqrt(3.0) / 2 * base_;
  //  TODO: there's more than one way to do it (tmtowtdi]
  //height_ = std::sqrt( (base * base) - ((base / 2) * (base / 2)) );
  //height_ = std::sqrt( (base * base) - (base * base / 4) );
  sideA_ = sideB_ = base_;
  if (debug_) {
    std::cout << "EquilateralTriangle::EquilateralTriangle"s
              <<  std::setw(8) << base << " - "s
              <<  std::setw(8) << height_
              <<  std::setw(8) << base_
              <<  std::setw(8) << sideA_
              <<  std::setw(8) << sideB_
              <<  std::endl;
  }
}

/*
 *  MARK: EquilateralTriangle::display()
 */
std::string
EquilateralTriangle::display() const {
  std::ostringstream disp;
  disp << "base "s << base_
        << ", height "s << height_
        << ", perimeter "s << perimeter()
        << ", area "s << std::fixed << area();
  return disp.str();
}

/*
 *  MARK: EquilateralTriangle::area()
 */
double
EquilateralTriangle::area() const {
  return std::sqrt(3.0) / 4 * (base_ * base_);
}

//  MARK: - Class IsoscelesTriangle Implementation.
/*
 *  MARK: IsoscelesTriangle::IsoscelesTriangle() - default c'tor
 */
IsoscelesTriangle::IsoscelesTriangle(double base, double height)
  : Triangle(base, height, NAN, NAN) {
  ibase_ = iheight_ = iside_ = NAN;
  sideA_ = sideB_ = std::hypot(base_ / 2., height_);
  //  std::sqrt((base_ * base_ / 4) + (height_ * height_));
  if (debug_) {
    std::cout << "IsoscelesTriangle::IsoscelesTriangle"s
              <<  std::setw(8) << height
              <<  std::setw(8) << base << " - "s
              <<  std::setw(8) << height_
              <<  std::setw(8) << base_
              <<  std::setw(8) << sideA_
              <<  std::setw(8) << sideB_
              <<  std::endl;
  }
}

/*
 *  MARK: IsoscelesTriangle::display()
 */
std::string
IsoscelesTriangle::display() const {
  std::ostringstream disp;
  if (std::isnan(ibase_) && std::isnan(iheight_) && std::isnan(iside_)) {
    disp << "base "s << base_
         << ", height "s << height_
         << ", side length "s << sideA_
         << ", perimeter "s << perimeter()
         << ", area "s << std::fixed << area();
  }
  else {
    disp << "base "s << ibase_
         << ", height "s << iheight_
         << ", side length "s << iside_
         << ", perimeter "s << perimeter()
         << ", area "s << std::fixed << area();
  }
  return disp.str();

}

/*
 *  MARK: IsoscelesTriangle::dimensions()
 */
std::tuple<double, double, double, double>
IsoscelesTriangle::dimensions() const {
  std::cout << "IsoscelesTriangle::"s << __func__ << std::endl;
  std::tuple<double, double, double, double> rt;
  if (std::isnan(ibase_) && std::isnan(iheight_) && std::isnan(iside_)) {
    rt = this->Triangle::dimensions();
//    rt = std::make_tuple(base_, height_, sideA_, sideB_);
  }
  else {
    rt = std::make_tuple(ibase_, iheight_, iside_, iside_);
  }
  return rt;
}

//  MARK: - Class RightIsoscelesTriangle Implementation.
/*
 *  MARK: RightIsoscelesTriangle::RightIsoscelesTriangle() - default c'tor
 */
RightIsoscelesTriangle::RightIsoscelesTriangle(double height)
: Triangle(height, height, height, NAN),
  RightTriangle(height, height),
  IsoscelesTriangle(NAN, NAN)
{
  ibase_ = hypotenuse_ = sideB_ = std::hypot(base_, height_);
  iside_ = sideA_ = height_;
  iheight_ = std::sqrt((height_ * height_) - (sideB_ * sideB_ / 4.0));
  if (debug_) {
    std::cout << "RightIsoscelesTriangle::RightIsoscelesTriangle"s
              <<  std::setw(8) << height << " - "s
              <<  std::setw(8) << height_
              <<  std::setw(8) << base_
              <<  std::setw(8) << sideA_
              <<  std::setw(8) << sideB_
              <<  std::setw(8) << iheight_
              <<  std::setw(8) << ibase_
              <<  std::setw(8) << iside_
              <<  std::endl;
  }
}

/*
 *  MARK: display()
 */
std::string RightIsoscelesTriangle::display() const {
  std::ostringstream disp;
  disp << "base "s << base_
       << ", height "s << height_
       << ", (sides "s << sideA_ << ", " << sideB_ << ")"
       << ", hypotenuse "s << hypotenuse_
       << ", (height 2) "s << iheight_
       << ", perimiter "s << perimeter()
       << ", area "s << area();
  return disp.str();
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
  std::cout << "Circle::"s << __func__ << std::endl;
  auto rt = std::make_tuple(radius_, NAN, NAN, NAN);
  return rt;
}

/*
 *  MARK: Circle::display()
 */
std::string
Circle::display() const {
  std::ostringstream disp;
  disp << "radius "s << radius_
        << ", circumference "s << circumference()
        << ", area "s << area();
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
