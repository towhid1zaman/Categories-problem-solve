/*
Single source shortestPath. One source to all nodes minimum cost
*/

int dijkstra(vector<pii> graph[MAX_CITY], int src) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	vector<int>distance(MAX_CITY, 0);
	vector<bool>visited(MAX_CITY, false);

	for (register int i = 0; i < NodeCount; ++i) {
		distance[i] = INF;
	}
	distance[src] = 0;
	pq.push({0, src});


	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) continue;


		visited[u] = true;
		for (auto val : graph[u]) {
			int v = val.first, d = val.second;
			if (distance[v] > distance[u] + d) {
				distance[v] = distance[u] + d;
				pq.push({ distance[v], v });
			}
		}
	}


	register int totalCost = 0;
	for (register int i = 0; i < NodeCount; ++i) {
		totalCost += distance[i];
	}
	return totalCost;
}
