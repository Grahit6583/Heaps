#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};

node* ist_in_bst(node* root ,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = ist_in_bst(root->right,data);
    }
    else
    {
        root->left = ist_in_bst(root->left,data);
    }

    return root;
}

void take_input(node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = ist_in_bst(root,data);
        cin>>data;
    }
}

void inorder(node* root ,vector<int>& arr)
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

void preorder(node* root , vector<int> arr ,int &i)
{
    if(root == NULL)
    {
        return;
    }

    root->data = arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);

}

void converttoHeap(node* root)
{
    vector<int> arr;
    int i = 0;

    inorder(root,arr);
    preorder(root,arr,i);

    // for(int i = 0 ; i<arr.size();i++)
    // {
    //     cout<<arr[i]<<"  ";
    // }
    // cout<<endl;
}

void print(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<"  ";
    print(root->left);
    print(root->right);
}


// void by_priorityqueue(node* root)
// {
//     priority_queue<int, vector<int> ,greater<int>> pq;
//     if(root == NULL)
//     {
//         return;
//     }

//     by_priorityqueue(root->left);
//     pq.push(root->data);
//     cout<<pq.top()<<" ";
//     by_priorityqueue(root->right);

//     cout<<endl;
//     while (!pq.empty())
//     {
//         cout<<pq.top()<<"  ";
//         pq.pop();
//     }
    
// }

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    cout<<"Enter the data in BST "<<endl;
    take_input(root);
    converttoHeap(root);
    print(root);

    // cout<<"BY PRIORITY_QUEUE "<<endl;
    // by_priorityqueue(root);
    return 0;
}