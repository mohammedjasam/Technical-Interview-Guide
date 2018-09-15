# -*- coding: UTF-8 -*-

''' 
	Problem: Given a graph and a source vertex in graph, find shortest paths from source to all
	vertices in the given graph.
'''

import sys
from data_structures.adjacency_list_graph import AdjacencyListGraph

class Dijikstra(object):
	def __init__(self, graph):
		self.graph = graph

	def get_minimum_distance(self, distances, mst):
		'''Return the vertex at minimum distance'''
		min_value = sys.maxint

		for vertex, weight in distances.iteritems():
			if weight < min_value and not mst[vertex]:
				min_value = weight
				min_vertex = vertex

		return min_vertex

	def all_visited(self, mst):
		'''Check if all the nodes are visited or not'''
		if False in mst.values():
			return False

		return True

	def dijkstra(self, source):
		'''Calculates the minimum distance to all the vertex from source vertex'''
		distances = {}
		mst = {}

		''' Initialize a distance dict with all nodes as infinite expect source node'''
		for v in self.graph.adjacency_dict:
			if v != source:
				distances[v] = sys.maxint
			else:
				''' Initialize the source with 0 '''
				distances[source] = 0	
			mst[v] = False

		mst[source] = True
		while(not self.all_visited(mst)):
			for edge in self.graph.adjacency_dict[source]:
				if not mst[edge.dest] and distances[edge.dest] > distances[source] + edge.weight:
					distances[edge.dest] = distances[source] + edge.weight

			min_vertex = self.get_minimum_distance(distances, mst)

			mst[min_vertex] = True
			source = min_vertex	

		return distances

def test_dijikstra():
	graph = AdjacencyListGraph()

	# Initialize the vertex in the graph
	s = graph.create_vertex("s")
	a = graph.create_vertex("a")
	b = graph.create_vertex("b")
	c = graph.create_vertex("c")
	d = graph.create_vertex("d")
	e = graph.create_vertex("e")
	f = graph.create_vertex("f")
	g = graph.create_vertex("g")
	h = graph.create_vertex("h")


	# Add edges in a graph
	graph.add_edge(s, a, weight=4, directed=False)
	graph.add_edge(s, g, weight=8, directed=False)

	graph.add_edge(a, b, weight=8, directed=False)
	graph.add_edge(a, g, weight=11, directed=False)

	graph.add_edge(b, c, weight=7, directed=False)
	graph.add_edge(b, h, weight=2, directed=False)
	graph.add_edge(b, e, weight=4, directed=False)

	graph.add_edge(c, e, weight=14, directed=False)
	graph.add_edge(c, d, weight=9, directed=False)

	graph.add_edge(d, e, weight=10, directed=False)

	graph.add_edge(e, f, weight=2, directed=False)

	graph.add_edge(f, g, weight=1, directed=False)
	graph.add_edge(f, h, weight=6, directed=False)

	graph.add_edge(g, h, weight=7, directed=False)

	dijkstra = Dijikstra(graph)
	distances = dijkstra.dijkstra(s)

	# Print the vertex and their corresponding distances from source node
	for vertex, distance in distances.iteritems():
		print vertex, ": ", distance

if __name__ == "__main__":
	test_dijikstra()
