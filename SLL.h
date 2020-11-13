
#ifndef  SLL_INC
#define  SLL_INC

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#ifndef LIST_TYPE

// Símbolos posibles: INT, CHAR
#define LIST_TYPE INT
#endif

#if LIST_TYPE == INT
typedef int Item;
#elif LIST_TYPE == CHAR
typedef char Item;
#else
#error "Tipo no soportado."
#endif


typedef struct Node
{
	Item data;
	struct Node* next;
} Node;

typedef struct SLL
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} SLL;

SLL*   SLL_New();
void   SLL_Delete(       SLL** this );
void   SLL_Insert_front( SLL* this, Item data );
void   SLL_Insert_back(  SLL* this, Item data );
void   SLL_Insert(       SLL* this, Item data );
Item   SLL_Get(          SLL* this );
void   SLL_Remove_front( SLL* this );
void   SLL_Remove_back(  SLL* this );
void   SLL_Remove(       SLL* this );
size_t SLL_Len(          SLL* this );
bool   SLL_IsEmpty(      SLL* this );
void   SLL_MakeEmpty(    SLL* this );
void   SLL_Cursor_front( SLL* this );
void   SLL_Cursor_back(  SLL* this );
void   SLL_Cursor_next(  SLL* this );
bool   SLL_Find(         SLL* this, Item key );

#endif   /* ----- #ifndef SLL_INC  ----- */
