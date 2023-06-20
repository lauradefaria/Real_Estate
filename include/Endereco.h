#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Endereco
{
    public:
        Endereco();

        Endereco(string rua,string n,string  b,string  cp,string  cd);
        void setLogradouro(string rua);
        void setBairro(string b);
        void setCep(string cp);
        void setCidade(string cd);
        void setNumero(string n);
        string getLogradouro();
        string getBairro();
        string getCep();
        string getCidade();
        string getNumero();
        string getDescricao();

;

        virtual ~Endereco();

    protected:
        string logradouro;
        string bairro;
        string cep;
        string cidade;
        string numero;
};

#endif // ENDERECO_H
