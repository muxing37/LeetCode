void dfs(int boardSize,int* boardColSize,char **board,int i,int j) {
    if(i<0 || j<0 || i>=boardSize || j>=boardColSize[i]) return;
    if(board[i][j]=='.') return;
    board[i][j]='.';

    dfs(boardSize,boardColSize,board,i+1,j);
    dfs(boardSize,boardColSize,board,i-1,j);
    dfs(boardSize,boardColSize,board,i,j+1);
    dfs(boardSize,boardColSize,board,i,j-1);
}

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int i,j;
    int count=0;
    for(i=0;i<boardSize;i++) {
        for(j=0;j<boardColSize[i];j++) {
            if(board[i][j]=='X') {
                dfs(boardSize,boardColSize,board,i,j);
                count++;
            }
        }
    }
    return count;
}