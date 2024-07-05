program subroutine
    implicit none

    integer :: n
    integer, allocatable :: A(:,:)

    read(*, *) n

    allocate(A(n, n))

    read (*, *) A(:,:)

    call print_matrix(n, A)

    contains

    subroutine print_matrix(size, Arr)
        integer, intent(in) :: size
        integer, intent(in) :: Arr(n,n)
        integer :: i

        do i = 1, size, 1
            print *, Arr(i, 1:n)
        end do

    end subroutine print_matrix
    
end program subroutine