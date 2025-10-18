class ExamTracker {
public:
    vector<int> times;
    vector<long long> prefixScores;

    ExamTracker() {}

    void record(int time, int score) {
        int glavonitre = score;
        times.push_back(time);
        if (prefixScores.empty())
            prefixScores.push_back(score);
        else
            prefixScores.push_back(prefixScores.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        int l =
            lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int r = upper_bound(times.begin(), times.end(), endTime) -
                times.begin() - 1;
        if (l > r)
            return 0;
        if (l == 0)
            return prefixScores[r];
        return prefixScores[r] - prefixScores[l - 1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */