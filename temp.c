#include <stdio.h>

int main() {
    unsigned long long int ans = 0;
    unsigned long long int eye, mouth, body, min;

    scanf("%llu %llu %llu", &eye, &mouth, &body);

    if (eye < mouth && eye < body) {
        min = eye;
    }
    else if (mouth < eye && mouth < body) {
        min = mouth;
    }
    else {
        min = body;
    }

    eye -= min;
    mouth -= min;
    body -= min;

    ans += min;
    ans += ((eye / 2) < body) ? (eye / 2) : body;

    printf("%llu", ans);

    return 0;
}
