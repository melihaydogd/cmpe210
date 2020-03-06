#include "QueueType.cpp"

int main()
{
    QueueType<int> myQ;
 /* int arr[20] = {5,4,9,6,4,2,9,7,64,3,2,0,34,12,56,43,12};
    for(int i = 0; i < MAX_ITEMS; i++) {
        myQ.Enqueue(arr[i]);
    }*/
    myQ.Enqueue(10);
    myQ.Enqueue(5);
    myQ.Enqueue(2);
    cout << myQ.IsFull() << endl;
    cout << myQ.IsEmpty() << endl;
	int a,b,c,d;
	myQ.Dequeue(a);
	myQ.Enqueue(8);
	cout << a << endl;
	myQ.Dequeue(b);
	cout << b << endl;
	myQ.Enqueue(9);
	myQ.Enqueue(11);
	myQ.Dequeue(c);
	cout << "\n";
	cout << c << endl;
	myQ.Dequeue(d);
	cout << d << endl;
	
    return 0;
}
