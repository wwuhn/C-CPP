#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 12

#define EAST maze[x][y+1]
#define WEST maze[x][y-1]
#define SOUTH maze[x+1][y]
#define NORTH maze[x-1][y]

#define ExitX (ROW-2)
#define ExitY (COL-2)

struct list
{
    int x,y;
    struct list* next;
};
typedef struct list node;
typedef node* link;

int maze[ROW][COL]={1,1,1,1,1,0,0,0,1,1,1,1,	/*声明迷宫数组*/
		            1,2,0,0,1,1,1,1,1,1,1,1,
				    1,1,1,0,1,1,0,0,0,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,0,0,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,0,1,0,1,1,
					1,1,0,0,0,0,0,0,1,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,1};
link push(link stack, int x, int y)
{
    link newnode;
    newnode = (link)malloc(sizeof(node));
    if(!newnode)
    {
        printf("Error! 内存分配失败！\n");
        return NULL;
    }
    newnode->x = x;
    newnode->y = y;
    newnode->next = stack;
    stack = newnode;
    return stack;
}

link pop(link stack, int* x, int* y)
{
    link top;
    if(stack!=NULL)
    {
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        free(top);
        return stack;
    }
    else
        *x = -1;
    return stack;
}

int chkExit(int x, int y, int ex, int ey)
{
    if(x==ex && y == ey)
    {
        if(NORTH == 1 || SOUTH == 1 || WEST == 1 || EAST == 2)
            return 1;
        if(NORTH == 1 || SOUTH == 1 || WEST == 2 || EAST == 1)
            return 1;
        if(NORTH == 1 || SOUTH == 2 || WEST == 1 || EAST == 1)
            return 1;
        if(NORTH == 2 || SOUTH == 1 || WEST == 1 || EAST == 1)
            return 1;
    }
    return 0;
}

void output()
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
            printf("%2d",maze[i][j]);
        printf("\n");
    }
    printf("\n");
}

void mazeSolution()
{
    int x,y; // 坐标
    link path = NULL;
    x=1;
    y=1;
    printf("迷宫模拟图（1表示墙，0表示通道）\n");
    output();

    while(x<=ExitX && y<=ExitY)
    {
        maze[x][y] = 6;
        if(NORTH == 0)
        {
            x -= 1;
            path = push(path,x,y);
        }
        else if(SOUTH == 0)
        {
            x += 1;
            path = push(path,x,y);
        }
        else if(EAST == 0)
        {
            y += 1;
            path = push(path,x,y);
        }
        else if(WEST == 0)
        {
            y -= 1;
            path = push(path,x,y);
        }
        else if(chkExit(x,y,ExitX,ExitY)==1)
            break;
        else
        {
            maze[x][y] = 2;
            path = pop(path,&x,&y);
        }
    }
    printf("迷宫模拟图（6表示老鼠走过的路线）\n");
    output();
}

int main()
{
    mazeSolution();

    while(1);
    return 0;
}
/*
迷宫模拟图（1表示墙，0表示通道）
 1 1 1 1 1 0 0 0 1 1 1 1
 1 2 0 0 1 1 1 1 1 1 1 1
 1 1 1 0 1 1 0 0 0 0 1 1
 1 1 1 0 1 1 0 1 1 0 1 1
 1 1 1 0 0 0 0 1 1 0 1 1
 1 1 1 0 1 1 0 1 1 0 1 1
 1 1 1 0 1 1 0 1 1 0 1 1
 1 1 1 0 1 1 0 0 1 0 1 1
 1 1 0 0 0 0 0 0 1 0 0 1
 1 1 1 1 1 1 1 1 1 1 1 1

迷宫模拟图（6表示老鼠走过的路线）
 1 1 1 1 1 0 0 0 1 1 1 1
 1 6 6 6 1 1 1 1 1 1 1 1
 1 1 1 6 1 1 6 6 6 6 1 1
 1 1 1 6 1 1 6 1 1 6 1 1
 1 1 1 6 0 0 6 1 1 6 1 1
 1 1 1 6 1 1 6 1 1 6 1 1
 1 1 1 6 1 1 6 1 1 6 1 1
 1 1 1 6 1 1 6 0 1 6 1 1
 1 1 0 6 6 6 6 0 1 6 6 1
 1 1 1 1 1 1 1 1 1 1 1 1
*/
