class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        int s = digits.size();
        reverse(digits.begin(), digits.end());

        int carry = 1;
        int i = 0;
        while (i < s && carry)
        {
            int sum = carry;
            sum += digits[i];

            digits[i++] = sum % 10;
            carry = sum / 10;
        }

        while (carry)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};