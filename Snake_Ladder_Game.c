#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int board[10][10], P1 = 0, P2 = 0, dice;
void random();
void setup();
void display();
void snakes();
void ladder();
void player1();
void player2();
void main()
{
    setup();
    srand(time(NULL));
    while (P1 != 100 || P2 != 100)
    {
        system("cls");
        display();
        player1();
        player2();
    }
}
void random()
{
    
    A: dice = rand() % 7;
    if (dice == 0)
    {
        goto A;
    }
    printf("DICE = %d\n\n",dice);
}
void setup()
{
    int i, j, value = 1;
    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            value = (i + 1) * 10;
            for (j = 0; j < 10; j++)
            {
                board[i][j] = value;
                value--;
            }
        }
        else
        {
            value = (i * 10) + 1;
            for (j = 0; j < 10; j++)
            {
                board[i][j] = value;
                value++;
            }
        }
    }
}
void display()
{
    int i, j, value, flag = 0;
    printf("----------------------------- SNAKE & LADDER ------------------------------\n\n");
    for (i = 9; i >= 0; i--)
    {
        for (j = 9; j >= 0; j--)
        {
            if(board[i][j] == P1)
            {
                printf("-P1-\t");
                flag = 1;
            }
            if(board[i][j] == P2)
            {
                printf("-P2-\t");
                flag = 1;
            }
            if(flag == 1)
            {
                flag = 0;
                continue;
            }
            value = board[i][j];
            printf("%d\t", value);
        }
        printf("\n\n");
    }
    printf("----------------------------- SNAKE & LADDER ------------------------------\n\n");
    //printf("");
    //printf("----------------------------- SNAKE & LADDER ------------------------------\n\n");
}
void player1()
{
    random();
    if((P1 + dice) > 100)
    {
        player1();
    }
    P1 += dice;
    display();
    return;
}
void player2()
{
    random();
    if ((P2 + dice) > 100)
    {
        player2();
    }
    
    P2 += dice;
    display();
    return;
}
