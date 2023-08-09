%{
    #include "m.hpp"
    #include "m.lexer.hpp"
%}

%token HALT GUI

%%
grammar : | grammar ex ;

ex : HALT   { halt(); }
   | GUI    { gui();  }
