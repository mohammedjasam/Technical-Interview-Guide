# coding: UTF-8

class MaxHeap(object):
	def __init__(self, size=None, array=None):
		self.size = size
		self.array = array


def swap(a, b):
	temp = a
	a = b
	b = a

def maxHeapify(maxheap, index):
	largest = index
	left = 2*index+1
	right = 2*index+2

	if left < maxheap.size and maxheap.array[left] > maxheap.array[largest]:
		largest = left
	if right < maxheap.size and maxheap.array[right] > maxheap.array[largest]:
		largest = right

	if largest != index:
		maxheap.array[index], maxheap.array[largest] = maxheap.array[largest], maxheap.array[index]
		maxHeapify(maxheap, largest)

def createAndBuildHeap(array):
	maxHeap = MaxHeap(len(array), array)

	for i in range((maxHeap.size-2)/2, -1, -1):
		maxHeapify(maxHeap, i)

	return maxHeap

def heapSort(array):
	maxHeap = createAndBuildHeap(array)

	while (maxHeap.size > 1):
		maxHeap.array[maxHeap.size-1], maxHeap.array[0]=maxHeap.array[0], maxHeap.array[maxHeap.size-1]

		maxHeap.size -= 1

		maxHeapify(maxHeap, 0)


arr = [12, 11, 13, 5, 6, 7, 3, 55, 21, 77, 4]

print (arr)

heapSort(arr)

print arr