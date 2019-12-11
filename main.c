/*
FALTA


*FAZER A LIMPEZA DAS FUNÇÕES

*COMENTARIO E ORGANIZAÇÃO NO .H

-----------------------------------------------------------
BUGS

-----------------------------DUVIDAS------------------------


-----------------------------IDEIAS---------------------------


-----------------------------PROBLEMAS---------------------


-------------------------------------------------------------
*/


#include <stdio.h>
#include "funcions.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include "aparencia.h"
#include "cores.h"



int main(){

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

  
  
int j;
//cria os locais
  FILE *arq=NULL;
  if ((arq = fopen("arquivos\\locais.txt", "r")) == NULL){
    for(j=1;j<=8;j++){
      criarLocais(j);
    }
  }
mostra();
calma();


//MENU

int op,op2,op3;
do{
  

 limpaTela();
 fundo_tela();

     gotoxy(50,13); amarelo("MENU PRINCIPAL\n");
     gotoxy(40,15); azulclaro("|1|OGANIZADORES\n");
     gotoxy(58,15); azulclaro("|2|CONGRESSISTAS\n");
     gotoxy(40,16); azulclaro("|3|PALESTRANTES\n");
     gotoxy(58,16); azulclaro("|4|EVENTOS\n");
     gotoxy(52,17); azulclaro("|5|SAIR\n");



  cinzaclaro("Escolha uma opcao>>");
  scanf("%d",&op);
  switch(op){ 
    case 1:{//OGANIZADORES
    limpaTela();
        gotoxy(50,13);amarelo("OGANIZADORES\n");
        gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
        gotoxy(58,15); azulclaro("|2|EDITAR\n");
        gotoxy(40,16); azulclaro("|3|LISTAR\n");
        gotoxy(58,16); azulclaro("|4|REMOVER\n");
        gotoxy(52,17); azulclaro("|5|VOLTAR\n");
      cinzaclaro("Escolha uma opcao>>");
      scanf("%d",&op2);

      switch(op2){
        case 1:limpaTela();criaOrganizador(); break;//-CADASTRAR
        case 2:limpaTela();editaOrganizador(); break;//-EDITAR
        case 3:limpaTela();listaOrganizador(); break;//-LISTAR
        case 4:limpaTela();removeOrganizador(); break;//-REMOVER
        case 5: break;//voltar
        default:break;
      }
    }break;
    
    case 2:{//-CONGRESSISTAS
      limpaTela();
      gotoxy(50,13);amarelo("CONGRESSISTAS\n");
      
        azulclaro("|1|CADASTRAR\n");
        azulclaro("|2|EDITAR\n");
        azulclaro("|3|LISTAR\n");
        azulclaro("|4|REMOVER\n");
        azulclaro("|5|CADASTRAR EM EVENTO\n");
        azulclaro("|6|EVENTOS\n");
        azulclaro("|7|SAIR DE EVENTOS\n");
        azulclaro("|8|VOLTAR\n");

      cinzaclaro("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:
          if((numCongressistas())<300){
            limpaTela();
            NovoCongressista(); break;//-CADASTRAR CONGRESSISTA
          }else{
            puts("\n!Numero maximo de congressistas cadastrados!\n");break;
          }
        case 2:limpaTela();editaAluno(); break;//-EDITAR
        case 3:limpaTela();listarAlunos(); break;//-LISTAR
        case 4:limpaTela();removerAluno(); break;//-REMOVER
        case 5:limpaTela();cadastrarAlunoemEvento(); break;//-CADASTRAR EM EVENTO 
        case 6:limpaTela();listaEventosdeAlunos(); break;//-EVENTOS  DO CONGRESSISTA
        case 7:limpaTela();deixarEvento(); break;//-SAIR DE EVENTOS
        case 8: break;//voltar
        default:break;
      }break;
    }break;

    case 3:{//-PALESTRANTES
      limpaTela();
        gotoxy(50,13);amarelo("PALESTRANTES\n");

        gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
        gotoxy(58,15); azulclaro("|2|EDITAR\n");
        gotoxy(40,16); azulclaro("|3|LISTAR\n");
        gotoxy(58,16); azulclaro("|4|REMOVER\n");
        gotoxy(40,17); azulclaro("|5|EVENTOS\n");
        gotoxy(58,17); azulclaro("|6|VOLTAR\n");

      cinzaclaro("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:limpaTela();cadastroPalestrante(); break;//-CADASTRAR
        case 2:limpaTela();editaPalestrante(); break;//-EDITAR
        case 3:limpaTela();listarPalestrantes(); break;//-LISTAR
        case 4:limpaTela();removerPalestrantes(); break;//-REMOVER
        case 5:limpaTela();listaEventosdoPalestrante(); break;//-EVENTOS  DO PALESTRANTE
        case 6: break;//voltar
        default:break;
      }break;
    }break;

    case 4:{//-EVENTOs
      limpaTela();
      gotoxy(50,13); amarelo("EVENTOS\n");
      gotoxy(40,15); azulclaro("|1|PALESTRAS\n");
      gotoxy(58,15); azulclaro("|2|GRUPOD DE DISCUSSOES\n");
      gotoxy(40,16); azulclaro("|3|CURSOS\n");
      gotoxy(58,16); azulclaro("|4|OFICINAS\n");
      cinzaclaro("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:{ //PALESTRAS
          limpaTela();
          gotoxy(50,13);amarelo("PALESTRAS\n");

            gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
            gotoxy(58,15); azulclaro("|2|EDITAR\n");
            gotoxy(40,16); azulclaro("|3|LISTAR\n");
            gotoxy(58,16); azulclaro("|4|REMOVER\n");
            gotoxy(40,17); azulclaro("|5|LISTAR POR PALESTRAS\n");
            gotoxy(58,17); azulclaro("|6|EVENTOS\n");

          cinzaclaro("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:limpaTela();criaPalestra(); break;//-CADASTRAR
            case 2:limpaTela();editaPalestra(); break;//-EDITAR
            case 3:limpaTela();listaPalestras(); break;//-LISTAR
            case 4:limpaTela();removerPalestra(); break;//-REMOVER
            case 5:limpaTela();listarAlunosdaPalestra(); break;//-LISTAR ALUNOS DA PALESTRA 
            case 6: break;//voltar
            default:break;
          }
        }break;
        
        case 2:{//GRUPOD DE DISCUSSÕES
          limpaTela();
          gotoxy(50,13);amarelo("GRUPOS DE DISCUSSOES\n");
            gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
            gotoxy(58,15); azulclaro("|2|EDITAR\n");
            gotoxy(40,16); azulclaro("|3|LISTAR\n");
            gotoxy(58,16); azulclaro("|4|REMOVER\n");
            gotoxy(40,17); azulclaro("|5|LISTAR POR GRUPOS\n");
            gotoxy(58,17); azulclaro("|6|EVENTOS\n");
          cinzaclaro("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:limpaTela();criaGrupo(); break;//-CADASTRAR
            case 2:limpaTela();editaGrupo(); break;//-EDITAR
            case 3:limpaTela();listaGrupos(); break;//-LISTAR
            case 4:limpaTela();removeGrupo(); break;//-REMOVER
            case 5:limpaTela();listaAlunosdoGrupo(); break;//-LISTAR ALUNOS DO GRUPOD
            case 6: break;//voltar
            default:break;
          }
        }break;
        case 3:{ //CURSOS
          gotoxy(50,13);amarelo("CURSOS\n");
            gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
            gotoxy(58,15); azulclaro("|2|EDITAR\n");
            gotoxy(40,16); azulclaro("|3|LISTAR\n");
            gotoxy(58,16); azulclaro("|4|REMOVER\n");
            gotoxy(40,17); azulclaro("|5|LISTAR POR CURSO\n");
            gotoxy(58,17); azulclaro("|6|EVENTOS\n");
          cinzaclaro("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:limpaTela();criaCurso(); break;//-CADASTRAR
            case 2:limpaTela();editaCurso(); break;//-EDITAR
            case 3:limpaTela();listaCursos(); break;//-LISTAR
            case 4:limpaTela();removerCurso(); break;//-REMOVER
            case 5:limpaTela();listarAlunosdoCurso(); break;//-LISTAR ALUNOS DO CURSO 
            case 6: break;//voltar
            default:break;
          }
        }break;
        case 4:{ //OFICINAS
          gotoxy(50,13);amarelo("OFICINAS\n");
            gotoxy(40,15); azulclaro("|1|CADASTRAR\n");
            gotoxy(58,15); azulclaro("|2|EDITAR\n");
            gotoxy(40,16); azulclaro("|3|LISTAR\n");
            gotoxy(58,16); azulclaro("|4|REMOVER\n");
            gotoxy(40,17); azulclaro("|5|LISTAR POR OFICINAS\n");
            gotoxy(58,17); azulclaro("|6|EVENTOS\n");
          cinzaclaro("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:limpaTela();criaOficina(); break;//-CADASTRAR
            case 2:limpaTela();editaOficinas(); break;//-EDITAR
            case 3:limpaTela();listaOficinas(); break;//-LISTAR
            case 4:limpaTela();removerOficinas(); break;//-REMOVER
            case 5:limpaTela();listaAlunosdaOficina(); break;//-LISTAR ALUNOS DA PALESTRA 
            case 6: break;//voltar
            default:break;
          }
        }break;
      }break;
    }
    case 5:{
      puts("Fim do programa");break;
    }
    default: puts("OPCAO INVALIDA");
  }
  perainda();
}while(op!=5);


  getchar();
  return 0 ;
}
