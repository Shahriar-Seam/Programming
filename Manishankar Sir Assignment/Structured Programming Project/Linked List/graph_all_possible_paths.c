#include <stdio.h>

// Adjacency matrix to represent the graph
int graph[100][100] = {0}; 

// Array to store indices of nodes
int indices[100]; 

// Counter for the number of nodes
int indcount = 0; 

// Variables to store the start and end nodes of the path
int startnode, endnode; 

// Function to get the index of a node in the indices array
int getindex (int node)
{
    int i =0;
    for (i=0;i<indcount;i++)
    {
        if (indices[i] == node) { return i; }
    }
    // If the node is not found, add it to the indices array
    indices[indcount] = node;
    indcount++;
    return indcount-1;
}

// Function to check if a node is present in the given path array
int ispresentinpath (int * path, int count, int ind)
{
    int i = 0;
    for (i=0;i<count;i++)
    {
        if (path[i] == ind) { return 1; }
    }
    return 0;
}

// Function to print the path
void printpath (int * path, int count)
{
    int i =0;
    printf ("\n");
    for (i=0;i<count;i++)
    {
        printf (" %d ", indices[path[i]]);
    }
}

// Function to recursively search for paths in the graph
void search (int *path, int count)
{
    // Get the index of the current node from the path
    int cind = path[count-1];
    int i = 0;
    // Iterate through all nodes in the graph
    for (i=0;i<indcount;i++)
    {
        // Check if there is an edge between the current node and node i
        if (graph[cind][i] > 0)
        {
            // Check if node i is not already in the path
            if (ispresentinpath(path, count, i) == 0)
            {
                // Add node i to the path
                path[count] = i;
                count++;
                // If node i is the end node, print the path
                if (i == endnode)
                { 
                    printpath (path, count); 
                }
                // Recursively search for paths starting from node i
                search (path, count);
                // Backtrack: remove node i from the path
                count--;
            }
        }
    }
}

int main() {
    int a, b, c;
    // Reading edges and their weights until input is 0 0 0
    while (1)
    {
        scanf ("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) {break;}
       
        // Get indices for nodes 'a' and 'b'
        int i1 = getindex (a);
        int i2 = getindex (b);
       
        // Set the weight for the edge between nodes 'a' and 'b'
        graph[i1][i2] = c;
        graph[i2][i1] = c; // Assuming the graph is undirected
    }
   
    int s, e;
    printf ("input start: "); scanf ("%d", &s);
    printf ("input end: "); scanf ("%d", &e);
   
    int path[100], count = 0;
   
    // Initialize path with the start node
    path[0] = getindex(s);
    count++;
    endnode = getindex(e);
   
    // Start searching for paths
    search (path, count);

    return 0;
}
