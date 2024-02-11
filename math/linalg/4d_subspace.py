import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

# Generate some random 4D data (for example, 100 points in R^4)
np.random.seed(42)
data = np.random.randn(100, 4)

# Initialize PCA to reduce to 2 dimensions
pca = PCA(n_components=2)

# Fit and transform the data
data_2d = pca.fit_transform(data)

# Plot the projected data
plt.scatter(data_2d[:, 0], data_2d[:, 1])
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.title('2D PCA projection of 4D data')
plt.grid(True)
plt.show()