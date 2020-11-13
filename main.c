


#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include "SLL.h"

// ====================
// Las siguientes funciones NO son parte de la API de la pila, pero accesaremos
// a sus elementos directamente con el fin de simplificar su codificación

void showStructure( const SLL* lst )
{
   printf( "Unimplemented!\n" );
}

void printHelp()
{
    printf( "\nComandos:\n" );

    printf( "  H  : Ayuda (muestra este mensaje)\n" );

#if LIST_TYPE == INT
    printf( "  +x : Inserta x a la derecha del cursor [0,10)\n" );
#else
    printf( "  +x : Insert x a la derecha del cursor [a,z]\n" );
#endif

#if LIST_TYPE == INT
    printf( "  =x : Reemplaza con x el valor indicado por el cursor [0,10)\n" );
#else
    printf( "  =x : Reemplaza con x el valor indicado por el cursor [a,z]\n" );
#endif

    printf( "  -  : Elimina el elemento a la derecha del cursor\n" );

    printf( "  X  : Elimina el primer elemento\n" );

    printf( "  @  : Muestra el dato apuntado por el cursor\n" );

    printf( "  N  : Mueve el cursor a la derecha\n" );

    printf( "  <  : Mueve el cursor al principio de la lista\n" );

    printf( "  >  : Mueve el cursor al final de la lista\n" );

    printf( "  C  : Purga la lista\n" );

    printf( "  E  : ¿Lista vacía?\n" );

    printf( "  #  : Número de elementos actualmente en la lista\n" );

    printf( "  Q  : Termina el programa de prueba\n" );

    printf( "\n" );
}

void testSLL( SLL* lst )
{
   int testDataItem;
   char cmd;
   char str[80];

   printHelp();

   do {
      showStructure( lst );

      printf( "----\nCmd> " );
      scanf( "%s", str );
      cmd = str[ 0 ];

      switch( cmd )
      {
      case 'Q': case 'q': break;
      case 'H': case 'h': printHelp(); break;
      
      case '+': 
#if LIST_TYPE == INT
         testDataItem = str[1] - '0';
         printf( "Pushing: %d\n", testDataItem ); 
#else
         testDataItem = str[1];
         printf( "Pushing: %c\n", testDataItem ); 
#endif
         SLL_Insert( lst, testDataItem );
      break;

#if 0
      case '-':
         printf( "Eliminando el nodo con valor: %d\n", SLL_Get( lst ) );
         SLL_Remove( lst );
      break;

      case 'E': case 'e':
         printf( SLL_IsEmpty( lst ) ? "La lista está vacía\n" : "La lista no está vacía\n" );
      break;

      case 'C': case 'c':
         printf( "Purgando la pila...\n" );
         SLL_MakeEmpty( lst );
      break;
      
      case '#':
         printf( "Elementos en la lista: %ld\n", SLL_Len( lst ) );
      break;
#endif
      
      default: 
         printf( "Comando inactivo o inválido\n" );
         printHelp();
      break;
      }
      

   } while( cmd != 'q' && cmd != 'Q' );
}


//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main(void)
{
	
	return 0;
}
