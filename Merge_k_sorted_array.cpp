#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        int i;
        int j;
        node(int data , int row , int col)
        {
            this->data = data;
            i = row;
            j = col;
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

vector<int> merge_array(vector<vector<int>>& arr, int k)
{
    priority_queue<node*, vector<node*>, compare> minheap;

    for(int i =0; i<k ; i++)
    {
        node* tmp = new node(arr[i][0],i,0);
        minheap.push(tmp);
    }

    vector<int> ans;
    while(minheap.size()>0)
    {
        node* temp = minheap.top();

        ans.push_back(temp->data);
        minheap.pop();
        int i = temp->i;
        int j = temp->j;

        if(j+1 < arr[i].size())
        {
            node* next = new node(arr[i][j+1],i,j+1);
            minheap.push(next);
        }
    }

    return ans;
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>> arr;
    int n,m;
    cin>>n;
    cin>>m;
    int i,j;
    for(i=0; i<n; i++)
    {
        vector<int> temp;
        for(j=0; j<m; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
        cin>>m;
    }
    cout<<"grahit"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    vector<int> ans;
    ans = merge_array(arr,n);
    for(int  i=0 ; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}