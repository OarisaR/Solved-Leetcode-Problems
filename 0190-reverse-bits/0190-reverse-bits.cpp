class Solution {
public:
    int reverseBits(int n) {
        string num = bitset<32>(n).to_string();
        //cout<<num;
        reverse(num.begin(),num.end());
        cout<<num;
        return stoi(num,nullptr,2); // function to convert binary number to integer
    }
};