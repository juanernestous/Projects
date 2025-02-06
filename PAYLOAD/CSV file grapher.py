# Knights Experimental Rocketry
# Juan Ernesto Leon
# May 4, 2022

import matplotlib.pyplot as plt
import csv

# csv file name
filename = "output.csv"

with open(filename, 'r') as csvfile:
    
    csvreader = csv.reader(csvfile)
    
    # extracting each row as a list into a list
    rows = []
    for row in csvreader:
        rows.append(row)


plt.title("Force Over Time", fontsize='16')	#title


count = 0
for x in rows:
    plt.scatter(float(rows[count][0]),float(rows[count][1]),color='purple') # creates scatter plot

    count +=1

plt.xlabel("Time (Seconds)",fontsize='13', color = 'blue')	#adds a label in the x axis
plt.ylabel("Force (Newtons)",fontsize='13', color = 'red')	#adds a label in the y axis
plt.savefig('CSV scatter plot.png')	#saves the figure in the present directory
plt.grid()	#shows a grid under the plot
plt.show()
