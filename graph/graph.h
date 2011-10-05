#include <vector>
#include <list>
#include <string>
#include <utility>
#include <ostream>
#include <iostream>

using std::vector;
using std::list;
using std::string;
using std::pair;

struct Graph_base {
    friend std::ostream& operator<<(std::ostream&, const Graph_base&);

    typedef vector<string>::iterator vertex_iter;
    typedef vector<string>::const_iterator const_vertex_iter;
    typedef pair<int,int> edge;

    Graph_base(): num_vertex(0), directed(true) {}
    Graph_base(int nbv, bool is_directed = true): 
        num_vertex(nbv), directed(is_directed) {}
    Graph_base(const vector<string>&, bool = true);

    virtual Graph_base& add_edge(int, int) = 0;
    virtual Graph_base& rm_edge(int, int) = 0;

    virtual string to_dot_string() const = 0;
    virtual void to_dot_file(const string&) const;

    virtual ~Graph_base() {};

    vector<string> vertices;
    int num_vertex;
    bool directed;
protected:
    virtual std::ostream& 
        display(std::ostream& = std::cout) const = 0;
};

struct Graph_adj_list: public Graph_base {

    typedef vector< list<int> >::iterator adj_list_iter;
    typedef vector< list<int> >::const_iterator const_adj_list_iter;
    typedef list<int>::iterator edge_iter;
    typedef list<int>::const_iterator const_edge_iter;

    Graph_adj_list() {}
    Graph_adj_list(int, bool = true); 
    Graph_adj_list(const vector<string>&,
          const vector< pair<int,int> >& = vector< pair<int,int> >(),
          bool = true);

    Graph_adj_list& add_edge(int, int);
    Graph_adj_list& rm_edge(int, int);

    string to_dot_string() const;

    vector< list<int> > adj_list;
private:
    void rm_edge_sub(int, int);
    std::ostream& display(std::ostream&) const;
};

