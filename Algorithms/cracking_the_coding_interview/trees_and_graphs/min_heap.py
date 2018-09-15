# -*- coding: UTF-8 -*-

''' 
	A binary heap is a tree based data structure where nodes are arranged in a specific order such that root node is given the most
	priority. 

	Complexity: 
	Insertion: O(log n)
	ExtractMin: 
	
'''

class MinHeap(object):

	def __init__(self):
		self.arr = []

	def parent(self, x):
		return x / 2

	def get_min(self):
		return self.arr[0]

	def insert(self, data):
		self.arr.append(data)

		child_index = len(self.arr)-1
		parent_index = self.parent(child_index)
		while (child_index != 0 and self.arr[parent_index] > self.arr[child_index]):
			self.arr[parent_index], self.arr[child_index] = self.arr[child_index], self.arr[parent_index]
			
			# Assign parent index to child node
			child_index = parent_index
			parent_index = self.parent(child_index)

		# print self.arr


	def heapify(self, i):
		left = 2 * i + 1
		right = 2 * i + 2

		minimum = i

		if left < len(self.arr) and self.arr[minimum] > self.arr[left]:
			minimum = left

		if right < len(self.arr) and self.arr[minimum] > self.arr[right]:
			minimum = right

		if minimum != i:
			self.arr[i], self.arr[minimum] = self.arr[minimum], self.arr[i]
			self.heapify(minimum)

	def extract_min(self):
		if len(self.arr) == 0:
			return
		deleted_node = self.arr.pop(0)
		self.heapify(0)

		return deleted_node

	def decrease_key(self, i, new_val):
		self.arr[i] = new_val

		while(i != 0 and self.arr[self.parent(i)] > self.arr[i]):
			self.arr[self.parent(i)], self.arr[i] = self.arr[i], self.arr[self.parent(i)]
			i = self.parent(i)

	def delete_key(self, i):
		self.decrease_key(i, -10000000000)
		self.extract_min()

		print self.arr

if __name__ == "__main__":
	min_heap = MinHeap()

	min_heap.insert(4)
	min_heap.insert(8)
	min_heap.insert(1)
	min_heap.insert(10)
	min_heap.insert(5)
	min_heap.insert(7)
	min_heap.insert(2)
	print min_heap.extract_min()
	print min_heap.extract_min()
	print min_heap.extract_min()
	min_heap.delete_key(3)
	