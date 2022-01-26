#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(-1 * 34);
    pq.push(-1 * 12);
    pq.push(-1 * 45);
    cout << pq.top() << endl;pq.pop();
    cout << pq.top() << endl;
    
}