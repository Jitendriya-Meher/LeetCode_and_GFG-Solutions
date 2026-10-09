class Solution {
	public:
	
	void rec(vector<long long> &ans, long long num) {
		
		ans.push_back(num);
		
		if (num <= 1) {
			return;
		}
		
		if ((num&1) == 0) {
			num = pow(num, 0.5);
		}
		else {
			num = pow(num, 1.5);
		}
		
		rec(ans, num);
		
	}
	
	vector<long long> jugglerSequence(long long n) {
		// code here
		vector<long long> ans;
		long long num = n;
		
		rec(ans, num);
		
		return ans;
		
	}
};
