program matrix_multiplication
    implicit none

    integer :: m, n, p
    integer, allocatable :: A(:,:), B(:,:), C(:,:)

    read (*, *) m, n, p

    allocate(A(m, n))
    allocate(B(n, p))

    read(*, *) A(:,:)
    read(*, *) B(:,:)

    A = transpose(A)
    B = transpose(B)

    C = transpose(matmul(A, B))

    print *, C
    
end program matrix_multiplication