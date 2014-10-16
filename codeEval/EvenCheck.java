package codeEval;

import java.util.*;
import java.io.*;

public class EvenCheck {

	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            //System.out.println("Reading input from file: " + args[0]);
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
		    while(scanner.hasNextInt()){
		        int input = scanner.nextInt();
		        if(0 < input  && input < 5000){
		           int res =  (input%2 == 0) ? 1 : 0;
		           System.out.println(res);
		        } 
		    }
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file" + e.getMessage());			
		}
	}
}
