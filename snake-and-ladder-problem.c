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
int no_of_nodes, i, j, ns, end, start, a, nl,star,en;
void display_graph(struct node *board[])
{
    struct node *temp;
    for (i = 1; i <= no_of_nodes; i++)
    {
        temp = board[i];
        printf("vertices adjacent to %d are : ", i);
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
// void bfs(struct node *board[]);
// void path();
void snakes(int start, int end, struct node *board[])
{
    for (a = start - 1; a >= start - 6 && a > 0; a--)
    {
        struct node *temp=board[a];
        while (temp->data != start)
            temp =temp->link;
       temp->data = end;
    }
    board[start] = NULL;
}

void ladders(int end, int start, struct node *board[])
{
    for (a = start - 1; a >= start - 6 && a > 0; a--)
    {
        struct node *temp=board[a];
        while (temp->data != start)
            temp =temp->link;
       temp->data = end;
    }
    board[start] = NULL;
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
    display_graph(board);

    printf("\nEnter the number of snakes : ");
    scanf("%d", &ns);
    for (i = 1; i < ns + 1; i++)
    {
        printf("Enter the starting cell and ending value of  snake %d : \n ", i);
        scanf("%d%d", &end, &start);
        snakes(end, start, board);
    }

    printf("\nEnter the number of Ladders  : ");
    scanf("%d", &nl);
    for (i = 1; i < nl + 1; i++)
    {
        printf("Enter the starting cell and ending value of  Ladder %d : \n ", i);
        scanf("%d%d", &en, &star);
       ladders(en, star, board);
    }

    display_graph(board);
}

