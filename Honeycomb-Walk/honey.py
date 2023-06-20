import numpy as np
from numpy.linalg import matrix_power
mat = [
    [0, 1, 1, 1, 1, 1, 1, ],
    [1, 0, 1, 0, 0, 0, 1, ],
    [1, 1, 0, 1, 0, 0, 0, ],
    [1, 0, 1, 0, 1, 0, 0, ],
    [1, 0, 0, 1, 0, 1, 0, ],
    [1, 0, 0, 0, 1, 0, 1, ],
    [1, 1, 0, 0, 0, 1, 0, ],
]

m = np.matrix(mat)
print(matrix_power(m, 3))