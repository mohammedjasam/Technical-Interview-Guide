'''
	Find if a given binary tree has duplicate sub trees or not. 
	(Two leaf nodes of a parent do not count as subtree)
'''

inorder_subtrees = []
def get_inorder_subtrees(root):
	if not root.left and not root.right:
		return str(root.data)
	temp = ''
	
	if root.left:
		temp += get_inorder_subtrees(root.left)
	
	temp += str(root.data)
	
	if root.right:
		temp += get_inorder_subtrees(root.right)
	
	inorder_subtrees.append(temp)
	
	return temp
 
postorder_subtrees = []
def get_postorder_subtrees(root):
	if not root.left and not root.right:
		return str(root.data)
	temp = ''
	
	if root.left:
		temp += get_postorder_subtrees(root.left)
 
	if root.right:
		temp += get_postorder_subtrees(root.right)
 
	temp += str(root.data)
 
	postorder_subtrees.append(temp)
 
	return temp
 
def compare_subtrees():
	global inorder_subtrees
	global postorder_subtrees
	
	hash_map = {}
	for inorder, postorder in zip(inorder_subtrees, postorder_subtrees):
		key =  inorder + '-' + postorder
		if key in hash_map:
			return True
		else:
			hash_map[key] = 1
	return False
	
def duplicate_subtree(tree):
	get_inorder_subtrees(tree.root)
	get_postorder_subtrees(tree.root)

	answer = compare_subtrees()

	return answer

if __name__ == "__main__":
	import binary_tree
	tree = binary_tree.construct_binary_tree()
	print duplicate_subtree(tree)
