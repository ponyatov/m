#include "m.hpp"

int main(int argc, char* argv[]) {
    init(argc, argv);
    for (int i = 1; i < argc; i++) {
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
    }
    return fini();
}

#define ERR                                                          \
    "\n\n"                                                           \
        << yyfile << ':' << yylineno << ' ' << msg << " [" << yytext \
        << "]\n\n"
void yyerror(QString msg) {
    qDebug().noquote().nospace() << ERR;
    exit(-1);
}

void arg(int argc, char* argv) {  //
    qDebug().nospace() << "argv[" << argc << "] = <" << argv << ">";
}

void init(int& argc, char* argv[]) {
    arg(0, argv[0]);
    assert(qapp = new QApplication(argc, argv));
}

int fini(int err) {
    if (!qapp) delete qapp;
    return err;
}

QApplication* qapp = nullptr;
QMain* qmain = nullptr;

void halt() { exit(fini()); }

void gui() {
    assert(qmain = new QMain());
    qmain->show();
    fini(qapp->exec());
}

QMain::QMain(QWidget* parent) : QMainWindow(parent) {  //
    darkly();
}

void QMain::darkly() {
    assert(palette = new QPalette());
    palette->setColor(QPalette::Window, QColor(0x22, 0x22, 0x22));
    qapp->setPalette(*palette);
}

QMain::~QMain() { delete palette; }

QPalette* QMain::palette = nullptr;
