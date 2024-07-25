program float
    use, intrinsic :: iso_fortran_env, only: sp=>real32, dp=>real64, bleh=>real128

    implicit none

    real(sp) :: float32
    real(dp) :: float64
    real(bleh) :: float128

    float32 = 2 ** 30
    float64 = 2 ** 62_dp
    float128 = 2 ** 126_bleh

    print *, float32
    print *, float64
    print *, float128
    
end program float