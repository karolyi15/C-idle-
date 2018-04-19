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

    botoncp (QPlainTextEdit *a){
    this->Stdout =a;
    pButton = new QPushButton(this);
    QObject::connect(pButton, &QPushButton::clicked, this, &botoncp::onButtonClicked);
  }

public slots:
  void onButtonClicked () {Stdout->appendPlainText("Mission complete!!");}
};

#endif // BOTONCP_H
