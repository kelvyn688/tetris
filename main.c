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

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main()
{

    int keypressed = 0;
    char matrix[ROWS][COLUMNS];
    int posI, posJ;

    //posicao inicial do personagem ******
    posI = 0;
    posJ = COLUMNS / 2;

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
        matrix[posI][posJ] = '@';

        //mostro a matriz na tela ****
        printMatrix(matrix);

        //faça posição anterior do @ ser apagada *****
        matrix[posI][posJ] = ' ';

        //faço a posição da @ ir para a direita *****
        if (posI < (ROWS - 1))
            posI++;

        //lendo teclas  *****
        keypressed = 0;
        if (kbhit()) keypressed = getch();
        if(keypressed == ARROWS) keypressed = getch();

        switch(keypressed){
            case TECLA_A:           
            case LEFT:
            case TECLA_a:
             if(posJ >0) posJ--;     // vai para esquerda *****
             
             break;     
              
            case TECLA_D :
            case RIGHT:
            case |TECLA_d:
                if(posJ < (COLUMNS -1)) posJ++;  // vai para direita *****

           break;   
                
         
          


        }

    } // fim de while *****

    system("pause");

    return 0;
}