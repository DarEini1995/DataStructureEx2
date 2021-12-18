#include <stdio.h>
#include "Heap.h";

Heap::Heap(int max) 
{
	data = new Pair[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

Heap::~Heap() {
	if (allocated) {
		delete[] data;
	}

	data = NULL;
}

int Heap::Parent(int node) 
{
	return (node - 1) / 2;
}

int Heap::Left(int node) 
{
	return (2 * node + 1);
}

int Heap::Right(int node)
{
	return (2 * node + 2);
}

void Swap(Pair* x, Pair* y)
{
	Pair temp = *x;
	*x = *y;
	*y = temp;
}

void Heap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	//Fix max among node ,left and right
	if ((left < heapSize) && (data[left].priority > data[node].priority)) 
	{
		max = left;
	}
	else 
	{
		max = node;
	}
	if ((right < heapSize) && (data[right].priority > data[max].priority))
	{
		max = right;
	}

	if (max != node)
	{
		Swap(&data[node], &data[max]);
		FixHeap(max);
	}
}

Pair Heap::DeleteMax()
{
	//if (heapSize < 1)
		//Handle Error;

	Pair max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return(max);
}

void Heap::Insert(Pair item)
{
	//if(heapSize == maxSize)
		//Handle Error

	int i = heapSize;
	heapSize++;
	while ((i > 0) && data[Parent(i)].priority < item.priority) {
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = item;
}

Heap::Heap(Pair A[], int n)
{
	heapSize = maxSize = n;

	data = A;
	allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--) {
		FixHeap(i);
	}
}

void HeapSort(Pair A[],int n)
{
	Heap H(A, n);
	Pair item;

	for (int i = n - 1; i >= 1; i--)
	{
		item = H.DeleteMax();
		A[i] = item;
	}
}