/**
* @file ADugum.cpp
* @description Agacin icindeki verileri dugumde tutmami saglayan dugum sinifim
* @course 2-C
* @assignment 2
* @date 15.12.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "ADugum.hpp"
#include <iostream>
using namespace std;

ADugum::ADugum(char veri)
{
    this->veri = veri;
    sol = 0;
    sag = 0;
}

ADugum::~ADugum() {
}