
#include "SLL.h"

// newNode es una función privada, por eso su nombre está fuera 
// del patrón y además no tiene prototipo en el archivo de encabezados.
static Node* newNode( Item data )
{
	Node* n = malloc( sizeof( Node ) );
	if( n ){
		n->data = data;
		n->next = NULL;
	}
	return n;
}

/**
 * @brief Crea una nueva lista SLL
 * @return Referencia a la nueva lista
 */
SLL* SLL_New()
{
   SLL* sll = malloc( sizeof( SLL ) );
   if( sll ){
      sll->first = sll->last = sll->cursor = NULL;
      sll->len = 0;
   }
   return sll;
}

/**
 * @brief Destruye una lista SLL.
 * @param this Referencia a un objeto SLL.
 * @post La lista se destruyó y no debiera ser utilizada de nuevo.
 */
void SLL_Delete( SLL** this )
{
   assert( *this );

   // primero borra todos los nodos:

   // luego borra al propio objeto this:

   // luego hace que this sea NULL:

}

/**
 * @brief Indica si la lista está vacía
 * @param this Referencia a un objeto SLL
 * @return true si la lista está vacía; false en cualquier otro caso
 */
bool SLL_IsEmpty( SLL* this )
{
}

/**
 * @brief Inserta un elemento a la derecha del cursor. 
 *
 * Si la lista no está vacía, inserta el elemento a la derecha del cursor, 
 * y deja al cursor en su posición original; en caso contrario, inserta al 
 * elemento como el primero y único elemento y el cursor apunta a éste.
 *
 * @param this Referencia a un objeto SLL.
 * @param data El valor que se quiere insertar.
 * @pre El cursor debe apuntar a una posición válida dentro de la lista; en caso
 * contrario no se garantiza el comportamiento.
 * @post El elemento es insertado a la derecha del cursor. EL CURSOR NO
 * SE MUEVE DE POSICIÓN. Si la lista estaba previamente vacía, el cursor queda
 * apuntando al nuevo elemento.
 */
void SLL_Insert( SLL* this, Item data )
{
   Node* n = newNode( data );

   // Asumimos que siempre habrá memoria

   if( SLL_IsEmpty( this ) ){
      this->first = this->last = this->cursor = n;
   } else{

      n->next = this->cursor->next;
      // guardamos el nodo a la derecha del cursor

      this->cursor->next = n;
      // insertamos el nuevo nodo a la derecha del cursor
   }

   ++this->len;
}

/**
 * @brief Inserta un elemento al principio de la lista.
 *
 * @param this Referencia a un objeto SLL.
 * @param data El valor que se quiere insertar.
 * @post El cursor no se modifica.
 */
void SLL_Insert_front( SLL* this, Item data )
{
   Node* n = newNode( data );

   if( SLL_IsEmpty( this ) ){
      this->first = this->last = n;
   } else{
      n->next = this->first;
      this->first = n;
   }

   ++this->len;
}

/**
 * @brief Inserta un elemento al final de la lista.
 *
 * @param this Referencia a un objeto SLL.
 * @param data El valor que se quiere insertar.
 * @post El cursor no se modifica.
 */
void SLL_Insert_back( SLL* this, Item data )
{
}

/**
 * @brief Saca de la lista al elemento indicado por el cursor
 * @param this Referencia a un objeto SLL.
 * @pre La lista no está vacía.
 */
void SLL_Remove( SLL* this )
{
   assert( this->first );
   // error fatal si la lista está vacía

   assert( this->cursor );

   // las SLL's tienen muchas limitaciones, una de ellas es la problemática
   // de borrar el último nodo:

   if( this->len > 1 && this->cursor == this->last ){
      fprintf( stderr, "Error fatal: el cursor apunta al último nodo en"
                       "una lista con más de un elemento.\n" );
      exit( 1 );
   } else if( this->len == 1 ){
      free( this->first );
      this->cursor = this->first = this->last = NULL;
   } else{
      Node* to_be_deleted = this->cursor->next;
      // guardamos el nodo que está a la derecha del cursor

      Node* tmp = to_be_deleted->next;
      // guardamos el nodo que está a la derecha del nodo a la derecha del cursor

      free( to_be_deleted );

      this->cursor->next = tmp;
   }

   --this->len;
}


void SLL_Remove_front( SLL* this )
{
   assert( this->first );
   // error fatal si la lista está vacía

}

void SLL_Remove_back(  SLL* this )
{
   assert( 0 );
   // no está disponible en esta versión de listas enlazadas

}

/**
 * @brief Devuelve una copia del elemento indicado por el cursor. El
 * comportamiento es indefinido si el cursor no apunta a una posición
 * válida.
 * @param this Referencia a un objeto SLL.
 * @return Una copia del elemento indicado por el cursor
 */
Item SLL_Get( SLL* this )
{
   assert( this->first );
   // error fatal si la lista está vacía

   assert( this->cursor );
   // error fatal si el cursor no apunta a una posición válida

}

void SLL_Cursor_first( SLL* this )
{
}

void SLL_CursorLast( SLL* this )
{
}

/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * Esta función se puede utilizar para iterar sobre la lista.
 *
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover a la derecha; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
bool SLL_CursorNext( SLL* this )
{
   bool ret = false;

	if( this->cursor != NULL ){
		this->cursor = this->cursor->next;
      ret = true;
   }

   return ret;
   // las prácticas de buena programación indican que siempre que sea
   // posible debemos de salir en uno y sólo un punto. Si optamos por
   // hacerlo, entonces hay que ser consistentes en todo el programa.
}

/**
 * @brief Vacía la lista sin destruirla.
 * @param this Referencia a un objeto SLL.
 * @post La lista queda vacía.
 */
void SLL_MakeEmpty( SLL* this )
{
   while( this->len > 0 ){
      SLL_Remove_front( this );
   }
}

/**
 * @brief Busca si un elemento está en la lista.
 * @param this Referencia a un objeto SLL.
 * @param key El valor que estamos buscando.
 * @return true si se encontró una coincidencia; false en caso contrario.
 * @post Coloca al cursor en el nodo en el que se hubiera encontrado una
 * coincidencia
 */
bool SLL_Find( SLL* this, Item key )
{
	bool found = false;
	
	if( !SLL_IsEmpty( this ) ){

		for( Node* it = this->first; it != NULL && found == false ; it = it->next ){

			if( key == it->data ){
         // si el dato es compuesto, entonces esta instrucción deberá 
         // modificarse

				this->cursor = it;
				found = true;
			}
		}
	}
	return found;
}

/**
 * @brief Devuelve el número de elementos actualmente en la lista.
 * @param this Referencia a un objeto SLL.
 * @return El número de elementos actualmente en la lista.
 */
size_t SLL_Len( SLL* this )
{
   return this->len;
}
