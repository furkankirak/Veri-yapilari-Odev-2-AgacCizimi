#include "KDugum.hpp"
#ifndef Kuyruk_hpp
#define Kuyruk_hpp

using namespace std;

class Kuyruk
{
private:
KDugum* ilk;
KDugum* son;
    
public:
    Kuyruk();
    ~Kuyruk();
    void ekle(ADugum* dugum);
    void cikar();
    ADugum* getir();
    bool bosmu();
};


#endif