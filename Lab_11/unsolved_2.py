def heapify(arr, n, i):
    largest = i
    l_child = 2 * i + 1
    r_child = 2 * i + 2

    if l_child < n and arr[l_child] > arr[largest]:
        largest = l_child

    if r_child < n and arr[r_child] > arr[largest]:
        largest = r_child

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

if __name__ == '__main__':
    array = [4,2,5,1,7,3,6]
    print("Original array:", array)
    heap_sort(array)
    print("Sorted array:", array)