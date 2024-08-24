#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// void heapify(vector<int> &arr,int n , int i)
// {
//     int largest = i;
//     int left = 2*i+1;
//     int right = 2*i+2;

//     if(left < n && arr[largest] < arr[left])
//     {
//         largest = left;
//     }
//     if(right < n && arr[largest] < arr[right])
//     {
//         largest = right;
//     }

//     if(largest != i)
//     {
//         swap(arr[largest],arr[i]);
//         heapify(arr,n,largest);
//     }
// }

// vector<int> merge_heap(vector<int> &a , vector<int> &b , int n , int m)
// {
//     vector<int> ans;
//     for(auto i : a)
//     {
//         ans.push_back(i);
//     }


//     for(auto i : b)
//     {
//         ans.push_back(i);
//     }

//     int size = ans.size();
//     for(int i = size/2 - 1 ; i>=0 ; i--)
//     {
//         heapify(ans,size,i);
//     }

//     return ans;
// }

vector<int>merge_heap(vector<int> &a, vector<int> &b, int n, int m)
{
    priority_queue<int> pq;
    for(auto i:a)
    {
        pq.push(i);
    }

    for(auto i:b)
    {
        pq.push(i);
    }

    vector<int> ans;
    int size = pq.size();
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int> a;
    vector<int> b;
    int n,m;
    cin>>n;
    cin>>m;
    for(int i = 0 ; i<n;i++)
    {
        int element;
        cin>>element;
        a.push_back(element);
    }
    for(int i = 0 ; i<m;i++)
    {
        int element;
        cin>>element;
        b.push_back(element);
    }

    vector<int> ans = merge_heap(a,b,n,m);
    int size = ans.size();
    cout<<size<<endl;
    for(int i = 0 ; i<size ; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}