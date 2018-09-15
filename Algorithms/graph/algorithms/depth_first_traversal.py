# -*- coding: UTF-8 -*-

'''
	Program to do a depth first traversal of a graph. This will print only nodes which are reachable
	from the start node. To make sure it traverse all the nodes, you need to create a DFSUtil() for every vertex.
	Also, before calling DFSUtil(), we should check if it is already printed by some other call of DFSUtil().
'''

# Time-complexity: O(V+E)
class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(V)]

	def add_edge(self, src, dest):
		self.adj_list[src].append(dest)

	def dfs_util(self, start, visited):
		'''Print depth first traversal of a graph'''
		visited[start] = 1
		print start

		for vertex in self.adj_list[start]:
			if not visited[vertex]:
				self.dfs_util(vertex, visited)

	def dfs(self, start):
		visited = [0] * graph.V
		self.dfs_util(start, visited)

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
	graph.dfs(2)
