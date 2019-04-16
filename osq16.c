#include<stdio.h>
void main()
{

    int AR[]={2,0,3,1},BT[]={4,5,3,2},PR[]={0,1,2,3},BT1[50],cycle[50],CT[50],TAT[50];
    int i,j,n=4,k,min,pos,temp,lim,looplimit=0,next,q;
    double sum=0;
    for(i=0;i<n;i++)
    BT1[i]=BT[i];
    for(i=0;i<n;i++)
    {
        min=AR[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(AR[j]<min)
            {
                min=AR[j];
                pos=j;
            }
        }

            temp=AR[i];
            AR[i]=AR[pos];
            AR[pos]=temp;

            temp=BT[i];
            BT[i]=BT[pos];
            BT[pos]=temp;

            temp=PR[i];
            PR[i]=PR[pos];
            PR[pos]=temp;
    }
    for(i=0;i<n;i++)
    {
        //printf("%d ",PR[i]);
        //printf("%d",BT1[i]);
        looplimit+=BT[i];
    }
    q=looplimit;
    i=0,next=0,lim=0,j=0;
    while(looplimit!=0)
    {
        BT[i]=BT[i]-1;
        if(cycle[j-1]!=PR[i])
        cycle[j++]=PR[i];
        lim+=1;
        if(BT[i]==0)
        {
        TAT[PR[i]]=lim-AR[i];
        //printf("%d ",lim);
        CT[PR[i]]=lim;
        }
        looplimit=looplimit-1;
        for(k=0;k<n;k++)
        {
            if(AR[k]<=lim && BT[k]>0)
            {
                next=k;
                for(i=k+1;i<n;i++)
                {
                    if(AR[i]<=lim && BT[i]>0 && BT[next]>BT[i])
                        next=i;
                }
                break;
            }
        }
        i=next;
    }
    printf("                    THE SEQUENCE OF PROCESS EXECUTION\n\n");
    for(i=0;i<j;i++)
    {
        printf("        P%d     ",cycle[i]);
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("\n  CT of  P%d : %d ",i,CT[i]);
        printf("\n  TAT of P%d : %d",i,TAT[i]);
        printf("\n  WT of  P%d : %d",i,TAT[i]-BT1[i]);
        sum=sum+(TAT[i]-BT1[i]);
        printf("\n");
        //printf("\n%d ",BT1[i]);
    }

    printf("\n\n  Average Waiting Time : %.2f\n\n",sum/n);

    printf("Process\t AT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t %d\t%d\t%d\t%d\t%d\n",i,AR[i],BT1[i],CT[i],TAT[i],TAT[i]-BT1[i]);
    }
}
