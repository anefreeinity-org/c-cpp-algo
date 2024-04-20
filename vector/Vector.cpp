#include <cmath>

class Vector
{
public:
    double x, y, z;

    Vector(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector(double x, double y)
    {
        this->x = x;
        this->y = y;
        this->z = 0;
    }

    Vector()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector *Clone() const
    {
        return new Vector(this->x, this->y, this->z);
    }

    Vector *operator-(Vector const &obj) const
    {
        return new Vector(this->x - obj.x, this->y - obj.y, this->z - obj.z);
    }

    void CrossProduct(Vector const &obj, Vector const &obj2)
    {
        this->x = obj.y * obj2.z - obj.z * obj2.y;
        this->y = obj.z * obj2.x - obj.x * obj2.z;
        this->z = obj.x * obj2.y - obj.y * obj2.x;
    }

    double Length() const
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
};