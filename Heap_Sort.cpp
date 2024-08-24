#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[] , int n , int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void print(int arr[], int a)
{
    cout<<"HEAP IS "<<endl;
    for(int i=0 ; i<a ; i++ )
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapsort(int arr[],int n )
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(arr,n,i);
    }
    cout<<endl;
    print(arr,n);
    int size = n-1;
    while(size>0)
    {
        swap(arr[size],arr[0]);
        heapify(arr,size,0);
        size--;
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    int arr[a];
    cout<<"Enter the data in array "<<endl;
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    print(arr,a);
    heapsort(arr,a);
    print(arr,a);
    return 0;
}