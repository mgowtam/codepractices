#include <iostream>

using namespace std;


template <class T> class Queue
{
public:
	bool isEmpty();
	T getFront();
	T dequeue();
	void enqueue(T e);
	void clear();
	Queue(){
		front = -1;
		back = -1;
		max = 100;
	}
private:
	int front;
	int back;
	T arr[100];
	int max;
};

template <class T>
bool Queue<T>::isEmpty()
{
	if(front == -1){
		return true;
	}
	return false;
}

template <class T>
T Queue<T>::getFront()
{
	if(front==-1 || front>back){
		return NULL;
	}
	return arr[front];
}

template <class T>
void Queue<T>::enqueue(T e)
{
	if(back == max-1){
		cout<<"queue is full"<<endl;
		return;
	}
	if(front == -1) front = 0;
	back = back + 1;
	arr[front] =  e;
}

template <class T>
T Queue<T>::dequeue()
{
	if(front==-1 || front>back){
		return NULL;
	}
	front++;
	return arr[front];
}

int main()
{
	return 0;
}
