typedef struct typedData
{
	int value;
	char* type;
	char* name;
	int scope;
	int init;
	struct typedData* next; 
	struct typedData* previous;
} typedData;

/*
 * Adds a new element on the stack without the name, just value and type 
 */
typedData* newAnonymous(char* t, int v);

/*
 * Adds a new element (variable) on the the stack to which a value has not been assigned
 */
typedData* newVariable(char* t, char* n);

/*
 * Adds a new element (variable) on the stack to which a value has been assigned
 */
typedData* newValuedVariable(char* t, char* n, int v);