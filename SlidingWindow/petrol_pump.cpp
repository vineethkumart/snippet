/* Given a petrol pump find if a tour is possible and return the first start point
 *
 * This is a sliding window, keep sliding up as long as you can travel. once you can't shrink window and travel again
 * return if there is an answer */



int travel(int gas[], int fuel[], int n)
{
    int p = gas[0] - cost[0];
    if (p < 0) return -1;


    int start = 0;
    int end = 1;

    while (start != end || p < 0) {
        while (start != end && p < 0) {
            // shrink
            p -= gas[start] - cost[start];
            start = (start + 1) %n;
            if (start == 0) return -1;
        }
        // grow window
        p += gas[end] - cost[end];
        end = (end + 1) % n;
    }

    return start;
}
