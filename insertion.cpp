#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert_maxheap(int val)
    {
        size = size+1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void insert_minheap(int val)
    {
        size = size+1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;

            if(arr[parent] > arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromheap()
    {
        if(size == 0)
        {
            cout<<"HEAP IS EMPTY"<<endl;
            return;
        }

        int i = 1;
        arr[i] = arr[size];
        size--;

        while(i<size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i = 1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    heap h,h1;
    h.insert_maxheap(50);
    h.insert_maxheap(45);
    h.insert_maxheap(55);
    h.insert_maxheap(40);
    h.insert_maxheap(60);
    h.print();
    h.deletefromheap();
    h.deletefromheap();
    h.print();


    h1.insert_minheap(50);
    h1.insert_minheap(45);
    h1.insert_minheap(55);
    h1.insert_minheap(40);
    h1.insert_minheap(60);
    h1.print();
    return 0;
}