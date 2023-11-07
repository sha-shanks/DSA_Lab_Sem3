# Write a program ( in .py) to sort an array
# in descending order using extra variable and
# without using extra variable

# used bubble sorting with added optimisation (boolean swapped)

def sort_extra_var(arr):
    n = len(arr)
    swapped = False

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] < arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

                swapped = True
        
        if not swapped:
            break

def sort_no_extra_var(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] < arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        
        if not swapped:
            break

if __name__ == "__main__":
    array = [4,2,5,1,7,3,6] #input array using int(input(""))
    array_1 = array.copy()
    array_2 = array.copy()
    sort_extra_var(array_1)
    sort_no_extra_var(array_2)
    print("Original Array: ", array)
    print("Array sorted in descending order:")
    print("Using extra variable: ", array_1)
    print("Using no extra variable: ", array_2)