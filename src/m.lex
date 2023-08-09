%{
    #include "m.hpp"

    char* yyfile = nullptr;
%}

%option yylineno noyywrap

%%
.   {yyerror("");}
