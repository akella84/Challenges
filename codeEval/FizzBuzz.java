package codeEval;

import java.io.*;
import java.util.*;

public class FizzBuzz {
	
	static int maxTestCases = 20;
	static int AMax = 20;
	static int BMax = 20;
	static int NMax = 100;
	static int NMin = 21;

	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else{
            //System.out.println("Reading input from file: " + args[0]);
		}   
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    while(scanner.hasNext()){		    	
		    	int A = Integer.parseInt(scanner.next());
		    	int B = Integer.parseInt(scanner.next());
		    	int N = Integer.parseInt(scanner.next());
		    	fizzBuzz(A, B, N);
		    }
		    
		    scanner.close();
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file " + e.getMessage());			
		}
		
	}
	
	public static int fizzBuzz(int A, int B, int N){
		
		if((A < 1) && (A > AMax))
			return 0;
		
		if((B < 1) && (B > BMax))
			return 0;
		
		if((N < NMin) && (N > NMax))
			return 0;
		
		for(int i=1; i<= N; i++){
		    if(i>1){
		        System.out.print(" ");
		    }
		    
			if (i%(A*B) ==0){
				System.out.print("FB");
			}
			
			else if(i%A == 0){
				System.out.print("F" );
			}
			
			else if(i%B ==0){
				System.out.print("B");
			}

			else
				System.out.print("" +i);
		}
		
		System.out.println();
		
		return 0;
	}
	
	
}
