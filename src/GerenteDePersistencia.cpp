#include "GerenteDePersistencia.h"
#include <iostream>

using namespace std;

GerenteDePersistencia::GerenteDePersistencia(){}

GerenteDePersistencia::~GerenteDePersistencia(){}

vector <Imovel*> GerenteDePersistencia::recuperaListaImoveis(){
    vector<Imovel*> lista;
    stringstream converter;
    Imovel *inserir;

    ifstream arquivo;
    arquivo.open("recuperacao.txt", ios::in);

    string string_value;
    int int_value = 0;
    double double_value = 0;

    if(arquivo.is_open()){

        while(arquivo.peek()!=EOF){
            Endereco ender = Endereco();
            inserir = new Imovel();
            arquivo >> int_value;
            arquivo.ignore();
            //arquivo >> string_value;
            //converter(string_value);
            //string_value >> int_value;
            if(int_value == 1){
                inserir = new Casa();
                inserir->setTipo(1);

                getline(arquivo,string_value);
                inserir->setTitulo(string_value);
                arquivo >> int_value;
                inserir->setTransacao(int_value);
                arquivo >> double_value;
                inserir->setValor(double_value);
                arquivo.ignore();
                getline(arquivo, string_value);
                ender.setLogradouro(string_value);
                getline(arquivo, string_value);
                ender.setNumero(string_value);
                getline(arquivo, string_value);
                ender.setBairro(string_value);
                getline(arquivo, string_value);
                ender.setCep(string_value);
                getline(arquivo, string_value);
                ender.setCidade(string_value);
                inserir->setEndereco(ender);
                getline(arquivo, string_value);
                static_cast <Casa*>(inserir)->setQuartos(string_value);
                getline(arquivo, string_value);
                static_cast <Casa*>(inserir)->setAreaTerreno(string_value);
                getline(arquivo, string_value);
                static_cast <Casa*>(inserir)->setAreaConstruida(string_value);

                lista.push_back(inserir);

            }else if(int_value == 2){
                inserir = new Apartamento();
                inserir->setTipo(2);

                getline(arquivo,string_value);
                inserir->setTitulo(string_value);
                arquivo >> int_value;
                inserir->setTransacao(int_value);
                arquivo >> double_value;
                inserir->setValor(double_value);
                arquivo.ignore();
                getline(arquivo, string_value);
                ender.setLogradouro(string_value);
                getline(arquivo, string_value);
                ender.setNumero(string_value);
                getline(arquivo, string_value);
                ender.setBairro(string_value);
                getline(arquivo, string_value);
                ender.setCep(string_value);
                getline(arquivo, string_value);
                ender.setCidade(string_value);
                inserir->setEndereco(ender);
                getline(arquivo, string_value);
                static_cast <Apartamento*>(inserir)->setQuartos(string_value);
                getline(arquivo, string_value);
                static_cast <Apartamento*>(inserir)->setArea(string_value);
                getline(arquivo, string_value);
                static_cast <Apartamento*>(inserir)->setPosicao(string_value);
                getline(arquivo, string_value);
                static_cast <Apartamento*>(inserir)->setAndar(string_value);
                getline(arquivo, string_value);
                static_cast <Apartamento*>(inserir)->setVagasGaragem(string_value);
                arquivo >> double_value;
                static_cast <Apartamento*>(inserir)->setValorCondominio(double_value);


                lista.push_back(inserir);


            }else if(int_value == 3){
                inserir = new Terreno();
                inserir->setTipo(3);

                getline(arquivo,string_value);
                inserir->setTitulo(string_value);
                arquivo >> int_value;
                inserir->setTransacao(int_value);
                arquivo >> double_value;
                inserir->setValor(double_value);
                arquivo.ignore();
                getline(arquivo, string_value);
                ender.setLogradouro(string_value);
                getline(arquivo, string_value);
                ender.setNumero(string_value);
                getline(arquivo, string_value);
                ender.setBairro(string_value);
                getline(arquivo, string_value);
                ender.setCep(string_value);
                getline(arquivo, string_value);
                ender.setCidade(string_value);
                inserir->setEndereco(ender);
                getline(arquivo, string_value);
                static_cast <Terreno*>(inserir)->setArea(string_value);

                lista.push_back(inserir);


            }else if(arquivo.bad()){
                break;
            }

        }
        arquivo.close();
    }

    return lista;
}

void GerenteDePersistencia::salvaListaImoveis(vector<Imovel*>salvar){
    ofstream arquivo;
    arquivo.open("recuperacao.txt", ios::out);
    if(!arquivo.is_open()){
        cout << "1-Nao foi possivel abrir arquivo!\n";
        arquivo.close();
    }
    for(unsigned int i = 0 ; i<salvar.size() ; i++){
        //cout << "\nSALVANDO ISSO\n" << getDescricaoString(salvar[i]->getTipo(),salvar[i]);
        arquivo << getDescricaoString(salvar[i]->getTipo(), salvar[i]);
    }
    arquivo.close();
}

string GerenteDePersistencia::getDescricaoString(int tipo, Imovel* parametro){
    stringstream descricao;
    Endereco copiar;
    copiar = parametro->getEndereco();
    if(parametro->getTipo() == 1){
    descricao <<parametro->getTipo() << "\n" << parametro->getTitulo() << "\n" << parametro->getTransacao()<< "\n" << parametro->getValor() <<"\n" << copiar.getLogradouro() <<"\n"
     << copiar.getNumero() << "\n" << copiar.getBairro() << "\n" << copiar.getCep() << "\n" << copiar.getCidade() << "\n" << static_cast<Casa*>(parametro)->getPavimentos() << "\n"
     << static_cast<Casa*>(parametro)->getQuartos() << "\n" << static_cast<Casa*>(parametro)->getAreaTerreno() << "\n" << static_cast<Casa*>(parametro)->getAreaConstruida() << "\n";
    }else if(parametro->getTipo() == 2){
    descricao <<parametro->getTipo() << "\n" << parametro->getTitulo() << "\n" << parametro->getTransacao() << "\n" << parametro->getValor() << "\n" << copiar.getLogradouro() << "\n"
     << copiar.getNumero() << "\n" << copiar.getBairro() << "\n" << copiar.getCep() << "\n" << copiar.getCidade() << "\n" << static_cast<Apartamento*>(parametro)->getQuartos() << "\n"
     << static_cast<Apartamento*>(parametro)->getArea() << "\n" << static_cast<Apartamento*>(parametro)->getPosicao() << "\n" << static_cast<Apartamento*>(parametro)->getAndar() << "\n"
     << static_cast<Apartamento*>(parametro)->getVagasGaragem() << "\n" << static_cast<Apartamento*>(parametro)->getValorCondominio() << "\n";
    }else if(parametro->getTipo() == 3){
    descricao <<parametro->getTipo() << "\n" << parametro->getTitulo() << "\n" << parametro->getTransacao() << "\n" << parametro->getValor() << "\n" << copiar.getLogradouro() << "\n"
     << copiar.getNumero() << "\n" << copiar.getBairro() << "\n" << copiar.getCep() << "\n" << copiar.getCidade() << "\n" << static_cast<Terreno*>(parametro)->getArea() << "\n";
    }
    return descricao.str();
}



