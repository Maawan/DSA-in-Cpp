/* Code Contributed by Mohd Mawan Ahmad */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isPathAvailable(int startNode , int endNode , int vertices , vector<vector<int>> adj){
    bool isVis[vertices];
    queue<int> queue;
    queue.push(startNode);
    while(!queue.empty()){
        int curNode = queue.front();
        queue.pop();
        if(endNode == curNode) return true;
        for(auto ele : adj[curNode]){
            if(!isVis[ele]){
                isVis[ele] = true;
                queue.push(ele);
            }
        }
    }
    return false;
}
int main(){
    // Graph Created is Directed and 0 Indexed
    cout << "Enter Number of Vertices " << endl;
    int ver;
    cin >> ver;
    cout << "Enter Number of Edges " << endl;
    int edges;
    cin >> edges;
    vector<vector<int>> adj(ver);
    for(int i = 0 ; i < edges ; i++){
        int source;
        int destination;
        cout << "Enter Source " << endl;
        cin >> source;
        cout << "Enter Destination " << endl;
        cin >> destination;
        adj[source].push_back(destination);
    }
    int startNode;
    int endNode;
    cout << "Enter Source Node " << endl;
    cin >> startNode;
    cout << "Enter Destination Node " << endl;
    cin >> endNode;
    if(isPathAvailable(startNode , endNode , ver , adj))
        cout << "Path Available" << endl;
    else
        cout << "Oops ! No Path Found" << endl;    
    return 0;
}