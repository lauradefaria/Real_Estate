#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "GerenteDePersistencia.h"
#include "Terreno.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

class SistemaImobiliaria
{
    public:
        SistemaImobiliaria();
        Imovel* cadastroGeral();
        void cadastraImovel(Imovel* cadastro);
        string getImoveis();
        string getDescricaoImovel(Imovel* val);
        string getImovelPorTipo(int tipo);
        string getImovelPorTransacao(int transacao);
        vector <Imovel*> getImoveisPorBairro(string bairro);
        vector <Imovel*> getImoveisPorCidade(string cidade);
        vector <Imovel*> getImoveisPorTitulo(string titulo);
        vector <Imovel*> getImoveisPorValorMaior(double valor);
        vector <Imovel*> getImoveisPorValorMenor(double valor);
        void AgulhaPalheiro(string enviado);
        void removerImovel(string titulo);
        void editarImovel(string titulo);
        void salvar();
        void recupera();

        ~SistemaImobiliaria();

    protected:
        vector <Imovel*> sistema;
        GerenteDePersistencia gerente;

};

#endif // SISTEMAIMOBILIARIA_H
