#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int kth_largest(int arr[] , int n , int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0 ; i<k ; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k ; i<=n ; i++)
    {
        cout<<arr[i]<<" "<<pq.top()<<endl;
        if(arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i =0 ; i<n ;i++)
    {
        cin>>arr[i];
    }
    int k ;
    cin>>k;
    int ans = kth_largest(arr,n-1,k);
    cout<<ans<<endl;
    return 0;
}