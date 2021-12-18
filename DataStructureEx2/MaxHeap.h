#pragma once
#ifndef MAX_HEAP_H
# define MAX_HEAP_H

typedef struct {
	int priority;
	char* data;
} Pair;

class MaxHeap {
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
	MaxHeap(int max);
	MaxHeap(Pair A[], int n);
	~MaxHeap();
	Pair Max();
	Pair DeleteMax();
	void Insert(Pair item);
};

#endif