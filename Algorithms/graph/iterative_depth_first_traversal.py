# -*- coding: UTF-8 -*-

'''
	Iterative depth first traversal
'''

class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(V)]

	def add_edge(self, src, dest):
		self.adj_list[src].append(dest)

	def dfs_util(self, start, visited):
		'''Print depth first traversal of a graph'''
		stack = [start]
		
		while stack:
			s = stack.pop(-1)
			if not visited[s]:
				visited[s] = 1
				print s

			for vertex in self.adj_list[s]:
				if not visited[vertex]:
					stack.append(vertex)

	def dfs(self):
		visited = [0] * self.V
		for i in range(self.V):
			if not visited[i]:
				self.dfs_util(i, visited)

def construct_graph():
	graph = Graph(5)
	graph.add_edge(1, 0)
	graph.add_edge(0, 2)
	graph.add_edge(2, 1)
	graph.add_edge(0, 3)
	graph.add_edge(1, 4)

	return graph

if __name__ == "__main__":
	graph = construct_graph()
	graph.dfs()
