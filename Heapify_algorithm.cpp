#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Max_heapify(int arr[],int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        Max_heapify(arr,n,largest);
    }
}

void Min_heapify(int arr[],int n , int i)
{
    int smallest = i ;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[smallest] > arr[left])
    {
        cout<<"hello";
        smallest = left;
    }
    if(right <= n && arr[smallest] > arr[right])
    {
        cout<<"hi";
        smallest = right;
    }
    if(smallest != i)
    {
        cout<<"world"<<" ";
        swap(arr[smallest],arr[i]);
        Min_heapify(arr,n,smallest);
    }
}

int main()
{
    int arr[12] = {-1,1,3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = (sizeof(arr) / sizeof(arr[0]))-1;
    // cout<<"the size of array"<<" "<<n<<endl;
    // for(int i = n/2 ; i>0 ; i--)
    // {
    //     Max_heapify(arr,n,i);
    // }

    // cout<<"HEAP IS "<<endl;
    // for(int i=1 ; i<=n ; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    for(int i = n/2 ; i>0 ; i--)
    {
        cout<<"how"<<" ";
        Min_heapify(arr,n,i);
    }

    cout<<"HEAP IS "<<endl;
    for(int i=1 ; i<=n ; ++i )
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}