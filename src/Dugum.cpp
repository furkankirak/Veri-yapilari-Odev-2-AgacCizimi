/**
* @file Dugum.cpp
* @description BagliListede agac referanslarini dugumde tutmami saglayan dugum sinifim
* @course 2-C
* @assignment 2
* @date 14.12.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include <iostream>
#include <Agac.hpp>
using namespace std;

Dugum::Dugum(Agac* agac) {
    this->agac =agac;
    sonraki=0;
}

Dugum::~Dugum()
{
    delete agac;
    agac=0;
}
