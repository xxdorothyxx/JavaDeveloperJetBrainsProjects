//
// Created by Alex on 3/3/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#ifndef SNEK_HEAD_H
#define SNEK_HEAD_H

#endif //SNEK_HEAD_H

typedef struct point {
    int x;
    int y;
} Point;

typedef struct node {
    struct node *next;
    struct node *prev;
    Point *pos;
} NodeT;

typedef struct snek {
    NodeT *head;
    NodeT *tail;
    int size;
} Snake;

void initialize();

void play();

void initializeBoard();

bool isEatingItself(Point *point);

void initializeBorders();

void initializeSnake();

void initializeApple();

void updateBoard();

void printBoard();

void shiftTail();

NodeT *createSnakeNode(int x, int y);

void showEndGameScreen();

Point *getRandomPoint();

char **board;
Snake *snek;
Point *apple;
