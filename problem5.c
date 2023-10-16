#include <stdio.h>
#include <string.h>

void main()
{
    char *a[]={"Ram","Mohan" ,"Shyam" ,"Amit" ,"Kritika" ,"Ram" ,"Mohit" ,"Amit"};
    int n;
    printf("enter n ");
    scanf("%d",&n);

    

    for(int i=0;i<n;i++)
    {
        printf("Enter %d name",i);
        char name[100];
        fgets(name,sizeof(name),stdin);
        name[strcspn(name, "\n")] = '\0';
        a[i]=strdup(name);
    }

    for(int i = 0;i<n;i++){
        char* curr=a[i];

        for(int j=0; j< n;j++){
            if(strcmp(a[j],a[j+1]) >0)
            {
                char* tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf(" %s ",a[i]);
    }

    printf("\n");
    char *unique[100];
    int uniqueCount=0;
    for( int i=0;i<n;i++)
    {
        int flag =0;
        for(int j=0;j<uniqueCount;j++)
        {
            if(strcmp(unique[j],a[i]) == 0)
            {
                flag =1;
                break;
            }
        }
        if (flag == 0)
        {
            unique[uniqueCount]=a[i];
             uniqueCount++;
        }
       

    }   
    // printf("helllllllllllllllll");

    for(int i=0;i<uniqueCount;i++)
    {
        printf(" %s ",unique[i]);
    }
}