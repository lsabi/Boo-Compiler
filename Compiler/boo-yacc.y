/*
 ***********************************************************
 ********************* DECLARATIONS ************************
 ***********************************************************
*/
%{
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdio.h>
// Include header definition of data type
	#include "boo-variable.h"
// Include header definition of methods
	#include "boo-yacc.h"
// Global counter for saving the current scope
	int globalCounter, ignore;
	typedData *topOfTheStack=NULL;
	typedData *staticStackValues=NULL;

// http://stackoverflow.com/questions/26211770/how-to-detect-error-line-number-using-yacc-parser#26219633
// http://stackoverflow.com/questions/496448/how-to-correctly-use-the-extern-keyword-in-c#496476 
	extern int yylineno;

// http://stackoverflow.com/questions/20106574/simple-yacc-grammars-give-an-error
	int yylex();
%}

%union
{
	int integer;		//value of terminal
	char *lexeme; 		//identifier
	typedData *data;	//variable type defined in the boo-variable.h
}

// Definitions for the tokens
%token <lexeme> ID STRING
%token <integer> NUMBERS
%token IF ELSE PRINT SHOW AND OR NOT EQ NEQ EXIT BOOL TRUE FALSE INT INTEGER

%type <data> expr

// Associativity and precedence between operators
%left OR
%left AND
%left NOT
%left '(' ')' '{' '}'
%left '<' '>' EQ NEQ
%left '+' '-'
%left '*' '/'

%nonassoc CASTING
%nonassoc UMINUS


/*
 ***********************************************************
 ************************ GRAMMAR **************************
 ***********************************************************
*/

// Scope of the language
%start start
%%

// Now, starting from the scope of the language derive the grammar
// Using left-recursion http://epaperpress.com/lexandyacc/rec.html
start : scope start
	  | /* NULL */
	  ;

scope : '{' {pushStack();} start '}' {popStack();}
	  | expr '.' 									
	  | declaration '.' 							
	  | statement 	
	  | assignment '.'
	  | PRINT expr '.'		{ printExpression($2); }
	  | SHOW expr '.'		{ showExpression($2); }			
	  | EXIT '.' 			{ exit(EXIT_SUCCESS); }
	  | PRINT STRING '.' 	{ printf("%s",$2); }
	  ;

declaration : INT ID { insertNotInstantiatedVariable("int", $2); } decl
			| BOOL ID { insertNotInstantiatedVariable("bool", $2); } decl 
			| INTEGER ID { insertNotInstantiatedVariable("integer", $2); } decl
			| INT ID '=' expr { insertInstantiatedVariable("int", $2, $4); } decl
			| BOOL ID '=' expr  { insertInstantiatedVariable("bool", $2, $4); } decl
			| INTEGER ID '=' expr { insertInstantiatedVariable("integer", $2, $4); } decl
			;

// Left-recursion doesn't matter since bottom-up parsers can handle it (Yacc is a bu parser)
decl : decl ',' ID 				{ insertNotInstantiatedVariable(firstVar()->type, $3); }
	 | decl ',' ID '=' expr 	{ insertInstantiatedVariable(firstVar()->type, $3, $5); }
	 | /* NULL */
	 ;

assignment : ID '=' expr 	{ if(!$3) { yyerror("Invalid expression to assign!"); exit(EXIT_FAILURE); } else { if(!ignore) { assignValue($1, $3); } } }
		   ;

statement : IF expr 
		  			{if(!$2){yyerror("Invalid condition!");exit(EXIT_FAILURE);}}
		  		'{' 
		  			{pushStack(); if($2->value>0){ignore=0;}else{ignore=1;}} 
		  		if_scope 
		  		'}' 
		  			{popStack();} 
		  		else_statement 
		  			{ignore=0;}
		  ;

else_statement : /* NULL */
		   	   | ELSE '{' 
		  			{pushStack(); if(ignore){ignore=0;}else{ignore=1;}} 
		  		if_scope
		  		'}' 
		  			{popStack();}
		  	   ;

if_scope : assignment '.' if_scope
		 | PRINT expr '.' { if(!ignore){printExpression($2);}} if_scope
		 | SHOW expr '.' { if(!ignore){showExpression($2);}} if_scope
		 | EXIT '.' {if(!ignore){exit(EXIT_SUCCESS);}} if_scope
		 | PRINT STRING '.' { if(!ignore){printf("%s",$2);}} if_scope
		 | /* NULL */
		 ;

expr : TRUE 									{ $$=lookupPrimitive("bool", 1); }
	 | FALSE 									{ $$=lookupPrimitive("bool", 0); }
	 | NUMBERS		 							{ $$=newAnonymous("integer", $1); }
	 | ID 										{ if(!$1) { $$=NULL; yyerror("Invalid variable name!"); exit(EXIT_FAILURE); } else { $$=getTypedData($1); } }
	 | expr OR expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid members of the OR operator!"); exit(EXIT_FAILURE); } else { $$=orExpression($1, $3); } } 
	 | expr AND expr							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid members of the AND operator!"); exit(EXIT_FAILURE); } else { if(strcmp($1->type,$3->type)) { yyerror("Variables type of AND operator don't match!"); exit(EXIT_FAILURE); } else { $$=andExpression($1, $3); } } } 
	 | NOT '(' expr ')'							{ if(!$3) { $$=NULL; yyerror("Invalid member of NOT operator!"); exit(EXIT_FAILURE); } else { $$=notExpression($3); } }
	 | INT '(' expr ')'	 %prec CASTING			{ if(!$3) { $$=NULL; yyerror("Invalid member of INT CAST operator!"); exit(EXIT_FAILURE); } else { $$=castExpression($3, "int"); } }
	 | BOOL '(' expr ')' %prec CASTING			{ if(!$3) { $$=NULL; yyerror("Invalid member of BOOL CAST operator!"); exit(EXIT_FAILURE); } else { $$=castExpression($3, "bool"); } }
	 | '(' expr ')'		 						{ if(!$2) { $$=NULL; yyerror("Invalid member of ( ) operator!"); exit(EXIT_FAILURE); } else { $$=$2; } }
	 | expr '<' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of < operator!"); exit(EXIT_FAILURE); } else { $$=lessThan($1, $3); } }
	 | expr '>' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of > operator!"); exit(EXIT_FAILURE); } else { $$=greterThan($1, $3); } }
	 | expr EQ expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of == operator!"); exit(EXIT_FAILURE); } else { $$=eqExpression($1, $3); } }
	 | expr NEQ expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of != operator!"); exit(EXIT_FAILURE); } else { $$=different($1, $3); } }
	 | expr '+' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of + operator!"); exit(EXIT_FAILURE); } else { $$=plus($1, $3); } }
	 | expr '-' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of - operator!"); exit(EXIT_FAILURE); } else { $$=minus($1, $3); } }
	 | expr '*' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of * operator!"); exit(EXIT_FAILURE); } else { $$=multiply($1, $3); } }
	 | expr '/' expr 							{ if(!$1 || !$3) { $$=NULL; yyerror("Invalid member of / operator!"); exit(EXIT_FAILURE); } else { $$=divide($1, $3); } }
	 | '-' expr 		%prec UMINUS			{ if(!$2) { $$=NULL; yyerror("Invalid member of - operator!"); exit(EXIT_FAILURE); } else { $$=negative($2); } }
	 | '|' expr '|'								{ if(!$2) { $$=NULL; yyerror("Invalid member of | | operator!"); exit(EXIT_FAILURE); } else { $$=modulo($2); } }
	 ;

%%

/*
 ***********************************************************
 *********************** FUNCTIONS *************************
 ***********************************************************
*/

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the first value is less than the second
 */
typedData* lessThan(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of < operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of < operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value < t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the first value is greater than the second
 */
typedData* greterThan(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of > operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of > operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value > t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending of the values are different or not
 */
typedData* different(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of != operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of != operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value != t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the sum of the two parameters
 */
typedData* plus(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of + operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of + operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value + t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the difference of the two parameters
 */
typedData* minus(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of - operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of - operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value - t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the multiplication of the two parameters
 */
typedData* multiply(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of * operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of * operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value * t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the division of the two parameters. In case of zero dividend, an error is raised and the program is exited
 */
typedData* divide(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of / operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of / operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t2->value)
		return newAnonymous("integer", t1->value / t2->value);
	else
	{
		yyerror("Cannot divide by zero, you ignorant!");
		exit(EXIT_FAILURE);
	}
}

/*
 * Given one typedData (parameter), checks that it is of type integer and returns a reference to a new element of type integer containing the negation of the parameter
 */
typedData* negative(typedData* t1)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("Member of - (negative) operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value*-1);
}

/*
 * Given one typedData (parameter), checks that it is of type integer and returns a reference to a new element of type integer containing the modulo of the parameter
 */
typedData* modulo(typedData* t1)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("Member of | | operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value<0)
		return newAnonymous("integer", t1->value*-1);
	else
		return newAnonymous("integer", t1->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the values are equal or not
 */
typedData* eqExpression(typedData* t1, typedData* t2)
{	
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value == t2->value)
			return lookupPrimitive(t1->type, 1);
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of equals operation are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if((t1->value>0 && t2->value>0) || (t1->value<1 && t2->value<1))
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointers are valid or of the same type because the semantic action has already checked if they are not null or of the same type, returning a particular error notice
 */
typedData* orExpression(typedData* t1, typedData* t2)
{
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value>0 || t2->value>0)
			return lookupPrimitive(t1->type, 1); 
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of OR operator are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t1->value>0 || t2->value>0)
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointers are valid or of the same type because the semantic action has already checked if they are not null or of the same type, returning a particular error notice
 */
typedData* andExpression(typedData* t1, typedData* t2)
{	
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value>0 && t2->value>0)
			return lookupPrimitive(t1->type, 1); 
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of AND operator are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t1->value>0 && t2->value>0)
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointer is valid beacause the semantic action has already checked if it is not null, returning a particular error notice
 */
typedData* notExpression(typedData* t)
{
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t->type, "bool"))
		if(t->value)
			return lookupPrimitive(t->type, 0); 
		else
			return lookupPrimitive(t->type, 1);
	else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t->value)
				return lookupPrimitive("int", 0);
			else
				return lookupPrimitive("int", 1);
		}
}

/*
 * There is no need to check if the pointer is valid because the semantic action has already checked if it is not null, returning a particular error notice
 */
typedData* castExpression(typedData* t, char* type)
{
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	typedData* temp=NULL;
	if(!strcmp(t->type, type))
	{
		printf("Notice: The expression at line %d is already of type %s\n", yylineno, t->type);
		free(temp);
		return t;
	}
	if(!strcmp("bool", type))
		if(t->value>0)
			temp=lookupPrimitive("bool", 1);
		else
			temp=lookupPrimitive("bool", 0);
	else
		if(!strcmp("int", type))
			if(t->type>0)
				temp=lookupPrimitive("int", 1);
			else
				temp=lookupPrimitive("int", 0);
	return temp;
}

/*
 * Inserts a variable into the symbol table with no defined value
 */
void insertNotInstantiatedVariable(char* t, char* n)
{
	if(!lookupWithScope(n))
	{
		newVariable(t, n);
		return;
	}
	yyerror(strcat(n, " has been already declared within the scope!"));
	exit(EXIT_FAILURE);
}

/*
 * Inserts a variable into the symbol table with a defined value
 */
void insertInstantiatedVariable(char* t, char* n, typedData* t2)
{
	if(!lookupWithScope(n))
	{
		assignment(newVariable(t, n), t2);
		return ;
	}
	yyerror(strcat(n, " has been already declared within the scope!"));
	exit(EXIT_FAILURE);
} 

/*
 * Takes as parameter an expression (of type typedData) and prints its value, depending on the type
 */
void printExpression(typedData* t)
{
	if(!t)
	{
		yyerror("Invalid expression to print!");
		exit(EXIT_FAILURE);
	}
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t->type, "bool"))
		if(t->value)
			printf("true\n");
		else
			printf("false\n");
	else
		if(!strcmp(t->type, "int"))
			printf("%d\n",t->value);
		else
			if(!strcmp(t->type, "integer"))
				printf("%d\n",t->value);
}

/*
 * Takes as parameter an expression (of type typedData) and prints its value, on the same line, depending on the type
 */
void showExpression(typedData* t)
{
	if(!t)
	{
		yyerror("invalid expression to print!");
		exit(EXIT_FAILURE);
	}
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t->type, "bool"))	
		if(t->value)
			printf("true");
		else
			printf("false");
	else
		if(!strcmp(t->type, "int"))
			printf("%d",t->value);
		else
			if(!strcmp(t->type, "integer"))
				printf("%d",t->value);
}

/*
 * Takes as parameter the type and the name of the variable to insert into the symbol table. It updates the pointer of the stack
 */
typedData* newVariable(char* t, char* n)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->name=strdup(n);
	newvar->scope=globalCounter;
	newvar->init=0;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Takes as parameter the type, the name and the value of the variable to insert into the symbol table. It updates the pointer of the stack
 */
typedData* newValuedVariable(char* t, char* n, int v)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->name=strdup(n);
	newvar->scope=globalCounter;
	newvar->value=v;
	newvar->init=1;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Takes as parameter the type and the value of a variable to insert into the symbol table. It is used for the base/default values
 */
typedData* newAnonymous(char* t, int v)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->scope=globalCounter;
	newvar->value=v;
	newvar->init=1;
	newvar->name=NULL;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Initializes the symbol table. The global counter is set to 0, the basic/default values are inserted into the symbol table and both the top of the stack pointer and the static stack pointer are set to the newest entry of the symbol table
 */
void initialize()
{
	ignore=0;
	globalCounter=0;
	topOfTheStack=NULL;
	staticStackValues=NULL;
// Generate default values
	newAnonymous("int", 0);
	newAnonymous("int", 1);
	newAnonymous("bool", 0);
	newAnonymous("bool", 1);
	staticStackValues=topOfTheStack; 
	globalCounter++;
}

/*
 * Increases the global counter by one, meaning that a new scope is entered
 */
void pushStack()
{
	globalCounter+=1;
}

/*
 * Removes all the variables, on top of the stack, that belong to the scope that is exited, and the global counter is decreased by one
 */
void popStack()
{
	if(topOfTheStack==NULL || topOfTheStack==staticStackValues)
		return ;
	while(topOfTheStack->scope==globalCounter)
	{
		typedData* temp=topOfTheStack;
		topOfTheStack=topOfTheStack->previous;
		topOfTheStack->next=NULL;
		temp->previous=NULL;
//		free(temp->previous);
		free(temp->name);
		free(temp->type);
		free(temp);
	}
	globalCounter-=1;
	return ;
}

/*
 * Takes as parameter the name of a variable and looks for it through the symbol table. If no variable with such a name is found, then NULL is returned, otherwise a pointer pointing to it is returned
 */
typedData* lookup(char* name)
{
	if(topOfTheStack==NULL || topOfTheStack==staticStackValues)
		return NULL;
	typedData* temp=topOfTheStack;
	while(temp!=staticStackValues)
	{
		if(temp->name && !strcmp(temp->name, name))
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Takes as parameters the type and the value of a basic/default value and looks for it into the first part of the stack
 */
typedData* lookupPrimitive(char* t, int v)
{
	if(staticStackValues==NULL)
		initialize();
	typedData* temp=staticStackValues;
	while(temp!=NULL)
	{
		if((!strcmp(temp->type,t)) && temp->value==v)
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Takes as parameter the name of a variable, uses the lookup method to get the first variable with that name, starting from the top of the stack. Then compares the scope of it with the current global counter and returns either 1 or 0 if, respectively, it has been declared within the current scope or a more external (i.e. looks that a variable with that name has not been already instantiated within the same scope).  
 */
// This method is a boolean method: 0 stands for false (i.e. the variable's declaration is not in the current scope) and 1 for true
int lookupWithScope(char* name)
{
	typedData* temp=lookup(name);
	if(temp!=NULL && temp->scope==globalCounter)
		return 1;
	else
		return 0;
}

/*
 * Returns a reference to the first element on top of the stack that is a variable (i.e. name not NULL)
 */
typedData* firstVar()
{
	typedData* temp=topOfTheStack;
	while(temp!=NULL)
	{
		if(temp->name)
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Given the name of a variable and the result of an expression, assigns the value of the expression to the variable (after looking for it through the stack). An expression is only of type int or bool and thus there is no need to check if the type is a valid one, but it is checked if they are both of the same type
 */
void assignValue(char* n, typedData* t)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, t->type))
	{
		temp->value=t->value;
		temp->init=1;
	}
	else
	{
		if(!strcmp(temp->type, "int") && !strcmp(t->type, "integer"))
		{
			if(t->value > 0)
				temp->value=1;
			else
				temp->value=0;
			temp->init=1;
		}
		else
		{
			yyerror("Cannot assign a value that is not of the same type as the variable!");
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * Given two typedData (parameters), check that they are of the same type or at least that the right variable is of type int and the left variable of type integer and assigns the right value to the left variable
 */
void assignment(typedData* t1, typedData* t2)
{
	if(!strcmp(t1->type, t2->type))
	{
		t1->value=t2->value;
		t1->init=1;
	}
	else
	{
		if(!strcmp(t1->type, "int") && !strcmp(t2->type, "integer"))
		{
			if(t2->value > 0)
				t1->value=1;
			else
				t1->value=0;
			t1->init=1;
		}
		else
		{
			yyerror("Cannot assign a value that is not of the same type as the variable!");
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * Given the name of a variable, looks for it through the stack and returns the pointer to it if it is of type integer, otherwise throws an error
 */
int getInteger(char* n)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE); 
	}
	if(!temp->init)
	{
		yyerror(strcat(temp->name, " has not value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, "integer"))
		return temp->value;
	else
	{
		yyerror(strcat(n, " is not of type integer!"));
		exit(EXIT_FAILURE);
	}
}

/*
 * Given the name of a variable, looks for it through the stack and returns the pointer to it if it is of type int or bool, otherwise throws an error
 */
typedData* getTypedData(char* n)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE);
	}
	if(!temp->init)
	{
		yyerror(strcat(temp->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, "int") || !strcmp(temp->type, "bool") || !strcmp(temp->type, "integer"))
		return temp;
	else
	{
		yyerror(strcat(n, " is not of type int, bool or integer!\nSomething wrong happened to the stack"));
		exit(EXIT_FAILURE);
	}
}







/*
 * Part of functions reserved for debugging (aka, vip functions)
 */
void printStack()
{
	printf("***SYMBOL TABLE***\n");
	typedData* temp=topOfTheStack;
	while(temp!=NULL && temp!=staticStackValues)
	{
		printf("|");
		if(temp->name!=NULL)
			printf("%s\t", temp->name);
		else
			printf("NULL\t");
		printf("%s\t", temp->type);
		if(temp->init)
			if(!strcmp(temp->type,"int") || !strcmp(temp->type,"integer"))
				printf("%d", temp->value);
			else
				if(!strcmp(temp->type,"bool"))
					if(temp->type)
						printf("true");
					else
						printf("false");
		else
			printf("not assigned");
		temp=temp->previous;
		printf("|\n|\t\t|\n");
	}
}

#include "lex.yy.c"

// Since the parser is going to be run as a program, the main function is required and has to invoke yyparse() for starting the parser
int main()
{
	printf("***Welcome to Boo-Compiler***\n\n");
	initialize();
	// Can print anything, like a welcome string or simply execute the parsing
	// yyparse() starts the parser when called
	return yyparse();
}

// Patch for Ubuntu
int yyerror (char const *message)
{
	/* Error message of type
	 * ERROR at <line_number>:
	 * 		<error_message>	
	 */
  	return fprintf (stderr, "ERROR %s %d:\n\t%s\n", "at", yylineno, message);
  	fputs (message, stderr);
  	fputc ('\n', stderr);
  	return 0;
}