program variables
    implicit none

    ! declaration
    integer :: age
    real :: pi
    complex :: frequency
    character :: initial
    logical :: isOkay

    ! assignment
    age = 21
    pi = 3.1415927
    frequency = (1.0, -0.5)
    initial = 'S'
    isOkay = .false.

    ! standard output
    print *, 'the value of age (integer) is: ', age
    print *, 'the value of pi (real) is: ', pi
    print *, 'the value of frequency (complex) is: ', frequency
    print *, 'the value of initial (character) is: ', initial
    print *, 'the value of isOkay (logical) is: ', isOkay
    
end program variables