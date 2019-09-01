#include<stdio.h>
# define n = 5
void insertion(int ele,int *r,int q[],int*f)
{
    if ((*f == *r+1)||(*f==0 && *r == n-1))
    {
        printf("Queue is full\n");
        return;
    }
    if(*f==-1)
    {
        *f = 0;
        *r = (*r+1)%n;
        q[*r] = ele;
    }
}

int delete(int q[],int *f,int *r)
{
    int ele;
    if(*f==-1)
    {
        printf("Queue is empty\n");
        return -999;
    }
    else
    {
        ele = q[*f];
        if(*f == *r)
        {
            *f =  -1;
            *r = -1;
        }

        else
        {
            *f = (*f+1)%n;
            return ele;
        }
        
    }
    
}

int display (int q[],int f,int r)
{
    int i;
    if(f == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i = f; i!=r; i=(i+1)%n)
        {
            printf("%d",q[i]);
        }
        printf("%d",q[i]);
    }
}

int main()
{
    int *f = 0,*r = -1,q[n],ele,ch,ch1;
    do
    {
       printf("***** Enter Your Choice *****\n ");
       printf("1 for Inserting\n 2 for Deleting \n 3 for Display \n 4 for Exit\n");
       scanf("%d",&ch);
       switch (ch)
        {
         case 1 : printf("Enter the number\n");
                  scanf("%d",&ele);
                  insertion(ele,&f,&r);
                  break;
         case 2 : delete(q,&f,&r);
                  break;
         case 3 : display(q,f,r);
                  break;                  
         case 4 : exit();
         default : printf("Invalid Entry\n");
        }
       printf("***** Do you want to Continue? *****");
       printf("Enter 1 for YES or 2 for No\n");
       scanf("%d",&ch1);
    } while(ch1!=0);
return 0;
}