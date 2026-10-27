// Algo covers in 5 steps and concept of this question is Greedy.
// Concepts used: Greedy Approach, Frequency Counting, Ordered Map.
// 1. Check if hand.size() is divisible by groupSize.
//    If not, forming equal-sized groups is impossible.
// 2. Store each card's frequency in an ordered map.
// 3. Always choose the smallest available card as the group start.
// 4. Find each consecutive card from start to start + groupSize - 1.
//    If any card is missing, return false.
// 5. Decrease frequencies and erase cards whose frequency becomes zero.
//    If all cards are used successfully, return true.
// TC: O(n log n) - Each card is processed once, with ordered-map
// operations taking O(log n) time.
// SC: O(n) - The frequency map can store up to n distinct cards.
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> count;

        for (int card : hand) {
            count[card]++;
        }

        while (!count.empty()) {
            int start = count.begin()->first;

            for (int card = start; card < start + groupSize; card++) {
                if (count[card] == 0) {
                    return false;
                }

                count[card]--;

                if (count[card] == 0) {
                    count.erase(card);
                }
            }
        }

        return true;
    }
};

