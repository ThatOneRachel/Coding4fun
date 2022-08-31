#define LINHAS 20
#define COLUNAS 25
void localiza_jogador(char mapa[LINHAS][COLUNAS], int linhas, int colunas, int *x_jog, int *y_jog)
{
    int ctl = 0, ctc = 0;

    ///Percorre a matriz para achar o jogador
    for (ctl = 0; ctl < linhas; ctl++)
    {
        for (ctc = 0; ctc < colunas; ctc++)
        {
            if (mapa[ctl][ctc] == 'D')
            {
                *x_jog = ctl;
                *y_jog = ctc;
            }
        }
    }
}


///Movimentação lateral
///Colocar o caso da porta
void movimenta_lado(char mapa[LINHAS][COLUNAS], int linhas, int colunas, int locomocao, int direcao, int *xaux,  int *flag){
    int x_jog, y_jog, yaux;
    ///localiza o jogador
    localiza_jogador(mapa, linhas, colunas, &x_jog, &y_jog);
        //Se tiver uma parede, então não pode se mover
        if (mapa[x_jog][y_jog+direcao] == 'X') locomocao = 0;
        //caso contrário, opde se mover
        else locomocao = 1;
        if (locomocao == 1)
        {
            //Se for uma escada emcima, coloca uma escada ao se mover
            if (mapa[x_jog-1][y_jog] == 'H') mapa[x_jog][y_jog] = 'H';
            //Parte CERTA pro baú (provavelmente, pq a prate principal fica na função movimenta_cima
            else if (mapa[x_jog][y_jog+direcao] == 'C') {
                *xaux = x_jog;
                yaux = y_jog+direcao;
                mapa[x_jog][y_jog] = ' ';
            }
            //Senão, coloca espaço
            else mapa[x_jog][y_jog] = ' ';
            //o trequinho do jogador aumenta  e ele se move
            y_jog = y_jog + direcao;
            mapa[x_jog][y_jog] = 'D';
            ///Aqui é onde o treco do baú funciona
            if (*flag == 1){
                mapa[x_jog][y_jog-direcao] = 'C';
                *flag = 0;
                *xaux = 0;
            }
            if (*xaux != 0) *flag = 1; //Se xaux for dirente de zero (ou seja, tiver uma coordenada), *flag recebe 1

            //Se não tiver chão embaixo, então ele cai
            if (mapa[x_jog+1][y_jog] == ' ') cair(mapa, x_jog, y_jog);
        }
}


///Função da gravidade
cair(char mapa[LINHAS][COLUNAS], int x_jog, int y_jog)
{
    int cont = 0;
    mapa[x_jog][y_jog] = ' ';
    while (mapa[x_jog+1][y_jog] == ' ')
    {
        x_jog++;
        cont++;
    }
    mapa[x_jog][y_jog] = 'D';
    if (cont >= 3)
    {
        printf("morreuuuu\n");
        //Colocar que ele morra mesmo aqui
    }

}
///Movimento vertical
///TERMINAR ESSE TRECOOOO
///Colocar o caso da porta
void movimenta_cima(char mapa[LINHAS][COLUNAS], int linhas, int colunas, int *escada, int direcao, int *xaux)
{
    int x_jog, y_jog, yaux;
    localiza_jogador(mapa, linhas, colunas, &x_jog, &y_jog);

    /*busca_porta(mapa, linhas, colunas, *porta, &x_porta, &y_porta);
    printf("ele estava em uma porta? %c\n", *porta);
    if (*porta != ' ') *flag = 1;
    printf("flagcima: %d", *flag);
    ///caso porta



    if ((*porta != ' '))
    {
        // busca a outra porta do par
        busca_porta(mapa, linhas, colunas, *porta, &x_porta, &y_porta);
        // jogador passa a estar na posição da porta
        mapa[x_porta][y_porta] = 'D';
        // posição do jogador volta a ser uma porta
        mapa[x_jog][y_jog] = *porta;

    }
    */
    ///caso escada
    ///Melhorar isso aqui pra ficar mais otimizado
        if (direcao == -1)
        {
            if (mapa[x_jog-1][y_jog] != 'H' && mapa[x_jog][y_jog+1] != 'X' && mapa[x_jog][y_jog-1] != 'X') *escada = 0;
            else *escada = 1;
            if (*escada == 1)
            {
                x_jog--;
                mapa[x_jog][y_jog] = 'D';
                mapa[x_jog+1][y_jog] = 'H';
            }
        }
        if (direcao == 1)
        {
            if (mapa[x_jog+1][y_jog] != 'H') *escada = 0;
            else *escada = 1;
            if (*escada == 1)
            {
                if (mapa[x_jog-1][y_jog] != 'H' && mapa[x_jog][y_jog+1] != 'X' && mapa[x_jog][y_jog-1] != 'X') mapa[x_jog][y_jog] = ' ';
                else mapa[x_jog][y_jog] = 'H';
                x_jog++;
                mapa[x_jog][y_jog] = 'D';
            }
        }
    ///Aqui fica o que realmente faz funcionar a questão da caixa
    if (mapa[x_jog][y_jog+direcao] == 'C'){
        printf("caixinha");
        *xaux = x_jog;
        yaux = y_jog+direcao;
        mapa[x_jog][y_jog] = 'D';
        printf("%d %d", *xaux, yaux);
    }
}
