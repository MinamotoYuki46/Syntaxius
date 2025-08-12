def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:
	a, b = matrix[0]
	c, d = matrix[1]

	trace = a + d
	det = a * d - b * c

	discriminant = (trace ** 2 - 4 * det) ** .5
	lambda1 = (trace + discriminant) / 2
	lambda2 = (trace - discriminant) / 2

	return [lambda1, lambda2]


if __name__ == "__main__":
	matrix = [[2, 1], [1, 2]]

	print(calculate_eigenvalues(matrix))
	print(calculate_eigenvalues([[4, -2], [1, 1]]))