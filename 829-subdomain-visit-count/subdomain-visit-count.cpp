class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        unordered_map<string,int>countMap;
        for(auto domainInfo:cpdomains){
            int spaceIndex = domainInfo.find(' ');
            int count = stoi(domainInfo.substr(0,spaceIndex));
            string domain = domainInfo.substr(spaceIndex + 1);

            countMap[domain] += count;

            for(int i=0; i<domain.size(); i++){
                if(domain[i] == '.'){
                    string subDomain = domain.substr(i+1);
                    countMap[subDomain] += count;
                }
            }
        }
            vector<string>result;
            for(auto i: countMap) result.push_back(to_string(i.second) + " " + i.first);
            return result;
    }
};