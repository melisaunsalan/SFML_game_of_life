#include "game.h"

grid :: grid() {
  for(int i=0;i<=SIZE;i++)
    for(int j=0;j<=SIZE;j++)
      m[i][j]=0;
}

grid grid :: operator=(grid g) {
  for(int i=0;i<=SIZE;i++)
    for(int j=0;j<=SIZE;j++)
      m[i][j]=g.m[i][j];
}

void grid :: display() {
  for(int i=1;i<SIZE;i++) {
    for(int j=1;j<SIZE;j++) {
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<endl;
}

int grid :: neighbours (int i, int j) {
  return m[i-1][j-1]+m[i-1][j]+m[i-1][j+1]+m[i][j-1]+m[i][j+1]+m[i+1][j-1]+m[i+1][j]+m[i+1][j+1];
}

bool grid :: isAlive(int i, int j) {
  return m[i][j]==alive;
}

void grid :: becomesAlive(int i, int j)  {
  if(m[i][j]==dead)
    m[i][j]=alive;
}

void grid :: dies(int i, int j) {
  if(m[i][j]==alive)
    m[i][j]=dead;
}



void grid :: play() {

  grid n;
  n=*this;

  for(int i=1;i<SIZE;i++)
    for(int j=1;j<SIZE;j++) {
      if(this->isAlive(i,j)) {
        switch (this->neighbours(i,j)) {
          case 0:
          case 1:
            n.dies(i,j);
            break;
          case 2:
          case 3:
            break;
          default:
            n.dies(i,j);
        }
      }
      else {
        if (this->neighbours(i,j)==3)
          n.becomesAlive(i,j);
      }
    }
  *this=n;
}


void initRect(sf::RectangleShape rect[SIZE-1][SIZE-1]) {
    for(int i=0;i<SIZE-1;i++) {
        for(int j=0;j<SIZE-1;j++) {
            rect[i][j].setSize(sf::Vector2f(CELL_WIDTH,CELL_WIDTH));
            rect[i][j].setPosition(i*CELL_WIDTH, j*CELL_WIDTH);
            rect[i][j].setFillColor(sf::Color::Red);
        }
    }
}

void Draw(sf::RenderWindow &window, sf::RectangleShape rect[SIZE-1][SIZE-1], grid g) {
    for(int i=0;i<SIZE-1;i++)
        for(int j=0;j<SIZE-1;j++) {
            rect[i][j].setFillColor((g.m[i+1][j+1]==alive) ? sf::Color::White : sf::Color::Black);
            window.draw(rect[i][j]);
        }
}
