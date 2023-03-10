//created by Rushikesh
#include<bits/stdc++.h>
using namespace std;
#define V 9
#define INF 9999999999
#define visited true




int mindistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for(int v=0; v<V; v++)
		if(sptSet[v]==false && dist[V]<=min)
			min = dist[v], min_index = v;

	return min_index;	
}

void printSolution(int dist[])
{
	cout<<"vertex \t distance from source"<<endl;
	for(int i=0; i<V;i++)
		cout<<i<<" \t\t"<<dist[i]<<endl;
}

void  dijkstra(int graph[V][V], int vertex )
{
	int dist[V];
	bool sptSet[V];

	for(int i=0;i<V;i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[vertex] = 0;

	//🚩🚩
	for(int count =0; count <V-1; count++)
	{
		int u = mindistance(dist, sptSet);
		sptSet[u] = true;

		for(int v=0; v<V; v++)
		{
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	//🚩🚩
	printSolution(dist);
}


int main()
{
  
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);

    return 0;
}
