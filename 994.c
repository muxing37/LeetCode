struct Node {
    int i;
    int j;
};

int fresh=0;
struct Node *que;

int bfs(int t,int gridSize,int* gridColSize,int **grid,int i,int j) {
    if(i<0 || j<0 || i>=gridSize || j>=gridColSize[0]) return t;
    if(grid[i][j]!=1) return t;
    grid[i][j]=2;
    fresh--;
    que[t].i=i;
    que[t].j=j;
    t++;
    return t;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int i,j;
    int tail=0;
    int head=0;
    int t;
    fresh=0;
    que=malloc(gridSize*gridColSize[0]*sizeof(struct Node));
    for(i=0;i<gridSize;i++) {
        for(j=0;j<gridColSize[i];j++) {
            if(grid[i][j]==2) {
                que[tail].i=i;
                que[tail].j=j;
                tail++;
            }
            if(grid[i][j]==1) {
                fresh++;
            }
        }
    }
    j=0;
    while(head<tail) {
        if(fresh==0) break;
        t=tail;
        for(i=head;i<tail;i++) {
            t=bfs(t,gridSize,gridColSize,grid,que[i].i+1,que[i].j);
            t=bfs(t,gridSize,gridColSize,grid,que[i].i-1,que[i].j);
            t=bfs(t,gridSize,gridColSize,grid,que[i].i,que[i].j+1);
            t=bfs(t,gridSize,gridColSize,grid,que[i].i,que[i].j-1);
        }
        head=tail;
        tail=t;
        j++;
    }
    free(que);
    if(fresh>0) return -1;
    return j;
}