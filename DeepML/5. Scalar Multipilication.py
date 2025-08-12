def scalar_multiply(matrix: list[list[int|float]], scalar: int|float) -> list[list[int|float]]:
	return [list(i * scalar for i in row) for row in matrix]


if __name__ == "__main__":
	matrix = [[1, 2], [3, 4]]
	scalar = 2

	print(scalar_multiply(matrix, scalar))