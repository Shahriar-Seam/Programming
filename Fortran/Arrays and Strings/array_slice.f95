program array_slice
    implicit none

    integer :: i
    integer :: array1(10)
    integer :: array2(10, 10)

    array1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] ! Array constructor
    array1 = [(i, i = 1, 10)] ! Implied do loop constructor
    array1(:) = 0 ! set all elements to 0
    array1(1:5) = 1 ! set first five elements to 1
    array1(6:) = 2 ! set all elements after five to 2
    array2(:,:) = 9

    print *, array1(1:10:2) ! print out elements at odd indices
    print *, array2(:,1) ! print out the first column in a 2d array
    print *, array1(10:1:-1) ! print array in reverse
    
end program array_slice