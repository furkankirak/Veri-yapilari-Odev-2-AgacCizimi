/**
* @file KDugum.cpp
* @description Kuyrukdaki verileri dugum olarak tutmama yarayan dugum sinifim
* @course 2-C
* @assignment 2
* @date 22.12.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "KDugum.hpp"
KDugum::KDugum(ADugum *dugum)
{
    this->dugum = dugum;
    sonraki = 0;
}