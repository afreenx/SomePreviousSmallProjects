package application;

public class Prime {

		//this method will determine if a number is prime or not
		//this will be helpful in calculating twin primes
		//no need for setters and getters
		 public static boolean prime(int num){
		        if(num<=1)
		        {
		            return false; //if 0 or 1 not prime
		        }
		        int counter = 2;
		        while(counter <= num/2){
		            if(num%counter == 0){
		                return false;
		            }
		            counter++;
		        }
		        return true;
		      
		  }

}


