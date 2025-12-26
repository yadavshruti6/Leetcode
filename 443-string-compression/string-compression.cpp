class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;   // index to write compressed result
        int i = 0;       // index to read chars

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            // count frequency of current character
            while (i < n && chars[i] == curr) {
                i++;
                count++;
            }

            // write the character
            chars[write++] = curr;

            // write count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
