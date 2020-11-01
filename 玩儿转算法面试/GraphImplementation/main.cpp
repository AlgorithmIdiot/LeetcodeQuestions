#include<iostream>
#include"SparseGraph.h"
#include<ctime>
using namespace std;
int main()
{
	int N = 20;
	int M = 100;
	srand(time(NULL));

	// Sparse graph
	SparseGraph g1(N, false);
	for (int i = 0; i < M; i++)
	{
		int a = rand() % N;
		int b = rand() % N;
		g1.addEdge(a, b);
	}
	for (int v = 0; v < N; v++)
	{
		cout << v << " : ";
		SparseGraph::adjIterator adj(g1, v);
		for (int w = adj.begin(); w!= adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}