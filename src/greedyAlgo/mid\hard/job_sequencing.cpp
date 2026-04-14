// statement- given set of N jobs where each job comes with deadline & profit. profit can only be earned upon completing job within its deadline.
//            Find no of jobs done & max profit that can be obtained. Each job takes single unit of time & only 1 job can be performed at a time

// 1st code gives TLE ,to avoid it we need to apply DSU (done in 2nd code) in order to reduce complexity where we replace :
//  "find next free slot by looping" with "find next free slot in near O(1)"

// (optimal) t.c- O(nlogn + n * max deadline)  s.c- O(maxdeadline)
struct Job{ //structure to represent a job
    int id;     // Job ID
    int dead;   // Deadline
    int profit; // Profit
};

static bool cmp(const Job &a, const Job &b){ // Comparator: sort jobs by profit (descending)
    return a.profit > b.profit;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit){
    int n = deadline.size();

    //  Create job array
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++){
        jobs[i] = {i + 1, deadline[i], profit[i]};
    }

    //  Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), cmp);

    //  Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, jobs[i].dead);
    }

    //  Create slot array (time slots)
    // slot[i] = -1 means free, otherwise stores job index
    vector<int> slot(maxDeadline + 1, -1);

    int jobCount = 0;
    int totalProfit = 0;

    // Assign jobs greedily
    for (int i = 0; i < n; i++){
        // Try to place job in latest possible free slot
        for (int j = jobs[i].dead; j > 0; j--){
            if (slot[j] == -1){
                slot[j] = i; // mark slot as occupied
                jobCount++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    return {jobCount, totalProfit};
}


// (optimal) - applied DSU to avoid TLE t.c- O(nlogn + n)  s.c- O(maxdeadline)
struct Job{ // Structure to represent a job
    int id;     // Job ID
    int dead;   // Deadline
    int profit; // Profit
};

static bool cmp(const Job &a, const Job &b){ // Comparator to sort jobs in descending order of profit
    return a.profit > b.profit;
}

// DSU Find with path compression
// Returns the latest available free slot ≤ x
int findParent(int x, vector<int> &parent){
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent);
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit){
    int n = deadline.size();

    //  Create jobs array
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++){
        jobs[i] = {i + 1, deadline[i], profit[i]};
    }

    //  Sort jobs by decreasing profit (Greedy choice)
    sort(jobs.begin(), jobs.end(), cmp);

    //Find maximum deadline to determine slot range
    int maxDeadline = 0;
    for (int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, jobs[i].dead);
    }

    // Initialize DSU
    // Each slot initially points to itself (free slot)
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++){
        parent[i] = i;
    }

    int jobCount = 0;    // Number of jobs scheduled
    int totalProfit = 0; // Total profit earned

    // Process jobs in sorted order
    for (int i = 0; i < n; i++){
        // Find the latest available slot for current job
        int availableSlot = findParent(jobs[i].dead, parent);

        // If a valid slot is available (slot 0 means no slot)
        if (availableSlot > 0){
            jobCount++;
            totalProfit += jobs[i].profit;

            // Mark this slot as occupied:
            // Merge it with previous slot → next free slot becomes (slot-1)
            parent[availableSlot] = findParent(availableSlot - 1, parent);
        }
    }
    return {jobCount, totalProfit};
}