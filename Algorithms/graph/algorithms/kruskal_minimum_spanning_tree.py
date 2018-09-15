# -*- coding: UTF-8 -*-

'''
	Spanning Tree: Given an undirected and connected graph G=(V, E), a spanning tree of the graph G is a tree that spans G 
	(that is, it includes every vertex of G) and is a subgraph of G (every edge in the tree belongs to G).

	Minimum Spanning Tree: The cost of the spanning tree is the sum of the weights of all the edges in the tree. 
	There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all 
	the spanning trees.
'''

from data_structures import graph

class Kruskal(object):
	'''Find the kruskal minimum spanning tree of a graph'''
	def __init__(self, graph):
		self.graph = graph

	def sort_edges(self):
		'''Soft the edges of the graph by weight'''
		num_edges = len(self.graph.edges)

		for i in range(num_edges):
			for j in range(i+1, num_edges):
				if self.graph.edges[i] > self.graph.edges[j]:
					self.graph.edges[i], self.graph.edges[j] = self.graph.edges[j], self.graph.edges[i]

	def get_parent(self, x, parent):
		''' Rreturn the parent of a node until it is 1 '''
		if (parent[x] == -1):
			return x

		return self.get_parent(parent[x], parent)

	def initialize_parent(self):
		''' Initialize a parent dict where each node stores its parent node.
			Initially each node is a different subsets with no parent node, hence initialized with -1 '''
		parent = {}
		for vertex in self.graph.vertices:
			parent[vertex.name] = -1

		return parent

	def minimum_spanning_tree(self):
		'''Return the minimum spanning tree of a graph'''
		self.sort_edges()
		mst = []
		minimumCost = 0
		parent = self.initialize_parent()

		for edge in self.graph.edges:
			src = edge.src.name
			dest = edge.dest.name

			# If the current edge do not form a cycle
			if (self.get_parent(src, parent) != self.get_parent(dest, parent)):
				minimumCost += edge.weight
				parent[src] = dest
				mst.append(edge)
			
		return mst, minimumCost


def test_kruskal():
	g = graph.construct_graph()

	kruskal = Kruskal(g)
	mst, minimumCost = kruskal.minimum_spanning_tree()
	
	for edge in mst:
		print edge

	assert minimumCost == 6

if __name__ == "__main__":
	test_kruskal()
