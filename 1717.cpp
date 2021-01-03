//노정훈 고컴 과탑먹자 ^!^ 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair <int, int> pii;

int root[1000001];

int Find(int node) {
    if (root[node] == -1) return node;
    root[node] = Find(root[node]);
    return root[node];
}
void Union(int nodeA, int nodeB) {
    if (Find(nodeA) == Find(nodeB)) return;
    else root[Find(nodeA)] = Find(nodeB);
    return;
}

int main() {

    int n,  m;
    memset(root, -1, sizeof(root));

    scanf("%d %d", &n, &m);
    int a, b;
    int order;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &order,&a,&b);

        if (order) {
            if (Find(a) == Find(b)) printf("YES\n");
            else printf("NO\n");
        }
        else {
            Union(a, b);
        }
    }
    return 0;

}



