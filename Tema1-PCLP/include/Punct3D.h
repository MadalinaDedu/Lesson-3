#ifndef PUNCT3D_H
#define PUNCT3D_H


class Punct3D
{
public:
    Punct3D(double,double,double );
    Punct3D();
    void setX(double);
    double getX();

    void setY(double );
    double getY();

    void setZ(double);
    double getZ();


private:
    double x;
    double y;
    double z;

};

#endif // PUNCT3D_H

