#pragma once

#include <assert.h>

#include <iostream>

#include <QString>
#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QPalette>

extern int main(int argc, char* argv[]);    ///< program entry point
extern void init(int& argc, char* argv[]);  ///< system initialize
extern int fini(int err = 0);               ///< system finalize & exit
extern void arg(int argc, char* argv);      ///< print command line argument

extern FILE* yyin;
extern char* yyfile;
extern int yylineno;
extern char* yytext;
extern void yyerror(QString msg);
#include "m.parser.hpp"

extern void halt();

extern QApplication* qapp;

class QMain : public QMainWindow {
    static QPalette* palette;
    void darkly();

   public:
    QMain(QWidget* parent = nullptr);
    ~QMain();
};

extern QMain* qmain;

extern void gui();
