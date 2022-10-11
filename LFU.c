//LFU Page replacement Algorithm----not completed
#include<stdio.h>
void main()
{
    int frame_no,page_no,rs[100],i,frame[30],frq[500],j,fault=0,hit=0,max,x=0,k,min1,min2,value=0,z,change[30];
    printf("Enter the number of pages:");
    scanf("%d",&page_no);
    printf("Enter the refernce string:");
    for(i=0;i<page_no;i++)
        scanf("%d",&rs[i]);
    printf("Enter the number of frames:");
    scanf("%d",&frame_no);
    max=rs[0];
    for(i=1;i<page_no;i++)
    {
        if(max<rs[i])
            max=rs[i];
    }
    for(i=0;i<frame_no;i++)
        frame[i]=-1;
    for(i=0;i<max;i++)
        frq[i]=0;
    for(i=0;i<page_no;i++)
    {
        for(j=0;j<frame_no;j++)
        {
           if(rs[i]==frame[j])
            {
                hit++;
                frq[rs[i]]++;
                break;
            }
            else if(frame[j]==-1)
            {
                frame[j]=rs[i];
                fault++;
                x++;
                frq[rs[i]]++;
                break;
            }
            else
            {
                if(x==frame_no)
                {
                    for(k=0;k<max;k++)
                    {
                        if(frq[k]!=0)
                        {
                            min1=frq[k];
                            break;
                        }
                    }
                    for(k=0;k<max;k++)
                    {
                        if(min1>=frq[k])
                        {
                            z=frq[k];
                            if(z==0)
                                continue;
                            min2=frq[k];
                            if(min1==min2)
                                value++;
                            else
                                value=1;
                            min1=min2;
                        }
                        if(value>=2)
                        {
                            
                        }
                    }
                    fault++;
                }
                
            }
        }
        
    }
}