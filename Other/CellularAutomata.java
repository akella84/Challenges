public class CellularAutomata {
	
	static boolean[][] automata = new boolean[32][64];
	
	public static void main(String[] args) {
		//initial condition for first row
		int mid = (automata[0].length/2) - 1;
		automata[0][mid] = true;
		//System.out.println(mid + " " + automata[0].length);
		
		//apply the two rules of the automata on rows other than the first one
		for(int i=1; i < automata.length; i++){
			for(int j=0; j < automata[i].length; j++){	
				// First column requires the left outer cell value
				// Assuming that elements not in the scope are false
				if(j==0)
					automata[i][j] = false ^ automata[i-1][j+1];
				// Last column elements require the right outer cell value
				// Assuming that elements not in the scope are false
				else if(j==automata[i].length-1)
					automata[i][j] = automata[i-1][j-1] ^ false;				
				else 
					automata[i][j] = automata[i-1][j-1] ^ automata[i-1][j+1];	
			}
		}	
		
		//print the result
		for(int i=0; i < automata.length; i++)
		  printAutomata(automata[i]);

	}
	
	public static void printAutomata(boolean[] myRow ){
		for(int i=0; i < myRow.length; i++){
			if(myRow[i]) 
				System.out.print("*");
			else 
				System.out.print("-");
		}
		System.out.println();
	}

}

