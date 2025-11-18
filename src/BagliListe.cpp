/**
 * @file BagliListe.cpp
 * @description Dugumlerinde agac tutan ve bu agacin fonksiyonlarina erismemi, gostermemi saglayan bagliliste sinifim
 * @course 2-C
 * @assignment 2
 * @date 14.12.2024
 * @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
 */
#include "BagliListe.hpp"
#include <iostream>
#include <fstream>
using namespace std;
string agaclartxt = "agaclar.txt";
BagliListe::BagliListe()
{

    ilk = 0;
    dugumSayisi = 0;
}

BagliListe::~BagliListe()
{
    Dugum *gec = ilk;
    while (gec != 0)
    {
        Dugum *sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
    dugumSayisi = 0;
    ilk = 0;
}
// BagliListe elemanlarini eklemek icin kullanilan fonksiyon
void BagliListe::ekle(Agac *agac)
{
    Dugum *yeni = new Dugum(agac);
    if (ilk == 0)
    {
        ilk = yeni;
        dugumSayisi++;
        return;
    }
    else
    {
        Dugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        dugumSayisi++;
    }
}
// BagliListe elemanlarini cikarmak icin kullanilan fonksiyon
void BagliListe::cikar(int sira)
{
    if (ilk == 0)
    {
        return;
    }
    if (sira < 0 || sira >= dugumSayisi)
    {
        return;
    }
    // Eğer ilk eleman çıkarılacaksa
    if (sira == 0)
    {
        Dugum *sil = ilk;
        ilk = ilk->sonraki;
        dugumSayisi--;
        delete sil;
        return;
    }
    Dugum *gec = ilk;
    int sayac = 0;
    // Sıra numarasına ulaşana kadar gez
    while (gec->sonraki != 0 && sayac < sira - 1)
    {
        gec = gec->sonraki;
        sayac++;
    }
    if (gec->sonraki == 0)
    {
        return;
    }
    // Sıra numarasındaki elemanı çıkar
    Dugum *sil = gec->sonraki;
    gec->sonraki = gec->sonraki->sonraki;
    dugumSayisi--;
    delete sil;
}

// BagliListe elemanlarinin dugumlerinden istenilen dugumun getirilmesini saglayan fonksiyon
Dugum *BagliListe::dugumGetir(int sira)
{

    if (sira < 0 || sira > dugumSayisi)
    {
        return 0;
    }
    else
    {
        Dugum *gec = ilk;
        int sayac = 0;
        while (gec != 0)
        {
            if (sira == sayac)
            {
                return gec;
            }
            gec = gec->sonraki;
            sayac++;
        }
    }
}
// Dosya daki verileri okuyup agac yapmaya yarayan fonksiyon
void BagliListe::ekleDosyadakiAgaclar()
{
    string agaclartxt = "agaclar.txt";
    ifstream oku(agaclartxt);
    string satir;

    while (getline(oku, satir))
    {

        if (satir.empty())
        {
        }
        else
        {
            Agac *yeniAgac = new Agac();
            yeniAgac->satiriAgacYap(satir);
            ekle(yeniAgac);
        }
    }
    cout << "Agaclareklendi";

    oku.close();
}
// Agaci cizdirmeyi cagiran fonksiyon
void BagliListe::agaciGoster(int sira)
{
    Dugum *dugum = dugumGetir(sira);
    if (dugum != 0)
    {
        Agac &agac = *(dugum->agac);
        agac.levelOrder();
    }
    else
    {
        cout << "0" << endl;
    }
}