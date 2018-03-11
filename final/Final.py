##
# Hello, this is the python part of the final.
# Code by Team Red
#
import numpy as np

def problem5():
     from scipy.spatial import distance_matrix # this is being resourceful, not cheating ;)
     print("\nThis is problem 5.")
     x = [[4,2], [-3,5], [0,0], [5,3], [-2,-4]]
     mat = distance_matrix(x, x)
     print("This is the distance matrix.")
     print(mat)
     maxdist = np.unravel_index(np.argmax(mat), mat.shape)
     print("Points", x[maxdist[0]], 'and', x[maxdist[1]], 'are the farthest apart.')

def problem6():
    print("\nThe answer to problem 6 is c.\n")

if __name__ == "__main__":
    problem5()
    problem6()