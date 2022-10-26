//
// Created by user on 12/13/2021.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#endif //UNTITLED_GRAPH_H
using namespace std;
//items from the clustering list are stored
struct adjNode {
    int Val, Cost;
    adjNode* Next;
};
// asymmetric storage architecture
struct graphEdge {
    int start_Ver, end_Ver, Weight;
};
class TheDiagraph{
    // from either the supplied graphs, add new nodes to the adjacency list
    static adjNode* get_Adjlistnode(int Value, int Weight, adjNode* head)   {
        auto* newnode = new adjNode;
        newnode->Val = Value;
        newnode->Cost = Weight;

        newnode->Next = head;   // connect the new node to the source vertex
        return newnode;
    }
    int n;  // the overall number of nodes in the graph
public:
    adjNode **head;                //as an arrays containing pointers, the pairwise list
    // fresh node allocation
    TheDiagraph(graphEdge Edges[], int n, int N)  {
        // establish a new node
        head = new adjNode*[n]();
        this->n = N;
        // for any and all edges, establish the heading pointer
        for (int i = 0; i < n; ++i)
            head[i] = nullptr;
        // append vertices to the a directional group to make it more directional
        for (unsigned i = 0; i < n; i++)  {
            int start_Ver = Edges[i].start_Ver;
            int end_Ver = Edges[i].end_Ver;
            int Weight = Edges[i].Weight;
            // during the first paragraph
            adjNode* newnode = get_Adjlistnode(end_Ver, Weight, head[start_Ver]);

            // place this same head marker on the a new instance of the node
            head[start_Ver] = newnode;
        }
    }
    // Memory allocator
    ~TheDiagraph() {
        for (int i = 0; i < n; i++)
            delete[] head[i];
        delete[] head;
    }
};
// display every edges that are next to a device that is designed
void display_Adjlist(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->Val
             << ", " << ptr->Cost << ") ";
        ptr = ptr->Next;
    }
    cout << endl;
}
// encapsulation of a graph in C++