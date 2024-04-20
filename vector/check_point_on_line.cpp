#include <iostream>
#include "./Vector.cpp"

bool IsPointOnLine(const Vector &pointA, const Vector &pointB, const Vector &pointToCheck)
{
    Vector *vector_pointA_pointToCheck = pointA - pointToCheck;
    Vector *vector_pointB_pointToCheck = pointB - pointToCheck;
    Vector *resultVector = new Vector();

    resultVector->CrossProduct(*vector_pointB_pointToCheck, *vector_pointA_pointToCheck);
    return (resultVector->Length() == 0);
}

int main()
{
    std::string result = IsPointOnLine(Vector(2, 2, 2), Vector(4, 2, 2), Vector(3, 2.0001, 2)) == 1 ? "true" : "false";
    std::cout << result << std::endl;
    return 0;
}