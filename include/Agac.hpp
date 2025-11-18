#include "ADugum.hpp"
#ifndef Agac_hpp
#define Agac_hpp

#include <iostream>
using namespace std;

class Agac
{
public:
    Agac();
    ~Agac();
    int yukseklik();
    void ekle(char veri);
    int veriHesapla();
    void aynalama();
    friend ostream &operator<<(ostream &os, Agac &agac);
    void levelOrder();
    void satiriAgacYap(string satir);
    void sil(ADugum *&aktif);

private:
    int yukseklik(ADugum *aktifDugum);
    void ekle(char veri, ADugum *aktifDugum);
    int veriHesapla(ADugum *aktif, int carpan);
    void aynalama(ADugum *aktif);
    void boslukBirak(int adet);
    void noktaBirak(int adet);
    ADugum *kok;
};

#endif