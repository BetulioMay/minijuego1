/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include "raylib.h"
#include <string>

using namespace std;

const float WIDTH = 800.0;
const float HEIGHT = 800.0;

int main(int argc, char* argv[]){
    
    int N = atoi(argv[1]);
    
    Particula base(WIDTH / 2.0, HEIGHT - 20.0, 5.0, 0.0, RADIO * 2.0);
    ConjuntoParticulas cp(N);
    
    InitWindow(WIDTH, HEIGHT, "El juego toca pelotas");
    
    SetTargetFPS(60);
    
    int time = 0;
    int ticks = 0;
    string s;
    
    while (!WindowShouldClose()){
        
        // Update
        if (cp.GetUtiles() > 0) {
            cp.Mover(WIDTH, HEIGHT);
            cp.Rebotar(WIDTH, HEIGHT);

            if (IsKeyDown(KEY_LEFT)) {
                base.MoverGrid('L', WIDTH, HEIGHT);
            } else if (IsKeyDown(KEY_RIGHT)) {
                base.MoverGrid('R', WIDTH, HEIGHT);
            }

            for (int i = cp.GetUtiles() - 1; i >= 0; --i) {
                if (base.Colision(cp.ObtieneParticula(i))) {
                    cp.BorraParticula(i);
                }
            }
        
        
            time += (ticks < 59) ? 0 : 1;
            
            ticks++;
            ticks = ticks % 60;
        }
        
        // Draw
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        if (cp.GetUtiles() == 0) {
            
            s = "Juego Finalizado!\tTiempo total -> " + to_string(time) + "\nPulsa ESC para salir";
            DrawText(s.c_str(), WIDTH / 4.0, HEIGHT / 2.0, 30, GREEN);
            
        } else {
            
            s = "Particulas -> " + to_string(cp.GetUtiles()) + "\tCap -> " +
                to_string(cp.GetCapacidad()) + "\tTiempo -> " + to_string(time);
            
            pintarParticula(base, BLACK);
            pintarConjunto(cp, RED);

            DrawText("Pulse ESC to exit", 10, 10, 20, BLACK);
            DrawText(s.c_str(), 10, 30, 20, BLACK);
        }

        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
