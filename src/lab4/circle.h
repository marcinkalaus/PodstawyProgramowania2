#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
private:
    int xCenter;
    int yCenter;
    int radius;
public:
    Circle(int xCenter, int yCenter, int radius){
        this->xCenter = xCenter;
        this->yCenter = yCenter;
        this->radius = radius;
    }
    int getX() const {
        return xCenter;
    }

    int getY() const {
        return yCenter;
    }

    int getRadius() const {
        return radius;
    }
    virtual bool isIn(int x, int y) const override{
        return pow((x - xCenter),2) + pow((y - yCenter),2) <= pow(radius,2);
    }
};
} // namespace Shapes

#endif // CIRCLE_H
