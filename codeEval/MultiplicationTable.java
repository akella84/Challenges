package codeEval;


public class MultiplicationTable {

	public static void main(String[] args) {
		int max_num = 12;
		
		for(int i=1; i<=max_num; i++){
			for(int j=1; j<=max_num; j++){
				System.out.printf("%4d",i*j);
			}
			System.out.println("");
		}	
	}	
}

