#include <stdio.h>
 
#define Anonymous_HF __(a, n, i, m, a, t, e)
#define __(n, e, u, t, r, a, l) t##r##u##e
 
Anonymous_HF ()
{
    printf("%d\n", 8 & 7);
}