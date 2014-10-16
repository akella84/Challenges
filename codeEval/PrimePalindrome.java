package codeEval;


public class PrimePalindrome {

	public static void main(String[] args) {
		int max_num = 100000;
		
		//System.out.println(max_num+" is palindrome? "+isPalindrome(max_num));
		//System.out.println(max_num+" is prime? "+isPrime(max_num));
		
		if(max_num%2 == 0) max_num--;
		
        for(int i = max_num; i>100 ; i-=2)
        {
        	if (isPrime(i) && isPalindrome(i)){
        		System.out.println(i);
        		System.exit(0);
        	}
        }
	}
	
	public static boolean isPrime(int n)
	{
		if (n%2==0)
			return false;
		
		for(int i=3; i < n; i=i+2)
		{
			if(n%i == 0){
			   //System.out.println(n+" divisible by "+ i);	
				return false;
			}	
		}
		
		return true;
	}
	
	public static boolean isPalindrome(int n)
	{
		String s = Integer.toString(n);
       
		int numberLength = s.length();
		for (int i=0, j=numberLength-1; i<=j; i++, j--){
			//System.out.println(s.charAt(i) + " " + s.charAt(j));
			if (s.charAt(i) != s.charAt(j))
				return false;
		}	
		
		return true;
	}
	
}

