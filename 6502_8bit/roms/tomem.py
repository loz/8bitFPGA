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
	counter = 0
	line = []
	str = ""
	for ch in block:
		line.append("{:02x}".format(ord(ch)))
		if len(line) == 32:
			str += " ".join(line) + "\n"
			line = []
	str += " ".join(line)
	print str
