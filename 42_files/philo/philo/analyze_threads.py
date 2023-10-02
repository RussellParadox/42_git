"""
    A little script to show threads launch time difference
    (duration between launch of thread n and thread n + 1)
    depending on the threads launched quantity
"""

import sys
import os
import matplotlib.pyplot as plt

def init_differences(delays):
    d = []
    for i in range(len(delays) - 1):
        d += [delays[i + 1] - delays[i]]
    return d

if (len(sys.argv) != 3):
    exit(0)

os.system('make test')

threads = range(0, int(sys.argv[1]))

t = sys.argv[1]
stream = os.popen('./generate_delay ' + t)
output = stream.read().strip().split('\n')

delays = [int(i) for i in output]
tltd = init_differences(delays)

p = 1
precision = int(sys.argv[2]) + 1
while (p < precision):
    stream = os.popen('./generate_delay ' + t)
    output = stream.read().strip().split('\n')
    
    delays = [int(i) for i in output]
    diff = init_differences(delays)
    for i in range(int(t)):
        tltd[i] = tltd[i] + diff[i]

    diff_mean = [(i / p) for i in tltd]

    plt.xlabel("Thread launched quantity")
    plt.ylabel(r"Launch time diff ($\mu$s)")
    plt.title("Launch time difference mean depending on the thread quantity")
    plt.clf()
    plt.plot(threads, tltd)

    p = p + 1
    plt.pause(0.01)
plt.show()
