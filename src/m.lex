%{
    #include "m.hpp"

    char* yyfile = nullptr;
%}

%option yylineno noyywrap

%%
#.*             {}                  /// line comment

".end"          {return HALT;}      /// \ directives
".halt"         {return HALT;}
".gui"          {return GUI;}

[ \t\r\n]+      {}                  /// drop spaces
.               {yyerror("");}      /// any undetected char
