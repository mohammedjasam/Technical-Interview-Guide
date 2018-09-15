# -*- coding: UTF-8 -*-

''' 
	Problem: Detect cycle in an undirected graph
'''

from data_structures import graph

class UnionFind(object):
	def __init__(self, graph):
		self.graph = graph
		self.parent = self.initialize_parent()
	
	def get_parent(self, x):
		''' Rreturn the parent of a node until it is 1 '''
		if (self.parent[x] == -1):
			return x

		return self.get_parent(self.parent[x])

	def detect_cycle(self):
		''' Detects if there is a cycle in a graph '''
		edges = self.graph.edges

		for edge in edges:
			src = edge.src.name
			dest = edge.dest.name
			
			if (self.get_parent(src) == self.get_parent(dest)):
					return True
			else:
				self.parent[src] = dest

		return False

	def initialize_parent(self):
		''' Initialize a parent dict where each node stores its parent node.
			Initially each node is a different subsets with no parent node, hence initialized with -1 '''
		parent = {}
		for vertex in self.graph.vertices:
			parent[vertex.name] = -1

		return parent

def test_union_find_algorithm():
	g = graph.construct_graph()
	union_find = UnionFind(g)

	assert (union_find.detect_cycle() == True)

if __name__ == "__main__":
	test_union_find_algorithm()
