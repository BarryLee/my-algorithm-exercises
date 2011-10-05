#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::ofstream;
using std::runtime_error;

/*
 *************************************
 * Graph_base
 *************************************
 */
Graph_base::Graph_base(const vector<string> &vvec, bool is_directed): 
    vertices(vvec), num_vertex(vvec.size()), directed(is_directed) {}

void 
Graph_base::to_dot_file(const string &fname) const
{
    ofstream of(fname.c_str());
    if (!of) {
        cerr << "error: cannot open file: "
             << fname << endl;
        throw runtime_error("error: cannot open file: " + fname);
    }
    of << to_dot_string() << endl;
    of.close();
}

/*
 *************************************
 * Graph_adj_list
 *************************************
 */
Graph_adj_list::Graph_adj_list(int nbv, bool is_directed):
                    Graph_base(nbv, is_directed) 
{
    for (int i = 0; i != num_vertex; i++) {
        vertices.push_back(string(1, '0'+i));
        adj_list.push_back(list<int>());
    }
}

Graph_adj_list::Graph_adj_list(const vector<string> &vvec,
                    const vector< pair<int,int> > &edges, 
                    bool is_directed): Graph_base(vvec, is_directed) 
{
    for (int i = 0; i != num_vertex; i++)
        adj_list.push_back(list<int>());

    for (vector< pair<int, int> >::const_iterator first = edges.begin();
            first != edges.end(); first++) {
        int from = first->first,
            to = first->second;
        add_edge(from, to);
    }
}

Graph_adj_list&
Graph_adj_list::add_edge(int from_vertex, int to_vertex)
{
    if ((from_vertex >= 0) && (from_vertex < num_vertex) 
            && (to_vertex >= 0) && (to_vertex < num_vertex)) {
        adj_list[from_vertex].push_front(to_vertex);
        if (!directed)
            adj_list[to_vertex].push_front(from_vertex);
    } else
        throw runtime_error("invalid edge");

    return *this;
}

Graph_adj_list&
Graph_adj_list::rm_edge(int from_vertex, int to_vertex)
{
    if ((from_vertex >= 0) && (from_vertex < num_vertex) 
            && (to_vertex >= 0) && (to_vertex < num_vertex)) {
        rm_edge_sub(from_vertex, to_vertex);
        if (!directed)
            rm_edge_sub(to_vertex, from_vertex);
    } else
        throw runtime_error("invalid edge");

    return *this;
}

void
Graph_adj_list::rm_edge_sub(int from, int to)
{
    list<int> &edges = adj_list.at(from);
    list<int>::iterator iter = edges.begin();
    for (; iter != edges.end() && *iter != to; iter++)
        ;
    if (iter == edges.end())
        throw runtime_error("no such edge");
    edges.erase(iter);
}

string 
Graph_adj_list::to_dot_string() const
{
    string dotstr = directed ? "digraph" : "graph";
    dotstr += " G {\n";

    string link = directed ? "->" : "--";
    int i = 0;
    for (vector< list<int> >::const_iterator first = adj_list.begin();
            first != adj_list.end() && i != num_vertex; first++, i++)
        for (list<int>::const_iterator eiter = first->begin();
                eiter != first->end(); eiter++) {
            if (!directed && *eiter < i)
                continue;
            dotstr += vertices.at(i);
            dotstr += link;
            dotstr += vertices.at(*eiter);
            dotstr += "\n";
        }

    dotstr += "}";
    return dotstr;
}

std::ostream&
Graph_adj_list::display(std::ostream &os) const
{
    for (int i = 0; i != num_vertex; i++) {
        os << "|" << vertices.at(i) << "|";
        for (const_edge_iter ei = adj_list[i].begin(); 
                ei != adj_list[i].end(); ei++) 
            os << " -> " << vertices.at(*ei);
        if (i+1 != num_vertex) os << endl;
    }
    return os;
}

std::ostream&
operator<<(std::ostream &os, const Graph_base &g)
{
    return g.display(os);
}

