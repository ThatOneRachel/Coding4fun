#include <stdio.h>
#include "raylib.h"
#define ALTTELA 640
#define LARGTELA 660

int main (){
    InitWindow(LARGTELA, ALTTELA, "Rocky caminhando");
    Texture2D rockydireita = LoadTexture("Rockywalkcycle.png");
    Texture2D rocky = LoadTexture ("Rockywalkcycle.png");
    Texture2D rockyesquerda = LoadTexture("Rockywalkcycleleft.png");
    Vector2 rockyposicao = {300.0f, 280.0f};
    Rectangle frameRef = {0.0f, 0.0f, (float)rocky.width/4, (float)rocky.height};
    int Frameatual= 0;
    int Cont = 0;
    int Velocidade = 6;
    SetTargetFPS(60);

     while (!WindowShouldClose()){
        Cont++;
        if (Cont >= (60/Velocidade))
        {
            Cont = 0;
            Frameatual++;
            if (Frameatual> 3)
                Frameatual = 0;

            frameRef.x = (float)Frameatual*(float)rocky.width/4;
        }
        //movimento do personagem para direita e para a esquerda
        // controle do movimento do personagem
        if (IsKeyDown(KEY_RIGHT)){
                rockyposicao.x += 1.75f;
                rocky = rockydireita;

        }
        else if (IsKeyDown(KEY_LEFT)){
                rockyposicao.x -= 1.75f;
                rocky = rockyesquerda;
        }
        else{
            frameRef.x = 0;
            rocky = rocky;}
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTextureRec(rocky, frameRef, rockyposicao, WHITE);

        EndDrawing();

    }


    CloseWindow();


return 0;}
