// statement- Given list of job durations representing time it takes to complete each job. Implement Shortest Job First algo to find avg waiting time for these jobs
// shortest job first algo: scheduling policy that selects waiting process with smallest execution time to execute next


// (optimal) t.c- O(nlogn + n)  s.c- O(1)
float calculateAverageWaitTime(vector<int> &jobs){
    sort(jobs.begin(), jobs.end()); // Sort jobs in ascending order (Shortest Job First)

    float waitTime = 0;  // Stores cumulative waiting time
    int totalTime = 0;   // Tracks elapsed execution time
    int n = jobs.size(); // No of jobs

    // Iterate through each job to calculate waiting time
    for (int i = 0; i < n; i++){
        waitTime += totalTime; // Add curr total time to waiting time
        totalTime += jobs[i];  // Execute current job
    }
    return waitTime / n; // Return the average waiting time
}