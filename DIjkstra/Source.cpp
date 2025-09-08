#include <iostream>
#include "Source.h"
#define INFINITY 1000000
#define MAX 200

using namespace std;

int V, E;

int G[MAX][MAX];
int dist[MAX];
int used[MAX];
int parent[MAX];


void ReadVertices()
{
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			G[i][j] = (i == j ? 0 : INFINITY);
		}
	}
}

void ReadEdges() {
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w < G[u][v]) G[u][v] = w;
	}
}

int minIndexUnused() {
	int u = -1, best = INFINITY;

	for (int i = 0; i < V; i++) {
		if (used[i] == 0 && dist[i] < best) {
			best = dist[i];
			u = i;
		}
	}

	return u;
}

void Dijkstra(int src) {
	for (int i = 0; i < V; i++) {
		dist[i] = INFINITY;
		used[i] = 0;
		parent[i] = -1;
	}

	dist[src] = 0;

	for (int i = 0; i < V; i++) {
		int u = minIndexUnused();
		if (u == -1) break;
		used[u] = 1;

		for (int v = 0; v < V; v++) {
			if (G[u][v] >= INFINITY) {
				continue;
			}

			int cand = dist[u] + G[u][v];
			if (cand < dist[v]) {
				dist[v] = cand;
				parent[v] = u;
			}
		}
	}
}

int main() {
	cin >> V >> E;
	ReadVertices();
	ReadEdges();
	
	Dijkstra(0);
	for (int i = 0; i < V; i++) {
		if (dist[i] >= INFINITY) cout << -1;
		else cout << dist[i];
		if (i + 1 < V) cout << ' ';
	}
	cout << "\n";
	return 0;
}

