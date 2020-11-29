
// bubble sort
#include<stdio.h>
#include<time.h>
double totaltime=0;
void bubble(int *a,int n)
{

    clock_t start, end;
    start = clock();
    //printf("\n%d",stime);100000

    int temp,i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     end = clock();
    //printf("\n%d",etime);
    totaltime=((double) (end - start)) / CLOCKS_PER_SEC;


}
void print(int *a,int n)
{
    int i,p;
    printf("\nSorted array is:\n ");
    for (i=0; i<10; i++)
    {
        printf(" %d",a[i]);
    }

    if(n>10)
    {
        printf("..............");
        p=n-10;
        for (i=p; i<n; i++)
        {
            printf(" %d",a[i]);
        }
    }

}
void main()
{
    int *a,*b,*c,*d,*e;
    int n,i,j;
    char ch;
    printf("--------------------------------------------------Bubble Sort-----------------------------------------------------------\n");

    do{
    printf("\nEnter the range of  elements in array :");
    scanf("%d",&n);
    a= (int*)malloc(n * sizeof(int));
    b= (int*)malloc(n * sizeof(int));
    c= (int*)malloc(n * sizeof(int));
    d= (int*)malloc(n * sizeof(int));
    e= (int*)malloc(n * sizeof(int));



    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    bubble(a,n);
    //print(a,n);
    //printf("\n total time in sorting: %f",totaltime);
    //printf(" sec\n");

      printf("\n------------------Sorting of numbers which are sorted in descending order-----------\n");
   for (i=0,j=n-1; i < n; i++,j--)
    {
        c[i] = a[j];


    }
    /*printf("\nReversed array input\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d",c[i]);

    }*/


    bubble(c,n);
    print(c,n);
    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");


    printf("\n------------------Sorting of numbers which are sorted in ascending order------------\n");
    for (i = 0; i < n; i++)
    {
        b[i] = d[i];
    }
    /*printf("\n sorted array input\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d",b[i]);

    }*/
    bubble(b,n);
    print(b,n);
   printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");

    printf("\n--------------------------------Sorting of Random numbers--------------------------\n");
    for (i = 0; i < n; i++)
    {
        e[i] = rand();
    }
 for (i = 0; i < n; i++)
    {
        d[i]=e[i];
    }

    bubble(e,n);
    print(e,n);
    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");




    printf("\n Do you want to continue ? Press 'y' to continue:");
    fflush(stdin);
    scanf("%c",&ch);
     free(a);

    }while((ch=='y') || (ch=='Y'));


}

