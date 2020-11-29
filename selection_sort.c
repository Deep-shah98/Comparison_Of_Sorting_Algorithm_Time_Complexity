
// selection sort
#include<stdio.h>
#include<time.h>
double totaltime=0;
void selection(int *a,int n)
{

    clock_t start, end;
    start = clock();

    int min;

    int temp,i,j;
    for(i=0; i<n-1; i++)

    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(a[min]>a[j])
                min=j;

        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;

        }
    }
    end = clock();

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
        printf("......");
        p=n-10;
        for (i=p; i<n; i++)
        {
            printf(" %d",a[i]);
        }
    }

}
void main()
{
    int *a,*b,*c;
    int n,i,j;
    char ch;
    printf("-------------------------------------------------Selection Sort---------------------------------------------------------\n");

    do
    {
        printf("\nEnter the range of  elements in array :");
        scanf("%d",&n);
        a= (int*)malloc(n * sizeof(int));
        b= (int*)malloc(n * sizeof(int));
        c= (int*)malloc(n * sizeof(int));




        printf("\n--------------------------------Sorting of Random numbers--------------------------\n");
        for (i = 0; i < n; i++)
        {
            a[i] = rand();
        }
        selection(a,n);
        print(a,n);
        printf("\n total time in sorting: %f",totaltime);
        printf(" sec\n");

        printf("\n------------------Sorting of numbers which are sorted in ascending order------------\n");
        for (i = 0; i < n; i++)
        {
            b[i] = a[i];
        }
        /*printf("\n sorted array input\n");

        for (i = 0; i < n; i++)
        {
            printf(" %d",b[i]);

        }*/
        selection(b,n);
        print(b,n);
        printf("\n total time in sorting: %f",totaltime);
        printf(" sec\n");

        printf("\n------------------Sorting of numbers which are sorted in descending order-----------\n");
        for (i=0,j=n-1; i < n; i++,j--)
        {
            c[i] = b[j] ;


        }
        /*printf("\nReversed array input\n");

        for (i = 0; i < n; i++)
        {
            printf(" %d",c[i]);

        }*/


        selection(c,n);
        print(c,n);
        printf("\n total time in sorting: %f",totaltime);
        printf(" sec\n");

        printf("\n Do you want to continue ? Press 'y' to continue or any other key to exit:");
        fflush(stdin);
        scanf("%c",&ch);
        free(a);

    }
    while((ch=='y') || (ch=='Y'));


}

