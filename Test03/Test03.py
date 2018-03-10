## Created by group
# MTRE2610 Test 3


######################## Part 1 ############################
def partone():
    import numpy
    print('\nQuestion 1')
    def fib(lowerbound, upperbound):
        x = 0
        y = 1
        while x <= upperbound:
            if (x >= lowerbound):
                yield x
            x, y = y, x + y

    startNumber = 1
    endNumber = 4000
    fibs = []
    for fib_sequence in fib(startNumber, endNumber):
        fibs.append(fib_sequence)
    print("And the next to last number is... ",fibs[-2])
    print("And the last number is... ",fibs[-1])


######################## Part 2 ############################
def parttwo():
    import random
    import numpy as np
    import matplotlib.cm
    import matplotlib.pyplot as plt
    import matplotlib.animation as anim
    from PIL import Image
    print("\nQuestion 2")
    img = np.array(Image.open("stinkBug.png", mode="r"))
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            if img[i,j] < 0.39*255 and img[i,j] > 0.1*255:
                img[i,j] = 0
            else:
                img[i,j]=  1
    plt.imshow(img, cmap=matplotlib.cm.Greys_r)
    plt.show()

    


######################## Part 3 ############################
def partthree():
    print('\nProblem 3')
    import numpy as np
    import matplotlib.pyplot as plot
    from mpl_toolkits.mplot3d import Axes3D

    print('Problem 3 - see figure 3')
    x,y = np.meshgrid(np.linspace(-5,5,300),np.linspace(0,3,300))
    z = np.sin(x)*np.cos(y)
    z[np.power(y,2) < 4-np.power(x,2)] = float('nan')
    fig = plot.figure(3)
    ax = fig.gca(projection='3d')
    ax.plot_surface(x,y,z)
    ax.set_aspect('equal')
    ax.set_xlim(-5,5)
    ax.set_ylim( 0,3)
    ax.set_zlim(-1,1)
    plot.show()

######################## Part 4 ############################
def partfour():
    import random
    import numpy as np
    import matplotlib.cm
    import matplotlib.pyplot as plt
    import matplotlib.animation as anim
    from PIL import Image
    print('\nQuestion 4')
    print('calculating things...')
    def y(x):
        return np.sqrt(1-x**2)
    inside = 0
    outside = 0
    for i in range(1000000):
        if random.uniform(0, 1) <= y(random.uniform(0, 1)):
            inside += 1
        else:
            outside += 1
    print(inside/(outside + inside)*4)



if __name__ == "__main__":
    partone()
    parttwo()
    partthree()
    partfour()