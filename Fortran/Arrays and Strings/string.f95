program string
    implicit none

    character(len=30) :: first_name
    character(len=30) :: last_name
    character(61) :: full_name

    first_name = 'Ibnul Abrar Shahriar'
    last_name = 'Seam'

    full_name = first_name//' '//last_name

    print *, full_name
    
end program string