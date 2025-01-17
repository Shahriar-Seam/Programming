from sortedcontainers import SortedList

def count_good_subarrays(n, a):
    count = 0
    
    for start in range(n):
        freq = [0] * 11  # frequency array for numbers 1 to 10
        sorted_subarray = SortedList()  # Maintain a sorted list of the current subarray
        
        for end in range(start, n):
            num = a[end]
            freq[num] += 1
            sorted_subarray.add(num)
            length = end - start + 1
            
            if length % 2 == 1:  # odd length
                median = sorted_subarray[length // 2]
                count += 1  # every odd length subarray is good
            else:  # even length
                median1 = sorted_subarray[length // 2 - 1]
                median2 = sorted_subarray[length // 2]
                if median1 == median2:
                    count += 1
    
    return count

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])
    results = []
    index = 1
    for _ in range(t):
        n = int(data[index])
        a = list(map(int, data[index + 1].split()))
        index += 2
        good_subarray_count = count_good_subarrays(n, a)
        results.append(good_subarray_count)
    
    print('\n'.join(map(str, results)))

if __name__ == '__main__':
    main()
