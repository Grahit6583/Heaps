#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    int row;
    int col;
    node(int data, int r, int c)
    {
        this->data = data;
        col = c;
        row = r;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
};

int smallest_range(vector<vector<int>>& arr,int n,int m)
{
    int mini =INT_MAX; 
    int maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for(int i=0; i<n; i++)
    {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element,i,0));
    }
    int start = mini; 
    int end = maxi;
    while(!minHeap.empty())
    {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi-mini < end-start)
        {
            start = mini;
            end = maxi;
        }

        if(temp->col + 1 < m)
        {
            maxi = max(maxi,arr[temp->row][temp->col+1]);
            minHeap.push(new node(arr[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else
        {
            break;
        }

    }
    return end-start+1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>> arr;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            int k;
            cin>>k;
            temp.push_back(k);
        }
        arr.push_back(temp);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    int ans = smallest_range(arr,n,m);
    cout<<ans<<endl;
    return 0;
}