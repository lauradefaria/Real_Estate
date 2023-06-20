#include "Apartamento.h"
#include <iostream>

using namespace std;

Apartamento::Apartamento(){
    area = "";
    quartos = "";
    posicao = "";
    andar = "";
    vagasGaragem = "";
    valorCondominio = 0;
    tipo = 2;
}

Apartamento::Apartamento(string q, string a, string p, string floor, string vagasG, double valorC) : Apartamento(){
    setQuartos(q);
    setArea(a);
    setPosicao(p);
    setAndar(floor);
    setVagasGaragem(vagasG);
    setValorCondominio(valorC);
}

string Apartamento::getDescricao(){
    stringstream descricao;
    descricao << "Tipo: Apartamento" << "\nNumero de quartos: "
     << quartos << "\nArea: " << area << "\nPosicao: " << posicao <<  "\nAndar: "
     << andar << "\nVagas de garagem: " << vagasGaragem << "\nValor do condominio: "<<
     valorCondominio << "\n";
    return Imovel::getDescricao() + descricao.str();
}


string Apartamento::getQuartos(){
    return quartos;
}

string Apartamento::getArea(){
    return area;
}

string Apartamento::getPosicao(){
    return posicao;
}

string Apartamento::getAndar(){
    return andar;
}

string Apartamento::getVagasGaragem(){
    return vagasGaragem;
}

double Apartamento::getValorCondominio(){
    return valorCondominio;
}

void Apartamento::setQuartos(string val){
    quartos = val;
}

void Apartamento::setArea(string val){
    area = val;
}

void Apartamento::setPosicao(string val){
    posicao = val;
}

void Apartamento::setAndar(string val){
    andar = val;
}

void Apartamento::setVagasGaragem(string val){
    vagasGaragem = val;
}

void Apartamento::setValorCondominio(double val){
    valorCondominio = val;
}


Apartamento::~Apartamento(){
    //dtor
}
