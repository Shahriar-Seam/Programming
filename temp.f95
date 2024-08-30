program temp
    implicit none

    integer :: arr(635:639), i

    arr = [1, 2, 3, 4, 5]

    do i = 635, 639
        if ( arr(i) == 3 ) then
            print *, i
        end if        
    end do
    
end program temp