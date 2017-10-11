#!/usr/bin/env python3
# -*- coding: utf-8 -*-
print('........')
List = ["a", "b", "c","e"]
for x in List :
	print(x)
List.insert(0, "0")
List.insert(len(List), ['ff','gg'])
print(List)
Tuple = (1, 2, 3, 4, [5, 6])
print("tuple") 
print(Tuple)
Tuple[4][0] = 0
Tuple[4][1] = 0
print(Tuple)
while True :
	pwd = input("password:")
	if pwd == 'citrix' : 
		print('welcome')
		break
	else: 
		print('Wrong password, please input the correct password')



