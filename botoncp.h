#ifndef BOTONCP_H
#define BOTONCP_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include "textEditor.h"

class botoncp : public QWidget
{
private:
    CodeEditor *Stdout;
    QPlainTextEdit *b;

public:
    QPushButton *pButton;

    botoncp (QPlainTextEdit *b,CodeEditor *a,QString name){
    this->Stdout =a;
    this->b=b;
    pButton = new QPushButton(this);
    pButton->setText(name);
    QObject::connect(pButton, &QPushButton::clicked, this, &botoncp::onButtonClicked);
  }

public slots:
  void onButtonClicked () {


      b->appendPlainText(Stdout->toPlainText());

  }
};

#endif // BOTONCP_H
