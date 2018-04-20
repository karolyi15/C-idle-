#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textEditor.h"
#include <QLayout>
#include <QRect>
#include <QTableWidget>
#include <QPushButton>
#include <QToolBar>
#include <botoncp.h>

//***************************************BORDER LAYOUT****************************************//
//********************************************************************************************//

class BorderLayout : public QLayout
  {
  public:
      enum Position { West, North, South, East, Center };

      explicit BorderLayout(QWidget *parent, int margin = 0, int spacing = -1);
      BorderLayout(int spacing = -1);
      ~BorderLayout();

      void addItem(QLayoutItem *item) override;
      void addWidget(QWidget *widget, Position position);
      Qt::Orientations expandingDirections() const override;
      bool hasHeightForWidth() const override;
      int count() const override;
      QLayoutItem *itemAt(int index) const override;
      QSize minimumSize() const override;
      void setGeometry(const QRect &rect) override;
      QSize sizeHint() const override;
      QLayoutItem *takeAt(int index) override;

      void add(QLayoutItem *item, Position position);

  private:
      struct ItemWrapper
      {
          ItemWrapper(QLayoutItem *i, Position p) {
              item = i;
              position = p;
          }

          QLayoutItem *item;
          Position position;
      };

      enum SizeType { MinimumSize, SizeHint };
      QSize calculateSize(SizeType sizeType) const;

      QList<ItemWrapper *> list;
  };


//*****************************************MAIN WINDOW*******************************************//
//***********************************************************************************************//

class MainWindow{
public:
    MainWindow();
private:
    void setup();
    QWidget *w=new QWidget;
    BorderLayout *layout=new BorderLayout;
    CodeEditor *textEditor;
    QPlainTextEdit *Stdout;
    QPlainTextEdit *ram;
    syntaxHightlight *syntax;
    QToolBar *toolBar;
    botoncp *runButton;
    botoncp *debugButton;
};


#endif // MAINWINDOW_H
