/**
 * @file Agac.cpp
 * @description  Agaci oluşturma yazdırma verisini hesaplama ve aynalama işlemlerini yaptiğim İkili arama agaci sinifim
 * @course 2-C
 * @assignment 2
 * @date 15.12.2024
 * @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
 */
#include "Agac.hpp"
#include <iostream>
#include <cmath>
#include <Kuyruk.hpp>
using namespace std;

Agac::Agac()
{
    kok = 0;
}

Agac::~Agac()
{
    sil(kok);
}
// agaci silmeye yarayan fonksiyon
void Agac::sil(ADugum *&aktif)
{
    if (aktif == 0)
    {
        return;
    }
    sil(aktif->sol);
    sil(aktif->sag);
    delete aktif;
    aktif = 0;
}

// agaca veri eklenmesi islemini yapan fonksiyon public
void Agac::ekle(char veri)
{
    if (kok == 0)
    {
        kok = new ADugum(veri);
    }
    else
    {
        ekle(veri, kok);
    }
}
// agaca veri eklenmesi islemini yapan fonksiyon
void Agac::ekle(char veri, ADugum *aktifDugum)
{
    if (aktifDugum->veri > veri)
    {
        if (aktifDugum->sol)
        {
            ekle(veri, aktifDugum->sol);
        }
        else
        {
            aktifDugum->sol = new ADugum(veri);
        }
    }
    else if (aktifDugum->veri < veri)
    {
        if (aktifDugum->sag)
        {
            ekle(veri, aktifDugum->sag);
        }
        else
        {
            aktifDugum->sag = new ADugum(veri);
        }
    }
    else
    {
        return;
    }
}

// agacin yuksekligini bulan fonksiyon public
int Agac::yukseklik()
{
    return yukseklik(kok);
}
// agacin yuksekligini bulan fonksiyon
int Agac::yukseklik(ADugum *aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
    }
    return -1;
}
// level order islemlerinde agac yapisin olusturmak icin aralara baslangica gelecek bosluklarin kisa formulu 2^n-1
void Agac::boslukBirak(int adet)
{
    int bosluk = (pow(2, adet) - 1);
    for (int i = 0; i < bosluk; i++)
        cout << " ";
}
// level order islemlerinde agac yapisin olusturmak icin dugumler arasindaki nokta birakma fonksiyonu
void Agac::noktaBirak(int adet)
{
    int nokta = (pow(2, adet) - 1);
    for (int i = 0; i < nokta; i++)
        cout << ".";
}
// agac yazdirma islemini yapmak için faydalandığım level order fonksiyonum
void Agac::levelOrder()
{
    if (kok == 0)
    {
        return;
    }
    // Verilerin yazılması için gerekli kuyruk
    Kuyruk kuyruk;
    kuyruk.ekle(kok);
    // Noktalarin(coklu) yazılması için gerekli kuyruk
    Kuyruk ikinciKuyruk;
    ikinciKuyruk.ekle(kok);
    // Noktalarin(tekli) yazılması için gerekli kuyruk
    Kuyruk ucuncuKuyruk;
    ucuncuKuyruk.ekle(kok);
    // dongulerin yazilamasi için seviye degiskenleri
    int seviye = 0;
    int ikinciDonguSeviye = 0;
    int ucuncuDonguSeviye = 0;
    // yukseklik
    int yuksek = yukseklik();
    // dongulerin yazilmasi icin gerekli kat ifadesi
    int kat = 0;
    int ikinciDongukat = 0;
    int ucuncuDongukat = 0;
    // dongusirasini kontrol edebilmek için gerekli ifade
    int donguSirasi = 0;

    cout << endl;
    while (!kuyruk.bosmu() && seviye <= yuksek)
    {
        ADugum *siradaki = kuyruk.getir();

        kuyruk.cikar();

        // Noktalarin yazdirilmasi icin gerekli döngü
        while (donguSirasi == 2 && !ikinciKuyruk.bosmu() && ikinciDonguSeviye <= yuksek)
        {
            ADugum *ikinciSiradaki = ikinciKuyruk.getir();
            ikinciKuyruk.cikar();
            if (ikinciDongukat == 0)
            {
                boslukBirak(yuksek - ikinciDonguSeviye - 1);
            }

            if (ikinciSiradaki)
            {

                if (ikinciSiradaki->sol)
                {
                    cout << ".";
                    noktaBirak(yuksek - ikinciDonguSeviye - 1);
                    cout << ".";
                    if (ikinciSiradaki->sag)
                    {
                        noktaBirak(yuksek - ikinciDonguSeviye - 1);
                        cout << ".";
                    }
                    else
                    {
                        boslukBirak(yuksek - ikinciDonguSeviye - 1);
                        cout << " ";
                    }
                }
                else if (ikinciSiradaki->sag)
                {
                    cout << " ";
                    boslukBirak(yuksek - ikinciDonguSeviye - 1);
                    cout << ".";
                    noktaBirak(yuksek - ikinciDonguSeviye - 1);
                    cout << ".";
                }
                else
                {
                    cout << " ";
                    boslukBirak(yuksek - ikinciDonguSeviye - 1);
                    cout << " ";
                    boslukBirak(yuksek - ikinciDonguSeviye - 1);
                    cout << " ";
                }
            }
            else
            {
                cout << " ";
                boslukBirak(yuksek - ikinciDonguSeviye - 1);
                cout << " ";
                boslukBirak(yuksek - ikinciDonguSeviye - 1);
                cout << " ";
            }

            boslukBirak(yuksek - ikinciDonguSeviye);

            if (ikinciSiradaki)
            {
                ikinciKuyruk.ekle(ikinciSiradaki->sol);
                ikinciKuyruk.ekle(ikinciSiradaki->sag);
            }
            else
            {
                ikinciKuyruk.ekle(0);
                ikinciKuyruk.ekle(0);
            }

            ikinciDongukat++;
            if (pow(2, ikinciDonguSeviye) == ikinciDongukat)
            {
                cout << endl;
                ikinciDonguSeviye++;
                ikinciDongukat = 0;
                donguSirasi = 0;
            }
        }

        // Nokta yazdırması için gerekli döngü ifadesi
        while (donguSirasi == 0 && !ucuncuKuyruk.bosmu() && ucuncuDonguSeviye <= yuksek)
        {
            ADugum *ucuncuSiradaki = ucuncuKuyruk.getir();
            ucuncuKuyruk.cikar();

            if (ucuncuDongukat == 0)
            {
                boslukBirak(yuksek - ucuncuDonguSeviye);
            }

            if (ucuncuSiradaki)
            {
                if (ucuncuSiradaki != kok)
                {
                    cout << ".";
                }
            }
            else
            {
                cout << " ";
            }

            boslukBirak(yuksek - ucuncuDonguSeviye + 1);
            if (ucuncuSiradaki)
            {
                ucuncuKuyruk.ekle(ucuncuSiradaki->sol);
                ucuncuKuyruk.ekle(ucuncuSiradaki->sag);
            }
            else
            {
                ucuncuKuyruk.ekle(0);
                ucuncuKuyruk.ekle(0);
            }

            ucuncuDongukat++;
            if (pow(2, ucuncuDonguSeviye) == ucuncuDongukat)
            {
                cout << endl;
                ucuncuDonguSeviye++;
                ucuncuDongukat = 0;
                donguSirasi = 1;
            }
        }

        // Veri yazdırması için gerekli döngü ifadesi
        if (kat == 0)
        {
            boslukBirak(yuksek - seviye);
        }

        if (siradaki)
        {
            cout << siradaki->veri;
        }
        else
        {
            cout << " ";
        }

        boslukBirak(yuksek - seviye + 1);

        if (siradaki)
        {
            kuyruk.ekle(siradaki->sol);
            kuyruk.ekle(siradaki->sag);
        }
        else
        {
            kuyruk.ekle(0);
            kuyruk.ekle(0);
        }
        kat++;
        if (pow(2, seviye) == kat)
        {
            cout << endl;
            seviye++;
            kat = 0;
            donguSirasi = 2;
        }
    }
}
// Agacin verisini hesaplamak için kullandığım verihesapla fonksiyonu public
int Agac::veriHesapla()
{
    // Kök düğümle başlar carpan 1 olarak verilir
    return veriHesapla(kok, 1);
}
// Agacin verisini hesaplamak için kullandığım verihesapla fonksiyonu
int Agac::veriHesapla(ADugum *aktif, int carpan)
{
    if (!aktif)
    {
        return 0;
    }
    // ASCII değerine göre hesaplanma yapılması
    int toplam = aktif->veri * carpan;
    // Sol çocuk için çarpanı 2 olarak güncelliyoruz
    toplam += veriHesapla(aktif->sol, 2);
    // Sağ çocuk için çarpan 1 olarak güncelliyoruz
    toplam += veriHesapla(aktif->sag, 1);
    return toplam;
}
// Aynalama fonksiyonu public
void Agac::aynalama()
{
    // İşleme kök düğümden başla
    aynalama(kok);
}
// Aynalama fonksiyonu
void Agac::aynalama(ADugum *aktif)
{
    if (!aktif)
    {
        return;
    }

    // Sol ve sağ çocuklar yer değiştirmesi için gecici degisken ataması
    ADugum *gec = aktif->sol;
    aktif->sol = aktif->sag;
    aktif->sag = gec;

    // tüm çocuklar üzerinde etkili olması için fonksiyonu tekrar çağırıyoruz
    aynalama(aktif->sol);
    aynalama(aktif->sag);
}
// dosyadan veri alirken okunan string satiri agac yapma fonksiyonu
void Agac::satiriAgacYap(string satir)
{
    // Satırdaki her karakteri tek tek almak için gerekli döngü ifadesi
    for (int i = 0; i < satir.length(); i++)
    {
        // bosluklari dahil etmeden her bir satırı dugumlere ekleme islemi
        if (satir[i] != ' ')
        {
            ekle(satir[i]);
        }
    }
}
// agaci ekranda gostermek icin ostream fonksiyonu
ostream &operator<<(ostream &os, Agac &agac)
{
    // ağacı yazdırma
    agac.levelOrder();
    return os;
}