#include <iostream>
#include <cmath>
#include <string>

const double PI = 3.14159265358979323846; // Приблизне значення числа π

class Figure {
public:
    virtual double perimeter() const = 0;
};

class Rectangle : public Figure {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {
        return 2 * PI * radius;
    }
};

class RightTriangle : public Figure {
private:
    double base;
    double height;

public:
    RightTriangle(double b, double h) : base(b), height(h) {}

    double perimeter() const override {
        double hypotenuse = std::sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }
};

class Trapezoid : public Figure {
private:
    double topLength;
    double bottomLength;
    double leftSide;
    double rightSide;

public:
    Trapezoid(double tL, double bL, double lS, double rS)
        : topLength(tL), bottomLength(bL), leftSide(lS), rightSide(rS) {}

    double perimeter() const override {
        return topLength + bottomLength + leftSide + rightSide;
    }
};

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}
    virtual ~Person() {}

    virtual void printInfo() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Woman : virtual public Person {
public:
    Woman(const std::string& n) : Person(n) {}

    void printInfo() const override {
        std::cout << "Woman's name: " << name << std::endl;
    }
};

class Employee : virtual public Person {
protected:
    double salary;

public:
    Employee(const std::string& n, double s) : Person(n), salary(s) {}

    void printInfo() const override {
        std::cout << "Employee's name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

class FemaleEmployee : public Woman, public Employee {
public:
    FemaleEmployee(const std::string& n, double s) : Person(n), Employee(n, s), Woman(n) {}

    void printInfo() const override {
        std::cout << "Female employee's name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

int main() {
    int choice;
    std::cout << "Enter 1 for geometric figures or 2 for person information: ";
    std::cin >> choice;

    if (choice == 1) {
        Rectangle rectangle(4, 5);
        Circle circle(3);
        RightTriangle rightTriangle(3, 4);
        Trapezoid trapezoid(2, 4, 3, 5);

        std::cout << "Rectangle perimeter: " << rectangle.perimeter() << std::endl;
        std::cout << "Circle perimeter: " << circle.perimeter() << std::endl;
        std::cout << "Right triangle perimeter: " << rightTriangle.perimeter() << std::endl;
        std::cout << "Trapezoid perimeter: " << trapezoid.perimeter() << std::endl;
    }
    else if (choice == 2) {
        Person person("John");
        person.printInfo();
        std::cout << std::endl;

        Woman woman("Mary");
        woman.printInfo();
        std::cout << std::endl;

        Employee employee("Alice", 5000);
        employee.printInfo();
        std::cout << std::endl;

        FemaleEmployee femaleEmployee("Emma", 6000);
        femaleEmployee.printInfo();
        std::cout << std::endl;
    }
    else {
        std::cout << "Invalid choice. Exiting..." << std::endl;
    }

    return 0;
}



