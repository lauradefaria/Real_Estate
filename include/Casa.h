#ifndef CASA_H
#define CASA_H

#include <Imovel.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Casa : public Imovel
{
    public:
        Casa();
        Casa(string q, string p, string aT, string aC);
        virtual ~Casa();

        string getDescricao();
        string getPavimentos();
        string getQuartos();
        string getAreaTerreno();
        string getAreaConstruida();
        void setPavimentos(string val);
        void setQuartos(string val);
        void setAreaTerreno(string val);
        void setAreaConstruida(string val);

    protected:
        string pavimentos;
        string quartos;
        string areaTerreno;
        string areaConstruida;

    private:
};

#endif // CASA_H
