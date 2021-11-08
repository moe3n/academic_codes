import java.util.Scanner;
public class calculator {
	public static void main(String args[])
	{
		
		int[][] testArr = new int[1][2];
		int largest =0, smallest = 10000000;
		
		Scanner scan = new Scanner(System.in);
		
		for(int r=0; r<testArr.length;r++)
		{
			for(int c=0; c<testArr[r].length; c++)
			{
				testArr[r][c] =scan.nextInt();
				
			}
			
		}
		
		int current=0;
		for(int r=0; r<testArr.length;r++)
		{
			for(int c=0; c<testArr[r].length; c++)
			{
				
				 current = testArr[r][c];
				if(current>largest)
					largest = current;
				if(current<smallest)
					smallest= current;
				//System.out.println(current);
				
			}
			
		}
		System.out.println("largest " +largest);
		System.out.println("smallest " +smallest+"\n\n");
		
		Outer:	//labeled here 
		for(int row = 0; row < 5; row++) 
			{ 
				System.out.println("Outer loop: " +row);
				
				for(int column = 0; column < 4 ;column++ ) 
				{ 
					System.out.print(column +" " );
					
					if ( ((row + column) % 2 ) == 0 ) 
					{
						System.out.println("Break \n" ); 
						break Outer; //labeled jump
					}
				
				}
				
		}
		
		
		
			for(int i=0; i<10; i++) 
			{ 
				System.out.print(i + " "); 
				if (i%2 == 0) 
					continue; 
				System.out.println("wutt");
				
			}
			
		
	}

}
