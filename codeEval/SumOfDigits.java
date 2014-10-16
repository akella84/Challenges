package codeEval;

import java.util.*;
import java.io.*;

public class SumOfDigits {

	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            //System.out.println("Reading input from file: " + args[0]);
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    while(scanner.hasNextInt()){
                String s = Integer.toString(scanner.nextInt());
                int sum = 0;
                for(int i=0; i< s.length(); i++)
                {
                	int temp = Character.getNumericValue(s.charAt(i));
                	sum+=temp;
                }
                System.out.println(sum);
		    }
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file" + e.getMessage());			
		}
	}
}
