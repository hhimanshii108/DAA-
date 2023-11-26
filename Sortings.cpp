// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n)
{
    int minInd=0;
    for(int i=0;i<n;i++)
    {
         minInd=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                minInd=j;
            }
        }
        if(minInd!=i)
        {
            swap(arr[i],arr[minInd]);
        }
    }
}

void stableSelectionSort(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        int minInd=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minInd])
            {
                minInd=j;
            }
        }
        int key=arr[minInd];
        for(int k=minInd;k>i;k--)
        {
            arr[k]=arr[k-1];
        }
        arr[i]=key;
    }
}
void insertionSort(int arr[],int n)
{
    int j;
    int key;
    for(int i=1;i<n;i++)
    {
         key=arr[i];
         j=i-1;
        while(j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void conquer(int s,int mid,int e,int arr[],int n)
{
    int index1=s;
    int index2=mid+1;
    int temp[e-s+1]={0};
    int len=e-s+1;
    int x=0;
    while(index1<=mid and index2<=e)
    {
        if(arr[index1]<=arr[index2])
        {
            temp[x++]=arr[index1++];
        }
        else
        {
            temp[x++]=arr[index2++];
        }
    }
    while(index1<=mid)
    {
        temp[x++]=arr[index1++];
    }
    while(index2<=e)
    {
        temp[x++]=arr[index2++];
    }
    // int ptr1=0;
    // int ptr2=0;
    // while(ptr1<len and ptr2<n)
    // {
    //     arr[ptr2++]=temp[ptr1++];
    // }
        for(int i=0,j=s;i<len;i++,j++)
    {
        arr[j]=temp[i];
    }

}
void merge(int s,int e,int arr[],int n)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    merge(s,mid,arr,n);
    merge(mid+1,e,arr,n);
    conquer(s,mid,e,arr,n);
}
void mergeSort(int arr[],int n)
{
    merge(0,n-1,arr,n);
}
int giveIndex(int s,int e,int arr[])
{
    int i=s-1;
    int pivot=arr[e];
    for(int k=s;k<e;k++)
    {
        if(arr[k]<pivot)
        {
            i++;
            swap(arr[i],arr[k]);
        }
    }
    i++;
    swap(arr[i],arr[e]);
    return i;
}
void quickSort(int low,int high,int arr[],int n)
{
    if(low<high)
    {
        int pivotIndex=giveIndex(low,high,arr);
        quickSort(low,pivotIndex-1,arr,n);
        quickSort(pivotIndex+1,high,arr,n);
    }
}
void countSort(int n,int arr[])
{
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    int temp[maxi+1]={0};
    int ans[n]={0};
    for(int i=0;i<n;i++)
    {
       temp[arr[i]]++;
    }
    for(int i=1;i<maxi+1;i++)
    {
        temp[i]=temp[i]+temp[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        ans[--temp[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
}
void func(int pos,int arr[],int n)
{
    int temp[10]={0};
    for(int i=0;i<n;i++)
    {
        temp[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        temp[i]=temp[i]+temp[i-1];
    }
    int ans[n]={0};
    for(int i=n-1;i>=0;i--)
    {
        ans[--temp[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
}
void radixSort(int n,int arr[])
{
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    
    for(int pos=1;maxi/pos>0;pos*=10)
    {
        func(pos,arr,n);
    }
}
int main() {
  int n=5;
  int arr[]={101,23,45,6,789};
  //selectionSort(arr,n);
  //stableSelectionSort(n,arr);
  //insertionSort(arr,n);
  //mergeSort(arr,n);
  //quickSort(0,n-1,arr,n);
  //countSort(n,arr);
  radixSort(n,arr);
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
    return 0;
}
