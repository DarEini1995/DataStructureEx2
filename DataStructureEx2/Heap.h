#pragma once
#ifndef HEAP_H
# define HEAP_H

typedef struct {
	int priority;
	char* data;
} Pair;

class Heap {
private: 
	Pair* data;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	Heap(int max);
	Heap(Pair A[], int n);
	~Heap();
	Pair Max();
	Pair DeleteMax();
	void Insert(Pair item);
};

#endif