# -*- coding: UTF-8 -*-

# Program to detect cycle in an directed graph

# Time-complexity: O(V+E)
class Graph(object):
	def __init__(self, V):
		self.V = V
		self.adj_list = [[] for i in range(V)]

	def addEdge(self, src, dest):
		self.adj_list[src].append(dest)

	def is_cyclic(self):
		visited = [0] * self.V
		rec_stack = [0] * self.V

		for i in range(self.V):
			if self.is_cycle_util(i, visited, rec_stack):
				return True

		return False

	def is_cycle_util(self, v, visited, rec_stack):
		if not visited[v]:
			visited[v] = True
			rec_stack[v] = True

			for vertex in self.adj_list[v]:
				# If visiting this vertex further leads to a cycle
				if not visited[vertex] and self.is_cycle_util(vertex, visited, rec_stack):
					return True

				# If the vertex is found in the rec_stack
				elif rec_stack[vertex]:
					return True

		# remove the vertex from recursion stack
		rec_stack[v] = False
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
	print graph.is_cyclic()
