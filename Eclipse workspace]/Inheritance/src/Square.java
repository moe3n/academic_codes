
public class Square extends shape{

	Square(double x)
	{
		super(x);
		
	}
	
	@Override
	double getVolume()
	{
		return x*x;
	}
	
	void print() {
		System.out.println("This the volume ofthe sqare "+getVolume());
	}
	
}
