public class PalindromicNumbers {

    static int min = 0;
	// since there is no unsigned type in Java, I used short type (max value is 2^15-1)
	static int max = 2*Short.MAX_VALUE+1;//65535;

	static int count = 0;
	
	public static void main(String[] args) {
		
		//using the fact that
		// 10 single digit palindromes
		// 9 2-digit palindromic numbers
		// 90 3-digit palindromes (9 choices for 1st and last digits, 10 choices for the middle element)
		// 90 4-digit palindromes (9 choices for 1st and last digits, 10 choices for the middle 2 elements
		
		count += 199; // sum up all above observations
		
		//Use similar inference for the nearest 5 digit number (I chose a number just less than 60,000)
		//Between [10,000 - 59,995], number of choices we have for the number "ABCBA"
		// A - 5, B- 10, C = 10 which make it 500 total palindromes in the chosen range		
		count += 500; //includes the range [10000, 59995]
		
		min = 59996; //so, we can skip the check for first 'min'-1 numbers since the count was already included
		
		// check on the confined range 
		for(int i=min; i<= max; i++){
			if(isPalindrome(i))
				count++;
		}
		
		//System.out.println(max);
		System.out.println(count);
	}
		
	public static boolean isPalindrome(int n){
		String s = Integer.toString(n);
        int i= 0, j = s.length()-1;
        while(i<j){
        	if(s.charAt(i)==s.charAt(j)){
             	i++;
        	    j--;
        	}
        	else 
        		return false;
        }
		
        //System.out.println(n);
		return true;
	}

}

