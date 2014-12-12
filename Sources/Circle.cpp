#include "circle.h"

Circle::Circle(){
    xC = 0;
    yC = 0;
    radius = 0;
}

// sets values
void Circle::setValues(int px, int py, int r){
    xC = px;
    yC = py;
    radius = r;
}

// helper function returns true is a given point lies in square
// Used in intersects function
bool Circle::contains(int px, int py){
    double distancex, distancey, distance;
    distancex = qAbs(xC-px);
    distancey = qAbs(yC-py);
    distance = qSqrt(qPow(distancex,2)+qPow(distancey,2));

    if (distance>=radius)
                return false;
            else
                return true;
}

// returns true if a enemy's rectangle intersects the circle, otherwise false
// checks points in circles of varying sizes
bool Circle::intersects(QRect *r){
    for (double i = 0; i < 361; i+=2){
        curvex = radius*qCos(i*M_PI/180);
        curvey = radius*qSin(i*M_PI/180);
        if(r->contains(xC+(int)curvex,yC-(int)curvey)){
            return true;
        }        
    }
    for (double i = 0; i < 361; i+=2){
        curvex = radius/4*qCos(i*M_PI/180);
        curvey = radius/4*qSin(i*M_PI/180);
        if(r->contains(xC+(int)curvex,yC-(int)curvey)){
            return true;
        }       
    }
    for (double i = 0; i < 361; i+=2){
        curvex = radius/1.5*qCos(i*M_PI/180);
        curvey = radius/1.5*qSin(i*M_PI/180);
        if(r->contains(xC+(int)curvex,yC-(int)curvey)){
            return true;
        }
    }        
    for (double i = 0; i < 361; i+=2){
        curvex = radius/2*qCos(i*M_PI/180);
        curvey = radius/2*qSin(i*M_PI/180);
        if(r->contains(xC+(int)curvex,yC-(int)curvey)){
            return true;
        }
    }        
            return false;
}

int Circle::x(){
    return xC;
}

int Circle::y(){
    return yC;
}

int Circle::getR(){
    return radius;
}
