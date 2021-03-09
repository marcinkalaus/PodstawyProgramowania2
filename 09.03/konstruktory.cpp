#include <iostream>
#include <string>
#include <math.h>

class Kolo
{
    private:
        double radius = 0;

    public:
        Kolo(double r)
        {
            std::cout << "Tworze kolo" << std::endl;
            this->radius = r;
        }
        ~Kolo()
        {
            std::cout << "Usuwam kolo" << std::endl;
        }
        void setR(double r)
        {
            this->radius = r;
        }
        int getR() const
        {
            return radius;
        }

        double calculateArea() const { return M_PI*pow(radius,2); }
        double calculatePerimeter() const { return 2*M_PI*radius; }
};

class Prostokat
{
    private:
        double a;
        double b;

    public:
        Prostokat(double a)
        {
            std::cout << "Tworze kwadrat" << std::endl;
            this->a = a;
        }
        Prostokat(double a, double b)
        {
            std::cout << "Tworze prostokat" << std::endl;
            this->a = a;
            this->b = b;
        }
        ~Prostokat()
        {
            std::cout << "Usuwam prostokat" << std::endl;
        }
        void setSides(double a, double b)
        {
            this->a = a;
            this->b = b;
        }
        double getA() const
        {
            return a;
        }
        double getB() const
        {
            return b;
        }

        double calculateArea() const { return a*b; }
        double calculatePerimeter() const { return 2*a+2*b; }
};

int main()
{
    Kolo kolo(5);
    std::cout << kolo.calculateArea() << std::endl;
    std::cout << kolo.calculatePerimeter() << std::endl;


    Prostokat prostokat(2,4);
    std::cout << prostokat.calculateArea() << std::endl;
    std::cout << prostokat.calculatePerimeter() << std::endl;

    return 0;
}
