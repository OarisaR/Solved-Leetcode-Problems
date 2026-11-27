/*
- Free copy rules
- On buying a copy i for first time,  we get free copy for all items other than
i
- factorj % factori == 0

- buying for the second time , we wont get it!
*/
class Solution {
public:
    // only n and budget changes
    int t[1001][1501];

    // this knapsack approach count from back since we send n!
    int solve(int n, int budget, int cheap, vector<vector<int>>& items,
              vector<int>& copies) {
        if (n == 0)
            return budget / cheap;
        // if all explored, we can still take more copies as it is said that
        // items are unlimited, so we return the cheapest one if some budget
        // remains. if cheap > budget then it will automatically return 0;
        if (t[n][budget] != -1)
            return t[n][budget];
        int take = 0;
        int price = items[n - 1][1];

        if (price <= budget) {
            take = 1 + copies[n - 1] +
                   solve(n - 1, budget - price, cheap, items, copies);
        }
        int skip = solve(n - 1, budget, cheap, items, copies);
        return t[n][budget] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(
            n, 0); // copies[i] = count of copies by buying i-th item

        int cheap = INT_MAX;
        // take a array and store number of free copies obtainable for each
        // factor O(n**2) , n is max of 1500 so it is fine
        for (int i = 0; i < n; i++) {
            int c = 0;
            cheap = min(cheap, items[i][1]);
            int itemi = items[i][0];
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                int itemj = items[j][0];
                if (itemj % itemi == 0)
                    c++;
            }
            copies[i] = c;
        }
        // choosing copies that can yield the high number of free copy
        // we need to think about knapsack! that maximizes the profit such that
        // the total weight <= knapsack here number of copies is to be
        // maximized, and knapsack = budget!!
        memset(t, -1, sizeof(t));
        return solve(n, budget, cheap, items, copies);
    }
};