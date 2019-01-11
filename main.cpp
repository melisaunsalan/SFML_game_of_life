#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"

#define SECONDS 1000000
#define SPEED 3
using namespace std;



int main() {
    
    grid g;
    
    // Queen Bee
    g.m[3][5]=g.m[3][6]=g.m[4][5]=g.m[4][6]=alive;
    g.m[8][5]=g.m[9][4]=g.m[10][3]=g.m[11][4]=g.m[11][5]=g.m[11][6]=g.m[12][3]=g.m[12][2]=g.m[12][7]=g.m[12][8]=g.m[9][6]=g.m[10][7]=alive;
    g.m[23][5]=g.m[23][6]=g.m[24][5]=g.m[24][6]=alive;
    
    // Toad (period 2)
    g.m[5][20]=g.m[5][21]=g.m[5][22]=g.m[6][21]=g.m[6][22]=g.m[6][23]=alive;
    
    // Glider - becomes a still life when it hits the edge
    g.m[30][1]=g.m[30][2]=g.m[30][3]=g.m[29][3]=g.m[28][2]=alive;
    
    // Beacon (period 2)
    g.m[15][15]=g.m[15][16]=g.m[16][15]=g.m[17][18]=g.m[18][17]=g.m[18][18]=alive;
    
    // Pentadecathlon (period 15)
    g.m[5][32]=g.m[6][32]=g.m[8][32]=g.m[9][32]=g.m[10][32]=g.m[11][32]=g.m[13][32]=g.m[14][32]=g.m[7][31]=g.m[7][33]=g.m[5][32]=g.m[12][31]=g.m[12][33]=alive;
    
    
    // Pre-Pulsar => Pulsar (period 3) after ~20 iterations
    g.m[25][25]=g.m[25][26]=g.m[25][27]=g.m[25][31]=g.m[25][32]=g.m[25][33]=g.m[27][25]=g.m[27][26]=g.m[27][27]=g.m[27][31]=g.m[27][32]=g.m[27][33]=g.m[26][25]=g.m[26][27]=g.m[26][31]=g.m[26][33]=alive;
    

    sf::RenderWindow window(sf::VideoMode((SIZE-1)*CELL_WIDTH,(SIZE-1)*CELL_WIDTH),"Game of life");
    window.setFramerateLimit(SPEED);
    
    sf::RectangleShape rectArray[SIZE-1][SIZE-1];

    initRect(rectArray);
    
    while(window.isOpen()) {
        // Event handling
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed) {
                window.close();
            }
        }
        
        // Draw stuff
        
        window.clear(sf::Color::Black);
        
        Draw(window, rectArray, g);
        
        g.play();
        
        window.display();
    }
 
    

  return 0;
}


/*
Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/



