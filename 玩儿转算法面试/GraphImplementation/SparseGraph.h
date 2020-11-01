#pragma once
#include<vector>
#include<cassert>
using namespace std;
class SparseGraph
{
private:
	int n, m;
	bool directed;
	vector<vector<int>> g;

public:
	SparseGraph(int n, bool directed)
	{
		this->m = 0;
		this->n = n;
		this->directed = directed;
		for (int i = 0; i < n; i++) {
			g.push_back(vector<int>());
		}
	}
	~SparseGraph() {}

	int V() {
		return n;
	}
	int E()
	{
		return m;
	}
	// 允许平行边的存在，保证用例中没有平行边。
	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		g[v].push_back(w);
		if (!directed && v != w)
		{
			g[w].push_back(v);
		}
		m++;
	}
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		for (int i = 0; i < g[v].size(); i++)
		{
			if (g[v][i] == w)
				return true;
			return false;
		}
	}
	class adjIterator
	{
	private:
		SparseGraph &G;
		int v;
		int index;
	public:
		adjIterator(SparseGraph &graph, int v) :G(graph) // 由于G是一个引用，在初始化列表中
		{
			this->v = v;
			this->index = 0;
		}
		~adjIterator()
		{

		}

		int begin() {
			if (G.g[v].size())
				return G.g[v][0];
			return -1;
		}

		int next() {
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		int end() {
			return index >= G.g[v].size();
		}
	};

	

};



