# -*- coding: UTF-8 -*-

# Program to swap kth node from start with kth node from end

import initialize

def swap(lList, k):

	if not lList.head:
		raise ValueError("List is empty")

	count = lList.size()

	if 2*k-1 == count:
		return

	x = lList.head
	x_prev = None

	for i in range(k-1):
		x_prev = x
		x = x.nextnode

	y = lList.head
	y_prev = None

	for i in range(count-k):
		y_prev = y
		y = y.nextnode

	if x_prev:
		x_prev.nextnode = y

	if y_prev:
		y_prev.nextnode = x

	temp = x.nextnode
	x.nextnode = y.nextnode
	y.nextnode = temp

	if k == 1:
		lList.head = y
	if k == count:
		lList.head = x

	return lList.head

lList = initialize.initialize_linked_list()

head = swap(lList, 1)

while (head):
	print head.data
	head = head.nextnode
