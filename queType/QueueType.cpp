#include "QueueType.h"

template <class Items>
QueueType<Items>::QueueType()
{
    info = new Items[MAX_ITEMS];
    front = -1;
    rear = -1;
    count = 0;
}

template <class Items>
QueueType<Items>::~QueueType()
{
    delete [] info;
}

template <class Items>
void QueueType<Items>::MakeEmpty()
{
    front = -1;
    rear = -1;
    count = 0;
}

template <class Items>
bool QueueType<Items>::IsFull() 
{
    return (count == MAX_ITEMS);
}

template <class Items>
bool QueueType<Items>::IsEmpty()
{
    return (count == 0);
}

template <class Items>
void QueueType<Items>::Enqueue(Items newItem)
{
    if(IsFull()) 
    {
        cout << "Que is full.";
    } 
    else 
    {
        rear++;
        if(rear == MAX_ITEMS)
        {
        	rear = 0;
		}
        info[rear] = newItem;
        count++;
    }
}

template <class Items>
void QueueType<Items>::Dequeue(Items &item)
{
    if(IsEmpty()) 
    {
        cout << "Que is empty.";
    } 
    else 
    {
        front++;
        if(front == MAX_ITEMS)
        {
        	front = 0;
		}
        item = info[front];
        count--;
    }
}
