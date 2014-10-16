package codeEval;

import java.io.File;
import java.util.Scanner;

public class MthToLastList {
	
	public class ListNode {	
		
		public ListNode(){
			value = "";
			next = null; 
		}
		
		public ListNode(String data){
			value = data;
			next = null; 
		}
		
		public String getValue(){
			return value;
		}
		
		public ListNode getNext(){
			return next;
		}
		
		public void setNext(ListNode l ){
			next = l;
		}
		
		private String value;
		private ListNode next;
	}
	
	public class MyList{
		
		private ListNode root;
		
		MyList(){
			root = null;
		}
		
		public void addNode(String n){
			if(root == null)
				root = new ListNode(n);
			else{
			   ListNode tmp = root;
			   while(tmp.getNext()!=null){
				   tmp = tmp.getNext();
			   }
			   tmp.setNext(new ListNode(n));
			}
		}
		
		public void printList(){
			while (root!=null){
				System.out.print(root.getValue() + " -> ");
				root = root.getNext();
			}	
		
			if(root == null)
			  System.out.println("NULL");	
		}
		
		public void printMtoLastList(int m){
			
			ListNode first = root;
			ListNode second = root;
		    int count = 1;
		    while(first.getNext()!=null){
		    	count++;
		    	first = first.getNext();
		    	if(count == m)
		    		break;		    	
		    }
		    
		    while(first.getNext()!=null){
		    	first = first.getNext();
		    	second = second.getNext();		    	
		    }
		    
			System.out.println(second.getValue());

		}
		

	}
	
	public static void main(String[] args) {
		if(!(args.length == 1))
			System.out.println("Input file missing ...");
		else{
            //System.out.println("Reading input from file: " + args[0]);
		}   
		
		try{
			Scanner scanner = new Scanner(new File(args[0]));
			int index = -1;
		    while(scanner.hasNextLine()){		    	
		    	String[] input = scanner.nextLine().split(" ");
		    	
		    	MthToLastList base = new MthToLastList();
		    	MthToLastList.MyList list = base.new MyList();		    	

		    	for(int i = 0; i < input.length-1; i++){
		    		list.addNode(input[i]);		    			
		    	}	
		    	
		    	//list.printList();
	    		
	    		if(input.length >= 1)
	    			index = Integer.parseInt(input[input.length-1]);
	    		
		    	if(index <= input.length-1)		    		
		    		list.printMtoLastList(index);
		    }
		    
		    scanner.close();
		}
		catch(Exception e){
			System.out.println("Possibly corrupted input file " + e.getMessage());			
		}
    }
	
}
