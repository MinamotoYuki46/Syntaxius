def matrixmul(a:list[list[int|float]],
              b:list[list[int|float]]):
	if (len(a[0]) != len(b)):
		return -1
	
	res = [[
		sum(x * y for x, y in zip(row_a, col_b)) 
			for col_b in zip(*b)] 
			for row_a in a
	]

	return res

if __name__ == "__main__":
	A = [[1,2],[2,4]]
	B = [[2,1],[3,4]]

	print(matrixmul(A, B))