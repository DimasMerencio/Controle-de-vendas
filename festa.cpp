#include "festa.h"

int Festa::size()
{
    return objeto.size();
}

bool Festa::TestarNome(Personalizado x, QString y)
{
    if((y.size()>3) and (y != "0")){
        return 1;
    }
    else return 0;
}

bool Festa::TestarQtdPersonalizados(Personalizado x, int y)
{
    if(y > 0){
        return 1;
    }
    else return 0;
}

bool Festa::TestarValorUnitario(Personalizado x, float y)
{
    if(y > 0){
        return 1;
    }
    else return 0;
}

Personalizado Festa::operator[](int a)
{
    return objeto[a];
}

void Festa::ColocarPersonalizados(Personalizado x)
{
    objeto.push_back(x);
}

void Festa::OrdenarPorNome()
{
    std::sort(objeto.begin(),objeto.end(),CompararPorNome);
}

void Festa::OrdenarPorQtd()
{
    std::sort(objeto.begin(),objeto.end(),CompararPorQtd);
}

void Festa::OrdenarPorValor()
{
    std::sort(objeto.begin(),objeto.end(),CompararPorValor);

}

void Festa::ProdutoComMaiorOuMenorValorTotal()
{
    std::sort(objeto.begin(),objeto.end(),CompararPorValor);

}

void Festa::ProdutoComMaiorOuMenorQuantidade()
{
    std::sort(objeto.begin(),objeto.end(),CompararPorQtd);
}

bool Festa::Dados(QString dados)
{
    QFile salvar(dados);
       QString arquivo;
           if(!salvar.open(QIODevice::WriteOnly))
               return false;

           for(Personalizado x : objeto){
           arquivo = x.getNome() + ',' + QString::number(x.getQtdPersonalizados()) + ',' + QString::number(x.getValorunitPersonalizados()) + ',' + QString::number(x.getValorTotalPersonalizados())+ '\n';
           salvar.write(arquivo.toLocal8Bit());
           }
           return true;
}

bool Festa::CarregarPersonalizados(QString arquivo)
{
    QFile carregar(arquivo);
           if(!carregar.open(QIODevice::ReadOnly))
               return 0;

           QString y;
           Personalizado x;
           while(!carregar.atEnd()){
               y = carregar.readLine();
               QStringList lista = y.split(",");
               x.setNome(lista[0]);
               x.setQtdPersonalizados(lista[1].toInt());
               x.setValorunitPersonalizados(lista[2].toFloat());
               x.setValorTotalPersonalizados(lista[3].toFloat());
               ColocarPersonalizados(x);
           }
           return 1;
}

void Festa::ColocarPersonalizados2(Personalizado x, int y)
{
    objeto[y] = x;

}

bool Festa::VerificarNome(Personalizado x)
{
    for(int i = 0; i < objeto.size(); i++){
        if(x.getNome() == objeto[i].getNome()){
            return 1;
        }
    }
    return 0;
}

int Festa::PosicaoDoPersonalizadoNoVector(Personalizado x)
{
 int i;
    for( i = 0; x.getNome()!=objeto[i].getNome();i++){

    }
    return i;
}

void Festa::Apagar()
{
    objeto.erase(objeto.begin(),objeto.end());
}

void Festa::ExcluirPersonalizado(Personalizado y)
{
    int j = PosicaoDoPersonalizadoNoVector(y);
    objeto.erase(objeto.begin() + j);

}

int Festa::ValorTotalDaConta()
{
    float ValorTotal;
    for(int i = 0; i < objeto.size(); i++){
        ValorTotal=ValorTotal+objeto[i].getValorTotalPersonalizados();
    }
    return ValorTotal;
}


bool CompararPorNome(Personalizado x, Personalizado y){
 return x.getNome().toLower() < y.getNome().toLower();

}
bool CompararPorQtd(Personalizado x, Personalizado y){
return x.getQtdPersonalizados() < y.getQtdPersonalizados();

}
bool CompararPorValor(Personalizado x, Personalizado y){
    return x.getValorTotalPersonalizados() > y.getValorTotalPersonalizados();

}


Festa::Festa()
{

}

