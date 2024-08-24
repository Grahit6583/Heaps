#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Kth_smallest(int arr[],int k ,int n)
{
    priority_queue<int> pq;
    for(int i =0 ; i<k ;i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k ;i<=n;i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
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
    int ans = Kth_smallest(arr,k,n-1);
    cout<<ans<<endl;
    return 0;
}