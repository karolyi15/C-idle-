#ifndef BOTONCP_H
#define BOTONCP_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>

class botoncp : public QWidget
{
private:
    QPlainTextEdit *Stdout;

public:
    QPushButton *pButton;

    botoncp (QPlainTextEdit *a,QString name){
    this->Stdout =a;
    pButton = new QPushButton(this);
    pButton->setText(name);
    QObject::connect(pButton, &QPushButton::clicked, this, &botoncp::onButtonClicked);
  }

public slots:
  void onButtonClicked () {Stdout->appendPlainText(">>Mission complete!!");}
};

#endif // BOTONCP_H
