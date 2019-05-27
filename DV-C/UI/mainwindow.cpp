#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QGLFormat qgl;
    qgl.setVersion(4,0);
    qgl.setProfile(QGLFormat::CoreProfile);
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(ui->centralWidget);
    m_glWidget = new GLWidget(qgl, this);
    m_glWidget->setMinimumSize(100,100);
    gridLayout->addWidget(m_glWidget, 0, 1);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_glWidget;
}
