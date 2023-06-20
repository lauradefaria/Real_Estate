#include "Casa.h"
#include <iostream>

using namespace std;

Casa::Casa(){
    pavimentos = "";
    quartos = "";
    areaConstruida = "";
    areaTerreno = "";
    tipo = 1;
}

Casa::Casa(string q, string p, string aT, string aC) : Casa(){
    setQuartos(q);
    setPavimentos(p);
    setAreaTerreno(aT);
    setAreaConstruida(aC);
}

string Casa::getDescricao(){
    stringstream descricao;
    descricao << "Tipo: Casa" << "\nNumero de pavimentos: "<< pavimentos << "\nNumero de quartos: "
     << quartos << "\nArea do terreno: " << areaTerreno << "\nArea Construida: " << areaConstruida <<  "\n";
    return Imovel::getDescricao() + descricao.str();
}


string Casa::getPavimentos(){
    return pavimentos;
}

string Casa::getQuartos(){
    return quartos;
}

string Casa::getAreaTerreno(){
    return areaTerreno;
}

string Casa::getAreaConstruida(){
    return areaConstruida;
}

void Casa::setPavimentos(string val){
   pavimentos = val;
}

void Casa::setQuartos(string val){
    quartos = val;
}

void Casa::setAreaTerreno(string val){
    areaTerreno = val;
}

void Casa::setAreaConstruida(string val){
    areaConstruida = val;
}

Casa::~Casa(){

}
