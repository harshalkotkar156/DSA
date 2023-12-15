#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijiktras(vector<int>adj[],int v,int source)
{
    vector<int>dist(v,INT_MAX);
    dist[source]=0;
    vector<bool>finalized(v,false);


    for(int i=0;i<v-1;i++)
    {
        int u=-1;
        for(int j=0;j<v;j++)
        {
            if(!finalized[j] and(u==-1 or dist[j] < dist[u]))
            {
                u=j;

            }
            
        }
        finalized[u]=true;

        for(int x =0;x < v;x++)
        {
            if((adj[u][x] != 0 ) and (finalized[x]==false))
            {
                dist[x]=min(dist[x],dist[u]+adj[u][x]);
            }
        }
    }
    return dist;
    
}


int main()
{
    cout<<"Start\n";


    int v;cout<<"Enter vertices : ";cin>>v;
    vector<int>adj[v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<"Enter num : ";int x;cin>>x;//adj[i][j];
            adj[i].push_back(x);
        }
    }
    vector<int>ans= dijiktras(adj,v,0);
    cout<<"The answer is with source = 0 \n";
    for(int x :ans){
        cout<<x<<" ";
    }
    cout<<"\nDone"<<endl;
    return 0;
}