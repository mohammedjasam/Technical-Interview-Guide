# -*- coding: UTF-8 -*-

'''
	Problem: Given a circular linked list, implement an algorithm that returns node at the beginning of the loop.

	Solution: Take a slow pointer and a fast pointer and faster pointer will iterate twice as fast as slow pointer. If the two meets or 
	slow pointer gets passed the fast pointer, there is a loop in the linked lists. 

	For explaination: http://stackoverflow.com/questions/2936213/explain-how-finding-cycle-start-node-in-cycle-linked-list-work
'''

import linked_list

def detect_loop(linked_list):
	'''Detect loop in a linked list and return starting point of loop'''
	slow_ptr = linked_list.head
	fast_ptr = linked_list.head

	while(fast_ptr != None and fast_ptr.nextnode != None):
		# print slow_ptr.data, fast_ptr.data
		slow_ptr = slow_ptr.nextnode
		fast_ptr = fast_ptr.nextnode.nextnode

		if slow_ptr == fast_ptr:
			break

	# If slow and fast do not meet, then no loop exists
	if fast_ptr is None or fast_ptr.nextnode is None:
		return False

	slow_ptr = linked_list.head

	while(slow_ptr != fast_ptr):
		slow_ptr = slow_ptr.nextnode
		fast_ptr = fast_ptr.nextnode

	# Both pointer point to start of the loop
	return fast_ptr

if __name__ == "__main__":
	llist = linked_list.initialize_linked_list()
	llist.print_list()

	current = llist.head

	while (current.nextnode is not None):
		current = current.nextnode

	current.nextnode = llist.head.nextnode.nextnode.nextnode
	print "We have put circle at", (llist.head.nextnode.nextnode.nextnode.data)
	start_node = detect_loop(llist)
	
	# If there is loop in the linked_list
	if start_node:
		print start_node.data
	else:
		print "Cycle not found"
