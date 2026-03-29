#include <stdio.h>
int main() {
    int i,n,bt[30],p[30],wt[30],tat[30],pr[30],j,total = 0,pos,temp;
    float avg_tat, avg_wt;
    printf("Enter the no of proc\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("bt = ");
        scanf("%d", &bt[i]);
        printf("pr = ");
        scanf("%d", &pr[i]);
    }

    for(i=0;i<n;i++){
        pos = i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos]){
                pos = j;
            }
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for(i=0;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
            total +=wt[i];
        }
    }
    avg_wt = (float)total;
    total =0;
    printf("pid\tbt\tpr\twt\ttat\n");
    for(i=0;i<n;i++){
        tat[i] = wt[i]+bt[i];
        total+=tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
    }
    avg_tat = (float)total;
    printf("avg wt = %f\n",avg_wt/n);
    printf("avg tat = %f\n",avg_tat/n); 
    return 0;
}