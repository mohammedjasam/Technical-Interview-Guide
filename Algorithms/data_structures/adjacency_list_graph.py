# -*- coding: UTF-8 -*-

from graph import AbstractGraph, Vertex, Edge

class AdjacencyListGraph(AbstractGraph):
	'''
		Class to represent a graph using adjacency list
	'''
	def __init__(self):
		self.adjacency_dict = {}

	def create_vertex(self, name):
		vertex = Vertex(name=name)

		if vertex not in self.adjacency_dict:
			self.adjacency_dict[vertex] = []

		return vertex

	def add_edge(self, src, dest, weight=None, directed=True):
		if directed:
			self.add_directed_edge(src, dest, weight)
		else:
			self.add_undirected_edge(src, dest, weight)

	def add_directed_edge(self, src, dest, weight=None):
		edge = Edge(src=src, dest=dest, weight=weight)

		self.adjacency_dict[src].append(edge)

	def add_undirected_edge(self, src, dest, weight=None):
		self.add_directed_edge(src, dest, weight)
		self.add_directed_edge(dest, src, weight)

	def get_weight(self, src, dest):

		adjacency_list = self.adjacency_dict[src]

		for edge in adjacency_list:
			if edge.dest == dest:
				return edge.weight

	def get_edges(self, src):
		'''Return all the edges connected to the given vertex'''
		return self.adjacency_dict[src]

	def get_connected_vertices(self, src):
		'''Return all the vertex connected to the given vertex'''
		return [edge.dest for edge in self.adjacency_dict[src]]

	def __str__(self):
		
		text = ''

		for vertex, edges in self.adjacency_dict.iteritems():
			text += "{" + str(vertex.name) + ": " + ', '.join([edge.dest.name for edge in edges]) + "}\n"

		return text


def construct_graph():
	'''
		Function to initialize a undirected graph 
	'''
	# Initialize a graph
	graph = AdjacencyListGraph()

	# Initialize the vertex in the graph
	a = graph.create_vertex("a")
	b = graph.create_vertex("b")
	c = graph.create_vertex("c")
	d = graph.create_vertex("d")
	# Initialize the edges in the graph
	graph.add_edge(a, b, directed=False)
	graph.add_edge(b, c, directed=False)
	graph.add_edge(c, d, directed=False)
	graph.add_edge(d, b, directed=False)

	return graph

if __name__ == "__main__":
	g = construct_graph()

	print g
