/*
 *	File : QueueType.h
 *  QueueType is used in ResetTree() and GetNextItem() functions.
*/
#include <iostream>
using namespace std;

#define MAX_ITEMS 20

template <class Items>
class QueueType
{
private:
    Items *info;
    int front;
    int rear;
    int count;
public:
    QueueType();
    ~QueueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(Items);
    void Dequeue(Items&);
};

