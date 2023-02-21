/*Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. This is done by
considering that the player can determine which number appears in the dice being biased. The player rolls the dice and if reaches a base of a ladder then he can move up
the ladder to a different position/cell and if he reaches a snake then it brings him down away from the destination cell position.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
int no_of_nodes, i, j,ns,end,start;
void display_graph();
void bfs();
void path();
void snakes_and_ladders(struct node *board[],int end ,int start)
{

}
void create_board(struct node *board[])
{
    struct node *last, *newnode;
    for (int i = 0; i < no_of_nodes + 1; i++)
    {
        for (int j = i + 1; j < i + 7 && j <= no_of_nodes; j++)
        {

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = j;
            newnode->link = NULL;

            if (board[i] == NULL)
            {
                board[i] = newnode;
            }
            else
            {
                last->link = newnode;
            }
            last = newnode;
        }
    }
}
<<<<<<< HEAD


=======
void snakes_and_ladders();
>>>>>>> 269248f3650599026a20306f006a75ea0ab9c955
void main()
{
    printf("\nENTER THE ending square in the board : ");
    scanf("%d", &no_of_nodes);
    struct node *board[no_of_nodes + 1];
    for (i = 1; i < no_of_nodes + 1; i++)
    {
        board[i] = NULL;

    }
    create_board(board);
    printf("\nEnter the number of snakes : ");
    scanf("%d",&ns);
    for(i=1;i<ns+1;i++)
    {
        printf("Enter the starting cell and ending value of  snake %d : \n ",i);
        scanf("%d%d",&end,&start);
        snakes_and_ladders(board,end,start);
    }

    printf("\nEnter the number of Ladders  : ");
    scanf("%d",&ns);
    for(i=1;i<ns+1;i++)
    {
        printf("Enter the starting cell and ending value of  Ladder %d : \n ",i);
        scanf("%d%d",&end,&start);
        snakes_and_ladders(board,end,start);
    }
    
    display_graph();
    bfs(board);
}
