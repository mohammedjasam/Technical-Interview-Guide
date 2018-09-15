# -*- coding: UTF-8 -*-

import initialize

# Program to rotate a linked list

def rotate(head):

	if not head:
		return
	
	temp = head

	while (temp.nextnode):
		temp = temp.nextnode

	node = head
	head = head.nextnode
	temp.nextnode = node
	temp.nextnode.nextnode = None

	return head

lList = initialize.initialize_linked_list()

head = rotate(lList.head)

while (head):
	print head.data
	head = head.nextnode