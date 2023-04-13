#!/usr/bin/python

import sys,getopt

filename = None

opts,args = getopt.getopt(sys.argv[1:],'f:b:')
for o,a in opts:
	if o == '-f':
		filename = a

offset = 0
with open(filename,"rb") as f:
	block = f.read()
	str = ""
	for ch in block:
		str += hex(ord(ch))+" "
	print str
