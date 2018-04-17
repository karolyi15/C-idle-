#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H
#include <QWidget>
#include <QPlainTextEdit>
#include <QLatin1Char>
#include <QPainter>
#include <QTextBlock>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

//*************************SYNTAX************************//
//*******************************************************//

class syntaxHightlight:public QSyntaxHighlighter{
    Q_OBJECT

public:
    syntaxHightlight(QTextDocument *parent=0);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};



//**********************Code Editor**********************//
//*******************************************************//

class CodeEditor:public QPlainTextEdit{
    Q_OBJECT
public:
    CodeEditor(QWidget *parent=0);
    void LineNumberAreaPaintEvent(QPaintEvent *event);
    int LineNumberAreaWidth();
protected:
    void resizeEvent(QResizeEvent *event)override;
private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &,int);
private:
    QWidget *lineNumberArea;
};



//********************Line Number Area********************//
//********************************************************//

class LineNumberArea:public QWidget
{
public:
    LineNumberArea(CodeEditor *editor):QWidget(editor){
     codeEditor=editor;
    }

    QSize sizeHint() const override{
        return QSize(codeEditor->LineNumberAreaWidth(),0);
    }
protected:
    void paintEvent(QPaintEvent *event)override{
        codeEditor->LineNumberAreaPaintEvent(event);
    }
private:
    CodeEditor *codeEditor;
};


#endif // LINENUMBERAREA_H
