# -*- coding: UTF-8 -*-

'''
	Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
	vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

	Time complexity: O(V+E)
'''

from data_structures.adjacency_list_graph import AdjacencyListGraph

class TopologicalSort(object):

	def __init__(self, graph):
		self.graph = graph

	def dfs(self, vertex, visited, stack):

		visited[vertex] = True

		for edge in self.graph.adjacency_dict[vertex]:
			if not visited[edge.dest]:  
				self.dfs(edge.dest, visited, stack)

		stack.append(vertex)

	def sort(self):
		vertices = self.get_vertices()
		visited = {vertex: False for vertex in vertices}

		stack = []
		for vertex in vertices:
			if not visited[vertex]:
				self.dfs(vertex, visited, stack)

		return stack[::-1]

	def get_vertices(self):
		return self.graph.adjacency_dict.keys()

def test_topological_sort():
	# Initialize a graph
	graph = AdjacencyListGraph()

	# Initialize the vertex in the graph
	a = graph.create_vertex("a")
	b = graph.create_vertex("b")
	c = graph.create_vertex("c")
	d = graph.create_vertex("d")
	e = graph.create_vertex("e")
	f = graph.create_vertex("f")

	# Initialize the edges in the graph
	graph.add_edge(f, c, directed=True)
	graph.add_edge(e, b, directed=True)
	graph.add_edge(c, d, directed=True)
	graph.add_edge(d, b, directed=True)
	graph.add_edge(e, a, directed=True)
	graph.add_edge(f, a, directed=True)

	topological_sort = TopologicalSort(graph)
	assert (topological_sort.sort() == [f, e, c, d, b, a])

if __name__ == "__main__":
	test_topological_sort()
