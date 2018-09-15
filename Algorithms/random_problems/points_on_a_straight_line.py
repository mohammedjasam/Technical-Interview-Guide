# -*- coding: UTF-8 -*-

'''
	Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

	Sample Input: (1, 1) (2, 2)

	Sample Output: 2
'''

def points_on_line(points_x, points_y):
	if len(points_x) != len(points_y):
		return -1

	n = len(points_x)
	if n <= 2:
		return n

	max_points = 0

	for i in range(n):
		dup = 1 # count the duplicates
		slopes = {}
		
		for j in range(n):
			if points_x[i] == points_x[j] and points_y[i] == points_y[j] and i != j:
				dup += 1
			elif i != j:
				if points_x[i] == points_x[j]:
					slopes['v'] = slopes.get('v', 0) + 1 
				elif points_y[i] == points_y[j]:
					slopes['h'] = slopes.get('h', 0) + 1

				else:
					slope = (points_y[i] - points_y[j]) / float(points_x[i] - points_x[j])
					slopes[slope] = slopes.get(slope, 0) + 1

			if len(slopes) > 0:
				max_points = max(max_points, max(slopes.values())+dup)
			else:
				max_points = max(max_points, dup)

	return max_points

print points_on_line([0, 1, -1], [0, 1, -1])
