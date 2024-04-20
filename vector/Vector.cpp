#include <cmath>

class Vector
{
    double _x;
    double _y;
    double _z;

public:
    Vector(double x, double y, double z)
    {
        this->_x = x;
        this->_y = y;
        this->_z = z;
    }

    Vector(double x, double y)
    {
        this->_x = x;
        this->_y = y;
        this->_z = 0;
    }

    Vector()
    {
        this->_x = 0;
        this->_y = 0;
        this->_z = 0;
    }

    Vector *Clone() const
    {
        return new Vector(this->_x, this->_y, this->_z);
    }

    Vector *operator-(Vector const &obj) const
    {
        return new Vector(this->_x - obj._x, this->_y - obj._y, this->_z - obj._z);
    }

    void CrossProduct(Vector const &obj, Vector const &obj2)
    {
        this->_x = obj._y * obj2._z - obj._z * obj2._y;
        this->_y = obj._z * obj2._x - obj._x * obj2._z;
        this->_z = obj._x * obj2._y - obj._y * obj2._x;
    }

    double Length() const
    {
        return sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
    }
};