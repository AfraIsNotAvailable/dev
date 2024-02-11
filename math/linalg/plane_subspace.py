import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the vectors u and v (basis vectors of the plane)
u = np.array([1, 0, 0])
v = np.array([0, 1, 0])

# Create a grid of points in the u-v space
a = np.linspace(-10, 10, 10)
b = np.linspace(-10, 10, 10)
aa, bb = np.meshgrid(a, b)
plane = np.outer(aa, u) + np.outer(bb, v)

# Reshape for plotting
x = plane[:, 0].reshape(aa.shape)
y = plane[:, 1].reshape(bb.shape)
z = plane[:, 2].reshape(bb.shape)

# Plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the plane
ax.plot_surface(x, y, z, alpha=0.5, rstride=100, cstride=100, color='r', edgecolors='r', label='Plane subspace')

# Mark the origin
ax.scatter(0, 0, 0, color='k', label='Origin')

# Set labels
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')

# Set the aspect ratio to be equal
ax.set_box_aspect([1,1,1])  # Aspect ratio is 1:1:1

plt.show()