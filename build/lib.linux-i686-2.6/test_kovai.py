#!/usr/bin/env python
import kovai
import sys

#print kovai.editdistance('coimbatore', 'coimbathore')


def fuzzyscore(s1, s2):
	return  [ 100.0 * ( 1.0 -  ( kovai.editdistance(s1,s2)/( 1.0 * len(s2) ) ) ), 100.0 * ( 1.0 -  ( kovai.editdistance(s1,s2)/( 1.0 * len(s1) ) ) ), ]

if len(sys.argv) >= 3:
  print 'Edit distance of: ' , sys.argv[1], 'and' , sys.argv[2], 'is :' ,kovai.editdistance(sys.argv[1], sys.argv[2])
else:
  s1 = raw_input("Enter first string:")
  s2 = raw_input("Enter second string:")
  print 'Edit distance of: ' , s1, 'and' , s2, 'is :' ,kovai.editdistance(s1, s2)
  print fuzzyscore(s1, s2)
