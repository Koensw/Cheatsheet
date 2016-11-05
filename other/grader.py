from subprocess import check_output as co
import sys, os
_, e, d, i, o = sys.argv # input <exe> <dir> <inp-ext> <out-ext>
for (_, _, fs) in os.walk(d): 
    for f in fs:
        if f[-len(i):] != i: continue
        out = [s.strip().decode() for s in co(e, stdin=open(os.path.join(d, f))).strip().splitlines()]
        exp = [s.strip() for s in open(os.path.join(d, f[:-len(i)]+o)).read().strip().splitlines()]
        
        print(f[:-len(i)], (exp == out)) 
    break
