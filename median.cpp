#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int signum(int a, int b)
{
    if(a == b)
    {
        return 0;
    }

    else if(a > b)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

void call_median(int element,priority_queue<int>& maxi, priority_queue<int, vector<int>, greater<int>>& mini, int &median)
{
    switch(signum(maxi.size(),mini.size()))
    {
        case 0:
            if(element > median)
            {
                mini.push(element);
                median = mini.top();
            }
            else
            {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        case 1:
            if(element > median)
            {
                mini.push(element);
                median = (mini.top()+maxi.top())/2;
            }
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (maxi.top()+mini.top())/2;

            }
            break;
        case -1:
            if(element > median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (maxi.top()+mini.top())/2;

            }
            else
            {
                maxi.push(element);
                median = (maxi.top() + mini.top())/2;
            }
            break;
    }
}

vector<int> findmedian(vector<int>& arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    for(int i=0; i<n; i++)
    {
        call_median(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }

    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    vector<int> ans;
    ans  = findmedian(arr,n);

    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}