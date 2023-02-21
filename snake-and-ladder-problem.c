/*Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. This is done by 
considering that the player can determine which number appears in the dice being biased. The player rolls the dice and if reaches a base of a ladder then he can move up 
the ladder to a different position/cell and if he reaches a snake then it brings him down away from the destination cell position.*/

#include<stdio.h>
#include<stdlib.h>
void bfs();
void path();
void create_board(struct node *board[])
{
    for(i=0;i<n+1;i++)
    {
        for(j=i+1;j<i+7 && j<=no_of_nodes;j++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=int i;
            newnode->link=NULL;
        }
        if(board[i]==NULL)
        {
            board[i]=newnode;
        }

    }

}
void snakes_and_ladders();

struct node
{
    int data;
    struct node *link;
};
int no_of_nodes;
void main()
{
    printf("\nENTER THE ending square in the board : ");
    scanf("%d",&no_of_nodes);
    struct node *board[no_of_nodes+1];
    for (i=1;i<n+1;i++)
    {
        board[i]=NULL;
    }
    create_board(board);

}
