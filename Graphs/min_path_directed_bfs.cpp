/* Code Contributed by Mohd Mawan Ahmad */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int shortestPathAvailale(int startNode , int endNode , int vertices , vector<vector<int>> adj){
    bool isVis[vertices];
    queue<int> que;
    que.push(startNode);
    int dis = 0;
    while(!que.empty()){
        queue<int> temp;
        while(!que.empty()){
            int curNode = que.front();
            que.pop();
            if(endNode == curNode) return dis;
            for(auto ele : adj[curNode]){
                if(!isVis[ele]){
                    isVis[ele] = true;
                    temp.push(ele);
                }
            }
        }
        for(int i = 0 ; i < temp.size() ; i++){
            que.push(temp.front());
            temp.pop();
        }
        dis++;
    }
    return -1;
}
int main(){
    // Graph Created is Directed and 0 Indexed
    // Weigth of Each edge is considered as 1
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
    int path = shortestPathAvailale(startNode , endNode , ver , adj);
    if(path == -1){
        cout << "Oops ! No path Exists" << endl;
    }else{
        cout << "Shortest Path is with distance of " << path << endl;
    }
    return 0;
}