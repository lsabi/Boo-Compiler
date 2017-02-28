%option noyywrap
%option yylineno
%{
	#include <stdlib.h>
	#include <string.h>
	char buffer[100];
	char *s;

/*
	Search for BEGIN keyword and read
	http://aquamentus.com/tut_lexyacc.html

	http://stackoverflow.com/questions/5418181/flex-lex-encoding-strings-with-escaped-characters

	http://epaperpress.com/lexandyacc/str.html

*/

%}

/* Regex Definition */

%x COMMENT COMMENT_LINE string

empty [ |\n|\t]
/* Matches a digit */
digit [0-9]
/* Matches all the possible integer numbers */
NUMBERS {digit}+
/* Letter */
letter [a-zA-Z]
/* Matches a name for the variable. It has to start with a letter and can be followed by whatever character */
ID {letter}({letter}|{digit})*

%%


"/*"            				{ BEGIN(COMMENT); }
				/* Jump back to the normal pattern matching */
<COMMENT>"*/" 					{ BEGIN(INITIAL); }
<COMMENT>\n   					{ }
<COMMENT>.    					{ }

\"								{ BEGIN(string); s=buffer; }
<string>\"{empty}*\+{empty}*\"  {  }
<string>\"  					{ *s=0; BEGIN 0; yylval.lexeme=buffer; return STRING; }
<string>\\n 					{ *s++='\n'; }
<string>\\\"					{ *s++='\"'; }
<string>\\t 					{ *s++='\t'; }
<string>\n 						{  }
<string>\t 						{  }
<string>.						{ *s++=*yytext; }

\/\/ 							{ BEGIN(COMMENT_LINE); }
<COMMENT_LINE>\n 				{ BEGIN(INITIAL); }
<COMMENT_LINE><<EOF>> 			{ BEGIN(INITIAL); }
<COMMENT_LINE>. 				{ }



[ \t\n]

"="			{ return '='; }
"." 		{ return '.'; }
","			{ return ','; }
"("			{ return '('; }
")"			{ return ')'; }
"{"			{ return '{'; }
"}"			{ return '}'; }
"+"			{ return '+'; }
"-"			{ return '-'; }
"*"			{ return '*'; }
"/"			{ return '/'; }
"|"			{ return '|'; }
"<"			{ return '<'; }
">"			{ return '>'; }
"=="		{ return EQ; }
"!="		{ return NEQ; }

"or"		{ return OR; }
"if"		{ return IF; }
"int"		{ return INT; }
"and"		{ return AND; }
"not"		{ return NOT; }
"show"		{ return SHOW; }
"true"		{ return TRUE; }
"false"		{ return FALSE; }
"bool"		{ return BOOL; }
"exit"		{ return EXIT; }
"else"		{ return ELSE; }
"print"		{ return PRINT; }
"integer"	{ return INTEGER; }

{ID}		{ yylval.lexeme=strdup(yytext); return ID; }

{NUMBERS}	{ yylval.integer=atof(yytext); return NUMBERS; }

. 			{ return yyerror("Invalid token!"); } 

%%