#include<bits/stdc++.h>
using namespace std;
bool visited[100000];
int parent[100000];
void bfs(int u,vector<int> adj[]){
   queue<int> q;
   q.push(u);
   visited[u]=true;
   while(!q.empty()){
      int v=q.front();
      q.pop();
   for(int x:adj[v]){
      if(visited[x]==false){
         visited[x]=true;
         parent[x]=v;
         q.push(x);
      }
   }
}
}
void path(int s,int t,vector<int> adj[]){
   memset(visited,false,sizeof(visited));
   memset(parent,0,sizeof(parent));
   bfs(s,adj);
   if(!visited[t]){
      cout<<"-1\n";
   }
   else{
      vector<int> res;
      while(t!=s){
         res.push_back(t);
         t=parent[t];
      }
      res.push_back(s);
      for(int i=res.size()-1;i>=0;i--){
         cout<<res[i]<<" ";
      }
      cout<<endl;

   }
}
int main(){
int t;
cin>>t;
while(t--){
   int V,E,s,t;
   cin>>V>>E>>s>>t;
   vector<int> adj[V+1];
   for(int i=1;i<=E;i++){
      int u,v;;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   path(s,t,adj);
}
}