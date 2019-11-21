#ifndef GRAPHUTILS_H
#define GRAPHUTILS_H

#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <queue>

class Graph{
public:
    //TODO: make member variables private
    int numVertices;
    std::vector < std::list<int> > adjList;

    Graph(int V):
        numVertices(V), adjList(std::vector < std::list<int> > (numVertices)) {}

    void addEdge(int src, int dest);
};

void Graph::addEdge(int src, int dest){
    std::cout<<"\nLinking Node "<<src<<" to "<<dest;
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

std::vector<int> BFS(Graph &graph, int root){
    std::queue<int> number_q; // queue of imtegers
    std::set<int> visited;
    std::vector <int> bfs_traversal;

    // push the root node to the queue
    number_q.push(root);

    while(!number_q.empty()){
        int cur_ele = number_q.front(); number_q.pop();
        // std::cout<<"\nCurrent element: "<<cur_ele;
        visited.insert(cur_ele);
        bfs_traversal.push_back(cur_ele);

        std::list<int> neighbours = graph.adjList[cur_ele];
        //iterator to traverse through the adj list of a node
        std::list<int>::iterator list_itr = neighbours.begin();

        //identify neighbours, add them to the queue if not visited
        for(; list_itr!=neighbours.end(); list_itr++){
            int cur_neighbour = *list_itr;
            // std::cout<<"\nCurrent neighbour: "<<cur_neighbour;
            if (visited.find(cur_neighbour) == visited.end()){
                // std::cout << "\nEle "<<cur_neighbour<<" not visited" << '\n';
                number_q.push(cur_neighbour);
                visited.insert(cur_neighbour);
            }
        }
    }

    std::cout<<"\n\nBFS Traversal: ";
    for (auto itr = bfs_traversal.begin(); itr!=bfs_traversal.end(); itr++){
        std::cout<<(*itr)<<" ";
    }
    return bfs_traversal;
}


#endif
