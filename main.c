/*
-----------------------------------------------------------
-----------------------------DUVIDAS------------------------

para incrementar, decrementar e trocar palestrantes eu preciso criar um novo arquivo e substituir o antigo?



-----------------------------IDEIAS---------------------------

 

-Inserir ID para as palestras e MATRICULA para os alunos
-Os ID's dos eventos são com numeros randomincos entre n e n+100 para serem indentificados com mais facilidade
-Criar menu para manipular congressistas e palestrantes nos eventos;
-ADD palestrante em gp de discussão direto do menu de manipulação de palestrantes;

-Função para verificar se COD, ID ou MATRICULA já existe; int verifica e retorna 1 ou 0;

-----------------------------PROBLEMAS---------------------
-Usar time.h para manipular as horas;
-caso altere dado ou remova um congressista ou palestrante é    necessário fazer o mesmo nos arquivos dos eventos;
-caso um palestrante seja removido é necessario cancelar um evento ou colocar um aviso para se alterar o palestrante da palestra que ele vai dar ou apagar a palesta;
-para o congressista ser removido é necessario cancelar sua inscrição nos eventos que ele está matriculado;
-criar função de cadastrar congressistas nos eventos assim como listar os eventos cadastrados; cadastro por MATRICULA;
lllll

-------------------------------------------------------------
*/


#include <stdio.h>
#include "funcions.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>



int main() {

  //criar a pasta de arquivos
    if(!CreateDirectory("arquivos", NULL)) {
            if(GetLastError()==183){
                printf("\n");
            }else{
        fprintf(stderr, "ERRO: %d\n", GetLastError());
            }
    }
    //hablitar portugues
    setlocale(LC_ALL, "Portuguese");

  //
  PROFS palestrantes[30];
  CONGRE congressistas[300];//add contador de oficina e de curso;
  char organizadores[30][TAM];


mostra();
  //cadastrar palestrante
cadastroPalestrante();
//cadastroPalestrante();
//Listar palestrantes
listarPalestrantes();

//ALTERAR DADOS DE PALESTRANTES
//editaPalestrante();
//Listar palestrantes
listarPalestrantes();

//REMOVER PALESTRANTES
//removerPalestrantes();
puts("dps de remover");
//Listar palestrantes
//listarPalestrantes();

//Listar palestrantes
//listarPalestrantes();




  //MENU
  /*
    1-EVENTOs{
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
      5-EVENTOS  DO CONGRESSISTA
      6-SAIR DE EVENTOS
    }

    3-PALESTRANTES{
      1-CADASTRAR
      2-EDITAR
      3-LISTAR
      4-REMOVER
      5-EVENTOS DO PALESTRANTE
      6-SAIR DE EVENTOS
    }

     4-ORGANIZADORES{
      1-CADASTRAR
      2-EDITAR
      3-LISTAR
      4-REMOVER
     }
  */


  printf("Bom dia\n");
  printf("Vamos programar\n");
  getchar();
  return 0 ;
}
