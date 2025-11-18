#include "Dugum.hpp"
#include "Agac.hpp"
#ifndef BagliListe_hpp
#define BagliListe_hpp

class BagliListe
{

public:
    BagliListe();
    ~BagliListe();
    void ekle(Agac *agac);
    void cikar(int sira);
    Dugum *dugumGetir(int sira);
    int dugumSayisi;
    void ekleDosyadakiAgaclar();
    void agaciGoster(int sira);

private:
    Dugum *ilk;
};
#endif