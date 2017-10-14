#!/usr/bin/env python3
array1 = [1,3, 4, 5,6,6]
array2 = [1,2,4,5,6,7,8,9,22]

def intersection(a1, a2):
	ret = set([])
	s = set(a1)
	for x in a2: 
		if x in s: 
			ret.add(x)
	return ret
print('intersection:',intersection(array1,array2))
while True:
	a1 =[int(x) for x in input('please input array1: ').split()]
	a2 =[int(x) for x in input('please input array2: ').split()]
	print('array1: %s',a1)
	print('array2: %s',a2)
	print('intersection of array1 and array2 is: ')
	print(intersection(a1,a2))


