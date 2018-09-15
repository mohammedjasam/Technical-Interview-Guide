# -*- coding: UTF-8 -*-

# Program to print kth node from end

import initialize

# --------*********** Approach - 1 *************---------------
# Find kth node by calculating the size first
# Then from staring the node will be at (size-k) location
# Iterating to (size - k) location
def kth_node_from_end_1(ll, k):
	if ll.head is None:
		return

	size = ll.size()

	if k > size:
		return

	current = ll.head
	pos = 0

	while(pos < (size - k)):
		current = current.nextnode
		pos += 1

	print "The element at position %d is %d"%(k, current.data)


# --------*********** Approach - 2 *************---------------

# Find kth node from end by using a fast pointer
# Take a fast pointer which first is moved till kth location from beginning
# Then both pointers are iterated till the last pointer and main pointer is returned.
def kth_node_from_end_2(head, k):

	if head is None:
		return

	node_ptr = head
	main_ptr = head

	count = 0

	while (count < k):
		node_ptr = node_ptr.nextnode
		count += 1

	while (node_ptr):
		main_ptr = main_ptr.nextnode
		node_ptr = node_ptr.nextnode

	print "The element at position %d is %d"%(k, main_ptr.data)

# Initialize the linked list
# 33  27  8  41  9  6  13  5  4
lList = initialize.initialize_linked_list()

# Call the kth element from end function
kth_node_from_end_1(lList, 4)
kth_node_from_end_2(lList.head, 5)
