#include "aparencia.h"

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void fundo_tela(){
    system("Color 05");
}

void linhas(){
     puts("\n==================================================================\n");
}

void limpaTela(){
    system("cls");
}

void perainda(){
    getchar();
    printf("\nPressione qualquer tecla para continuar...");
}

void calma(){
    Sleep(350);
}