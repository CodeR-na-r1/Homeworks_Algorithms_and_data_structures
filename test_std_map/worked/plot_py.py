import matplotlib.pyplot as plt, numpy as np

file_data_c = open("data.txt", 'r')
file_data_py = open("data_out_py.txt", 'r')

data_x_c = []
data_x_py = []
data_y_c = []
data_y_py = []

while True:
    bufer = file_data_c.readline()
    if bufer == "":
        break
    data_x_c.append(int(bufer.split(' ')[0]))
    data_y_c.append(float(bufer.split(' ')[1]))

file_data_c.close()

while True:
    bufer = file_data_py.readline()
    if bufer == "":
        break
    data_x_py.append(int(bufer.split(' ')[0]))
    data_y_py.append(float(bufer.split(' ')[1]))
    
file_data_py.close()

'''
print(data_x_c)
print(data_y_c)
print(data_x_py)
print(data_y_py)
'''

plt.figure()

plt.subplot(1, 2, 1)
plt.title("Dependence of the filling rate on the number of elements")
plt.xlabel('Quantity')
plt.ylabel('Filling rate')
plt.plot(data_x_c, data_y_c, label="C++", marker='o')
plt.plot(data_x_c, data_y_py, label="Python", marker='^')

plt.legend()

file_data_c = open("data.txt", 'r')
file_data_py = open("data_out_py.txt", 'r')

data_x_c = []
data_x_py = []
data_y_c = []
data_y_py = []

while True:
    bufer = file_data_c.readline()
    if bufer == "":
        break
    data_x_c.append(int(bufer.split(' ')[2]))
    data_y_c.append(int(bufer.split(' ')[0]))

file_data_c.close()

while True:
    bufer = file_data_py.readline()
    if bufer == "":
        break
    data_x_py.append(int(bufer.split(' ')[2]))
    data_y_py.append(int(bufer.split(' ')[0]))
    
file_data_py.close()

print(data_x_c)
print(data_y_c)
print(data_x_py)
print(data_y_py)

plt.subplot(1, 2, 2)
plt.title("The dependence of the size on the number of elements")
plt.xlabel('size')
plt.ylabel('number of elements')
plt.plot(data_x_c, data_y_c, label="C++", marker='*')
plt.plot(data_x_py, data_y_py, label="Python", marker='8')

plt.legend()
plt.show()