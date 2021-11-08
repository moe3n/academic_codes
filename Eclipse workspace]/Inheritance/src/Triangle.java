
public class Triangle extends shape{
	double y;
	Triangle(double x,double y)
	{
		super(x);
		this.y=y;
		
	}
	@Override
	double getVolume()
	{
		return .5*x*y;
	}
	@Override
	void print()
	{
		System.out.println("This is the volume of triangle: "+getVolume());
		
	}

}
