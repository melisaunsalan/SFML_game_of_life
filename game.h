#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

#define SIZE 41
#define CELL_WIDTH 25

const int dead=0;
const int alive=1;

struct grid {
  int m[SIZE+1][SIZE+1];
  grid();
  grid operator=(grid g);
  void display();
  int neighbours(int i, int j); // Moore neighborhood, Chebyshev distance=1
  bool isAlive(int i, int j);
  void becomesAlive(int i, int j);
  void dies(int i, int j);
  void play();
};


void initRect(sf::RectangleShape rect[SIZE-1][SIZE-1]) ;


void Draw(sf::RenderWindow &window, sf::RectangleShape rect[SIZE-1][SIZE-1], grid g);



