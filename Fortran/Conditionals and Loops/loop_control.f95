program loop_control
    implicit none

    integer :: i

    do i = 1, 10, 1
        if (mod(20, i) == 0) then
            cycle
        end if
                  
        print *, i
    end do

    print *

    do i = 10, 0, -1
        if (i == 5) then
            exit
        end if
        
        print*, i
    end do
    
end program loop_control