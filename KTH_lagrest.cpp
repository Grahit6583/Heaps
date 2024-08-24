#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Kth_largest(vector<int> arr, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int n = arr.size();

    for(int i =0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            if(pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int> arr;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int element;
        cin>>element;
        arr.push_back(element);
    }

    int k;
    cin>>k;
    int ans = Kth_largest(arr,k);
    cout<<ans<<endl;

    return 0;
}