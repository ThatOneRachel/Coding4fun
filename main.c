#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "map.h"
#include "movimentojog.h"
#define LINHAS 20
#define COLUNAS 25
#define ALTTELA 1000
#define LARGTELA 1100
#define AUMENTOL 105
#define AUMENTOH 90
int main(){

    ///�rea da declara��o de vari�veis
    char mapa[LINHAS][COLUNAS];
    //vari�veis que funcionam principalmente como locais
    int l, c, cl, cc;
    //vari�veis que funcionam principalmente para o funcionamento das fun��es
    int x_jog, y_jog, stairs, locomocao = 0, xaux = 0, flag = 0;
    //vari�veis para a anima��o do portal
    int fotoatualp = 0;
    int contfoto = 0;
    int velocidadeframe = 6;

    //texturas e estruturas para a anima��o
    InitWindow(LARGTELA, ALTTELA, "teste de textura");
    Texture2D tijolo = LoadTexture("tijolochao.png");
    Texture2D escada = LoadTexture("escada.png");
    Texture2D bau = LoadTexture("bau.png");
    Texture2D portal = LoadTexture ("portaloficial.png");
    Texture2D ladrao = LoadTexture ("protag.png");
    Rectangle fotoatualprec = {0.0f, 0.0f, (float)portal.width/10, (float)portal.height};

    SetTargetFPS(60);
    ///Carregamento do mapa
        carrega_mapa(mapa, &l, &c);

    ///Loop do funcionamento da tela
    while(!WindowShouldClose()){

        ///Anima��o do portal
        contfoto++;
        if (contfoto >= (60/velocidadeframe)){
            contfoto = 0;
            fotoatualp++;
                if (fotoatualp > 9) fotoatualp = 0;
                fotoatualprec.x = (float)fotoatualp*(float)portal.width/10;
        }

    ///Encontrar o Jogador
    localiza_jogador(mapa, l, c, &x_jog, &y_jog);

    ///Come�o do desenho na tela
    BeginDrawing();

    ClearBackground(WHITE);

    ///Imprimir cada coisa espec�fica para cada peda�o da matriz
    for (cl = 0; cl < l; cl++){
        for (cc = 0; cc < c; cc++){
                if (mapa[cl][cc] == 'X') DrawTexture(tijolo, AUMENTOL*cc, AUMENTOH*cl, WHITE);
                if (mapa[cl][cc] == 'H') DrawTexture(escada, AUMENTOL*cc, AUMENTOH*cl, WHITE);
                if (mapa[cl][cc] == 'C') DrawTexture(bau, AUMENTOL*cc, AUMENTOH*cl, WHITE);
                if (mapa[cl][cc] == '1' || mapa[cl][cc] == '2') {
                        Vector2 posicaop = {AUMENTOL*cc, AUMENTOH*cl};
                        DrawTextureRec(portal, fotoatualprec, posicaop, WHITE);
                }
                if (mapa[cl][cc] == 'D')DrawTexture(ladrao, AUMENTOL*cc, AUMENTOH*cl, WHITE);
        }
    }
    if (IsKeyPressed(KEY_D)) movimenta_lado(mapa, l, c, 1, 1, &xaux, &flag); //a flag funciona para ver se tem a caixa ou n�o
    if (IsKeyPressed(KEY_A)) movimenta_lado(mapa, l, c, 1, -1, &xaux, &flag);
    if (IsKeyPressed(KEY_W))movimenta_cima(mapa, l, c, &stairs, -1, &xaux);
    if (IsKeyPressed(KEY_S))movimenta_cima (mapa, l, c, &stairs, 1, &xaux);

    ///Terminar desenho na tela
    EndDrawing();

    }

return 0;}
