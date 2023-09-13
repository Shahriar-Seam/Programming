#include <stdio.h>

int main()
{
    // Declare variables
    int t, i, r1, r2, B, ball_played;
    double crr, rrr;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Get total run of opponent, r1; total run of own team, r2; balls left, B
        scanf("%d %d %d", &r1, &r2, &B);

        // 50 over match. Balls left = B. So, Balls played = 50 * 6 - B = 300 - B
        ball_played = 300 - B;
        // Current run rate = run of own team / overs played = run of own team / (balls played / 6) = (r2 / balls PLayed) * 6
        crr = ( (double) r2 / ball_played) * 6; // r2 needed typecasting to show correct run rate 
        
        if (r1 < r2) rrr = 0.00; // If our run is more than the opponent than we have already won. So, required runs = 0. Hence, required run rate = 0
        else {
            rrr = ((double) (r1 + 1 - r2) / B) * 6; // We need at least 1 run more than opponent to win.
        }

        // Print current and required run rate up to 2 decimal places
        printf("%0.2lf %0.2lf\n", crr, rrr);
    }

    return 0;
}

// Didn't thought about r1 < r2. So it showed wrong answer. Now it's fixed.