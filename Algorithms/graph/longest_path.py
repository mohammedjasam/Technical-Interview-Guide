# -*- coding: UTF-8 -*-

# Program to find longest path in a graph

class Edge(object):
	def __init__(self, src=None, dest=None, weight=None):
		self.src=src
		self.dest=dest
		self.weight = weight

class Graph(object):
	def __init__(self, V=None, edges=[]):
		self.V = V
		self.edges = edges

def topological_sort(graph, visited, start, stack):

	visited.append(start)
	connected_nodes = graph.edges[start]

	for i in connected_nodes:
		if i.dest not in visited:
			topological_sort(graph, visited, i.dest, stack)

	stack.append(start)

def longest_path(graph):

	visited = []
	stack = []

	for v in range(graph.V):
		if v not in visited:
			topological_sort(graph, visited, v, stack)

	# initialize longest path of every vertex to be maximum negative value
	longest_path = [-10000] * graph.V

	# 1 is the source vertex
	longest_path[1] = 0

	while stack:
		u = stack[-1]
		del stack[-1]

		if longest_path[u] != -10000:
			for v in graph.edges[u]:
				if (longest_path[v.dest] < longest_path[u] + v.weight):
					longest_path[v.dest] = longest_path[u] + v.weight

	print longest_path


def construct_graph():
	graph = Graph(6, [None]*6)
	
	graph.edges = [[] for i in graph.edges]

	edge = Edge(0, 1, 5)
	graph.edges[edge.src].append(edge)

	edge = Edge(0, 2, 3)
	graph.edges[edge.src].append(edge)

	edge = Edge(1, 3, 6)
	graph.edges[edge.src].append(edge)

	edge = Edge(1, 2, 2)
	graph.edges[edge.src].append(edge)

	edge = Edge(2, 4, 4)
	graph.edges[edge.src].append(edge)

	edge = Edge(2, 5, 2)
	graph.edges[edge.src].append(edge)

	edge = Edge(2, 3, 7)
	graph.edges[edge.src].append(edge)

	edge = Edge(3, 5, 1)
	graph.edges[edge.src].append(edge)

	edge = Edge(3, 4, -1)
	graph.edges[edge.src].append(edge)

	edge = Edge(4, 5, -2)
	graph.edges[edge.src].append(edge)

	return graph

graph = construct_graph()

longest_path(graph)