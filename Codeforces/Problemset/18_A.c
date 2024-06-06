#include <stdio.h>

int main()
{
    int x1, x2, x3, y1, y2, y3;
    int d1, d2, d3, temp;

    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
    d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));

    if (d1 > d2) {
        temp = d1;
        d1 = d2;
        d2 = temp;
    }
    if (d2 > d3) {
        temp = d3;
        d3 = d2;
        d2 = temp;
    }
    if (d1 > d2) {
        temp = d1;
        d1 = d2;
        d2 = temp;
    }

    if (d1 + d2 == d3) {
        printf("RIGHT\n");
    }

    else {
        d1 = ((x1 - x2 - 1) * (x1 - x2 - 1)) + ((y1 - y2) * (y1 - y2));
        d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
        d3 = ((x1 - x3 - 1) * (x1 - x3 - 1)) + ((y1 - y3) * (y1 - y3));

        if (d1 > d2) {
            temp = d1;
            d1 = d2;
            d2 = temp;
        }
        if (d2 > d3) {
            temp = d3;
            d3 = d2;
            d2 = temp;
        }
        if (d1 > d2) {
            temp = d1;
            d1 = d2;
            d2 = temp;
        }

        if (d1 + d2 == d3) {
            printf("ALMOST\n");
        }
        else {
            d1 = ((x1 - x2 - 1) * (x1 - x2 - 1)) + ((y1 - y2) * (y1 - y2));
            d2 = ((x3 - x2 - 1) * (x3 - x2 - 1)) + ((y3 - y2) * (y3 - y2));
            d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));

            if (d1 > d2) {
                temp = d1;
                d1 = d2;
                d2 = temp;
            }
            if (d2 > d3) {
                temp = d3;
                d3 = d2;
                d2 = temp;
            }
            if (d1 > d2) {
                temp = d1;
                d1 = d2;
                d2 = temp;
            }

            if (d1 + d2 == d3) {
                printf("ALMOST\n");
            }
            else {
                d1 = ((x1 - x2 + 1) * (x1 - x2 + 1)) + ((y1 - y2) * (y1 - y2));
                d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
                d3 = ((x1 - x3 + 1) * (x1 - x3 + 1)) + ((y1 - y3) * (y1 - y3));

                if (d1 > d2) {
                    temp = d1;
                    d1 = d2;
                    d2 = temp;
                }
                if (d2 > d3) {
                    temp = d3;
                    d3 = d2;
                    d2 = temp;
                }
                if (d1 > d2) {
                    temp = d1;
                    d1 = d2;
                    d2 = temp;
                }

                if (d1 + d2 == d3) {
                    printf("ALMOST\n");
                }
                else {
                    d1 = ((x1 - x2 + 1) * (x1 - x2 + 1)) + ((y1 - y2) * (y1 - y2));
                    d2 = ((x3 - x2 + 1) * (x3 - x2 + 1)) + ((y3 - y2) * (y3 - y2));
                    d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));

                    if (d1 > d2) {
                        temp = d1;
                        d1 = d2;
                        d2 = temp;
                    }
                    if (d2 > d3) {
                        temp = d3;
                        d3 = d2;
                        d2 = temp;
                    }
                    if (d1 > d2) {
                        temp = d1;
                        d1 = d2;
                        d2 = temp;
                    }

                    if (d1 + d2 == d3) {
                        printf("ALMOST\n");
                    }
                    else {
                        d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
                        d2 = ((x3 - x2 - 1) * (x3 - x2 - 1)) + ((y3 - y2) * (y3 - y2));
                        d3 = ((x1 - x3 - 1) * (x1 - x3 - 1)) + ((y1 - y3) * (y1 - y3));

                        if (d1 > d2) {
                            temp = d1;
                            d1 = d2;
                            d2 = temp;
                        }
                        if (d2 > d3) {
                            temp = d3;
                            d3 = d2;
                            d2 = temp;
                        }
                        if (d1 > d2) {
                            temp = d1;
                            d1 = d2;
                            d2 = temp;
                        }

                        if (d1 + d2 == d3) {
                            printf("ALMOST\n");
                        }
                        else {
                            d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
                            d2 = ((x3 - x2 + 1) * (x3 - x2 + 1)) + ((y3 - y2) * (y3 - y2));
                            d3 = ((x1 - x3 + 1) * (x1 - x3 + 1)) + ((y1 - y3) * (y1 - y3));

                            if (d1 > d2) {
                                temp = d1;
                                d1 = d2;
                                d2 = temp;
                            }
                            if (d2 > d3) {
                                temp = d3;
                                d3 = d2;
                                d2 = temp;
                            }
                            if (d1 > d2) {
                                temp = d1;
                                d1 = d2;
                                d2 = temp;
                            }

                            if (d1 + d2 == d3) {
                                printf("ALMOST\n");
                            }
                            else {
                                d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2 - 1) * (y1 - y2 - 1));
                                d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2 - 1) * (y3 - y2 - 1));
                                d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));

                                if (d1 > d2) {
                                    temp = d1;
                                    d1 = d2;
                                    d2 = temp;
                                }
                                if (d2 > d3) {
                                    temp = d3;
                                    d3 = d2;
                                    d2 = temp;
                                }
                                if (d1 > d2) {
                                    temp = d1;
                                    d1 = d2;
                                    d2 = temp;
                                }

                                if (d1 + d2 == d3) {
                                    printf("ALMOST\n");
                                }
                                else {
                                    d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2 + 1) * (y1 - y2 + 1));
                                    d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2 + 1) * (y3 - y2 + 1));
                                    d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));

                                    if (d1 > d2) {
                                        temp = d1;
                                        d1 = d2;
                                        d2 = temp;
                                    }
                                    if (d2 > d3) {
                                        temp = d3;
                                        d3 = d2;
                                        d2 = temp;
                                    }
                                    if (d1 > d2) {
                                        temp = d1;
                                        d1 = d2;
                                        d2 = temp;
                                    }

                                    if (d1 + d2 == d3) {
                                        printf("ALMOST\n");
                                    }
                                    else {
                                        d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2 - 1) * (y1 - y2 - 1));
                                        d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
                                        d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3 - 1) * (y1 - y3 - 1));

                                        if (d1 > d2) {
                                            temp = d1;
                                            d1 = d2;
                                            d2 = temp;
                                        }
                                        if (d2 > d3) {
                                            temp = d3;
                                            d3 = d2;
                                            d2 = temp;
                                        }
                                        if (d1 > d2) {
                                            temp = d1;
                                            d1 = d2;
                                            d2 = temp;
                                        }

                                        if (d1 + d2 == d3) {
                                            printf("ALMOST\n");
                                        }
                                        else {
                                            d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2 + 1) * (y1 - y2 + 1));
                                            d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
                                            d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3 + 1) * (y1 - y3 + 1));

                                            if (d1 > d2) {
                                                temp = d1;
                                                d1 = d2;
                                                d2 = temp;
                                            }
                                            if (d2 > d3) {
                                                temp = d3;
                                                d3 = d2;
                                                d2 = temp;
                                            }
                                            if (d1 > d2) {
                                                temp = d1;
                                                d1 = d2;
                                                d2 = temp;
                                            }

                                            if (d1 + d2 == d3) {
                                                printf("ALMOST\n");
                                            }
                                            else {
                                                d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
                                                d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2 - 1) * (y3 - y2 - 1));
                                                d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3 - 1) * (y1 - y3 - 1));

                                                if (d1 > d2) {
                                                    temp = d1;
                                                    d1 = d2;
                                                    d2 = temp;
                                                }
                                                if (d2 > d3) {
                                                    temp = d3;
                                                    d3 = d2;
                                                    d2 = temp;
                                                }
                                                if (d1 > d2) {
                                                    temp = d1;
                                                    d1 = d2;
                                                    d2 = temp;
                                                }

                                                if (d1 + d2 == d3) {
                                                    printf("ALMOST\n");
                                                }
                                                else {
                                                    d1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
                                                    d2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2 + 1) * (y3 - y2 + 1));
                                                    d3 = ((x1 - x3) * (x1 - x3)) + ((y1 - y3 + 1) * (y1 - y3 + 1));

                                                    if (d1 > d2) {
                                                        temp = d1;
                                                        d1 = d2;
                                                        d2 = temp;
                                                    }
                                                    if (d2 > d3) {
                                                        temp = d3;
                                                        d3 = d2;
                                                        d2 = temp;
                                                    }
                                                    if (d1 > d2) {
                                                        temp = d1;
                                                        d1 = d2;
                                                        d2 = temp;
                                                    }

                                                    if (d1 + d2 == d3) {
                                                        printf("ALMOST\n");
                                                    }
                                                    else {
                                                        printf("NEITHER\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// Doesn't work :P