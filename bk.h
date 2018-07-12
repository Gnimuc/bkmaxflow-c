#ifndef BK_MAXFLOW_H
#define BK_MAXFLOW_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bk_termtype
{
    SOURCE	= 0,
    SINK	= 1
} bk_termtype;

typedef struct error* bk_error;
const char* bk_error_message(bk_error error);
void bk_error_release(bk_error error);

typedef struct graph_int* bk_graph_int;
typedef struct graph_short* bk_graph_short;
typedef struct graph_float* bk_graph_float;
typedef struct graph_double* bk_graph_double;

bk_graph_int bk_create_graph_int(int node_num_max, int edge_num_max, bk_error* error);
bk_graph_short bk_create_graph_short(int node_num_max, int edge_num_max, bk_error* error);
bk_graph_float bk_create_graph_float(int node_num_max, int edge_num_max, bk_error* error);
bk_graph_double bk_create_graph_double(int node_num_max, int edge_num_max, bk_error* error);

void bk_delete_graph_int(bk_graph_int g);
void bk_delete_graph_short(bk_graph_short g);
void bk_delete_graph_float(bk_graph_float g);
void bk_delete_graph_double(bk_graph_double g);

int bk_add_node_int(bk_graph_int g, int num, bk_error* error);
int bk_add_node_short(bk_graph_short g, int num, bk_error* error);
int bk_add_node_float(bk_graph_float g, int num, bk_error* error);
int bk_add_node_double(bk_graph_double g, int num, bk_error* error);

void bk_add_tweights_int(bk_graph_int g, int id, int cap_source, int cap_sink, bk_error* error);
void bk_add_tweights_short(bk_graph_short g, int id, int cap_source, int cap_sink, bk_error* error);
void bk_add_tweights_float(bk_graph_float g, int id, float cap_source, float cap_sink, bk_error* error);
void bk_add_tweights_double(bk_graph_double g, int id, double cap_source, double cap_sink, bk_error* error);

void bk_add_edge_int(bk_graph_int g, int i, int j, int cap, int rev_cap, bk_error* error);
void bk_add_edge_short(bk_graph_short g, int i, int j, short cap, short rev_cap, bk_error* error);
void bk_add_edge_float(bk_graph_float g, int i, int j, float cap, float rev_cap, bk_error* error);
void bk_add_edge_double(bk_graph_double g, int i, int j, double cap, double rev_cap, bk_error* error);

int bk_maxflow_int(bk_graph_int g, bool reuse_trees, bk_error* error);
int bk_maxflow_short(bk_graph_short g, bool reuse_trees, bk_error* error);
float bk_maxflow_float(bk_graph_float g, bool reuse_trees, bk_error* error);
double bk_maxflow_double(bk_graph_double g, bool reuse_trees, bk_error* error);

bk_termtype bk_what_segment_int(bk_graph_int g, int i, bk_error* error);
bk_termtype bk_what_segment_short(bk_graph_short g, int i, bk_error* error);
bk_termtype bk_what_segment_float(bk_graph_float g, int i, bk_error* error);
bk_termtype bk_what_segment_double(bk_graph_double g, int i, bk_error* error);

#ifdef __cplusplus
}  // extern "C"
#endif
#endif
