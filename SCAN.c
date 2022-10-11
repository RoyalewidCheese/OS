//SCAN Disk Scheduling Algorithm
#include<stdio.h>
#include<stdlib.h>
void sorting(int list[],int num)
{
    int i,j,temp;
    for(i=0;i<num-1;i++)
        for (j=i+1;j<num;j++)
            if(list[i]>list[j])
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
}
void main()
{
    int req_q[30],req_no,head,total_movement=0,i,size,dir,pos,j;
    printf("Enter the number of requests:");
    scanf("%d",&req_no);
    printf("Enter the initial position of head:");
    scanf("%d",&head);
    printf("Enter disk size:");
    scanf("%d",&size);
    printf("Enter Request Queue:");
    for(i=0;i<req_no;i++)
    {
        scanf("%d",&req_q[i]);
        if(req_q[i]>size || req_q[i]<0)
        {
            printf("Enter a valid sequence");
            exit(0);
        }
    }
    printf("Direction of head movement\nEnter \n\t0 for left \n\t1 for right\n");
    scanf("%d",&dir);
    if(dir!=1 && dir!=0)
    {
        printf("Enter a valid choice");
        exit(0);
    }
    sorting(req_q,req_no);
    for(i=0;i<req_no;i++)
    {
        if(head<req_q[i])
        {
            pos=i;
            break;
        }
    }
    if(dir==0)
    {
        for(i=pos;i>0;i--)
        {
            total_movement=total_movement+abs(head-req_q[i-1]);
            head=req_q[i-1];
        }
        total_movement=total_movement+abs(head-0);
        head=0;
        for(i=pos;i<req_no;i++)
        {
            total_movement=total_movement+abs(head-req_q[i]);
            head=req_q[i];
        }
    }
    else
    {
        for(i=pos;i<req_no;i++)
        {
            total_movement=total_movement+abs(head-req_q[i]);
            head=req_q[i];
        }
        total_movement=total_movement+abs(head-size);
        head=size;
        for(i=pos;i>0;i--)
        {
            total_movement=total_movement+abs(head-req_q[i-1]);
            head=req_q[i-1];
        }
    }
    printf("Total Head movement=%d",total_movement);
}