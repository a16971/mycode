#!/usr/bin/env python3
def triagle():
	ret = [1];
	while True:
		yield ret
		ret.append(0);
		ret = [ret[i-1] + ret[i] for i in range(len(ret))]
n = 0
t = triagle()
for x in t: 
	print(x)
	n = n + 1
	if n > 10:
		break
	
