#include<iostream>
#include<vector>
#include<queue>
#include<stdexcept>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		queue<pair<int, int>> q;
		q.push(make_pair(n,0));

		vector<bool> visited(n + 1, false);
		visited[n] = true;
		while (!q.empty()) {
			int num = q.front().first;
			int step = q.front().second;
			q.pop();
			
			for (int i = 1; num - i * i >= 0; i++) {
				int a = num - i * i;
				if (a < 0)
					break;
				if (a == 0)
					return step + 1;
				if (!visited[a]) {
					q.push(make_pair(a, step + 1));
					visited[a] = true;
				}
			}
		}

		//throw invalid_argument("No solution.");

	}
};

int main() {
	int n = 12;
	cout << Solution().numSquares(n) << endl;
	cin.get();
	return 0;
}