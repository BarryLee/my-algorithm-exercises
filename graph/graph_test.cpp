#include "graph.h"
#include <iostream>

using namespace std;

const int sz = 5;

int main()
{
    typedef Graph_adj_list::edge edge;
    string vertices[] = { "a", "b", "c", "d", "e" };
    vector<Graph_adj_list::edge> edges;
    edges.push_back(edge(0, 1));
    edges.push_back(edge(0, 2));
    edges.push_back(edge(1, 2));
    edges.push_back(edge(2, 4));
    edges.push_back(edge(3, 4));

    Graph_adj_list G(vector<string>(vertices, vertices+5), edges, false);
    Graph_base *g = &G;

    G.add_edge(2,3).add_edge(0,4);
    cout << (*g) << endl;
    G.rm_edge(0,1).rm_edge(0,4);
    cout << endl;
    cout << G << endl;
    cout << G.to_dot_string() << endl;
    G.to_dot_file("/tmp/dottest.txt");
}

