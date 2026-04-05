class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        int fleetNum = 0;
        double maxTime = 0.0;
        for (int i = 0; i < position.size(); i++) {
            double currTime = (double)(target - cars[i].first) / cars[i].second;
            if (currTime > maxTime) {
                fleetNum ++;
                maxTime = currTime;
            }
        }

        return fleetNum;
    }
};
