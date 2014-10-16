package hackerRank;

import java.io.*;
import java.util.*;

public class UtopianTree {

	static int maxTestCases = 10;
	static int maxGrowthCycles = 60;
	
	public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numLines = 0;

        try{
		       numLines = Integer.parseInt(br.readLine());
		       if(numLines > maxTestCases){
		    	   System.out.println("Cannot handle more than 60 test cases");
		    	   numLines = maxTestCases;
		       }	
		       
		       int i=0;
		       int[] cycleList = new int[numLines];
		       while (i < numLines){
		    	   int currentCycle = Integer.parseInt(br.readLine());
		    	   cycleList[i] = currentCycle;
		    	   i++;
		       }
		       
		       for(int j=0; j< cycleList.length; j++){
		    	   System.out.println (calculateHeight(cycleList[j], 1));
		       }
        }
        catch(IOException e){
        	
        }
        
        //System.out.println("numLines:" + numLines);

	}

	public static int calculateHeight(int cycles, int height){
		
		 if((cycles > maxGrowthCycles) || (cycles <= 0) )
			 return height;
		 
		 int firstEvenCycles = 0;
		 boolean isOdd = false;
		 
		 if(cycles%2 == 0){
			 firstEvenCycles = cycles;
		 }
		 else{
			 firstEvenCycles = cycles-1; 
			 isOdd = true;
		 } 
		 
		 
		 int k = 1;
		 while(k <= firstEvenCycles/2){
		     height = 2*height + 1;
		     k++;
		 }
		 
		 if(isOdd)
			  height *=2;
		 
		
		return height;
	}	
}
