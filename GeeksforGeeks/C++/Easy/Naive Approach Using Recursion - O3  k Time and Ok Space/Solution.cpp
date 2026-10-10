class Solution {
	public:
	bool balancePan(int a, int b) {
		// code here
		
		while (b > 0) {
			int rem = b % a;
			
			// Remainder 0 or 1 means no carry is needed.
			if (rem == 0 || rem == 1) {
				b /= a;
			}
			
			// Remainder a - 1 means use one weight on opposite side and carry 1.
			else if (rem == a - 1) {
				// b = b + 1;
				b = b / a + 1;
			}
			
			// Any other remainder cannot be balanced.
			else {
				return false;
			}
		}
		
		return true;
		
	}
};
