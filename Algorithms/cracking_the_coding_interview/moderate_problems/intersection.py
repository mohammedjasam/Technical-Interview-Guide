# Given two straight line segments, find intersection point of two line segments

def slope(p):
	x1 = p[0][0]
	x2 = p[1][0]
	y1 = p[0][1]
	y2 = p[1][1]

	return (y2-y1)/float(x2-x1)

def intercept(p, m):
	return p[0][1] - (m * p[0][0])

def is_between(p, intersect_x, intersect_y):
	if intersect_x > p[0][0] and intersect_x < p[1][0] and intersect_y > p[0][1] and intersect_y < p[1][1]:
		return True

	return False

def point_of_intersection(a, b):
	m1 = slope(a)
	m2 = slope(b)

	if m1 == m2:
		return None
	else:
		c1 = intercept(a, m1)
		c2 = intercept(b, m2)
	
		intersect_x = (c1 - c2) / (m2 - m1)
		intersect_y = m1 * intersect_x + c1

		# Check if intersection point is witin the line segment range
		if is_between(a, intersect_x, intersect_y) and is_between(b, intersect_x, intersect_y):
			return intersect_x, intersect_y

		return None

print point_of_intersection([(1, 2), (3, 4)], [(5, 6), (8, 10)])