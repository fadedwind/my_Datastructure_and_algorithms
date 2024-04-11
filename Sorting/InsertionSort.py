def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def insertion_sort(A, n):
	# Traverse the list or array from index 1 to n-1.
	for i in range(1, n):
		j = i
		while j > 0 and A[j-1] > A[j]:
			swap(A, j, j - 1)
			j -= 1
		# Insert key at the correct position in the list or array.

# Testing
if __name__ == "__main__":

	import numpy as np

	# Repeating terms. 
	list1 = [11, 1, 51, 1, 5, 3]
	list1test = list(list1)
	insertion_sort(list1, len(list1))
	print(list1)
	print(list1 == sorted(list1test))

	# Empty list should return empty list. 
	list2 = []
	insertion_sort(list2, len(list2))
	print(list2)
	print(list2 == [])

	# Negative number. 
	list3 = [1, 1, -5, 6]
	list3test = list(list3)
	insertion_sort(list3, len(list3))
	print(list3)
	print(list3 == sorted(list3test))

	# Float and int, testing numpy array. 
	array1 = np.array([11, -4, 20, 15, 13.5, -20])
	array1test = np.copy(array1)
	insertion_sort(array1, len(array1))
	print(array1)
	print(np.array_equal(array1, np.sort(array1test)))

	# Already sorted array. 
	array2 = np.array(range(50))
	array2test = np.copy(array2)
	insertion_sort(array2, len(array2))
	print(array2)
	print(np.array_equal(array2, np.sort(array2test)))

	# Array in reversed sorted order. 
	array3 = np.arange(50, 0, -5)
	array3test = np.copy(array3)
	print("Before sorting: ", end = '')
	print(array3)
	insertion_sort(array3, len(array3))
	print("After sorting: ", end = '')
	print(array3)
	print(np.array_equal(array3, np.sort(array3test)))

	# Large array. 
	array4 = np.random.randint(-5000, 5000, size=1000)
	array4test = np.copy(array4)
	print("Before sorting: ", end = '')
	print(array4)
	insertion_sort(array4, len(array4))
	print("After sorting: ", end = '')
	print(array4)
	print(np.array_equal(array4, np.sort(array4test)))
