//
// Created by Sangmeshwar on 5/22/2023.
//

/*
Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
structure.
*/

#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<int> adj[], vector<int> &visited, queue<int> &q, vector<int > &ans){
    if(q.empty()){
        return;
    }
    int element = q.front();
    q.pop();
    ans.push_back(element);
    for(auto i: adj[element]){
        if(visited[i]==0){
            visited[i] = 1;
            q.push(i);
        }
    }
    bfsTraversal(adj, visited, q, ans);
}

vector<int> bfs(vector<int> adj[], int v){
    vector<int> visited(v+1,0);
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            visited[i] = 1;
            q.push(i);
            bfsTraversal(adj, visited, q, ans);
        }
    }
   // displaying traversal
//    cout<<"BFS traversal: "<<endl;
//    for(auto i: ans){
//        cout<<i<<" ";
//    }
//    cout<<endl;
    return ans;
}


void dfsTraversal(vector<int> adj[], vector<int> &visited, stack<int> &s, vector<int> &ans){
    if(s.empty()){
        return;
    }
    int element = s.top();
    s.pop();
    ans.push_back(element);
    for(auto i: adj[element]){
        if(visited[i]==0){
            visited[i] = 1;
            s.push(i);
            dfsTraversal(adj, visited, s, ans);
        }
    }
}


vector<int> dfs(vector<int> adj[], int v){
    vector<int> visited(v+1,0);
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            visited[i] = 1;
            s.push(i);
            dfsTraversal(adj, visited, s, ans);
        }
    }
    // displaying traversal
//    cout<<"DFS traversal: "<<endl;
//    for(auto i: ans){
//        cout<<i<<" ";
//    }
//    cout<<endl;
    return ans;
}

int main(){
    // creating graph
    int v, e, a, b;
    cout<<"\nEnter num of vertices: ";
    cin>>v;
    cout<<"Enter num of edges: ";
    cin>>e;
    vector<int> adj[v+1];
    // taking edge input
    for(int i=0;i<e;i++){
        cout<<"\nEnter details of edge "<<i<<": "<<endl;
        cout<<"Start node: ";
        cin>>a;
        cout<<"End node: ";
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //displaying adj graph
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }



    while(1)
    {
        vector<int> tmp;
        int flag = 0, search;
        cout<<"Enter the element to be searched: ";
        cin>>search;
        cout<<"\n 1. BFS";
        cout<<"\n 2. DFS";
        cout<<"\n 3. Exit";
        cout<<"\nChoice : ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 3:
                exit(1);
                break;
            case 1:
                tmp = bfs(adj, v);
                for(auto i: tmp){
                    if(i==search){
                        flag = 1;
                    }
                    cout<<i<<" ";
                }
                if (flag){
                    cout<<"\nElement found!"<<endl;
                }else{
                    cout<<"\nElement not found!"<<endl;
                }
                break;
            case 2:
                tmp = dfs(adj, v);
                for(auto i: tmp){
                    if(i==search){
                        flag = 1;
                    }
                    cout<<i<<" ";
                }
                if (flag){
                    cout<<"\nElement found!"<<endl;
                }else{
                    cout<<"\nElement not found!"<<endl;
                }
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}