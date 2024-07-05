program matrix_multiplication
    implicit none

    integer :: m, n, p
    integer, allocatable :: A(:,:), B(:,:), C(:,:)
    integer :: i, j, k

    ! read matrix dimension
    read (*, *) m, n, p

    ! allocate memory for the matrices
    allocate(A(m, n))
    allocate(B(n, p))
    allocate(C(m, p))

    C(:,:) = 0

    ! read elements of the matrices
    do i = 1, m, 1
        read(*, *) A(i, 1:n)
    end do

    do i = 1, n, 1
        read(*, *) B(i, 1:m)
    end do

    ! print the arrays
    do i = 1, m, 1
        print *, A(i, 1:n)
    end do

    print *

    do i = 1, n, 1
        print *, B(i, 1:m)
    end do

    print *

    ! print the product of matrix A and B
    ! using built in function
    print *, transpose(matmul(A, B))

    print *

    ! manually
    do i = 1, m, 1
        do j = 1, p, 1
            do k = 1, n, 1
                C(i, j) = C(i, j) + A(i, k) * B(k, j)
            end do
        end do
    end do

    do i = 1, m, 1
        print *, C(i, 1:p)
    end do

    ! free the allocated memory
    deallocate(A)
    deallocate(B)
    
end program matrix_multiplication