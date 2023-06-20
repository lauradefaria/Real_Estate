#include "Terreno.h"
#include<iostream>

using namespace std;

Terreno::Terreno(){
    area = "";
    tipo = 3;
}

Terreno::Terreno(string val) : Terreno(){
    setArea(val);
}

string Terreno::getArea(){
    return area;
}

void Terreno::setArea(string val){
    area = val;
}

string Terreno::getDescricao(){
    stringstream descricao;
    descricao << "Tipo: Terreno" << "\nArea: " << area << "\n";
    return Imovel::getDescricao() + descricao.str();
}

Terreno::~Terreno(){

}
