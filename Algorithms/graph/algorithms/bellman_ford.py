# -*- coding: UTF-8 -*-

'''
	Problem: Find the shortest distance to all the nodes from source. 

'''

import sys
import adjacency_list_graph

def bellman_ford(g, source):

	distances = {}

	''' Initialize a distance dict with all nodes as infinite expect source node '''
	for v in g.adjacency_dict:
		if v != source:
			distances[v] = sys.maxint
		else:
			''' Initialize the source with 0 '''
			distances[source] = 0


	# It will iterate through len(vertices)-1 times
	for _ in range(len(g.adjacency_dict)-1):
		# For each iteration check thorugh each vertex in a graph
		for u in g.adjacency_dict:
			for edge in g.adjacency_dict[u]:
				# IF the distance to a node is less than its current distance then update it
				if distances[u] != sys.maxint and distances[edge.dest] > distances[u] + edge.weight:
					distances[edge.dest] = distances[u] + edge.weight

	return distances

if __name__ == "__main__":
	graph = adjacency_list_graph.AdjacencyListGraph()

	# Initialize the vertex in the graph
	s = graph.create_vertex("s")
	a = graph.create_vertex("a")
	b = graph.create_vertex("b")
	c = graph.create_vertex("c")
	d = graph.create_vertex("d")
	e = graph.create_vertex("e")

	graph.add_edge(s, a, weight=10)
	graph.add_edge(s, e, weight=8)

	graph.add_edge(a, c, weight=2)

	graph.add_edge(b, a, weight=1)

	graph.add_edge(c, b, weight=-2)

	graph.add_edge(d, c, weight=-1)
	graph.add_edge(d, a, weight=-4)

	graph.add_edge(e, d, weight=1)

	distances = bellman_ford(graph, s)

	for vertex, distance in distances.iteritems():
		print vertex, ": ", distance
