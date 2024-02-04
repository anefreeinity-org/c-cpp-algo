#include "String.h"
using namespace ANEFreeInIty;

int main()
{
    String firstName("Ayan ");
    String lastName("Bhattacharya");
    String fullName = firstName + lastName;
    std::cout << fullName << std::endl;
}