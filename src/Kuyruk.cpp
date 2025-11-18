/**
* @file Kuyruk.cpp
* @description Level order yapabilmek icin kuyruk veriyapisina ihtiyac vardi bende kullanabilmek adina kendi kuyruk veriyapimi olusturdum
* @course 2-C
* @assignment 2
* @date 22.12.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "Kuyruk.hpp"

Kuyruk::Kuyruk()
{
    ilk = 0;
    son = 0;
}
Kuyruk::~Kuyruk()
{
    while (ilk != 0)
    {
        KDugum *gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
}
//kuyrugun bosmu dolumu oldugunu kontrol eden fonksiyon
bool Kuyruk::bosmu()
{
    if (ilk == 0)
    {
        return true;
    }
    return false;
}
//kuyruga ekleme yapan fonksiyon
void Kuyruk::ekle(ADugum *dugum)
{
    if (ilk == 0)
    {
        ilk = new KDugum(dugum);
        son = ilk;
    }
    else
    {
        KDugum *yeni = new KDugum(dugum);
        son->sonraki = yeni;
        son = yeni;
    }
}
//kuyruktan veri cikarmaya yarayan fonksiyon
void Kuyruk::cikar()
{
    if (ilk != 0)
    {
        KDugum *gec = ilk->sonraki;
        delete ilk;
        ilk = gec;
        if (ilk == 0)
        {
            son = 0;
        }
    }
}
//kuyrukdan dugumu getiren fonksiyon
ADugum *Kuyruk::getir()
{
    if (ilk != 0)
    {
        return ilk->dugum;
    }
}