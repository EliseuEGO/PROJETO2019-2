#include "aparencia.h"

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void fundo_tela(){
    system("Color 00");
    calma();
    calma();
    system("Color 10");
     calma();
    calma();
    system("Color 20");
    calma();
    calma();
    system("Color 30");
    calma();
    calma();
    system("Color 40");
    calma();
    calma();
    system("Color 50");
    calma();
    calma();
    system("Color 60");
    calma();
    calma();
    system("Color 70");
    calma();
    calma();
    system("Color 8");
    calma();
    calma();
}

void linhas(){
     puts("\n==================================================================\n");
}

void limpaTela(){
    system("cls");
}

void perainda(){
    printf("\nPressione qualquer tecla para continuar...");
    setbuf(stdin,NULL);
    getchar();
}

void calma(){
    Sleep(350);
}