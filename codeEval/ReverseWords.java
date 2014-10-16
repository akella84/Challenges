package codeEval;

import java.util.*;
import java.io.*;

public class ReverseWords {

	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            //System.out.println("Reading input from file: " + args[0]);
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    while(scanner.hasNextLine()){
                /*
		    	StringTokenizer st = new StringTokenizer(scanner.nextLine());
                while(st.hasMoreTokens())
                	System.out.print(" " + st.nextToken());
                System.out.println("");
                */
		    	String[] tokens = scanner.nextLine().split("\\s");
		    	for(int i=tokens.length-1; i >= 0; i--)
		    		System.out.print(" " + tokens[i]);
                System.out.println("");
		    }
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file: " + e.getMessage());			
		}
	}
}
