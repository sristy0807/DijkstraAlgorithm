#include <iostream>
#include <queue>

#define INFINITY 1000000
#define MAX 200

using namespace std;

int V, E, src;
vector<pair<int, int>> graph[MAX];
int dist[MAX];

priority_queue<
	pair<int, int>
> pq;

void readInputs() {
	cin >> V >> E;
	cin >> src;
}

void buildGraph() {
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}
}

void initialiseDistance() {
	for (int i = 0; i < V; i++) {
		dist[i] = INFINITY;
	}

	dist[src] = 0;
	pq.push({ 0,src });
}

void Dijkstra() {
	while (!pq.empty()) {
		int current_dist = -pq.top().first;
		int current_node = pq.top().second;
		pq.pop();
		if (current_dist > dist[current_node]) continue;
		
		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_node = graph[current_node][i].second;
			int next_dist = graph[current_node][i].first;

			int new_dist = dist[current_node] + next_dist;

			if (new_dist < dist[next_node]) {
				dist[next_node] = new_dist;
				pq.push({ -new_dist,next_node });
			}
		}
	}
}

void output() {
	for (int i = 0; i < V; i++) {
		if (dist[i] == INFINITY) {
			cout << "NODE " << i << " unreachable" << endl;
		}
		else
		{
			cout << "Node " << i << ": " << dist[i] << endl;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	readInputs();
	buildGraph();
	initialiseDistance();
	Dijkstra();

	output();
}