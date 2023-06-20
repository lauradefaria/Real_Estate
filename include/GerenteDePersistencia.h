#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "Endereco.h"
#include <iostream>

using namespace std;

class GerenteDePersistencia{
    public:
        GerenteDePersistencia();
        virtual ~GerenteDePersistencia();
        string getDescricaoString(int tipo, Imovel* parametro);
        vector <Imovel*> recuperaListaImoveis();
        void salvaListaImoveis(vector <Imovel*> salvar);
        //static Imovel* SistemaImobiliaria::lerCasa();

    protected:

    private:
};

#endif // GERENTEDEPERSISTENCIA_H
