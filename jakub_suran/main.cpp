class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 0)
            return {};
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] < intervals[i][0])
                result.push_back(intervals[i]);
            else
                result.back()[1] = result.back()[1] > intervals[i][1] ? result.back()[1] : intervals[i][1];
        }
        return result;
    }
};