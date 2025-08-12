def calculate_matrix_mean(matrix: list[list[float]], mode: str) -> list[float]:
	row, col = len(matrix), len(matrix[0])

	if mode == "row":
		return [sum(r) / col for r in matrix]
	
	elif mode == "column":
		return [sum(matrix[r][c] for r in range(row)) / row for c in range(col)]



if __name__ == "__main__":
	matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
	mode = 'column'

	print(calculate_matrix_mean(matrix, mode))