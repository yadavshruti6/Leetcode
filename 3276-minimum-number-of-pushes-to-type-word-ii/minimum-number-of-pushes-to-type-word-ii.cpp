class Solution {
public:
    int minimumPushes(string word) {
        // count the frequency of each character
        vector<int> charFreq(26, 0);
        for (char c : word) {
            charFreq[c - 'a']++;
        }

        // sort frequencies in descending order
        // need to assign the most frequent characters to the fewest push
        sort(charFreq.rbegin(), charFreq.rend());

        int totalPushes = 0;

        // calculating the total pushes using math
        for (int i = 0; i < 26; i++) {
            // quick otpmiziation, though if it matters cuz 26 iterations is
            // anyways small stop early if there are no more characters to
            // process
            if (charFreq[i] == 0)
                break;

            //  8 available keys on the keypad.
            // top 0-7 char get 1 push, 8-15 get 2 pushes, 16-23 get 3 pushes,
            // and next ones 4 pushes
            int pushesRequired = 1; // char 1 to 9

            if (i >= 8)
                pushesRequired = 2; // char 9 to 16
            if (i >= 16)
                pushesRequired = 3; // char 17 to 24
            if (i >= 24)
                pushesRequired = 4; // char 25 and 26

            totalPushes += charFreq[i] * pushesRequired;
        }

        return totalPushes;
    }
};