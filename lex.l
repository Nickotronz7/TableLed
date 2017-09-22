%option yylineno
%option noyywrap

%{
  #include "y.tab.h"
  #define yyterminate() return END
%}

numbers ([0-9]*)
names ([a-z]+[A-Z]*)
vars ([A-Z]((\$|\#|\@)*[a-zA-Z]*[0-9]*)*){0,11}

%%

"Time" {return TIEMPO;}

">>" {return COMMENT_I;}
"" {return COMMENT_F;}
"+" {return INCREMENT;}
"-" {return DECREMENT;}
"(" {return PARENT_O;}
")" {return PARENT_C;}
"," {return COMMA;}
";" {return SEMICOLONS;}

"TurnOn" {return TURN_ON;}
"TurnOff" {return TURN_OFF;}
"TurnON" {return TURN_ALL_ON;}
"TurnOFF" {return TURN_ALL_OFF;}
"SoundOn" {return PLAY_SOUND;}
"SoundOff" {return STOP_SOUND;}

"Dow" {return INIT_LOOP;}
"Exit" {return EXIT;}
"Enddo" {return END_LOOP;}

"For" {return INIT_FOR;}
"Times" {return TIMES;} /* REVISAR!!! */
"FEnd" {return END_FOR;}

"If" {return INIT_IF;}
"elseIf" {return ELSE_IF;}
"else" {return ELSE;}
"Endif" {return END_IF;}

"Call" {return CALL;}

"D" {return DEFINE;}
"P" {return START_PROCEDURE;}

%%
//
