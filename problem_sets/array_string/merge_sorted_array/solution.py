

def merge(nums1, m, nums2, n):
    p1 = m - 1
    p2 = n - 1
    p3 = (m + n) - 1

    while p1 >= 0 and p2 >= 0:
        if nums2[p2] > nums1[p1]:
            nums1[p3] = nums2[p2]
            p2 -= 1
        elif nums1[p1] > nums2[p2]:
            nums1[p3] = nums1[p1]
            p1 -= 1
        p3 -= 1

    while p2 > 0:
        nums1[p3] = nums2[p2]
        p2 -= 1
        p3 -= 1
        
    return nums1


def main():
    m1 = [1,2,3,0,0,0]
    m = 3

    n1 = [4,5,6]
    n = 3

    merged = merge(m1, m, n1, n)
    print(merged)


if __name__=='__main__':
    main()