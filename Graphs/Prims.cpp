#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int Prims(vector<vector<pair<int , int>>> adj , int V){
	priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> pq;
	int ans = 0;
	pq.push({0 , 0});
	bool isVis[V];
	for(int i = 0 ; i < V ; i++){
		isVis[i] = false;
	}
	while(!pq.empty()){
		pair<int , int> curNode = pq.top();
		pq.pop();
		if(isVis[curNode.second]) continue;
		isVis[curNode.second] = true;
		ans += curNode.first;
		for(auto p : adj[curNode.second]){
			pq.push(p);
		}
	}
	return ans;
}
int main(){
	cout << "Enter Number of Vertices " << endl;
    int ver;
    cin >> ver;
    cout << "Enter Number of Edges " << endl;
    int edges;
    cin >> edges;
    vector<vector<pair<int , int>>> adj(ver);
    for(int i = 0 ; i < edges ; i++){
        int source;
        int destination;
        int wei;
        cout << "Enter Source " << endl;
        cin >> source;
        cout << "Enter Destination " << endl;
        cin >> destination;
        cout << "Enter Weight " << endl;
        cin >> wei;
        adj[source].push_back({wei,destination});
    }
   	cout << "Minimum Weight to Visit all Vertex" << Prims(adj , ver) << endl;
    return 0;
    
}
