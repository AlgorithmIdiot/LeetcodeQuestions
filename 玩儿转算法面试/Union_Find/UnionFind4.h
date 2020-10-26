#pragma once
#include<cassert>

namespace UF4 {
	class UnionFind {
	private:
		int* parent;
		int* rank; // sz[i] 表示以i 为根的
		int count;
	public:
		UnionFind(int count) {
			parent = new int[count];
			rank = new int[count];// 以i为根的集合的层数
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}

		}
		~UnionFind()
		{
			delete[] parent;
			delete[] rank;
		}

		int find(int p)
		{
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;
			/*if (p != parent[p])
				parent[p] = find(parent[p]);
			return parent[p];*/
		}

		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		void unionElements(int p, int q) {
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			// 由短的列表指向长的列表
			if (rank[pRoot] < rank[qRoot]) {
				parent[pRoot] = parent[qRoot];
				//rank[qRoot] += rank[pRoot];
			}
			else if (rank[qRoot] < rank[pRoot])
			{
				parent[qRoot] = parent[pRoot];
			}
			else
			{//rank[qRoot] = rank[pRoot]
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}

		}
	};
}