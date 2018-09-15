# -*- coding: UTF-8 -*-
'''
	Detect cycle in a graph using three colors notation for each vertex and depth first traversal of the tree. 

	WHITE(0) : Vertex is not processed yet. Initially all vertices are WHITE.

	GRAY(1) : Vertex is being processed (DFS for this vertex has started, but not finished which means that 
		all descendants (ind DFS tree) of this vertex are not processed yet (or this vertex is in function
	       call stack)

	BLACK(2) : Vertex and all its descendants are processed.

	While doing DFS, if we encounter an edge from current vertex to a GRAY vertex, then this edge is back edge 
	and hence there is a cycle.
'''

# Time complexity: O(V+E)
class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(V)]

	def addEdge(self, src, dest):
		self.adj_list[src].append(dest)


	def detect_cycle_util(self, start, colors):
		if colors[start] == 0:	
			colors[start] = 1
			for vertex in self.adj_list[start]:
				if self.detect_cycle_util(vertex, colors):
					return True

			colors[start] = 2

		elif colors[start] == 1:
			return True

		else:
			return False

	def detect_cycle(self):
		colors = [0] * graph.V

		for v in range(graph.V):
			if self.detect_cycle_util(v, colors):
				return True

		return False

def construct_graph():
	graph = Graph(4)
	graph.addEdge(0, 1)
	graph.addEdge(0, 2)
	graph.addEdge(1, 2)
	graph.addEdge(2, 0)
	graph.addEdge(2, 3)
	graph.addEdge(3, 3)

	return graph

if __name__ == "__main__":
	graph = construct_graph()
	print graph.detect_cycle()
