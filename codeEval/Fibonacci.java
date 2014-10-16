package codeEval;

import java.util.*;
import java.io.*;

public class Fibonacci {

	HashMap<Integer, Integer> fibMap = new HashMap<Integer, Integer>();
	Fibonacci(){
		fibMap.put(0,0);
		fibMap.put(1,1);
	}
	
	int fibCompute(int n){
	    if (n<0)
	    	return -1;
		if(fibMap.containsKey(n))
			return fibMap.get(n);
		else{
			int result = fibCompute(n-1)+fibCompute(n-2); 
			fibMap.put(n, result);
		    return result;
		}
	}
	
	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            System.out.println("Reading input from file: " + args[0]);
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    Fibonacci myFib = new Fibonacci();
		    while(scanner.hasNextInt()){
		      System.out.println(myFib.fibCompute(scanner.nextInt()));
		    }
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file" + e.getMessage());			
		}
	}
}
