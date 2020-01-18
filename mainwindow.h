#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <festa.h>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <personalizado.h>
#include <QFileDialog>
#include <QDebug>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InserirPersonalizadoTabela(Personalizado a, int b);
    void AtualizarTabela();
    Festa gosto;

private slots:
    void on_InserirDados_clicked();

    void on_OrdenarNome_clicked();

    void on_OrdenarQtd_clicked();

    void on_OrdenarValor_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();



    void on_tabela_cellDoubleClicked(int row, int column);



    void on_Excluir_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
