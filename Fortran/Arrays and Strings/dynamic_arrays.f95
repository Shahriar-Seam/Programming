program dynamic_arrays
    implicit none

    integer, allocatable :: array1(:)
    integer, allocatable :: array2(:,:)

    allocate(array1(10))
    allocate(array2(2,2))

    array1(:) = 0
    array2(:,:) = 1

    print *, "before deallocation"
    print *, array2(:,:)
    
    deallocate(array1)
    deallocate(array2)

    print *, "after deallocation"
    print *, array2(:,:)
    
end program dynamic_arrays