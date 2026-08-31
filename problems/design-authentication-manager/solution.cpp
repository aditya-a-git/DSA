class AuthenticationManager {
    unordered_map<string, int> tokens;
    int timeToLive;

public:
    AuthenticationManager(int timeToLive) { this->timeToLive = timeToLive; }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) == tokens.end()) {
            return;
        }

        if (tokens[tokenId] <= currentTime) {
            tokens.erase(tokenId);
            return;
        }

        tokens[tokenId] = currentTime + timeToLive;
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for (auto it = tokens.begin(); it != tokens.end();) {
            if (it->second <= currentTime) {
                it = tokens.erase(it);
            } else {
                count++;
                it++;
            }
        }

        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */