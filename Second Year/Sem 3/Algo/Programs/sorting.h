#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <stdio.h>

void swap(int a[],int i,int pos)
{
    int temp;
    temp=a[i];
    a[i]=a[pos];
    a[pos]=temp;
}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}


void SS_sort(int n, int a[])
{
    int i,j,pos;

    for(i=0;i<n;i++)
    {
        j=pos=i+1;
        for(;j<n;j++)
            if(a[j]<a[pos])
                pos=j;
        if(a[pos]<a[i])
        {
            swap(a,i,pos);
        }
    }
}

void ins_sort(int n, int a[])
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
}

void bub_sort(int n, int a[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            if(a[j]<a[j-1])
                swap(a,j,j-1);
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[30000];
    int i=i1,j=i2,k=0;

    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)
        temp[k++]=a[i++];
    while(j<=j2)
        temp[k++]=a[j++];

    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}



void mer_sort(int a[],int i,int j)
{
    int mid;

    if(i<j)
    {
        mid=(i+j)/2;
        mer_sort(a,i,mid);
        mer_sort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

int partition(int a[],int l,int r)
{
    int pivot,i,j;
    pivot=a[l];
    i=l;
    j=r+1;
    while(1)
    {
        do{
            ++i;
        }while(a[i]<=pivot && i<=r);

        do{
            --j;
        }while(a[j]>pivot);

        if(i>=j)
            break;
        swap(a,i,j);
    }
    swap(a,l,j);
    return j;
}


void qck_Sort( int a[], int l, int r)
{
    int j;
    if( l < r )
    {
            j = partition( a, l, r);
            qck_Sort( a, l, j-1);
            qck_Sort( a, j+1, r);
    }
}


#endif // SORTING_H_INCLUDED
