program loop
    implicit none

    integer :: i

    do i = 1, 10, 2
        print *, i
    end do

    i = 1

    print *

    do while (i < 40)
        print *, i
        i = i + 1
    end do
    
end program loop