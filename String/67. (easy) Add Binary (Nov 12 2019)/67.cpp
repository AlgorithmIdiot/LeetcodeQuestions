class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        std::string res ;
        while (i >=0 || j >= 0 )
        {
            if (i>=0 && a[i--] == '1') carry++;
            if (j>=0 && b[j--] == '1') carry++;
            res.insert(res.begin(), ( carry%2 ==1 ? '1': '0'));
            carry /=2;
        }
        if (carry ==1 ) res.insert(res.begin(), '1');
        return res;
    }
};