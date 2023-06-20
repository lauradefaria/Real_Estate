#define APARTAMENTO_H

#include <Imovel.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Apartamento : public Imovel
{
    public:
        Apartamento();
        Apartamento(string q, string a, string p, string floor, string vagasG, double valorC);
        virtual ~Apartamento();

        string getDescricao();
        string getQuartos();
        string getArea();
        string getPosicao();
        string getAndar();
        string getVagasGaragem();
        double getValorCondominio();
        void setQuartos(string val);
        void setArea(string val);
        void setPosicao(string val);
        void setAndar(string val);
        void setVagasGaragem(string val);
        void setValorCondominio(double val);

    protected:
        string quartos;
        string area;
        string posicao;
        string andar;
        string vagasGaragem;
        double valorCondominio;

    private:
};

#endif // APARTAMENTO_H
