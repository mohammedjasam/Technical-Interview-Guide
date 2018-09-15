# -*- coding: UTF-8 -*-

'''
	A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached
	by a path from v.
'''


class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(self.V)]

	def add_edge(self, src, dest):
		self.adj_list[src].append(dest)

	def dfs_util(self, visited, start):
		visited[start] = 1

		for v in self.adj_list[start]:
			if not visited[v]:
				self.dfs_util(visited, v)

	# Time-complexity: O(V*(V+E))
	def mother_vertex_2(self):
		'''
			Return the mother vertex. Perform a DFS/BFS on all the vertices 
			and find whether we can reach all the vertices from that vertex.
		'''
		for i in range(self.V):
			visited = [0] * self.V
			self.dfs_util(visited, i)

			flag = 1
			for v in visited:
				flag *= v

			if flag:
				return i

		return None

	def mother_vertex(self):
		'''
			If there exist mother vertex (or vertices), then one of the mother vertices 
			is the last finished vertex in DFS. (Or a mother vertex has the maximum 
			finish time in DFS traversal).

			Time-complexity: O(V+E)
		'''
		visited = [0] * self.V
		mother = 0
		
		for i in range(self.V):
			if not visited[i]:
				self.dfs_util(visited, i)
				mother = i

		visited = [0] * self.V
		self.dfs_util(visited, mother)

		for i in range(self.V):
			if not visited[i]:
				return None

		return mother

def construct_graph():
	graph = Graph(7)
	graph.add_edge(0, 1)
	graph.add_edge(0, 2)
	graph.add_edge(1, 3)
	graph.add_edge(4, 1)
	graph.add_edge(6, 4)
	graph.add_edge(5, 6)
	graph.add_edge(5, 2)
	graph.add_edge(6, 0)

	return graph

if __name__ == "__main__":
	graph = construct_graph()
	print graph.mother_vertex()
