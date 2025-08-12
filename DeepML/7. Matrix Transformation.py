import numpy as np

def transform_matrix(A: list[list[int|float]], T: list[list[int|float]], S: list[list[int|float]]):
	if (np.linalg.det(T) == 0 or np.linalg.det(S) == 0):
		return -1
	
	return np.linalg.inv(T) @ A @ S

if __name__ == "__main__":
	A = [[1, 2], [3, 4]]
	T = [[2, 0], [0, 2]]
	S = [[1, 1], [0, 1]]

	print(transform_matrix(A, T, S))

	print(transform_matrix(
		[[2, 3], [1, 4]], 
		[[3, 0], [0, 3]], 
		[[1, 1], [1, 1]]))