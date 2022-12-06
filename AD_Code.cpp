#include <bits/stdc++.h>

using namespace std;

struct edges{
    int u;
    int v;
    int weight;
};
int n,m;    // n = number of vertex;   m = number of edges
int N=100;
int p[100];
edges graph[100];  // taking input u v and weight
edges mst[100];   // for storing the MST's edges
int parent(int u){
    if(p[u]==u)      // function for finding parent;
    return u;
    return p[u]=parent(p[u]);
}

int merge(int u,int v){  // merge disconnected component;
    int parent_u = parent(u);
    int parent_v = parent(v);
    if(parent_u==parent_v) return 0;
    p[parent_u] = p[parent_v];
    return 1;
}

void initialise_dsu(){
    for(int i=1;i<=n;i++){
        p[i] = i;
    }
}

int main()
{
   cout<<"Enter the number of vertex:- ";
   cin>>n;
   cout<<"Enter the number of edges:-  ";
   cin>>m;
   cout<<endl;
   int ans = 0;
   int k = 0;
   for(int i=0;i<m;i++){
       cout<<"Enter Edge starting point, end point and weight of edge:- ";
       cin>>graph[i].u>>graph[i].v>>graph[i].weight;
   }
   initialise_dsu();
   int min_edge[m+1];
   int cnt_cmp = n;
   while(cnt_cmp>1){
       for(int i=0;i<n;i++){
           min_edge[i] = -1;
       }
       for(int i=0;i<m;i++){
           if(parent(graph[i].u)==parent(graph[i].v)) continue;
           int parent_u = parent(graph[i].u);
           if(min_edge[parent_u]==-1 || graph[i].weight<graph[min_edge[parent_u]].weight){
               min_edge[parent_u] = i;
           }
           int parent_v = parent(graph[i].v);
           if(min_edge[parent_v]==-1 || graph[i].weight<graph[min_edge[parent_v]].weight){
               min_edge[parent_v] = i;
           }
       }
  
       for(int i=0;i<n;i++){
           if(min_edge[i]!=-1){
               if(merge(graph[min_edge[i]].u,graph[min_edge[i]].v)){
                   ans+=graph[min_edge[i]].weight;
                   mst[k].u = graph[min_edge[i]].u;
                   mst[k].v = graph[min_edge[i]].v;
                   mst[k].weight = graph[min_edge[i]].weight;
                   cnt_cmp--;
                   k++;
               }
           }
       }
   }
   
   
    // for(int i=0;i<n;i++){
    //       if(min_edge[i]!=-1){
    //           if(merge(graph[min_edge[i]].u,graph[min_edge[i]].v)){
    //               ans+=graph[min_edge[i]].weight;
    //               mst[k].u = graph[min_edge[i]].u;
    //               mst[k].v = graph[min_edge[i]].v;
    //               mst[k].weight = graph[min_edge[i]].weight;
    //               cnt_cmp--;
    //               k++;
    //           }
    //       }
    //   }
   
   cout<<"The Cost of Minimum Spanning Tree is:- "<<ans<<endl;
   for(int i=0;i<k;i++)
   {
       
       cout<<"The edge of MST:- "<<mst[i].u<<"->"<<mst[i].v<<" "<<mst[i].weight<<"\n";
       
   }
}