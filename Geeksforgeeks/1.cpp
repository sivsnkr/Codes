// CPP Program to count cycles of length n 
// in a given graph. 
#include <bits/stdc++.h> 
using namespace std; 

// Number of vertices 
const int V = 5; 

void DFS(bool graph[][V], bool marked[], int n, 
			int vert, int start, int &count) 
{ 
	// mark the vertex vert as visited 
	if(n == 0)
    {
        if(graph[vert][start])
        {
            count++;
        }
        return;
    }
    marked[vert] = 1;
    for(int i = 0; i < V; i++)
    {
        if(!marked[i] && graph[vert][i])
        {
            DFS(graph,marked,n-1,i,start,count);
        }
    }
    marked[vert] = 0;
} 

// Counts cycles of length N in an undirected 
// and connected graph. 
int countCycles(bool graph[][V], int n) 
{ 
	// all vertex are marked un-visited initially. 
	bool marked[V]; 
	memset(marked, 0, sizeof(marked)); 
    int count = 0;

    for(int i = 0; i < V-(n-1); i++)
    {
        DFS(graph,marked,n-1,i,i,count);
        marked[i] = 1;
    }
    return count/2;
} 

int main() 
{ 
	bool graph[][V] = {{0, 1, 1, 1, 0}, 
					{1, 0, 1, 0, 0}, 
					{1, 1, 0, 1, 1}, 
					{1, 0, 1, 0, 1}, 
					{0, 0, 1, 1, 0}}; 
	int n = 4; 
	cout << "Total cycles of length " << n << " are "
		<< countCycles(graph, n)<<endl;
	return 0; 
} 
