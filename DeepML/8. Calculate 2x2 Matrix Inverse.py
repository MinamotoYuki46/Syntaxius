def inverse_2x2(matrix: list[list[float]]):
	a, b = matrix[0]
	c, d = matrix[1]

	det = a * d - b * c;

	if det == 0:
		return None
	
	return [[1/det * d, 1/det * -b], [1/det * -c, 1/det * a]]

if __name__ == "__main__":
	matrix = [[4, 7], [2, 6]]

	print(inverse_2x2(matrix))