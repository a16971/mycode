#!/usr/bin/env python3
array1 = [1,3,5,5,5,7,9]
array2 = [1,3,4,2,4,6,8,9]


def intersection(array1, array2):

	ret = []
	s = set(array1)
	for x in array2: 
		if x in s: 
			ret.append(x)
	return ret

print(intersection(array1, array2))
