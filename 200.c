void dfs(int gridSize,int* gridColSize,char **grid,int i,int j) {
    if(i<0 || j<0 || i>=gridSize || j>=gridColSize[i]) return;
    if(grid[i][j]=='0') return;
    grid[i][j]='0';

    dfs(gridSize,gridColSize,grid,i+1,j);
    dfs(gridSize,gridColSize,grid,i-1,j);
    dfs(gridSize,gridColSize,grid,i,j+1);
    dfs(gridSize,gridColSize,grid,i,j-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i,j;
    int count=0;
    for(i=0;i<gridSize;i++) {
        for(j=0;j<gridColSize[i];j++) {
            if(grid[i][j]=='1') {
                dfs(gridSize,gridColSize,grid,i,j);
                count++;
            }
        }
    }
    return count;
}