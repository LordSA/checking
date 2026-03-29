#include <stdio.h>
int main()
{
    int i, n;
    int pid[20], at[30], bt[30], ct[30], tat[30], wt[30];
    int tot_tat, tot_wt;
    printf("Enter the no of proc\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("at = ");
        scanf("%d", &at[i]);
        printf("bt = ");
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    ct[0] = at[0]+bt[0];
    for(i=0;i<n;i++){
        if(ct[i-1]>at[i]){
            ct[i] = ct[i-1]+bt[i];
        } else{
            ct[i] = at[i]+bt[i];
        }
    }
    for(i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        tot_tat +=tat[i];
        tot_wt += wt[i];
    }

    printf("pid\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("avg tat = %f\n",(float)tot_tat/n);
    printf("avg wt = %f\n",(float)tot_wt/n);
    return 0;   
}