#include "bk.h"
#include "graph.cpp"
#include "maxflow.cpp"
#include <stdexcept>
#include <string>
#include <memory>

extern "C" {

struct error {
    std::string message;
};

const char* bk_error_message(bk_error error)
{
    return error->message.c_str();
}

void bk_error_release(bk_error error)
{
    delete error;
}

}  // extern "C"


template<typename Fn>
bool translateExceptions(bk_error* out_error, Fn&& fn)
{
    try {
        fn();
    } catch (const std::exception& e) {
        *out_error = new error{e.what()};
        return false;
    } catch (...) {
        *out_error = new error{"Unknown internal error"};
        return false;
    }
    return true;
}


extern "C" {

struct graph_int {
    graph_int(int node_num_max, int edge_num_max):graph(node_num_max,edge_num_max){}
    Graph<int,int,int> graph;
};

struct graph_short {
    graph_short(int node_num_max, int edge_num_max):graph(node_num_max,edge_num_max){}
    Graph<short,int,int> graph;
};

struct graph_float {
    graph_float(int node_num_max, int edge_num_max):graph(node_num_max,edge_num_max){}
    Graph<float,float,float> graph;
};

struct graph_double {
    graph_double(int node_num_max, int edge_num_max):graph(node_num_max,edge_num_max){}
    Graph<double,double,double> graph;
};

bk_graph_int bk_create_graph_int(int node_num_max, int edge_num_max, bk_error* error)
{
    bk_graph_int g = nullptr;
    translateExceptions(error, [&]{
        g = std::make_unique<graph_int>(node_num_max, edge_num_max).release();
    });
    return g;
}

bk_graph_short bk_create_graph_short(int node_num_max, int edge_num_max, bk_error* error)
{
    bk_graph_short g = nullptr;
    translateExceptions(error, [&]{
        g = std::make_unique<graph_short>(node_num_max, edge_num_max).release();
    });
    return g;
}

bk_graph_float bk_create_graph_float(int node_num_max, int edge_num_max, bk_error* error)
{
    bk_graph_float g = nullptr;
    translateExceptions(error, [&]{
        g = std::make_unique<graph_float>(node_num_max, edge_num_max).release();
    });
    return g;
}

bk_graph_double bk_create_graph_double(int node_num_max, int edge_num_max, bk_error* error)
{
    bk_graph_double g = nullptr;
    translateExceptions(error, [&]{
        g = std::make_unique<graph_double>(node_num_max, edge_num_max).release();
    });
    return g;
}

void bk_delete_graph_int(bk_graph_int g)
{
    delete g;
}

void bk_delete_graph_short(bk_graph_short g)
{
    delete g;
}

void bk_delete_graph_float(bk_graph_float g)
{
    delete g;
}

void bk_delete_graph_double(bk_graph_double g)
{
    delete g;
}

int bk_add_node_int(bk_graph_int g, int num, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.add_node(num);
    });
    return result;
}

int bk_add_node_short(bk_graph_short g, int num, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.add_node(num);
    });
    return result;
}

int bk_add_node_float(bk_graph_float g, int num, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.add_node(num);
    });
    return result;
}

int bk_add_node_double(bk_graph_double g, int num, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.add_node(num);
    });
    return result;
}

void bk_add_tweights_int(bk_graph_int g, int id, int cap_source, int cap_sink, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_tweights(id, cap_source, cap_sink);
    });
}

void bk_add_tweights_short(bk_graph_short g, int id, int cap_source, int cap_sink, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_tweights(id, cap_source, cap_sink);
    });
}

void bk_add_tweights_float(bk_graph_float g, int id, float cap_source, float cap_sink, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_tweights(id, cap_source, cap_sink);
    });
}

void bk_add_tweights_double(bk_graph_double g, int id, double cap_source, double cap_sink, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_tweights(id, cap_source, cap_sink);
    });
}

void bk_add_edge_int(bk_graph_int g, int i, int j, int cap, int rev_cap, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_edge(i, j, cap, rev_cap);
    });
}

void bk_add_edge_short(bk_graph_short g, int i, int j, short cap, short rev_cap, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_edge(i, j, cap, rev_cap);
    });
}

void bk_add_edge_float(bk_graph_float g, int i, int j, float cap, float rev_cap, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_edge(i, j, cap, rev_cap);
    });
}

void bk_add_edge_double(bk_graph_double g, int i, int j, double cap, double rev_cap, bk_error* error)
{
    translateExceptions(error, [&]{
        g->graph.add_edge(i, j, cap, rev_cap);
    });
}

int bk_maxflow_int(bk_graph_int g, bool reuse_trees, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.maxflow(reuse_trees);
    });
    return result;
}

int bk_maxflow_short(bk_graph_short g, bool reuse_trees, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.maxflow(reuse_trees);
    });
    return result;
}

float bk_maxflow_float(bk_graph_float g, bool reuse_trees, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.maxflow(reuse_trees);
    });
    return result;
}

double bk_maxflow_double(bk_graph_double g, bool reuse_trees, bk_error* error)
{
    int result = -1;
    translateExceptions(error, [&]{
        result = g->graph.maxflow(reuse_trees);
    });
    return result;
}

bk_termtype bk_what_segment_int(bk_graph_int g, int i, bk_error* error)
{
    bk_termtype result = SOURCE;
    translateExceptions(error, [&]{
        result = static_cast<bk_termtype>(g->graph.what_segment(i));
    });
    return result;
}

bk_termtype bk_what_segment_short(bk_graph_short g, int i, bk_error* error)
{
    bk_termtype result = SOURCE;
    translateExceptions(error, [&]{
        result = static_cast<bk_termtype>(g->graph.what_segment(i));
    });
    return result;
}

bk_termtype bk_what_segment_float(bk_graph_float g, int i, bk_error* error)
{
    bk_termtype result = SOURCE;
    translateExceptions(error, [&]{
        result = static_cast<bk_termtype>(g->graph.what_segment(i));
    });
    return result;
}

bk_termtype bk_what_segment_double(bk_graph_double g, int i, bk_error* error)
{
    bk_termtype result = SOURCE;
    translateExceptions(error, [&]{
        result = static_cast<bk_termtype>(g->graph.what_segment(i));
    });
    return result;
}


}  // extern "C"
