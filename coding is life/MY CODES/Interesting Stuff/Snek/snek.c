//
// Created by Alex on 3/3/2020.
//
#include "head.h"
#include "constants.h"

void initialize() {
    initializeBoard();
    initializeSnake();
    initializeApple();
}

void initializeBoard() {
    board = (char **) malloc(sizeof(char *) * BOARD_HEIGHT);
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        board[i] = (char *) malloc(sizeof(char) * BOARD_WIDTH);
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = NOTHING;
        }
    }
    initializeBorders();
}

void initializeBorders() {
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        board[i][0] = WALL;
        board[i][BOARD_WIDTH - 1] = WALL;
    }
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        board[0][i] = WALL;
        board[BOARD_HEIGHT - 1][i] = WALL;
    }
}

void initializeSnake() {
    snek = (Snake *) malloc(sizeof(Snake));
    snek->head = createSnakeNode(BOARD_WIDTH / 2, BOARD_HEIGHT / 2);
    snek->tail = createSnakeNode(snek->head->pos->x - 1, snek->head->pos->y);

    snek->head->next = snek->tail;
    snek->head->prev = NULL;

    snek->tail->prev = snek->head;
    snek->tail->next = NULL;
}

void initializeApple() {
    Point *rand = getRandomPoint();
    while (isEatingItself(rand)) {
        rand = getRandomPoint();
    }
    apple = rand;
}

void resetBoard() {
    for (int i = 1; i < BOARD_HEIGHT - 1; i++) {
        for (int j = 1; j < BOARD_WIDTH - 1; j++) {
            board[i][j] = NOTHING;
        }
    }
}

void placeSnakeOnBoard() {
    NodeT *currentSnakePart = snek->head;
    while (currentSnakePart != NULL) {
        if (currentSnakePart == snek->head) {
            board[currentSnakePart->pos->y][currentSnakePart->pos->x] = HEAD;
        } else {
            board[currentSnakePart->pos->y][currentSnakePart->pos->x] = REST_OF_SNAKE;
        }
        currentSnakePart = currentSnakePart->next;
    }
}

void placeAppleOnBoard() {
    board[apple->y][apple->x] = APPLE;
}

void printBoard() {
    resetBoard();
    placeSnakeOnBoard();
    placeAppleOnBoard();
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool snakeEatsApple() {
    Point *headPos = snek->head->pos;
    return headPos->x == apple->x && headPos->y == apple->y;
}

bool newHeadPositionHitsWall(Point *newHeadPosition) {
    return newHeadPosition->x == 0 || newHeadPosition->x == BOARD_WIDTH - 1 || newHeadPosition->y == 0 ||
           newHeadPosition->y == BOARD_HEIGHT - 1;
}

bool isEatingItself(Point *point) {
    NodeT *currentNode = snek->head;
    while (currentNode != NULL) {
        if (currentNode->pos->x == point->x && currentNode->pos->y == point->y) {
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

void growSnake() {
    NodeT *newTail = createSnakeNode(snek->tail->pos->x, snek->tail->pos->y);
    newTail->prev = snek->tail;
    newTail->next = NULL;
    snek->tail->next = newTail;
    snek->tail = newTail;
}

void moveSnek(int dirX, int dirY) {
    NodeT *newHead = createSnakeNode(snek->head->pos->x + dirX, snek->head->pos->y + dirY);

    if (isEatingItself(newHead->pos) || newHeadPositionHitsWall(newHead->pos)) {
        showEndGameScreen();
        return;
    }
    snek->head->prev = newHead;
    newHead->next = snek->head;
    newHead->prev = NULL;
    snek->head = newHead;

    shiftTail();

    if (snakeEatsApple()) {
        growSnake();
        initializeApple();
    }
}

NodeT *createSnakeNode(int x, int y) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->pos = (Point *) malloc(sizeof(Point));
    newNode->pos->x = x;
    newNode->pos->y = y;
    return newNode;
}

void shiftTail() {
    NodeT *oldTail = snek->tail;
    snek->tail = snek->tail->prev;
    snek->tail->next = NULL;
    free(oldTail);
}

Point *getRandomPoint() {
    int x = (rand() % (BOARD_WIDTH - 2)) + 1;
    int y = (rand() % (BOARD_HEIGHT - 2)) + 1;
    Point *rand = (Point *) malloc(sizeof(Point));
    rand->x = x;
    rand->y = y;
    return rand;
}

void play() {
    printBoard();
    char move = getch();
    while (move != EXIT) {
        if (move == LEFT) {
            moveSnek(-1, 0);
        } else if (move == DOWN) {
            moveSnek(0, 1);
        } else if (move == RIGHT) {
            moveSnek(1, 0);
        } else if (move == UP) {
            moveSnek(0, -1);
        }
        system("cls");
        printBoard();
        move = getch();
    }
}

void showEndGameScreen() {
    system("cls");
    printf("\n\n\n\t\t\tYOU HAVE LOST. PRESS ANY KEY TO RESTART.\n\n\n");
    getch();
    initialize();
}
