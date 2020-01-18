#ifndef PERSONALIZADO_H
#define PERSONALIZADO_H

#include <QObject>
#include <iomanip>
#include <iostream>
#include <fstream>



class Personalizado
{
  private:
    QString nome;
    int QtdPersonalizados;
    float ValorunitPersonalizados;
    float ValorTotalPersonalizados;

  public:

    Personalizado();
    QString getNome() const;
    void setNome(const QString &value);
    int getQtdPersonalizados() const;
    void setQtdPersonalizados(int value);
    float getValorunitPersonalizados() const;
    void setValorunitPersonalizados(float value);
    float getValorTotalPersonalizados() const;
    void setValorTotalPersonalizados(float value);
    Personalizado(QString a, int b, float c, float d);
};

#endif // PERSONALIZADO_H
