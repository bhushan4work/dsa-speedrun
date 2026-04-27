// statement- each int in arr represents asteroid. abs value(+ve) represents size of asteroid, sign represents direction (+ve - right, -ve - left)
// When two asteroids meet(i.e +ve -ve adjacently), smaller one explode. If both are of same size, both explode. Asteroids moving in same direc will never meet(i.e both +ve\-ve)


//(optimal) t.c- O(n)  s.c- O(n)
vector<int> asteroidCollision(vector<int> &asteroids){
    int n = asteroids.size();
    vector<int> st;

    for (int i = 0; i < n; i++){
        if (asteroids[i] > 0){
            st.push_back(asteroids[i]); // Push asteroid in stack if right moving asteroid is seen i.e +ve
        }
        else { // Else if asteroid is moving right, perform  collisions
            // Until right moving asteroids are smaller in size, keep on destroying
            while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){ //st el should be +ve & smaller than asteroid
                st.pop_back(); // Destroy  asteroid
            }

            if (!st.empty() && st.back() == abs(asteroids[i])){ // If right moving asteroid exists which is of same size
                st.pop_back(); // Destroy both  asteroids
            }
            else if (st.empty() || st.back() < 0){ //else if stack gets empty or has left moving asteroid
                st.push_back(asteroids[i]); // Push asteroid in stack
            }
        }
    }
    return st;
}