#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _accessManager = new QNetworkAccessManager(this);
    connect(_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QNetworkRequest request(QUrl("http://www.bibus.mobi/index.php?id=2277"));
    _accessManager->post(request, "a=recherche_code&code=1282");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    qDebug() << "replyFinished();";//debugtool:
//    qDebug() << "Reply:" << reply->readAll();//debugtool:
    QString html = reply->readAll();
    ui->webView->setHtml(html);
}
