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

int fini(int err) { return err; }

QApplication* qapp = nullptr;
