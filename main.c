/*
-----------------------------------------------------------
-----------------------------DUVIDAS------------------------
-membros da mesa//quem seriam?//PALESTRANTES
-carga horaria?
-Armazenar dados de pessoas//SÓ NOME?
-Planilha a ser apresentada//QUE PLANILHA?
-melhor forma de preencher os horários?


-----------------------------IDEIAS---------------------------
 //usar ADM para cadastro; enviar o ponteiro para função e preencher os dados
 Estudar time.h

 
-----------------------------PROBLEMAS---------------------
Usar time.h para manipular as horas
-------------------------------------------------------------
*/


#include <stdio.h>
#include "funcions.h"



int main() {
  //usar ADM para cadastro; enviar o ponteiro para função e preencher os dados
  PROFS palestrantes[30];
  CONGRE congressistas[300];//add contador de oficina e de curso;
  char organizadores[30][TAM];


  //MENU
  /*
    1-EVENTO{
      1-PALESTRAS{
        1-CADASTRAR
        2-EDITAR
        3-LISTAR
        4-REMOVER
      }
      2-GRUPOD DE DISCUSSÕES{
        1-CADASTRAR
        2-EDITAR
        3-LISTAR
        4-REMOVER
      }
      3-CURSOS{
        1-CADASTRAR
        2-EDITAR
        3-LISTAR
        4-REMOVER
      }
      4-OFICINAS{
        1-CADASTRAR
        2-EDITAR
        3-LISTAR
        4-REMOVER
      }
    }

    2-CONGRESSISTAS{
      1-CADASTRAR
      2-EDITAR
      3-LISTAR
      4-REMOVER
    }

    3-PALESTRANTES{
      1-CADASTRAR
      2-EDITAR
      3-LISTAR
      4-REMOVER
    }

     4-ORGANIZADORES{
      1-CADASTRAR
      2-EDITAR
      3-LISTAR
      4-REMOVER
     }
  */


  printf("Hello World\n");
  return 0;
}
