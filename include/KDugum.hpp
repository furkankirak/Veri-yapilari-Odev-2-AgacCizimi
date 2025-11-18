#include "ADugum.hpp"
#ifndef KDugum_hpp
#define KDugum_hpp

class KDugum
{
private:
public:
    KDugum(ADugum *dugum);
    ADugum *dugum;
    KDugum *sonraki;
};

#endif