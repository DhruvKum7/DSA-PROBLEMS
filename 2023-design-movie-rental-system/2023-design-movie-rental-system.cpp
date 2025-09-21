class MovieRentingSystem {
public:
    using P = pair<int,int>;

    // movie -> sorted set of {price, shop} for available copies
    unordered_map<int, set<P>> available;
    // movie -> {shop -> price} (direct lookup for price by shop)
    unordered_map<int, unordered_map<int,int>> priceOf;
    // globally rented copies sorted by {price, shop, movie}
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            priceOf[movie][shop] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (available.count(movie)) {
            int k = 0;
            for (auto &[price, shop] : available[movie]) {
                ans.push_back(shop);
                if (++k == 5) break;
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        auto it = priceOf[movie].find(shop);
        if (it == priceOf[movie].end()) return; // safety
        int price = it->second;
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        auto it = priceOf[movie].find(shop);
        if (it == priceOf[movie].end()) return; // safety
        int price = it->second;
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int k = 0;
        for (auto &[price, shop, movie] : rented) {
            ans.push_back({shop, movie});
            if (++k == 5) break;
        }
        return ans;
    }
};
