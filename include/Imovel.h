#ifndef IMOVEL_H
#define IMOVEL_H
#include <iostream>
#include "Endereco.h"
#include <string>
#include <sstream>
#include <iostream>

#define IMOVEL_PARA_VENDER 1
#define IMOVEL_PARA_ALUGAR 2

using namespace std;

class Imovel{
    public:
        Imovel();

        virtual bool getDisponivel();
        virtual double getValor();
       // virtual int getTransacao();
        virtual Endereco getEndereco();
       // virtual string getDescricao();
        virtual int getTipo();
        virtual string getTitulo();
        virtual void setDisponivel(bool disp);
        virtual void setValor(double val);
       // virtual void setTransacao(int transa);
        virtual void setEndereco(Endereco ender);
        virtual void setTipo(int tip);
        virtual void setTitulo(string tit);

        virtual ~Imovel();

    protected:
        Endereco endereco;
        string titulo;
        bool ativo;
        double valor;
        int transacao; // 1: Venda, 2: Aluguel
        int tipo;



};

#endif // IMOVEL_H
