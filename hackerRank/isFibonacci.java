package hackerRank;

import java.io.*;
import java.util.*;

public class isFibonacci {

	static int maxTestCases = (int)Math.pow(10, 5);
	static long maxInput = (long)Math.pow(10, 10);
	
	public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numLines = 0;

        try{
		       numLines = Integer.parseInt(br.readLine());
		       
		       if(numLines > maxTestCases && numLines < 1)
		    	   System.exit(0);
			       
		       int i=0;
		       long[] cycleList = new long[numLines];
		       while (i < numLines){
		    	   long currentCycle = Long.parseLong(br.readLine());
		    	   
			       if((currentCycle > maxInput) || (currentCycle < 1L))
			    	   System.exit(0);
		    	   
		    	   cycleList[i] = currentCycle;
		    	   i++;
		       }
		       
		       for(int j=0; j< cycleList.length; j++){
		    	   System.out.println (isFibo(cycleList[j]));
		       }
        }
        catch(IOException e){
       	
        }
	}

	public static String isFibo(long numberToCheck){
		
		String s= "IsNotFibo";
		long a = 0L;
		long b = 1L;
		int maxNum = 1000;
		for(int i=2; i<= maxNum; i++){
			long c = a+b;
			a = b;
			b = c;
			
			if(b > numberToCheck)
				return s;
			else if (b == numberToCheck){
				s = "IsFibo";
				return s;
			}
			
			if (i>maxNum)
				maxNum*=2;				
		}
		
		return s;
	}	
}
