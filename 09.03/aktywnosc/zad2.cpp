#include <iostream>

class StudenckaLodowka
{
public:

    StudenckaLodowka()
    {
        std::cout << "Sprawdz temperatury" << std::endl;
    }
    ~StudenckaLodowka()
    {
        std::cout << "Zamykam lodowke" << std::endl;
    }
    class Chlodnia
    {
        int temp;

    public:
        Chlodnia(int temp)
        {
            this->temp = temp;
            std::cout << "Temperatura w chlodni: " << temp << "C" << std::endl;
        }
        ~Chlodnia()
        {
            std::cout << "Zamykam chlodnie" << std::endl;
        }
    };

    class Zamrazalnik
    {
        int temp;

    public:
        Zamrazalnik(int temp)
        {
            this->temp = temp;
            std::cout << "Temperatura w zamrazalniku: " << temp << "C" << std::endl;
        }
        ~Zamrazalnik()
        {
            std::cout << "Zamykan zamrazalnik" << std::endl;
        }
    };


};


int main()
{
    StudenckaLodowka studenckaLodowka;
    StudenckaLodowka::Chlodnia chlodnia(5);
    StudenckaLodowka::Zamrazalnik zamrazalnik(-15);

    return 0;
}
