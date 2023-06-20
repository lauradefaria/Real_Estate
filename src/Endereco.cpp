#include "Endereco.h"
#include<iostream>

using namespace std;

Endereco::Endereco(){
    //ctor
    this->logradouro = "";
    this->numero = "";
    this->bairro = "";
    this->cep = "";
    this->cidade = "";
}

Endereco::Endereco(string rua, string n, string b, string cp, string cd){
    setLogradouro(rua);
    setNumero(n);
    setBairro(b);
    setCep(cp);
    setCidade(cd);
}


void Endereco::setLogradouro(string rua){
    logradouro = rua;string getDescricao();
}

void Endereco::setBairro(string b){
    bairro = b;
}

void Endereco::setCep(string cp){
    cep = cp;
}

void Endereco::setCidade(string cd){
    cidade = cd;
}

void Endereco::setNumero(string n){
    numero = n;
}

string Endereco::getLogradouro(){
    return logradouro;
}

string Endereco::getBairro(){
    return bairro;
}

string Endereco::getCep(){
    return cep;
}

string Endereco::getCidade(){
    return cidade;
}

string Endereco::getNumero(){
    return numero;
}

string Endereco::getDescricao(){
    stringstream descricao;
    descricao <<"\\Endereco " << "\nLogradouro: " << logradouro << "\nNumero: " << numero << "\nBairro: "
     << bairro << "\nCEP: " << cep << "\nCidade: " << cidade << "\n";
    return descricao.str();
}


Endereco::~Endereco(){

}
