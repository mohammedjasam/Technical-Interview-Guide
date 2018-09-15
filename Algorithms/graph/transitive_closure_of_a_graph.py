# -*- coding: UTF-8 -*-

'''
	Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v)
	in the given graph. Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is 
	called transitive closure of a graph.
'''

class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = {i: [] for i in range(self.V)}

	def add_edge(self, src, dest):
		self.adj_list[src].append(dest)

	def dfs_util(self, start, vertex, closure):
		'''Print depth first traversal of a graph'''
		closure[start][vertex] = 1

		for v in self.adj_list[vertex]:
			if not closure[start][v]:
				self.dfs_util(start, v, closure)

	def transitive_closure(self):
		'''Return transitive closure of the vertices in a graph'''
		closure = [[0] * self.V for i in range(self.V)]

		for i in range(self.V):
			self.dfs_util(i, i, closure)

		print closure

def construct_graph(): 
	graph = Graph(4)
	graph.add_edge(0, 1)
	graph.add_edge(0, 2)
	graph.add_edge(1, 2)
	graph.add_edge(2, 0)
	graph.add_edge(2, 3)
	graph.add_edge(3, 3)

	return graph

if __name__ == "__main__":
	graph = construct_graph()
	graph.transitive_closure()
