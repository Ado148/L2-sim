# Author:       Adam Pap
# Description:  This program reads the input data from the stdin and processes them.
#               It outputs the scatter plot of the plane points and saves it as plane_points.png

import sys
import os
import matplotlib.pyplot as plt
    
def input_data_processing(data): 
    # This function processes the input data and returns an array of tuples 
    # e.g. [('filename', 'group', x, y), ...]
    
    plane_points = []
    
    for line in data:
        try:
            
            file_name, group_coords = line.strip().split(' ', 1) # split the line by space and get the first element
            file_name = os.path.basename(file_name)
            group, group_coords = group_coords.split(':') # split the second element by space
            x, y = group_coords.split(',')
            plane_points.append((file_name, group, float(x), float(y)))
        except ValueError as err:
            print(f'Error occured while proccesing input data: {err}', file=sys.stdout)
            sys.exit(1)
    return plane_points
        
def plot_plane_points(plane_points):
    # This function plots the plane points and saves the plot as plane_points.png
    
    file_groups = {}
    
    fig, ax = plt.subplots()
    for point in plane_points:
        file_name = point[0]
        if file_name not in file_groups:
            file_groups[file_name] = []
        file_groups[file_name].append(point)
        
    for file_name, points in file_groups.items():
        x_coords = [point[2] for point in points]
        y_coords = [point[3] for point in points]
        ax.scatter(x_coords, y_coords, label=file_name) 
        for point in points:
            ax.annotate(f'{point[1]} ({point[2]}, {point[3]})', (point[2], point[3])) # annotate the points in the plane
                                                                                      # and also where to put them 
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_title('Scatter Plot of the Plane')
    ax.legend()

    plt.savefig('plane_points.png', bbox_inches='tight')


    
if __name__ == '__main__':
    data = sys.stdin.readlines()

    plane_points = input_data_processing(data)
    
    plot_plane_points(plane_points)
    print('Plot saved as plane_points.png.')
    
    sys.exit(0) # for the bash script
    
    