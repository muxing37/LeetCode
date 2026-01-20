#include <stdio.h>
#include <string.h>
int abc(char s) {
	int i;
	i=(s=='a'||s=='e'||s=='i'||s=='o'||s=='u');
    return i;
}
int maxVowels(char* s, int k) {
    int i;
    int n=strlen(s);
    int c=0;
    for(i=0;i<k;i++){
        if(abc(s[i])){
            c++;
        }
    }
    int max=c;
    for(i=k;i<n;i++){
        if(abc(s[i-k])!=0){
            c--;
        }
        if(abc(s[i])!=0){
            c++;
        }
        if(c>max){
            max=c;
        }
    }
    printf("%d\n",max);
    return max;
}
