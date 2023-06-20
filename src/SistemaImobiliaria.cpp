#include "SistemaImobiliaria.h"
#include <iostream>

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){

}

Imovel* SistemaImobiliaria::cadastroGeral(){
    Imovel *cadastro;
    Endereco endCadastro;
    string string_value;
    int int_value;
    double double_value;
    cout << "\nTipo do imovel: ";
    cin >> string_value;
    transform(string_value.begin(), string_value.end(), string_value.begin(), ::tolower);
    //transforma para lower case para comparacao
    if(string_value == "casa"){
        cadastro = new Casa();
        cin.ignore();
        cout << "\t\\Inicio de Cadastro\\" << "\nTitulo: ";
        getline(cin, string_value); cadastro->setTitulo(string_value);
        //para receber mais de uma palavra
        cout << "\nTipo de negocio(\\1-Venda\\2-Aluguel\\): ";
        cin >> int_value; cadastro->setTransacao(int_value);
        cout << "\nValor: ";
        cin >> double_value; cadastro->setValor(double_value);
        cout << "\nNumero de pavimentos: ";
        cin.ignore();
        getline(cin, string_value); static_cast<Casa*>(cadastro)->setPavimentos(string_value);
        //cast para poder ter acesso aos metodos set da classe filha
        cout << "\nNumero de quartos: ";
        getline(cin, string_value); static_cast<Casa*>(cadastro)->setQuartos(string_value);
        cout << "\nArea do terreno: ";
        getline(cin, string_value); static_cast<Casa*>(cadastro)->setAreaTerreno(string_value);
        cout << "\nArea construida: ";
        getline(cin, string_value); static_cast<Casa*>(cadastro)->setAreaConstruida(string_value);
        cout << "\nENDERECO:\n\n" << "Rua: ";
        getline(cin, string_value); endCadastro.setLogradouro(string_value);
        cout << "\nNumero: ";
        getline(cin, string_value); endCadastro.setNumero(string_value);
        cout << "\nBairro: ";
        getline(cin, string_value); endCadastro.setBairro(string_value);
        cout << "\nCEP: ";
        getline(cin, string_value); endCadastro.setCep(string_value);
        cout << "\nCidade: ";
        getline(cin, string_value); endCadastro.setCidade(string_value);
        cadastro->setEndereco(endCadastro);
        /*teste
        cout << cadastro->getDescricao();
        */
    }else if(string_value == "apartamento"){
        cadastro = new Apartamento();
        cin.ignore();
        cout << "\t\\Inicio de Cadastro\\" << "\nTitulo: ";
        getline(cin, string_value); cadastro->setTitulo(string_value);
        //para receber mais de uma palavra
        cout << "\nTipo de negocio(\\1-Venda\\2-Aluguel\\): ";
        cin >> int_value; cadastro->setTransacao(int_value);
        cout << "\nValor: ";
        cin >> double_value; cadastro->setValor(double_value);
        cout << "\nValor condominio: ";
        cin >> double_value; static_cast<Apartamento*>(cadastro)->setValorCondominio(double_value);
        cin.ignore();
        cout << "\nNumero de quartos: ";
        getline(cin, string_value); static_cast<Apartamento*>(cadastro)->setQuartos(string_value);
        cout << "\nArea: ";
        getline(cin, string_value); static_cast<Apartamento*>(cadastro)->setArea(string_value);
        cout << "\nPosicao: ";
        getline(cin, string_value); static_cast<Apartamento*>(cadastro)->setPosicao(string_value);
        cout << "\nAndar: ";
        getline(cin, string_value); static_cast<Apartamento*>(cadastro)->setAndar(string_value);
        cout << "\nVagas de garagem: ";
        getline(cin, string_value); static_cast<Apartamento*>(cadastro)->setVagasGaragem(string_value);
        cout << "\nENDERECO:\n\n" << "Rua: ";
        getline(cin, string_value); endCadastro.setLogradouro(string_value);
        cout << "\nNumero: ";
        getline(cin, string_value); endCadastro.setNumero(string_value);
        cout << "\nBairro: ";
        getline(cin, string_value); endCadastro.setBairro(string_value);
        cout << "\nCEP: ";
        getline(cin, string_value); endCadastro.setCep(string_value);
        cout << "\nCidade: ";
        getline(cin, string_value); endCadastro.setCidade(string_value);
        cadastro->setEndereco(endCadastro);
        /*teste
        cout << cadastro->getDescricao();
        */
    }else if(string_value == "terreno"){
        cadastro = new Terreno();
        cin.ignore();
        cout << "\t\\Inicio de Cadastro\\" << "\nTitulo: ";
        getline(cin, string_value); cadastro->setTitulo(string_value);
        //para receber mais de uma palavra
        cout << "\nTipo de negocio(\\1-Venda\\2-Aluguel\\): ";
        cin >> int_value; cadastro->setTransacao(int_value);
        cout << "\nValor: ";
        cin >> double_value; cadastro->setValor(double_value);
        cin.ignore();
        cout << "\nArea: ";
        getline(cin, string_value); static_cast<Terreno*>(cadastro)->setArea(string_value);
        cout << "\nENDERECO:\n\n" << "Rua: ";
        getline(cin, string_value); endCadastro.setLogradouro(string_value);
        cout << "\nNumero: ";
        getline(cin, string_value); endCadastro.setNumero(string_value);
        cout << "\nBairro: ";
        getline(cin, string_value); endCadastro.setBairro(string_value);
        cout << "\nCEP: ";
        getline(cin, string_value); endCadastro.setCep(string_value);
        cout << "\nCidade: ";
        getline(cin, string_value); endCadastro.setCidade(string_value);
        cadastro->setEndereco(endCadastro);
        /*teste
        cout << cadastro->getDescricao();
        */
    }
    return cadastro;
}

void SistemaImobiliaria::cadastraImovel(Imovel* cadastro){
    sistema.push_back(cadastro);
    /*
    teste 2
    if(sistema[0]->getTipo() == 1){
    cout << static_cast <Casa*>(cadastro)->getDescricao();
    }
    */
}

string SistemaImobiliaria::getDescricaoImovel(Imovel* val){
    if(val->getTipo() == 1){
        return static_cast <Casa*>(val)->getDescricao();
    }else if(val->getTipo() == 2){
        return static_cast <Apartamento*>(val)->getDescricao();
    }else if(val->getTipo() == 3){
        return static_cast <Terreno*>(val)->getDescricao();
    }
    return "Imovel sem tipo definido";
}

string SistemaImobiliaria::getImoveis(){
    stringstream concatenar;
    string lista = "";
    for(unsigned int i = 0 ; i< sistema.size() ; i++){
        concatenar << "Imovel #" << (i+1) << "\n" +sistema[i]->getTitulo() + "\n";
        lista += concatenar.str();
        concatenar.str("");
    }
    return lista;
}

string SistemaImobiliaria::getImovelPorTipo(int tipo){
    stringstream concatenar;
    string lista = "";
    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        if(sistema[i]->getTipo() == tipo){
            concatenar << "Imovel #" << i+1 << "\n" + getDescricaoImovel(sistema[i]) + "\n";
            lista += concatenar.str();
        }
    }
    return lista;
}

string SistemaImobiliaria::getImovelPorTransacao(int transacao){
    stringstream concatenar;
    string lista = "";
    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        if(sistema[i]->getTransacao() == transacao){
            concatenar << "Imovel #" << i+1 << "\n" + getDescricaoImovel(sistema[i]) + "\n";
            lista += concatenar.str();
        }
    }
    return lista;
}

void SistemaImobiliaria::AgulhaPalheiro(string enviado){

    int auxil;
    for(unsigned int i; i<sistema.size();i++){
        auxil = sistema[i]->getTitulo().find(enviado);

        if (auxil == 0){
            cout << sistema[i]->getDescricao() << endl;
        }
    }
}



vector <Imovel*> SistemaImobiliaria::getImoveisPorBairro(string bairro){
    vector <Imovel*> busca;
    string parteBusca;
    string parteBairro;

    transform(bairro.begin(), bairro.end(), bairro.begin(), ::tolower);

    parteBusca = bairro.substr(0,5);

    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        parteBairro = sistema[i]->getEndereco().getBairro();
        transform(parteBairro.begin(), parteBairro.end(), parteBairro.begin(), ::tolower);
        parteBairro = parteBairro.substr(0,5);

        if(sistema[i]->getEndereco().getBairro() == bairro || parteBusca == parteBairro){
            busca.push_back(sistema[i]);
        }
    }
    return busca;
}

vector <Imovel*> SistemaImobiliaria::getImoveisPorCidade(string cidade){
    vector <Imovel*> busca;
    string parteBusca;
    string parteCidade;

    transform(cidade.begin(), cidade.end(), cidade.begin(), ::tolower);
    parteBusca = cidade.substr(0,5);

    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        parteCidade = sistema[i]->getEndereco().getCidade();
        transform(parteCidade.begin(), parteCidade.end(), parteCidade.begin(), ::tolower);
        parteCidade = parteCidade.substr(0,5);

        if(sistema[i]->getEndereco().getCidade() == cidade || parteBusca == parteCidade){
            busca.push_back(sistema[i]);
        }
    }
    return busca;
}

vector <Imovel*> SistemaImobiliaria::getImoveisPorTitulo(string titulo){
    vector <Imovel*> busca;
    string parteBusca;
    string parteTitulo;

    transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
    parteBusca = titulo.substr(0,5);

    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        parteTitulo = sistema[i]->getTitulo();
        transform(parteTitulo.begin(), parteTitulo.end(), parteTitulo.begin(), ::tolower);
        parteTitulo = parteTitulo.substr(0,5);

        if(sistema[i]->getTitulo() == titulo || parteBusca == parteTitulo){
            busca.push_back(sistema[i]);
        }
    }
    return busca;
}

vector <Imovel*> SistemaImobiliaria::getImoveisPorValorMaior(double valor){
    vector <Imovel*> busca;
    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        if(sistema[i]->getValor() >= valor){
            busca.push_back(sistema[i]);
        }
    }
    return busca;
}

vector <Imovel*> SistemaImobiliaria::getImoveisPorValorMenor(double valor){
    vector <Imovel*> busca;
    for(unsigned int i = 0 ; i<sistema.size() ; i++){
        if(sistema[i]->getValor() <= valor){
            busca.push_back(sistema[i]);
        }
    }
    return busca;
}

void SistemaImobiliaria::removerImovel(string titulo){
    vector <Imovel*> encontrado = getImoveisPorTitulo(titulo);
    if(encontrado.size() != 0 && encontrado.size() == 1){
        for(unsigned int i = 0 ; i<sistema.size() ; i++){
            if(sistema[i] == encontrado[0]){
                sistema.erase(sistema.begin() + i);
            }
        }//for
    }else{
        cout << "\nMais de um imovel encontrado\\Um deletado.";
        for(unsigned int i = 0 ; i<sistema.size() ; i++){
            if(sistema[i] == encontrado[0]){
                sistema.erase(sistema.begin() + i);
            }
        }//for
    }//else
}//testar!!!!!!

void SistemaImobiliaria::editarImovel(string titulo){
    vector <Imovel*> encontrado = getImoveisPorTitulo(titulo);
    if(encontrado.size() != 0 || encontrado.size() == 1){
        for(unsigned int i = 0 ; i<sistema.size() ; i++){
            if(sistema[i] == encontrado[0]){
                delete sistema[i];
                cout << "\nCadastre a edicao do imovel:\n" << endl;
                sistema[i] = cadastroGeral();
            }
        }//for
    }else{
        cout << "\nMais de um imovel encontrado\\Editando o primeiro";
        for(unsigned int i = 0 ; i<sistema.size() ; i++){
            if(sistema[i] == encontrado[0]){
                delete sistema[i];
                cout << "\nCadastre a edicao do imovel:\n" << endl;
                sistema[i] = cadastroGeral();
            }
        }//for
    }//else
}

void SistemaImobiliaria::salvar(){
    gerente.salvaListaImoveis(sistema);
}

void SistemaImobiliaria::recupera(){
    sistema = gerente.recuperaListaImoveis();
   //teste cout << "\nITENS SALVOS\n\n" << endl;

   //teste cout << getDescricaoImovel(sistema[0]);
}





SistemaImobiliaria::~SistemaImobiliaria(){
}
