#ifndef CIRCLE_H
#define CIRCLE_H

#include <QtGlobal>
#include <QtCore>
#include <QRect>
#include "math.h"

// Circle class used as a member of the Tile class
// Used to detect a tower range and enemies in range

class Circle
{
   public:
    // sets
    Circle();

    // helper function used in intersects function
    bool contains(int px, int py);
    
    // returns true if a given rectangle intersects the circle
    bool intersects(QRect *r);
    
    // reassigns the x,y points and radius
    void setValues(int px, int py, int r);
    
    // getters for x,y, radius
    int x();
    int y();
    int getR();

private:
    int xC;
    int yC;
    int radius;
    double curvex;
    double curvey;
};

#endif // CIRCLE_H
