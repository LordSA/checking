#include <stdio.h>

int main() {
    int i,n,time = 0, completed = 0;
    int at[30],bt[30],ct[40],wt[40],tat[30],pid[30];
    float avg_tat = 0, avg_wt = 0;
    
    printf("enter no \n");
    scanf("%d",&n);
    int iscompleted[n];


    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("at = ");
        scanf("%d", &at[i]);
        printf("bt = ");
        scanf("%d", &bt[i]);
        iscompleted[i] = 0;
    }

    while(completed<n){
        int idx = -1;
        int minbt = 10000;

        for(i=0;i<n;i++){
            if(at[i]<=time && iscompleted[i]==0){
                if(bt[i]<minbt){
                    minbt=bt[i];
                    idx=i;
                }
            }
        }

        if(idx == -1){
            time++;
        }else{
            time+=bt[idx];
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            avg_tat += tat[idx];
            avg_wt += wt[idx];
            iscompleted[idx] = 1;
            completed++;
        }
    }

    printf("pid\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("avg tat = %.2f\n",avg_tat/n);
    printf("avg wt = %.2f\n",avg_wt/n);

}