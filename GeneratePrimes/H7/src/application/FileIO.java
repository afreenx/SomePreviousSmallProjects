package application;
import java.util.*;
import java.io.*;


public class FileIO extends TwinPrimes{
	

	//read in twin primes & output result.txt
	//public int fromMainVar;
	public FileIO() {
		//this.fromMainVar = fromMainVar;
	}
	
	//void setMainVar(int val) {
	//	this.fromMainVar = val;
	//}
	//int getMainVar(int val) {
	//	return this.fromMainVar;
	//}
		
	/*
	 * This method will open a file results.txt and first use the array
	 *  returned from the twinprime method in TwinPrimes.java by giving in a set length
	 *   to search through which is bigger if N is bigger. Then that array will be used 
	 *   to find pairs of Hexagon crosses in the array by checking if a number in the array is there with it’s doubled version.
	 *    This is then printed to the console and stored in the results.txt file.
	 */
		public void produceOutput(int N){
			//int N = fromMainVar;
		
			try {
				File creation = new File("results.txt");	
				if(creation.exists()){
					creation.delete();
					creation.createNewFile();
				}
				FileWriter file_write = new FileWriter(creation, true);
				PrintWriter print_write = new PrintWriter(file_write);
			
				
			ArrayList<Integer> arr = new ArrayList<Integer>();
			int Nx = 10000;
			if(N <= 15){
                Nx = 110000;
            }else
            if(N <= 50){
                Nx = 550000;
            }else
            if(N <= 100){
                Nx = 1200000;
            }
               else if(N <= 200){
                    Nx = 3000000;

            }else if(N <= 500){
                Nx = 18000000;
            }else if(N <= 1000){
                Nx = 30000000;
            }else if(N <= 10000){
				Nx = 50000000;
			}

			
	        arr = twinprime(Nx);
	        int counterN = 0;
			
	        
	        for(int i = 0; i <= arr.size()-1; i++){
				if(counterN == N){
					break;
				 }
	             for(int j = 1; j <= arr.size()-1; j++){
	                 if(arr.get(i)*2 == arr.get(j)){
	                     String temp = arr.get(i) +", "+ arr.get(j);
	                     print_write.println(temp);
						 System.out.println(temp);
						 counterN++;

						 if(counterN == N){
							break;
						 }
						}
	                 }
	             }
	        
	        
	        print_write.close();
			}catch(IOException e) {
				System.out.println("Not working");
			}
	        
		}
}

	




	

