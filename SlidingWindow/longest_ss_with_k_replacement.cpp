/*
 * Given a string S and a k. you can make k character replacement
 * Find the longest substring of same characters
*/

/* This is good problem to understand.
 *
 * Here Think of bruteforce as always:
 * Get a substring and how will you replace things
 * Get a substring: and make count of each char and (window_len - max_freq_of_a_char) is the replacement you need to make window_len valid.
 * so make sure thats <= k, if so you got a valid window.remember the length
 * Slide as long as window is valid
 * shrink once you get invalid window */

class Solution {
    public:
        int characterReplacement(string s, int k) {
            if (s.empty()) return 0;
            int f[256];
            int n = s.size();
            memset(f, 0, sizeof(f));

            int start = 0;
            int len = 0;
            int mf = 0;


            auto valid = [&](int end, int start, int mf) -> bool
            {
                int w = end-start+1;
                /*
                int mf(0);
                for (int i = 0; i < 256; i++) {
                    if (f[i] > mf) mf = f[i];
                }
                */

                return (w - mf <= k);
            };


            for (int i = 0; i < n; i++) {
                f[s[i]]++;
                mf = max(mf, f[s[i]]);

                while (!valid(i, start, mf)) {
                    // slide the window
                    f[s[start]]--;
                    start++;
                }

                len = max(len, i-start+1);
            }

            return len;
        }
};



/* this is linear in time.
 * You can make it more efficient as:
 * use a mfreq to store the max frequency and update it on change
 * on shrinking technically you need to update that with next max, but you can skip this update as the window that you are going to get wont be bigger than existing valid max window
 * */
