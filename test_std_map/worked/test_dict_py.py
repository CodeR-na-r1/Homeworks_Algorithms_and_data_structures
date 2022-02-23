import time, sys

data = {}
max_count = pow(10, 7)
i = key = 1
in_file = open("data_out_py.txt", 'w')
start = time.time()
while i <= max_count:

    while key <= i:
        data[key] = key
        key += 1

    in_file.write(str(i) + " " + str(time.time() - start) + " " + str(sys.getsizeof(data)) + '\n')
    print(str(i) + " " + str(time.time() - start) + " " + str(sys.getsizeof(data)) + '\n')
    i *= 10

in_file.close()