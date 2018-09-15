# -*- coding: UTF-8 -*-

# Implement Binary MinHeap
import sys

class MinHeap(object):

	def __init__(self, capacity=0, size=0, harr=[]):
		self.capacity = capacity
		self.size = size
		self.harr = harr

	def parent(self, i):
		return (i-1)/2

	def left(self, i):
		return 2*i + 1

	def right(self, i):
		return 2*i + 2

	def insertKey(self, k):
		if self.size == self.capacity:
			return "Sorry, cound not insert more elements"

		else:
			self.size += 1
			i = self.size - 1
			self.harr.append(k)

			while (i != 0 and self.harr[self.parent(i)] > self.harr[i]):
				# Swap operation
				self.harr[i], self.harr[self.parent(i)] = self.harr[self.parent(i)], self.harr[i]
				i = self.parent(i)

	def decreaseKey(self, i, new_val):
		self.harr[i] = new_val

		while (i != 0 and self.harr[self.parent(i)] > self.harr[i]):
			# Swap operation
			self.harr[i], self.harr[self.parent(i)] = self.harr[self.parent(i)], self.harr[i]
			i = self.parent(i)

	def extractMin(self):
		if self.size == 0:
			return sys.maxint
		if self.size == 1:
			return self.harr[0]
			self.size -= 1
		else:
			root = self.harr[0]
			self.harr[0] = self.harr[self.size-1]
			self.size -= 1

			self.minHeapify(0)

			return root

	def minHeapify(self, i):
		l = self.left(i)
		r = self.right(i)
		minimum = i

		if l < self.size and self.harr[minimum] > self.harr[l]:
			minimum = l
		if r < self.size and self.harr[minimum] > self.harr[r]:
			minimum = r

		if minimum != i:
			self.harr[minimum], self.harr[i] = self.harr[i], self.harr[minimum]

	def deleteKey(self, i):
		self.decreaseKey(i, -1000000)
		self.extractMin()
