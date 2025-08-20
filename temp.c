#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main()
{
    system("tasklist");

    system("taskkill /IM chrome.exe /T /F");

    return 0;
}