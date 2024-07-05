program array_of_strings
    implicit none

    character(len=15), dimension(2) :: keys, vals

    keys = [character(len=15) :: 'user', 'dbname']
    vals = [character(len=15) :: 'Seam', 'mathematician']

    call show(keys, vals)

    contains

    subroutine show(akeys, avals)
        character(len=*), intent(in) :: akeys(:), avals(:)
        integer                      :: i

        do i = 1, size(akeys)
            print *, trim(akeys(i)), ": ", trim(avals(i))
        end do

    end subroutine show
    
end program array_of_strings