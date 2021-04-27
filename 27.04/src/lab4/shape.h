#ifndef SHAPE_H
#define SHAPE_H

#include <utility> // std::pair<>

/** Tresc do zrobienia:
Prosze o zaimplementowanie klasy czysto abstrakcyjnej Shape, majacej funkcje:
bool isIn(int x, int y) const, ktora dla podklas zwraca informacje czy dany punkt jest wewnatrz figury.
    Najlepiej jak metoda ta bedzie czysto wirtualna!
Po niej maja implementowac klasy:
Rectangle i Circle
oraz klasa-kompozyt ShapeComposite, ktora w konstruktorze przyjmuje dwie shared_ptr<Shape>
i operacje na zbiorach: INTERSECTION, SUM, DIFFERENCE
W oparciu o to bedzie mozna cala hierarchie figur polaczyc w jedno drzewo,
dla ktorego bedzie mozna zapytac czy dany punkt jest w hierarchii, czy nie.
Przyklad z kodu testow:
     21:            *******
     20:          ***********
     19:         *************
     18:        ***************
     17:       *****************
     16:      *******************
     15:      *******************
     14:     *********************
     13:     *********************
     12:     ***      ***      ***
     11:     ***      ***      ***
     10:     ***      ***      ***
      9:     ***      ***      ***
      8:     ***      ***      ***
      7:     ***      ***      ***
      6:     ***      ************
      5:     ***      ************
      4:     ***      ************
      3:     ***      ************
      2:     ***      ************
      1:     *********************
Opcjonalnie mozna sobie zaimplementowac klase Stage rysujaca na konsole.
**/

namespace Shapes
{
typedef std::pair<int,int> Point;

class Shape
{
public:
    virtual bool isIn(int x, int y) const = 0;
    virtual ~Shape(){}
};
} // namespace Shapes

#endif // SHAPE_H
