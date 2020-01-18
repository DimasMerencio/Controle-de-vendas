#include "personalizado.h"

QString Personalizado::getNome() const
{
    return nome;
}

void Personalizado::setNome(const QString &value)
{
    nome = value;
}

int Personalizado::getQtdPersonalizados() const
{
    return QtdPersonalizados;
}

void Personalizado::setQtdPersonalizados(int value)
{
    QtdPersonalizados = value;
}

float Personalizado::getValorunitPersonalizados() const
{
    return ValorunitPersonalizados;
}

void Personalizado::setValorunitPersonalizados(float value)
{

    ValorunitPersonalizados = value;

}

float Personalizado::getValorTotalPersonalizados() const
{
    return ValorTotalPersonalizados;
}

void Personalizado::setValorTotalPersonalizados(float value)
{
    value = QtdPersonalizados*ValorunitPersonalizados;
    ValorTotalPersonalizados = value;
}

Personalizado::Personalizado(QString a, int b, float c, float d)
{


}

Personalizado::Personalizado()
{
    nome = "\0";
    QtdPersonalizados = 0;
    ValorunitPersonalizados = 0;
    ValorTotalPersonalizados = 0;

}
