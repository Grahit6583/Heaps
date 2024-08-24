#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node* next;
    node()
    {
        this->data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    node(int data, node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare
{
    public:
    bool operator()(node* a , node* b)
    {
        return a->data > b->data;
    }
};

node* merge_LL(vector<node*> &listArray)
{
    priority_queue<node*, vector<node*>, compare> minheap;

    int k = listArray.size();

    if(k == 0)
    {
        return NULL;
    }

    for(int i =0; i<k; i++)
    {
        if(listArray[i] != NULL)
        {
            minheap.push(listArray[i]);
        }
    }
    node* head= NULL;
    node* tail= NULL;
    while(minheap.size()>0)
    {
        node* top = minheap.top();
        minheap.pop();

        if(top->next != NULL)
        {
            minheap.push(top->next);
        }

        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

node* create_ll(vector<int>& values) {
    if (values.empty()) return nullptr;
    node* head = new node(values[0]);
    node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new node(values[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(node* temp) {
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<node*> listArray(n);

    for(int i =0; i<n ; i++)
    {
        int m;
        cin>>m;
        vector<int> values(m);
        for(int j=0; j<m; j++)
        {
            cin>>values[j];
        }
        listArray[i] = create_ll(values);
    }
    node* head = merge_LL(listArray);
    printLinkedList(head);
}