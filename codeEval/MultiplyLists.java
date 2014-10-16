package codeEval;

import java.io.File;
import java.util.*;

public class MultiplyLists {
	
	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else
            //System.out.println("Reading input from file: " + args[0]);
		
		try{
			Scanner scanFile = new Scanner(new File(args[0]));
			while(scanFile.hasNext()){
				ArrayList<Integer> firstList = new ArrayList<Integer>();
				ArrayList<Integer> secondList = new ArrayList<Integer>();
				
				String[] token = scanFile.nextLine().split(" ");
				//System.out.println("Length: " + token.length);
				
				int i=0;
				while((token[i].charAt(0) != '|')){
					firstList.add(Integer.parseInt(token[i]));
					i++;
				}	
				
				i++;
				
				while(i < token.length){
					secondList.add(Integer.parseInt(token[i]));
					i++;
				}

				//System.out.println(firstList + " | " + secondList);	
				
				if(firstList.size() != secondList.size())
					System.exit(0);
				
				for(i=0; i< firstList.size(); i++)
					firstList.set(i, firstList.get(i)*secondList.get(i)); 
				
				for(i=0; i< firstList.size(); i++)
				   System.out.print(firstList.get(i) + " ");
				
				System.out.println("");
			}
			
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file: " + e.getMessage());			
		}
	}

}