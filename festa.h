#ifndef FESTA_H
#define FESTA_H

#include <QObject>
#include "personalizado.h"
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <QMessageBox>

class Festa
{
  public:
    QVector <Personalizado> objeto;
  public:
    int size();
    bool TestarNome(Personalizado x, QString y);
    bool TestarQtdPersonalizados(Personalizado x, int y);
    bool TestarValorUnitario(Personalizado x, float y);
    Personalizado operator[](int a);
    void ColocarPersonalizados(Personalizado x);
    void OrdenarPorNome();
    void OrdenarPorQtd();
    void OrdenarPorValor();
    void ProdutoComMaiorOuMenorValorTotal();
    void ProdutoComMaiorOuMenorQuantidade();
    bool Dados(QString dados);
    bool CarregarPersonalizados(QString arquivo);
    void MudarNome(QString t, QString x);
    void ColocarPersonalizados2(Personalizado x, int y);
    bool VerificarNome(Personalizado x);
    int PosicaoDoPersonalizadoNoVector(Personalizado x);
    void Apagar();
    void ExcluirPersonalizado(Personalizado y);
    int ValorTotalDaConta();
    Festa();
};

bool CompararPorNome(Personalizado x, Personalizado y);
bool CompararPorQtd(Personalizado x, Personalizado y);
bool CompararPorValor(Personalizado x, Personalizado y);

#endif // FESTA_H
