#include<iostream>
#include<vector>
using namespace std;
void bfs(vector<int> adj[] , int source ,  int destination, int v){
    vector<int> queue;
    queue.push_back(source);
    bool isVisited[v];
    for(int i = 0 ; i < v ; i++){
        isVisited[i] = false;
    }
    while(!queue.empty()){
        int ele = queue.front();
        queue.erase(queue.begin());
        cout << ele << " ";
        for(int pass : adj[ele]){
            if(!isVisited[pass]){
                queue.push_back(pass);
                isVisited[pass] = true;
            }
        }

    }
    
}

int main(){
    int vertices;
    int edges;
    cout << "Enter Vertices " << endl;
    cin >> vertices;
    cout << "Enter Edges " << endl;
    cin >> edges;
    vector<int> adj[vertices];
    for(int i = 0 ; i < edges ; i++){
        cout << "Enter Source " << endl;
        int source;
        cin >> source;
        cout << "Enter Destination " << endl;
        int dest;
        cin >> dest;
        if(source >= vertices || dest >= vertices){
            cout << "Invalid Source and Destination " << endl;
            return 0;
        }
        adj[source].push_back(dest);
    }
    int s , d;
    cout << "Enter Source and Destination " << endl;
    cin >> s >> d;
    bfs(adj , s , d , vertices);
    return 0;

}