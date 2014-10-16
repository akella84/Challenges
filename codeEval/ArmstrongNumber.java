package codeEval;

import java.io.*;
import java.util.*;

public class ArmstrongNumber{

	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else{
            //System.out.println("Reading input from file: " + args[0]);
		}   
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    while(scanner.hasNext()){	
		    	int num = Integer.parseInt(scanner.next());
		    	System.out.println(isArmstrong(num));
		    }
		    
		    scanner.close();
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file " + e.getMessage());			
		}		
	}
	
	public static String isArmstrong(int input){
		String s = Integer.toString(input);
		int n = s.length();
        int sum = 0;
		
		for(int i=0; i< n; i++){
			int j = Character.getNumericValue(s.charAt(i));
			sum += Math.pow(j, n);
		}
			
		return (sum==input)?"True":"False";
	}	
}