#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(SalvarDados()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(CarregarDados()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InserirPersonalizadoTabela(Personalizado a, int b)
{

    ui->tabela->setItem(b,0,new QTableWidgetItem(a.getNome()));
    ui->tabela->setItem(b,1,new QTableWidgetItem(QString::number(a.getQtdPersonalizados())));
    ui->tabela->setItem(b,2,new QTableWidgetItem(QString::number(a.getValorunitPersonalizados())));
    ui->tabela->setItem(b,3,new QTableWidgetItem(QString::number(a.getValorTotalPersonalizados())));



}

void MainWindow::AtualizarTabela()
{

    ui->tabela->clearContents();
    for (int i = 0; i < gosto.size(); i++) {
     InserirPersonalizadoTabela(gosto[i],i);
    }
}


void MainWindow::on_InserirDados_clicked()
{

    Personalizado adcionar;
    float a;
    adcionar.setNome(ui->Nome->text());
    adcionar.setQtdPersonalizados(ui->Quantidade->text().toInt());
    adcionar.setValorunitPersonalizados(ui->Valor->text().toFloat());
    adcionar.setValorTotalPersonalizados(0);
    ui->Nome->clear();
    ui->Valor->clear();
    ui->Quantidade->clear();
    QMessageBox frase;

    if((gosto.TestarNome(adcionar,adcionar.getNome())) and (gosto.TestarValorUnitario(adcionar,adcionar.getValorunitPersonalizados())) and (gosto.TestarQtdPersonalizados(adcionar,adcionar.getQtdPersonalizados()))){
        int b = ui->tabela->rowCount();
        ui->tabela->insertRow(b);
        gosto.ColocarPersonalizados(adcionar);
        InserirPersonalizadoTabela(adcionar,b);
        gosto.ProdutoComMaiorOuMenorValorTotal();
        ui->label_9->setText(gosto[0].getNome());
        ui->label_11->setText(gosto[gosto.size()-1].getNome());
        gosto.ProdutoComMaiorOuMenorQuantidade();
        ui->label_5->setText(gosto[gosto.size()-1].getNome());
        ui->label_7->setText(gosto[0].getNome());
        a = gosto.ValorTotalDaConta();
        ui->label_13->setText(QString::number(a));



    }
    else {
        frase.setText("Dados inválidos");
        frase.exec();
    }
}

void MainWindow::on_OrdenarNome_clicked()
{
    gosto.OrdenarPorNome();
    AtualizarTabela();
}

void MainWindow::on_OrdenarQtd_clicked()
{
    gosto.OrdenarPorQtd();
    AtualizarTabela();
}

void MainWindow::on_OrdenarValor_clicked()
{
    gosto.OrdenarPorValor();
    AtualizarTabela();
}

void MainWindow::on_actionSalvar_triggered()
{

    QMessageBox msg;
    QString tipos = "CSV(*.csv);; Arquivos de texto (*.txt) ";
    QString x = QFileDialog::getSaveFileName(this,"Escrever arquivos","",tipos);
    QFile teste(x);
    if(!teste.open(QFile::WriteOnly)){
        msg.setText("Não foi possível salvar o arquivo");
        msg.exec();
    }else {

        gosto.Dados(x);
        teste.close();
    }
}

void MainWindow::on_actionCarregar_triggered()
{
    QMessageBox msg;
        QString tipos= "CSV(*.csv)";
        QString carregar = QFileDialog:: getOpenFileName(this,"Carregar Arquivos","",tipos);
        QFile teste(carregar);
        if(!teste.open(QFile::ReadOnly)){
            msg.setText("Não foi possível carregar o arquivo");
            msg.exec();
        }
            gosto.CarregarPersonalizados(carregar);
             for(int i = 0; i < gosto.size() ; ++i){
              ui->tabela->insertRow(i);
              InserirPersonalizadoTabela(gosto[i],i);
              teste.close();

               }
}

void MainWindow::on_tabela_cellDoubleClicked(int row, int column)
{
    Personalizado a;
      if(column == 0){
              QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o nome do personalizado?");
                  if(resp == QMessageBox::Yes){
                  bool ok;
                  QString txt = QInputDialog::getText(this, "Alterar Nome", "Nome", QLineEdit::Normal,"",&ok);
                  if(ok and !txt.isEmpty()){
                      a.setNome(txt);
                      a.setQtdPersonalizados(gosto[row].getQtdPersonalizados());
                      a.setValorunitPersonalizados(gosto[row].getValorunitPersonalizados());
                      a.setValorTotalPersonalizados(gosto[row].getValorTotalPersonalizados());


                  }
                  qDebug()<< a.getNome();
                  qDebug()<<a.getQtdPersonalizados();
                  qDebug()<< a.getValorunitPersonalizados();
                  qDebug()<< a.getValorTotalPersonalizados();



              }
          }
      else if(column == 1){
                 QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar a qnt de personalizado?");

                 if(resp == QMessageBox::Yes){
                     bool ok;
                     QString txt = QInputDialog::getText(this, "Alterar quantidade", "Quantidade", QLineEdit::Normal,"",&ok);
                     if(ok and !txt.isEmpty()){
                         a.setNome(gosto[row].getNome());
                         a.setQtdPersonalizados(txt.toInt());
                         a.setValorunitPersonalizados(gosto[row].getValorunitPersonalizados());
                         a.setValorTotalPersonalizados(gosto[row].getValorTotalPersonalizados());



                   }
                     qDebug()<< a.getNome();
                     qDebug()<<a.getQtdPersonalizados();
                     qDebug()<< a.getValorunitPersonalizados();
                     qDebug()<< a.getValorTotalPersonalizados();

         }
}
      else if(column == 2){
                 QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o valor?");

                 if(resp == QMessageBox::Yes){
                     bool ok;
                     QString txt = QInputDialog::getText(this, "Alterar valor", "valor", QLineEdit::Normal,"",&ok);
                     if(ok and !txt.isEmpty()){
                         a.setNome(gosto[row].getNome());
                         a.setQtdPersonalizados(gosto[row].getQtdPersonalizados());
                         a.setValorunitPersonalizados(txt.toFloat());
                         a.setValorTotalPersonalizados(gosto[row].getValorTotalPersonalizados());



                 }

                    qDebug()<< a.getNome();
                    qDebug()<<a.getQtdPersonalizados();
                    qDebug()<< a.getValorunitPersonalizados();
                    qDebug()<< a.getValorTotalPersonalizados();

         }
}
                 else if(column == 3){
                            QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o valor total?");

                            if(resp == QMessageBox::Yes){
                                bool ok;
                                QString txt = QInputDialog::getText(this, "Alterar valor total", "valor total", QLineEdit::Normal,"",&ok);
                                if(ok and !txt.isEmpty()){
                                    a.setNome(gosto[row].getNome());
                                    a.setQtdPersonalizados(gosto[row].getQtdPersonalizados());
                                    a.setValorunitPersonalizados(gosto[row].getValorunitPersonalizados());
                                    a.setValorTotalPersonalizados(txt.toFloat());


                            }
                                qDebug()<< a.getNome();
                                qDebug()<<a.getQtdPersonalizados();
                                qDebug()<< a.getValorunitPersonalizados();
                                qDebug()<< a.getValorTotalPersonalizados();

                    }
           }

      gosto.ColocarPersonalizados2(a,row);
      InserirPersonalizadoTabela(a, row);
      gosto.ProdutoComMaiorOuMenorValorTotal();
      ui->label_9->setText(gosto[0].getNome());
      ui->label_11->setText(gosto[gosto.size()-1].getNome());
      gosto.ProdutoComMaiorOuMenorQuantidade();
      ui->label_5->setText(gosto[gosto.size()-1].getNome());
      ui->label_7->setText(gosto[0].getNome());

      qDebug() <<row;

   }






void MainWindow::on_Excluir_clicked()
{
    Personalizado x;
       x.setNome(ui->Nome->text());
       if(gosto.VerificarNome(x)){
       int t = gosto.PosicaoDoPersonalizadoNoVector(x);
       gosto.ExcluirPersonalizado(x);
       ui->tabela->removeRow(t);
       AtualizarTabela();

       }
       ui->Nome->clear();
       ui->Quantidade->clear();
       ui->Valor->clear();

}

