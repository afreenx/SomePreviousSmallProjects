
package application;

import java.util.*;

public class TwinPrimes extends Prime{

		/*
		 * This method will return an integer array of numbers that are between twin primes.
		 *  Twin primes will be checked for in the method, but only the number in between the twin prime will be appended to the array. 
		 *  This will create an array that is good for determining hexagon crosses. It will have all the possibilities of numbers that could be in a hexagon cross. 
		 */
	  public ArrayList<Integer> twinprime(int N){
	        ArrayList<Integer> hexNumArr = new ArrayList<Integer>();

	       
	        for(int i = 2; i <= N; i++){
	            if(prime(i) == true && prime(i+2) == true){ 
	                hexNumArr.add(i+1); //add to array
	            }
	        }
	        return hexNumArr;
	       
	    }
	  

	    
}

