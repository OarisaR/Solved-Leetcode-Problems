class Solution {
public:
    bool kmp(vector<int>& pattern, vector<int>& text) {
        int m = pattern.size();
        int n = text.size();
        if (m == 0)
            return true;
        if (m > n)
            return false;

        // Step 1: Build the LPS array
        // lps[i] = length of the longest proper prefix of
        // pattern[0...i] that is also a suffix.
        vector<int> lps(m, 0);

        int i = 1;
        int len = 0;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                // We found one more matching character
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Try a shorter prefix that could still match.
                    // Keep i unchanged and reuse previous LPS info.
                    len = lps[len - 1];
                } else {
                    // No matching prefix exists for this position
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search for the pattern in the text
        i = 0;     // Pointer for text
        int j = 0; // Pointer for pattern

        while (i < n) {
            if (text[i] == pattern[j]) {
                // Characters match, so advance both pointers
                i++;
                j++;

                // Entire pattern matched
                if (j == m) {
                    return true;
                }
            } else {
                if (j > 0) {
                    // Reuse the matching prefix; don't move i.
                    j = lps[j - 1];
                } else {
                    // Nothing to reuse, so move to the next text character
                    i++;
                }
            }
        }

        // Reached the end of text without finding the pattern
        return false;
    }
    bool isrotate(vector<int>& vec1, vector<int>& vec2) {
        // this is simply finding if any rotation of vec1 is present in vec2
        // lets say [6,5] ---> [5,6]
        // to find so we append [6,5,6,5]; --> we can see 5,6 is there!
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end()); // vec2+vec2

        return kmp(vec1,
                   text); // to find if vec2 pattern is present in the text.
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int res = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                // create block of k from nums
                vector<int> vec1(nums.begin() + start,
                                 nums.begin() + start + k);
                // create block of k from sorted
                vector<int> vec2(sorted.begin() + start,
                                 sorted.begin() + start + k);
                // check if we can rotate block of nums to form that sorted
                if (!isrotate(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res += k;
            }
        }
        return res;
    }
};