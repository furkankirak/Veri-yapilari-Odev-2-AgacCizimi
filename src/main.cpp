/**
 * @file main.cpp
 * @description BagliListe tasariminin ve ekranda gözükecek durumların yapildiği kaynak dosyasi
 * @course 2-C
 * @assignment 2
 * @date 14.12.2024
 * @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "BagliListe.hpp"
using namespace std;
int boslukMiktari = 3;
// noktalari yazmak için gerekli fonkiyon
void noktaYaz()
{

    for (int i = 0; i < boslukMiktari; i++)
    {
        cout << " ";
    }
    cout << "........";
}
// alana bağlı listedeki düğümlerin adreslerini yazmak için gerekli fonksiyon
void adresYaz(Dugum *adres)
{
    int adresMod = (unsigned int)adres % 10000;
    for (int i = 0; i < boslukMiktari; i++)
    {
        cout << " ";
    }
    cout << ".";
    cout << setw(6) << adresMod;
    cout << ".";
}
// alana bağlılistedeki verilerin değerlerini yazmak için gerekli fonksiyon
void degerYaz(int veri)
{
    for (int i = 0; i < boslukMiktari; i++)
    {
        cout << " ";
    }
    cout << ".";
    cout << setw(6) << veri;
    cout << ".";
}
// ekranda görünecek tasarimin kurgulanması sağlayan fonksiyon
void bagliListeTasarimi(BagliListe *p, int baslangic, int bitis)
{

    for (int i = baslangic; i < bitis; i++)
    {
        noktaYaz();
    }
    cout << endl;
    for (int i = baslangic; i < bitis; i++)
    {
        adresYaz(p->dugumGetir(i));
    }
    cout << endl;
    for (int i = baslangic; i < bitis; i++)
    {
        noktaYaz();
    }
    cout << endl;
    for (int i = baslangic; i < bitis; i++)
    {
        degerYaz(p->dugumGetir(i)->agac->veriHesapla());
    }
    cout << endl;
    for (int i = baslangic; i < bitis; i++)
    {
        noktaYaz();
    }
    cout << endl;

    for (int i = baslangic; i < bitis; i++)
    {
        adresYaz(p->dugumGetir(i)->sonraki);
    }
    cout << endl;
    for (int i = baslangic; i < bitis; i++)
    {
        noktaYaz();
    }
    cout << endl;
}
// isaretyaz fonksiyonu için yardimci fonksiyon
void isaretYazYardimci(int indeks)
{
    if (indeks != 0)
    {
        for (int i = 0; i < indeks; i++)
        {
            for (int i = 0; i < boslukMiktari; i++)
            {
                cout << " ";
            }
            cout << "        ";
        }
    }
    for (int i = 0; i < boslukMiktari; i++)
    {
        cout << " ";
    }
}
// hangi düğümde olduğumuzu ok işareti gibi gösteren fonksiyon düğüm değiştikçe yeri değişir ve o düğümü gösterir
void isaretYaz(int indeks)
{
    isaretYazYardimci(indeks);
    cout << "^^^^^^^^";
    cout << endl;
    isaretYazYardimci(indeks);
    cout << "||||||||";
}

int main()
{
    // baglilistemizi tanimliyoruz
    BagliListe *p = new BagliListe();
    // baglilistemize dosyadaki agaclari ekliyoruz
    p->ekleDosyadakiAgaclar();
    // ekranda gorunecek dugumler icin grup sistemi kullandığımız için  bir baslangic bir bitise ihtiyac duyarız hangi düğümler arasını göstersin diye

    // ekranda görünecek düğümlerin baslangic dugumu
    int baslangic = 0;
    // ekranda görünecek düğümlerin bitis dugumu
    int bitis = 10;
    // hangi grupta olduğumuzu görmek için gerekli grup degiskeni
    int grup = 1;
    // dugumler arasi gecisi gosteren indeks grup icerisindeki dugumkleri gosterir 0-9 arasi deger alir
    int indeks = 0;
    // dugumun gercek indeksi verileri göstermek veya islem yapmak icin kullanilir(aynalama v.b.)
    int bagliListeindeksi = 0;

    while (true)
    {

        system("cls");
        // eger dugum yok ise cailsmaz bu sayede uygulama patlamaz
        if (p->dugumSayisi != 0)
        {
            if (p->dugumSayisi <= bitis)
            {
                bitis = p->dugumSayisi;
                bagliListeTasarimi(p, baslangic, bitis);
                isaretYaz(indeks);
            }
            else
            {
                bagliListeTasarimi(p, baslangic, bitis);
                isaretYaz(indeks);
            }

            cout << endl;
            p->agaciGoster(bagliListeindeksi);
            cout << endl;
        }
        cout << "Seciminizi Yapin ->";
        char secim = cin.get();
        // uygulamadan cikma
        if (secim == 'x')
        {
            delete p;
            break;
        }
        // sola gitme
        else if (secim == 'a')
        {
            indeks--;
            bagliListeindeksi--;
        }
        // aynalama
        else if (secim == 'w')
        {
            if (p->dugumSayisi != 0)
            {
                p->dugumGetir(bagliListeindeksi)->agac->aynalama();
            }
        }
        // silme
        else if (secim == 's')
        {
            p->cikar(bagliListeindeksi);
            indeks--;
            bagliListeindeksi--;
        }
        // saga gitme
        else if (secim == 'd')
        {
            if (indeks + 1 >= bitis - baslangic && (indeks > -1 && indeks < 10))
            {
                if ((bitis != p->dugumSayisi))
                {
                    indeks++;
                    bagliListeindeksi++;
                }
            }
            else
            {
                indeks++;
                bagliListeindeksi++;
            }
        }
        // diger gruba geçmek için gerekli koşul
        if (indeks > 9)
        {
            indeks = 0;
            grup++;
            baslangic = baslangic + 10;
            bitis = bitis + 10;
        }
        // grup dusmek icin gerekli koşul
        if (indeks < 0)
        {
            // indeks ve baglilisteyi 0ın altına düşürmemek içn gerekli koşul
            if (grup == 1)
            {
                indeks = 0;
                bagliListeindeksi = 0;
            }
            else
            {
                indeks = 9;
                grup--;
                baslangic = baslangic - 10;
                if (bitis % 10 == 0)
                {
                    bitis = bitis - 10;
                }
                else
                {
                    bitis = bitis - (bitis % 10);
                }
            }
        }
    }
}
