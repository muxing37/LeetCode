/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **res;
int *colSizes;
int *path;
int *used;
int count;

void dfs(int n,int* nums,int depth) {
    if(depth==n) {
        res[count]=(int*)malloc(sizeof(int)*n);
        memcpy(res[count],path,sizeof(int)*n);
        colSizes[count]=n;
        count++;
        return;
    }
    int i;
    for(i=0;i<n;i++) {
        if(used[i]) continue;
        used[i]=1;
        path[depth]=nums[i];
        dfs(n,nums,depth+1);
        used[i]=0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n=numsSize;
    int c=1;
    int i;
    count=0;
    path=calloc(n,sizeof(int));
    used=calloc(n,sizeof(int));
    for(i=1;i<=n;i++) {
        c=c*i;
    }
    res=(int**)malloc(sizeof(int*)*c);
    colSizes=(int*)malloc(sizeof(int)*c);
    for(i=0;i<n;i++) {
        used[i]=0;
    }
    dfs(n,nums,0);

    *returnSize=count;
    *returnColumnSizes=colSizes;

    return res;
}