#include "Agac.hpp"
#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{

public:
    Agac *agac;
    Dugum(Agac* agac);
    ~Dugum();
    Dugum *sonraki;
private:
};

#endif