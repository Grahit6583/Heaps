#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // MAX HEAP
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(10);
    pq.push(8);

    cout<<pq.top()<<endl;
    cout<<pq.empty()<<endl;
    pq.pop();
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;

    // MIN HEAP 
    priority_queue<int, vector<int> , greater<int>> min;
    min.push(5);
    min.push(4);
    min.push(10);
    min.push(8);

    cout<<min.top()<<endl;
    cout<<min.empty()<<endl;
    min.pop();
    cout<<min.size()<<endl;
    cout<<min.top()<<endl;
    return 0;
}