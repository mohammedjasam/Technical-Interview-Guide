# -*- coding: UTF-8 -*-
'''
	A dictionary is a type of data structure that is supported natively in all major interpreted languages
	such as JavaScript, Python, Ruby and PHP, where it’s known as an Object, Dictionary, Hash and Array,
	respectively. In simple terms, a dictionary is a collection of unique keys and their values. The values can 
	typically be of any primitive type (i.e an integer, boolean, double, string etc) or other dictionaries 
	(dictionaries can be nested).

	Given a dictionary dict, write a function flattenDictionary that returns a flattened version of it.

	input:  dict = {
            Key1 : 1,
            Key2 : {
                a : 2,
                b : 3,
                c : {
                    d : 3,
                    e : 1
                }
            }
        }

	output: {
            Key1: 1,
            Key2.a: 2,
            Key2.b : 3,
            Key2.c.d : 3,
            Key2.c.e : 1
        }

'''

# Time-complexity: O(n) where n will be numder of keys in the input dictionary
# if you represent all the keys in a tree
#  O(N) since the output dictionary is asymptotically as big as the input dictionary. 
def flattendict(s, input, output):
	for key, value in input.iteritems():
		new_key = s + key
		if type(value) == type({}):
			flattendict(new_key + ".", value, output)
		else:
			output[new_key] = value

if __name__ == "__main__":
	input = {
		"Key1" : 1,
		"Key2"  : {
			"a" : 2,
			"b" : 3,
			"c" : {
				"d" : 3,
				"e" : 1
			}
		},
		"Key3": 4
	}

	output = {}
	flattendict("", input, output)
	print output
