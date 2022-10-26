#include <iostream>
#include "graph.h"



int main()
{
    // the program i have written below represents the Array of graphs edges 
    graphEdge Edges[] = {
            // (w, x, y) -> boundary having weight matrix spanning x to y
            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int n = 8;      // Considering graph's quantity many vertices i give mine 8 as the number of n
    // determine the number of vertices
    int S = sizeof(Edges)/sizeof(Edges[0]);
    // The graph adjacency contains a list of all the graphs that are connected to each
     TheDiagraph td(Edges, n, S);
    // output the graph's pairwise array representations
    cout<<"List of graph adjacencies "<<endl<<"(start_Vertex, end_Vertex, Weight):"<<endl;
    for (int i = 0; i < n; i++)
    {

        // displaying the edges of vertices i's neighboring edges
        display_Adjlist( td.head[i], i);
    }
    return 0;
}