package codeEval;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class StackImplementation {
	
    int[] stackArray;
		
	StackImplementation(int[] inputArray){
		stackArray = inputArray;
		//System.out.println(Arrays.toString(stackArray));
	}
		
	public void push(int n){
		//problem has no push specific requirement.
		//hence not needed
	}
		
	public int pop(){
			
		int item = -1;
		if(stackArray.length > 0){
			item = stackArray[stackArray.length-1];
		    stackArray = Arrays.copyOf(stackArray, stackArray.length-1);
		}
		//System.out.print(" " + item );
		return item;
	}
	
	public boolean isEmpty(){
		
		return (stackArray.length == 0)?true:false;
	}

	public static void main(String[] args) {
			if(!(args.length == 1))
				System.out.println("Input file missing ...");
			else{
	            //System.out.println("Reading input from file: " + args[0]);
			}   
			
			try{
				Scanner scanner = new Scanner(new File(args[0]));
			    while(scanner.hasNextLine()){		    	
			    	String[] input = scanner.nextLine().split(" ");
			    	int[] inputArray = new int[input.length];
			    	for(int i = 0; i < input.length; i++)
			    		inputArray[i] = Integer.parseInt(input[i]);
			    	
			    	StackImplementation s = new StackImplementation(inputArray);

			    	while(!s.isEmpty()){
			    		System.out.print(s.pop()+ " ");
			    		
			    		if(!s.isEmpty())
			    		  s.pop();
			    	}
			    	
			    	System.out.println();
			    }
			    
			    scanner.close();
			}
			catch(Exception e){
				System.out.println("Possibly corrupted input file " + e.getMessage());			
			}
	}

}

