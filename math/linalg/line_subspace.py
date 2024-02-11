import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the vector v (direction vector of the line)
v = np.array([1, 2, 3])

# Create scalar multiples of v
t = np.linspace(-10, 10, 100)
line = np.outer(t, v)

# Plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the line
ax.plot(line[:, 0], line[:, 1], line[:, 2], 'b', lw=2, label='Line subspace')

# Mark the origin
ax.scatter(0, 0, 0, color='k', label='Origin')

# Set labels
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.legend()

plt.show()