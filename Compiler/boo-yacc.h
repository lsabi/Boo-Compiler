int yyerror(char const *message);

/*
 * Add one level more of parenthesis (i.e. increase by one the scope counter)
 */
void pushStack();

/*
 * Exit the last level of parenthesis (i.e. decrease by one the scope counter and remove all the variables of the symbol table/stack that belong to that scope)
 */
void popStack();

/*
 * Initialize the scope counter to 0, create the static variables (i.e. the constant ones) and the topOfTheStack variable, pointing to the uppermost entry of the static variables (i.e. the start of the dynamic stack)
 */
void initialize();

/*
 * Shows the value of the typedData passed as parameter
 */
void showExpression(typedData* t);

/*
 * Prints the value of the typedData passed as parameter
 */
void printExpression(typedData* t);

/*
 * Insert a declared variable with no current associated value
 */
void insertNotInstantiatedVariable(char* t, char* n);

/*
 * Insert a declared variable with an associated value
 */
void insertInstantiatedVariable(char* t, char* n, typedData* t2);

/*
 * Look for a variable with the name passed as parameter and return a pointer to it if found, return NULL otherwise
 */
typedData* lookup(char* name);

/*
 * Given two variables, calculates if the two are equal, returning a pointer to the result
 */
typedData* eqExpression(typedData* t1, typedData* t2);

/*
 * Given two variables, calculates the OR of them, returning a pointer to the result
 */
typedData* orExpression(typedData* t1, typedData* t2);

/*
 * Given two variables, calculates the AND of them, returning a pointer to the result
 */
typedData* andExpression(typedData* t1, typedData* t2);

/*
 * Given one variables, calculates the NOT of it, returning a pointer to the result
 */
typedData* notExpression(typedData* t);

/*
 * Given one variable and a type, calculates the CAST of it, returning a pointer to the result
 */
typedData* castExpression(typedData* t, char* type);

/*
 * Look for a variable with the name passed as parameter within the current scope and return 1 if found, 0 otherwise 
 */
int lookupWithScope(char* name);

/*
 * Look for a primitive type of the static part of the stack and return a pointer to it
 */
typedData* lookupPrimitive(char* t, int v);

/*
 * Assigns the value of a typedData (i.e. variable or expression) to a variable
 */
void assignValue(char* n, typedData* t);

/*
 * Assigns the value of an integer to a variable
 */
void assignInteger(char* n, int v);

/*
 * Returns the value of the integer variable passed as parameter
 */
int getInteger(char* n);

/*
 * Returns the typedData of the int or bool variable passed as parameter
 */
typedData* getTypedData(char* n);

/*
 * Returns a typedData of type int with the result of < 
 */
typedData* lessThan(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of >
 */
typedData* greterThan(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of !=
 */
typedData* different(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of +
 */
typedData* plus(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of -
 */
typedData* minus(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of *
 */
typedData* multiply(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of /
 */
typedData* divide(typedData* t1, typedData* t2);

/*
 * Returns a typedData of type int with the result of -
 */
typedData* negative(typedData* t1);

/*
 * Returns a typedData of type int with the result of | |
 */
typedData* modulo(typedData* t1);

/*
 * Returns the top-most typedData with a name 
 */
typedData* firstVar();

/*
 * Assignes the value of t2 to t1
 */
void assignment(typedData* t1, typedData* t2);


/*
 ********************************************
 ********************************************
 * Part of functions reserved for debugging *
 ********************************************
 ********************************************
 */

/*
 * Prints the stack
 */
void printStack();