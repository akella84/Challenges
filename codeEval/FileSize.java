package codeEval;

import java.io.File;

public class FileSize {
	
	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            //System.out.println("Reading input from file: " + args[0]);
		
		try{
			File myFile = new File(args[0]);
			System.out.println(myFile.length());
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file: " + e.getMessage());			
		}
	}

}
