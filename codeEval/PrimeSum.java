package codeEval;


public class PrimeSum {

	public static void main(String[] args) {
		int max_num = 1000;
		
		// count and sum initialized with base case of 2 - the only even prime
		int primeSum = 2;
		int count=1,i = 3; 
		
		while(count < max_num)
		{
			if (isPrime(i))
			{	
				primeSum +=i;
			    count++;
			}   
			i+=2;//check for only odd numbers
		}
		System.out.println(primeSum);

	}
	
	public static boolean isPrime(int n)
	{
		if (n%2==0 && n > 2)
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
	
}

