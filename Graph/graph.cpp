#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
	map<int, vector<char>> adj;
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void constructGraph(vector<pair<int, int> > edgeList){
		for(int i = 0; i < edgeList.size(); i++){
			addEdge(edgeList[i].first, edgeList[i].second);
		}
	}
	vector<int> dfsUtil(int node=1){
		map<int, bool> visited;
		vector<int> dfsOrder;
		dfs(node, visited, dfsOrder);
		return dfsOrder;
	}
	void dfs(int node, map<int, bool> &visited, vector<int> &dfsOrder){
		visited[node] = true,
		dfsOrder.push_back(node);
		for(int next: adj[node]){
			if(!visited[next]){
				dfs(next, visited, dfsOrder);
			}
		}
	}
	vector<int> bfsUtil(int node=1){
		map<int, bool> visited;
		vector<int> bfsOrder;
		bfs(node, visited, bfsOrder);
		return bfsOrder;
	}
	void bfs(int node, map<int, bool> &visited, vector<int> &bfsOrder){
		queue<int> q;
		q.push(node);
		visited[node] = true;
		while(!q.empty()){
			node = q.front();
			bfsOrder.push_back(node);
			q.pop();
			for(int next: adj[node]){
				if(!visited[next]){
					q.push(next);
					visited[next] = true;
				}
			}
		}
	}
};
int main(){
	// going to build a graph
	Graph graph;
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		graph.addEdge(u, v);
	}
	vector<int> dfsOrder = graph.dfsUtil();
	vector<int> bfsOrder = graph.bfsUtil();
	cout<<"dfs: ";
	for(int node: dfsOrder){
		cout<<node<<" ";
	}
	cout<<"\n";
	cout<<"bfs: ";
	for(int node: bfsOrder){
		cout<<node<<" ";
	}
	cout<<"\n";
	return 0;
}