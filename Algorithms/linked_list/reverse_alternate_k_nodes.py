# -*- coding: UTF-8 -*-

# Program to reverse alternate k nodes in a linked list
import initialize

def reverse_alternate_k_nodes(head, k):

	count = 0	
	prev = None
	curr = head

	# reverse first k nodes in link list
	while count < k and curr:
		next = curr.nextnode
		curr.nextnode = prev
		prev = curr
		curr = next
		count += 1

	# head will point to k node. So next of it will point to the k+1 node
	if head:
		head.nextnode = curr

	# don't want to reverse next k nodes.
	count = 0
	while count < k-1 and curr:
			curr = curr.nextnode
			count += 1

	# Recursively call the same method if there are more elements in the link list
	if curr:
		curr.nextnode = reverse_alternate_k_nodes(curr.nextnode, k)

	return prev

head = initialize.initialize_linked_list()

head = reverse_alternate_k_nodes(head, 2)
print "After reversing the alternate k nodes in linked list"

while head:
	print head.data
	head = head.nextnode
