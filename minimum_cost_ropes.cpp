#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        
        for(int i = 0 ; i<n ; i++)
        {
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a+b;
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long n ;
    cin>>n;
    long long arr[n];
    for(int i = 0 ; i< n ;i++)
    {
        cin>>arr[i];
    }

    long long ans = minCost(arr,n);
    cout<<ans;
    return 0;
}