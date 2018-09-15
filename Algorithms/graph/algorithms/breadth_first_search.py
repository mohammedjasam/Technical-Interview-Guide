# -*- coding: UTF-8 -*-

# Program to do a breadth first traversal of a graph

import Queue

# Time-complexity: O(V+E)
class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(V)]

	def add_edge(self, src, dest):
		self.adj_list[src].append(dest)

	def bfs(self, start):
		'''Print the breadth first search traversal of the graph'''
		# Initialize a visited array with all node as not visited
		visited = [0] * graph.V
		# Initialize a queue which keeps the visited nodes
		queue = Queue.Queue()
		# Visit the first node
		queue.put(start)
		visited[start] = 1
		print start

		# Iteratively visit all the nodes in a graph in breadth first search manner
		while not queue.empty():
			node = queue.get()
			for vertex in self.adj_list[node]:
				if not visited[vertex]:
					print vertex
					visited[vertex] = 1
					queue.put(vertex)

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
	graph.bfs(0)
