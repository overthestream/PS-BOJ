//노정훈 고컴 과탑먹자 ^!^ 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

int c[401][401] = { 0 };
int f[401][401] = { 0 };
vector <int> adj[401];

int main() {

	int N, P;
	int total = 0, S = 1, T = 2; // 소 노드 1~ 200 축사 노드 201~ 400
	scanf("%d %d", &N, &P);

	// init 
	for (int i = 0; i < P; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		c[u][v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	

	while (1) {

		int prev[401];
		fill(prev, prev + 401, -1);
		queue<int> Q;
		Q.push(S);

		while (!Q.empty() && prev[T] == -1) {

			int cur = Q.front();
			Q.pop();
			for (int next : adj[cur]) {
				if (c[cur][next] > f[cur][next] && prev[next] == -1) {
					Q.push(next);
					prev[next] = cur;
					if (next == T) break;
				}
			}

		}
		if (prev[T] == -1)break;
		 
		int flow = 9876543210;
		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d", total);
	return 0;
}
