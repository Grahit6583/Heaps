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
            this->left = NULL;
            this->right = NULL;
        }
};

node* createTree(node* root)
{
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    root = new node(data);
    if(data == -1)
    {
        return NULL;
    }

    cout<<"ENTER THE IN LEFT CHILD "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"ENTER THE DATA IN RIGHT CHILD "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}

int countnodes(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int ans = 1+countnodes(root->left)+countnodes(root->right);

    return ans;
}

bool isCBT(node* root , int index , int count)
{
    if(root == NULL)
    {
        return true;
    }
    // cout<<"index  "<<index<<"  data  "<<root->data<<endl;
    if(index >= count)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left,2*index+1,count);
        bool right = isCBT(root->right,2*index+2,count);
        return (left && right);
    }
}

bool maxorder(node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if(root->right == NULL)
    {
        // cout<<"hello"<<endl;
        return (root->data > root->left->data);
    }
    else
    {
        bool left = maxorder(root->left);
        bool right = maxorder(root->right);
        // bool ans = left && right && (root->data > root->left->data && root->data > root->right->data);
        // cout<<"check    "<<ans<<endl;
        return (left && right && (root->data > root->left->data && root->data > root->right->data ));
    }
}

bool is_heap(node* root)
{
    if(root == NULL)
    {
        return true;
    }
    int index = 0;
    int totalcount = countnodes(root);
    // cout<<totalcount<<endl;
    // bool ans1 = isCBT(root,index,totalcount);
    // bool ans2 = maxorder(root);
    // cout<<ans1<<endl;
    // cout<<ans2<<endl;
    if(isCBT(root,index,totalcount) && maxorder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // give max heap in binary tree
    node* root = NULL;
    root = createTree(root);
    bool ans =  is_heap(root);
    cout<<ans<<endl;
}