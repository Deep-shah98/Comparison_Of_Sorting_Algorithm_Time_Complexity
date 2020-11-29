
// Quick sort
#include<stdio.h>
#include<time.h>
double totaltime=0;
void quick(int a[],int low,int high);
int partition(int a[], int low,int high);
void swap(int a[],int *,int *);
void quick(int a[],int low,int high)
{

    clock_t start, end;
    start = clock();
    //printf("\n%d",stime);
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        quick(a,low,mid-1);
        quick(a,mid+1,high);

    }
     end = clock();
    //printf("\n%d",etime);
    totaltime=((double) (end - start)) / CLOCKS_PER_SEC;


}
int partition(int a[],int low,int high)
{
    int pivot,i,j;
    pivot=a[low];
    i=low;
    j=high;
    while(i<=j)
    {
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        swap(a,&i,&j);

    }
    swap(a,&low,&j);
    return j;
}
void swap(int a[],int *i,int *j)
{
    int temp;
    temp=a[*i];
    a[*i]=a[*j];
    a[*j]=temp;
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
    printf("--------------------------------------------------Quick Sort-----------------------------------------------------------\n");

    do{
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
    quick(a,0,n-1);
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
    quick(b,0,n-1);
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

    quick(c,0,n-1);
    print(c,n);

    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");

    printf("\n Do you want to continue ? Press 'y' to continue:");
    fflush(stdin);
    scanf("%c",&ch);
    free(a);

    }while((ch=='y') || (ch=='Y'));


}

