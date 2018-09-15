
max_width = 0
from Queue import *
import binary_tree

def maximum_width(root):
	global max_width
	if not root:
		return 0
	
	else:
		queue = Queue()
		queue.put(root)
		
		while 1:
			numiterations = queue.qsize()
			if numiterations > max_width:
				max_width = numiterations
			
			if numiterations == 0:
				break

			while numiterations > 0:
					s = queue.get()
					
					if s.left:
						queue.put(s.left)
					if s.right:
						queue.put(s.right)
					numiterations -= 1

	return max_width

tree = binary_tree.construct_binary_tree()
print maximum_width(tree.root)