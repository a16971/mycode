#! /usr/bin/env python3
def odd(n): 
	for i in range(n):
		print('step ', i)
		yield i

o = odd(10)
while True:
	i = input('input \'n\' for next step ')
	if i == 'n':
		print('input is n')
		next(o)
	elif i =='q':
		break
