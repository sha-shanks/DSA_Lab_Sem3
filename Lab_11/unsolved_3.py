#used bubble sort as binary sort needs a sorted array to work :/
# or use the built in sort() function which sorts using timsort? ig
# usage: sort(array_name) #has no return

def bubbleSort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        
        if not swapped:
            break

def binarySearch(array, key):
    bubbleSort(array)
    left, right = 0, len(array) - 1

    while left <= right:
        mid = (left + right) // 2
        if array[mid] == key:
            return mid
        elif array[mid] < key:
            left = mid + 1
        else:
            right = mid - 1

    return -1;

if __name__ == "__main__":
    myArray = [4, 2, 7, 1, 9, 3, 6, 5]
    print("Given Array: ", myArray)
    keyEle = int(input("Enter the element to be searched for: "))
    index = binarySearch(myArray, keyEle)
    if index != -1:
        print(f"Element {keyEle} found in the array.")
    else:
        print(f"Element {keyEle} not found in the array.")