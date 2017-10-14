#! /usr/bin/env python3
def odd(): 
	for i in range(100):
		print('step ', i)
		yield i

o = odd()
while True:
	i = input('input \'n\' for next step ')
	if i == 'n':
		print('input is n')
		next(o)
	elif i =='q':
		break
