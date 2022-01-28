#!/usr/bin/python3
"""Log parsing"""

import sys


def printValues(calls, file_size):
    codes = [200, 301, 400, 401, 403, 404, 405, 500]
    print("File size: {}".format(file_size))
    for i in range(len(codes)):
        if calls[i] > 0:
            print("{}: {}".format(codes[i], calls[i]))


codes = [200, 301, 400, 401, 403, 404, 405, 500]
calls = [0, 0, 0, 0, 0, 0, 0, 0]
lines = 0
file_size = 0
try:
    for line in sys.stdin:
        try:
            lines += 1
            split = line.split()
            file_size += int(split[-1])
            code = int(split[-2])
            calls[codes.index(code)] += 1
            if lines == 10:
                lines = 0
                printValues(calls, file_size)
        except Exception:
            continue
except Exception:
    pass
finally:
    printValues(calls, file_size)
