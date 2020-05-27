
public class Card {

	int number;
	String shape;
	boolean cardUsed=false;
	String symbol;
	String name;
	int id;
	int value;
	
	public Card(int n,String s, int id)
	{
		this.number=n;
		this.shape=s;  
		this.id=id;
		
		if(number<11)
		{
			symbol=Integer.toString(number);
			name=Integer.toString(number);
			value=number;
		}else if(number==11)
		{
			symbol="J";
			name="Jack";
			value=10;
		}else if(number==12)
		{
			symbol="Q";
			name="Qeen";
			value=10;
		}else if(number==13)
		{
			symbol="K";
			name="King";
			value=10;
		}else
		{
			symbol="A";
			name="Ace";
			value=1;
		}
		this.shape = s;
		this.id = id;
		
		//System.out.println("Card "+ name+ " of "+ shape+" was created, id:"+this.id);
	}
	
	public void setUsed() {
		cardUsed = true;
	//	System.out.println("The Card  " + name + " of " + shape + " is now used");
	}
	
	public void setNotUsed() {
		cardUsed = false;
	//	System.out.println("The Card  " + name + " of " + shape + " is now not used");
	}
	
}
