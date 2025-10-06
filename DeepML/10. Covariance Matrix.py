import numpy as np

def calculate_covariance_matrix(vectors: list[list[float]]) -> list[list[float]]:
    arr = np.array(vectors)
    return np.cov(arr, rowvar=True)


if __name__ == "__main__":
    print("hello")
    a = [[1, 2, 3], [4, 5, 6]]
    print(calculate_covariance_matrix(a))