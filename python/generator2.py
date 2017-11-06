#! /usr/bin/env python3
def fib(n):
	N,N_1,i = 0,1,0
	while i < n: 
		yield N
		N_1, N = N, N + N_1
		i = i + 1
	return 'done'


Input = input('please input max: ')

f = fib(int(Input))

for x in f:
	print(x)

Input = input('please input max: ')
ff = fib(int(Input))
while True: 
	try: 
		x = next(ff)
		print('ff: ', x)
	except StopIteration as e:
		print('Genrator return value: ', e.value)
		break


