/* 
 * Longest substring without repeating characters
 * Input: "a abcd bw", Output: abcd
 * Start with bruteforce takes n3 time
 * Apply BUD - here unnecessary and duplicate work is there
 * sliding window:
 *  for each substring starting at i, grow until you dont have any duplicate, remember found in map
 *  once you get duplicate remember the result, increment i and start over - n2
 *
 *  Here again duplicate because you know from prev iteration that i to j no duplicates are there and the j+1 that you are getting you can start from prev location found and get in linear time*/


/*
 * This is linear in time, and shrinking of window is straight forward
 * questions like largest window with k unique/ k duplicate/ at most k etc., need a conditional shrinking from start to start'
 * the check of condition if we can do in constant time the algorithm is linear */

int lengthOfSs(string s)
{
    if (s.empty()) return 0;

    int start = 0;
    int m = 0;

    int found[256];
    memset(found, -1, sizeof(found));

    for (int i = 0; i < s.size(); i++) {
        // update start location with last found of this character + 1 for a valid window
        start = max(start, found[s[i]] + 1);
        m = max(m, i - start + 1);
        found[s[i]] = i;
    }

    return m;
}
