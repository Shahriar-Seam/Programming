program arithmetic
    implicit none

    real :: pi
    real :: radius
    real :: height
    real :: area
    real :: volume

    pi = 3.1415927

    print *, 'Enter cylinder base radius: '
    read (*, *) radius

    print *, 'Enter cylinder height: '
    read (*, *) height

    area = pi * radius ** 2
    volume = area * height

    print *, 'Radius: ', radius
    print *, 'Height: ', height
    print *, 'Base area: ', area
    print *, 'Volume: ', volume
    
end program arithmetic