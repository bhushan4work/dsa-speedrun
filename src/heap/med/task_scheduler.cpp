// statement- given list of tasks represented by uppercase (AtoZ), int n representing cooldown interval between 2 same tasks. Tasks can be executed in any order, but identical tasks must be separated by at least n intervals, during which the CPU may remain idle or execute other tasks
//            Return the min no of CPU intervals required to complete all the tasks


//(optimal) -using pq t.c- O(nlogk)  s.c- O(k)
int leastInterval(vector<char> &tasks, int p){
    int n = tasks.size();
    unordered_map<char, int> mp;

    for (char &ch : tasks){
        mp[ch]++;
    }

    priority_queue<int> pq; // max heap
    // we wanna finish process which is most occurring (having high freq)
    // so that we don't have to finish in the last with p gaps
    int time = 0;

    for (auto &it : mp){
        pq.push(it.second);
    }

    while (!pq.empty()){
        vector<int> temp;
        for (int i = 1; i <= p + 1; i++){
            // filling first p+1 characters
            if (!pq.empty()){
                temp.push_back(pq.top() - 1); // finishing 1 instance of each process
                pq.pop();
            }
        }

        for (int &freq : temp){
            if (freq > 0) pq.push(freq);
        }

        if (pq.empty())  time += temp.size(); // all processes finished
        else time += (p + 1); // we finished p+1 tasks above in loop
    }

    return time;
}



//(optimal) -using greedy t.c- O(n)  s.c- O(26)
int leastInterval(vector<char> &tasks, int k){
    int n = tasks.size();
    if (k == 0) return n;

    /*

    ["A","A","A","B","B","B"], k = 2
    A _ _ A _ _ A
    Number of chunks     = freq('A')-1 = 2
    Number of idol spots = (Number of chunks)*(k) = 2*2 = 4

    Now, we will try to fill these 4 idol spots
    If at the end idol spots is 0, it means all idol spots were enough
    to accomodate all other taks. So, out result will be tasks.size();

    If, idol spots are not empty, it means that we need more spaces (equal to idol spots)
    than the tasks.size() to accomodate all tasks.
    So, result = tasks.size() + idol_spots

    */

    int counter[26] = {0};
    for (char &ch : tasks){
        counter[ch - 'A']++;
    }

    sort(begin(counter), end(counter));

    int chunks = counter[25] - 1;
    int idolSpots = chunks * k;

    for (int i = 24; i >= 0; i--){
        idolSpots -= min(chunks, counter[i]);
    }

    if (idolSpots > 0) return n + idolSpots;

    return n;
}