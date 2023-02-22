/*Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. This is done by
considering that the player can determine which number appears in the dice being biased. The player rolls the dice and if reaches a base of a ladder then he can move up
the ladder to a different position/cell and if he reaches a snake then it brings him down away from the destination cell position.*/

#include <stdio.h>
#include <stdlib.h>
#define max 100
int no_of_nodes, i, j, ns, end, start, a, nl, star, en, x;
int queue[max], front = -1, rear = -1, new;
int parent[101],var5,var6;
int min_no_of_rolls[101];
int var = 1;
struct node
{
    int data;
    struct node *link;
};
void path(int[], int);
int dequeue();
void enqueue(int);
void display_graph(struct node *[]);
void bfs(int, struct node *[]);
void snakes(int, int, struct node *[]);
void ladders(int, int, struct node *[]);
void create_board(struct node *[]);
void main()
{
    printf("\nENTER THE ending square in the board : ");
    scanf("%d", &no_of_nodes);

    struct node *board[no_of_nodes + 1];
    for (i = 1; i <= no_of_nodes; i++)
    {
        board[i] = NULL;
    }
    create_board(board);

    display_graph(board);

    printf("\nEnter the number of snakes : ");
    scanf("%d", &ns);
    for (i = 1; i < ns + 1; i++)
    {
        printf("Enter the starting cell and ending value of snake %d : \n ", i);
        scanf("%d%d", &end, &start);
        snakes(end, start, board);
    }

    printf("\nEnter the number of Ladders  : ");
    scanf("%d", &nl);
    for (i = 1; i < nl + 1; i++)
    {
        printf("Enter the starting cell and ending value of  Ladder %d : \n ", i);
        scanf("%d%d", &star, &en);
        ladders(en, star, board);
    }

    display_graph(board);
    
    printf("\nEnter from which element you want to search : ",);
    scanf("%d",&var5);
    bfs(var5, board);
    printf("\nEnter the destination cell : ",);
    scanf("%d",&var6);
    printf("\nshortest path from %d to %d is : ",var5,var6);
    path(parent, var6);
}
int dequeue()
{
    int y;
    if (front == -1)
        printf("\nunderflow\n");
    else
    {
        y = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return y;
    }
}
void enqueue(int x)
{
    if (rear == max - 1)
        printf("overflow\n");
    else
    {
        if (rear == -1 && front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
            rear++;
        queue[rear] = x;
    }
}

void display_graph(struct node *board[])
{
    struct node *temp;
    for (i = 1; i <= no_of_nodes; i++)
    {
        temp = board[i];
        printf("vertices adjacent to %d are : ", i);
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void bfs(int b, struct node *board[])
{
    for (j = 0; j <= no_of_nodes + 1; j++)
    {
        parent[j] = -1;
        min_no_of_rolls[j] = -1;
    }

    // 1st element =0,next adj =1,adj=2.....
    min_no_of_rolls[b] = 0; // b = 1

    enqueue(b); // push 1  front =0
    while (front != -1)
    {
        new = queue[front]; // first new = 1 , 99
        struct node *temp1;
        temp1 = board[new];

        while (temp1 != NULL)
        {
            int p = temp1->data;
            if (min_no_of_rolls[p] == -1)
            {
                min_no_of_rolls[p] = min_no_of_rolls[new] + 1; // 1 , 1 , 2
                parent[p] = new;                               // 1 , 99
                enqueue(p);
            }
            temp1 = temp1->link;
        }
        dequeue();
    }
    printf("%d\n", min_no_of_rolls[100]);
}
void snakes(int start, int end, struct node *board[])
{
    for (a = start - 1; a >= start - 6 && a > 0; a--)
    {
        struct node *temp = board[a];
        while (temp->data != start)
            temp = temp->link;
        temp->data = end;
    }
    board[start] = NULL;
}

void ladders(int end, int start, struct node *board[])
{
    for (a = start - 1; a >= start - 6 && a > 0; a--)
    {
        struct node *temp = board[a];
        while (temp->data != start)
            temp = temp->link;
        temp->data = end;
    }
    board[start] = NULL;
}
void create_board(struct node *board[])
{
    struct node *last, *newnode;
    for (int i = 1; i <= no_of_nodes; i++)
    {
        for (int j = i + 1; j <= i + 6 && j <= no_of_nodes; j++)
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
void path(int parent[], int destination)
{
    if (parent[destination] != 0)
    {
        printf("%d <- ", destination);
        path(parent, parent[destination]);
    }
    printf("\n\n");
}
