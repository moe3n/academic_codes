
public class Rekt extends shape{

	double y;
	Rekt(double x,double y){
		super(x);
		this.y=y;
	}
	@Override
	double getVolume()
	{
		return x*y;
	}
	@Override
	void print()
	{
		System.out.println("This is a rectangle"+ "volume: "+getVolume());
	}
	
}
