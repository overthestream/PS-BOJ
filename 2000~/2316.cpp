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

int c[802][802] = { 0 };
int f[802][802] = { 0 };
vector <int> adj[802];

int main() {

	int N, P;
	int total = 0, S = 1, T = 402; 
	scanf("%d %d", &N, &P);

	// init  // 도시를 한번만 지나게 하기 위해 모든 정점을 둘로 나눈다.  i -> i+400 
	c[1][401] = 976543210;
	adj[1].push_back(401);
	adj[401].push_back(1);

	c[2][402] = 976543210;
	adj[2].push_back(402);
	adj[402].push_back(2);

	for (int i = 3; i <= N; i++) {
		c[i][i + 400] = 1;
		c[i + 400][i] = 1;
		adj[i].push_back(i + 400);
		adj[i + 400].push_back(i);
	}

	for (int i = 0; i < P; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		c[u + 400][v] ++;
		c[v+400][u] ++;
		
		adj[u+400].push_back(v);
		adj[v].push_back(u + 400);
		
		adj[v+400].push_back(u);
		adj[u].push_back(v + 400);

	}

	

	while (1) {

		int prev[802];
		fill(prev, prev + 802, -1);
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
