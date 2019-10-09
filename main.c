/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Para executar:
        > start programa.exe

    Autor: Augusto Luengo Pereira Nunes
    Data: 28/08/2019

*/

#include "tetris.h"
#include "display.h"

#define DEBUG 0

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main()
{
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed = 0;
   

    //posicao inicial do personagem ******
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = Tipo_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;

    //inicializando matriz ****
    init(matrix);

    //apagar o cursor da tela *****
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo********
    while (keypressed != ESC )
    {

        gotoxy(0, 0);

        //posicionar o @ no meio da tela *****
        if(tijolo.i-3>=0) matrix[tijolo.i -3][tijolo.j] = PIXEL;
        if(tijolo.i-2>=0) matrix[tijolo.i -2][tijolo.j] = PIXEL;
        if(tijolo.i-1>=0) matrix[tijolo.i -1][tijolo.j] = PIXEL;
        matrix[tijolo.i][tijolo.j] = PIXEL;

        //mostro a matriz na tela ****
        printMatrix(matrix);

        //faça posição anterior do @ ser apagada *****
        matrix[tijolo.i-3][tijolo.j] = EMPTY;
        matrix[tijolo.i-2][tijolo.j] = EMPTY;
        matrix[tijolo.i-1][tijolo.j] = EMPTY;
        matrix[tijolo.i][tijolo.j] = EMPTY;

        //faço a posição da @ ir para a direita *****
        if (tijolo.I < (ROWS - 1))
            tijolo.I++;

        //lendo teclas  *****
        keypressed = 0;
        if (kbhit()) keypressed = getch();
        if(keypressed == ARROWS) keypressed = getch();

        switch(keypressed){
            case TECLA_A:           
            case LEFT:
            case TECLA_a:
             if(tijolo.J >0) tijolo.J--;     // vai para esquerda *****
             
             break;     
              
            case TECLA_D :
            case RIGHT:
            case |TECLA_d:
                if(tijolo.J < (COLUMNS -1)) tijolo.J++;  // vai para direita *****

           break;   
                
         
          


        }

    } // fim de while *****

    system("pause");

    return 0;
}