#!/usr/bin/env python
#-- https://www.clear.rice.edu/comp130/12spring/editdist/
#--http://www.youtube.com/watch?v=CB425OsE4Fo

def lev(a, b):
    """Recursively calculate the Levenshtein edit distance between two strings, a and b.
    Returns the edit distance.
    """
    if("" == a): 
        return len(b)   # returns if a is an empty string
    if("" == b): 
        return len(a)   # returns if b is an empty string
    # Note: True=1 and False=0 when adding a boolean to an integer
    return min(lev(a[:-1], b[:-1])+(a[-1] != b[-1]), lev(a[:-1], b)+1, lev(a, b[:-1])+1)

import sys
    
#print lev('mohan', 'morhan')

print lev( sys.argv[1], sys.argv[2] );
