program INOUTEST
    implicit none

    integer :: n
    integer :: a
    integer :: b
    integer :: i

    read (*, *) n

    do i = 0, n
        read (*, *) a, b

        print *, a * b

    end do
    
end program INOUTEST

! TLE