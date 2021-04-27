#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
private:
    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
public:
    Rectangle(int xFrom, int yFrom, int xTo, int yTo){
        this->xFrom = xFrom;
        this->yFrom = yFrom;
        this->xTo = xTo;
        this->yTo = yTo;
    }
    int getX() const {
        return xFrom;
    }

    int getY() const {
        return yFrom;
    }

    int getXTo() const {
        return xTo;
    }

    int getYTo() const {
        return yTo;
    }
    virtual bool isIn(int x, int y) const override{
        return x >= xFrom && x <= xTo && y >= yFrom && y <= yTo;
    }
};
} // namespace Shapes

#endif // RECTANGLE_H
