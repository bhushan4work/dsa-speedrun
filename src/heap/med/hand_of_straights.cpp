// statement- in given arr hand[i] is value on ith card that Alice owns. Alice wanna split her entire hand into grps such that: every grp contains exactly grpsize cards, card values in each grp form seq of grpSize consecu int


//(optimal) t.c- O(nlogn)  s.c- O(n)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();

    // If total cards cannot be evenly divided into groups, return false
    if (n % groupSize != 0) {
        return false;
    }

    map<int, int> mp; // Ordered map: key = card, value = freq
    for (int &card : hand) {
        mp[card]++;
    }

    while (!mp.empty()) {
        int curr = mp.begin()->first; // Always start from smallest card

        for (int i = 0; i < groupSize; i++) {
            int val = curr + i; //to check consecu vals as curr, curr+1, so on

            if (mp.find(val) == mp.end()) { // Check existence of consecu val, i.e !map.contains(val)
                return false;
            }

            mp[val]--; // Decrease freq
            if (mp[val] == 0) { // If card is exhausted, remove it from map
                mp.erase(val);
            }
        }
    }

    return true;
}