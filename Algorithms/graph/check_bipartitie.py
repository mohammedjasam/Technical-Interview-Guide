# program to check if a graph is a bipartite or not

class Edge(object):
	def __init__(self, src=None, dest=None):
		self.src=src
		self.dest=dest

class Graph(object):
	def __init__(self, V=None, edges=[]):
		self.V = V
		self.edges = edges
	
	
def check_bipartite(graph, src):

	color = [-1] * graph.V

	color[src] = 0
	queue = []
	queue.append(src)

	while(queue):
		v = queue[0]
		del queue[0]

		connected_nodes = graph.edges[v]

		for node in connected_nodes:
			if color[node] == -1:
				color[node] = 1 - color[v]

			elif color[node] == color[v]:
				return False

	return True


if __name__=='__main__':
	graph = Graph(4, [None]*4)
	
	graph.edges = [[] for i in graph.edges]

	edge = Edge(0, 1)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(0, 3)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(1, 0)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(1, 2)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(2, 1)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(2, 3)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(3, 0)
	graph.edges[edge.src].append(edge.dest)

	edge = Edge(3, 2)
	graph.edges[edge.src].append(edge.dest)

	print graph.edges

	print check_bipartite(graph, 2)
