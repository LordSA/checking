#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,head,total=0,i,j;
    printf("no of r\n");
    scanf("%d",&n);
    int req[n],visited[n];
    printf("Requests\n");
    for(i = 0;i<n;i++){
        scanf("%d",&req[i]);
        visited[i] = 0;
    }
    printf("h p\n");
    scanf("%d",&head);
    for(int j = 0;j<n;j++){
        int min = 10000, index = -1;
        for (i = 0; i < n; i++){
            if (visited[i] == 0){
                int dist = abs(head - req[i]);
                if (dist < min){
                    min = dist;
                    index = i;
                }
            }
        }
        printf("%d\t%d\t%d\t%d\n",j+1,head,req[index],min);
        total+=min;
        head = req[index];
        visited[index] = 1;

    }
    printf("Total head movement: %d\n", total);
}