#include "Imovel.h"
#include<iostream>

using namespace std;

Imovel::Imovel(){
    valor = 0;
    titulo = "";
    transacao = 0;
    tipo = 0;
    ativo = 1;

}

int Imovel::getTipo(){
    return  tipo;
}
double Imovel::getValor(){
    return valor;
}

int Imovel::getTransacao(){
    return transacao;
}

Endereco Imovel::getEndereco(){
    return endereco;
}

bool Imovel::getDisponivel(){
    return ativo;
}

string Imovel::getTitulo(){
    return titulo;
}


void Imovel::setTipo(int tip){
    tipo = tip;
}

void Imovel::setValor(double val){
    valor = val;
}

void Imovel::setTransacao(int transa){
    transacao = transa;
}

void Imovel::setEndereco(Endereco ender){
    endereco = ender;
}

void Imovel::setDisponivel(bool disp){
    ativo = disp;
}

void Imovel::setTitulo(string tit){
    titulo = tit;
}


string Imovel::getDescricao(){
    stringstream descricao;
    descricao <<"Disponibilidade:\t*" <<(ativo ? "Disponivel*":"Indisponivel*") << "\nTitulo: " << titulo << "\nTransacao: "
     << (transacao == 1 ? "Venda" : "Aluguel" ) << "\nValor: R$ " << valor << "\n" + endereco.getDescricao() <<  "\n";
    return descricao.str();
}

Imovel::~Imovel(){

}
