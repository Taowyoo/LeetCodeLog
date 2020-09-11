// https://leetcode.com/problems/validate-ip-address/

// Approach 1: use regex
class Solution {
public:
    /**
     * @brief Use std::regex to check whether given string is IPV4 or IPV6
     * 
     * @param IP Given IP address string
     * @return string Result
     */
    string validIPAddress(string IP) {
        // create regex object for regulare expression
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if(regex_match(IP, ipv4)) // match regex expression with given IP string for IPv4
            return "IPv4";
        else if(regex_match(IP, ipv6)) // match regex expression with given IP string for IPv6
            return "IPv6";
        return "Neither"; // Otherwise return "Neither"
    }

};

// Approach 2: normal check
class Solution {
public:
    /**
     * @brief Use stringsteam to check whether given string is IPV4 or IPV6
     * 
     * @param IP Given IP address string
     * @return string Result
     */
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        if (IP.find(':') == string::npos) { // Check IPv4
            // use getline with customized delimiter to give each part of IPv4 address
            while (getline(is, t, '.')) {
                ++cnt;  // count the number of subpart of address
                // only have 4 parts, no abbreviation, no leading zero
                if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
                for (char c : t) {
                    // there are only numbers
                    if (c < '0' || c > '9') return "Neither";
                }
                int val = stoi(t);
                // number should be in [0,255]
                if (val < 0 || val > 255) return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else { // Check IPv6
            // use getline with customized delimiter to give each part of IPv6 address
            while (getline(is, t, ':')) {
                ++cnt;  // count the number of subpart of address
                // only have 8 parts, no abbreviation, each part at most haas 4 hex numbers
                if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
                for (char c : t) {
                    // there are only hex numbers
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            // only have 8 parts
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};