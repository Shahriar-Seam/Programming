module bleh
    implicit none
    
    integer :: n = 2

end module bleh

program scope
    implicit none

    real :: x

    block
        use bleh, only: n

        real :: y

        y = 2.0

        x = y ** n

        print *, y
    
    end block

    print *, x
    
end program scope