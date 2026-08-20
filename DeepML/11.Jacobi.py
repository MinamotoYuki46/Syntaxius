import numpy as np

def solve_jacobi(A: np.ndarray, b: np.ndarray, n: int) -> list:
    A = np.asarray(A, dtype=np.float64)
    b = np.asarray(b, dtype=np.float64).ravel()

    diag_A = np.diag(A)
    R = A - np.diag(diag_A)

    x = np.zeros_like(b)

    for _ in range(n):
        x = (b - (R @ x)) / diag_A

    return x.tolist()
