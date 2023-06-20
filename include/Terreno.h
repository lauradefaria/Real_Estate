#ifndef TERRENO_H
#define TERRENO_H

#include <Imovel.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Terreno : public Imovel
{
    public:
        Terreno();
        Terreno(string val);
        string getDescricao();
        virtual ~Terreno();

        string getArea();
        void setArea(string val);

    protected:
        string area;

    private:
};

#endif // TERRENO_H
