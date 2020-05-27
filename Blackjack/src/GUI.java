import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.print.*;
import javax.swing.text.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.WindowEvent;

public class GUI  extends JFrame{

	

	
	//actual window resolution
	int aW=1280;
	int aH=800;
	
	//game phases booleans
	boolean bool_hit_stay=true;
	boolean bool_dealer_turn=false;
	boolean bool_play_more=false;
	
	// colors
	Color colorBackground= new Color(15,157,88);
	Color colorButton = new Color(248,205,36);
	Color card=new Color(15,157,88);
		
	//fonts
	
	Font fontButton=new Font("Times New Roman",Font.PLAIN,30);
	Font fontCard=new Font("Times New Roman",Font.BOLD,35);
	Font fontQuestion=new Font("Times New Roman",Font.PLAIN,40);
	Font fontLog=new Font("Times New Roman",Font.BOLD,35);
	
	//Log message colors
		Color cDealer = Color.red;
		Color cPlayer = new Color(25,55,255);
		
	//list of messages
		ArrayList<Message> Log = new ArrayList<Message>();
	
	//questions
	String play_more_q="Play more?";
	String questHitStay = new String("Hit or Stay?");
	
	//buttons
	JButton bHit= new JButton();
	JButton bStay= new JButton();
	JButton bYes= new JButton();
	JButton bNo= new JButton();
	
	
	
	
	
	//card grid positioning and dimensions
	int gridX=50;
	int gridY=50;
	int gridW=900;
	int gridH=400;
	
	//card dimensions and spacing
	 int cardSpacing=10;
	 int cardEdgeSofting=8;
	int cardTW= gridW/6;
	int cardTH=gridH/2;
	int cardAW=cardTW-2*cardSpacing;
	int cardAH=cardTH-2*cardSpacing;
	
	//totals and hit-stay grid positioning and dimensions
	 int hsX=gridX+gridW+50;
	 int hsY=gridY;
	 int hsW=230;
	 int hsH=400;
	 
	 //PLAY MORE QUESTION GRID POSITIONING AND DIMENSIONS
	 int pmX=hsX;
	 int pmY=hsY+hsH+50;
	 int pmW=hsW;
	 int pmH=200;
	 
	 //arraylist that contains all the cards
	 ArrayList<Card> allCards=new ArrayList<Card>();
	 ArrayList<Card>playerCards=new ArrayList<Card>();
	 ArrayList<Card>dealerCards=new ArrayList<Card>();
	 
	//temporary integer used for used status
		int tempC;
		
	//boolean that indicates whether the dealer is thinking or not
		boolean dHitter = false;
		
	 //player-dealer totals
	 int total_player_max;
	 int total_player_min;
	 int total_dealer_max;
	 int total_dealer_min;
	 
	//integer used to generate a random number
	 int  rand= new Random().nextInt(52);
	
	public GUI()
	{
		this.setSize(aW+6,aH+29);
		this.setTitle("BLACKJACK");
		this.setVisible(true);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		
		Board board = new Board();
		this.setContentPane(board);
		this.setLayout(null);
		
		Move move = new Move();
		this.addMouseMotionListener(move);
		
		Click click = new Click();
		this.addMouseListener(click);
		
		//BUTTON STUFF
		
		ActHit aHit = new ActHit();
		bHit.addActionListener(aHit);
		bHit.setBounds(hsX+55, hsY+40, 120, 80);
		bHit.setBackground(colorButton);
		bHit.setFont(fontButton);
		bHit.setText("HIT");
		board.add(bHit);
		
		ActStay aStay = new ActStay();
		bStay.addActionListener(aStay);
		bStay.setBounds(hsX+55, hsY+280, 120, 80);
		bStay.setBackground(colorButton);
		bStay.setFont(fontButton);
		bStay.setText("STAY");
		board.add(bStay);
		
		ActYes aYes = new ActYes();
		bYes.addActionListener(aYes);
		bYes.setBounds(pmX+10, pmY+110, 100, 80);
		bYes.setBackground(colorButton);
		bYes.setFont(fontButton);
		bYes.setText("Yes");
		board.add(bYes);
		
		ActNo aNo = new ActNo();
		bNo.addActionListener(aNo);
		bNo.setBounds(pmX+120, pmY+110, 100, 80);
		bNo.setBackground(colorButton);
		bNo.setFont(fontButton);
		bNo.setText("No");
		board.add(bNo);
		
		String shapeS1=null;
		int id_setter=0;
		for(int s=0;s<4;s++)
		{
			if(s==0)
			{
				shapeS1="Spades";
			} else if(s==1)
			{
				shapeS1="Hearts";
			}else if(s==2)
			{
				shapeS1="Diamonds";
			}else
			{
				shapeS1="Clubs";
			}
			for(int i=2;i<15;i++)
			{  
			
				allCards.add(new Card(i,shapeS1,id_setter ));
				id_setter++;
			}
		}
		
		rand=new Random().nextInt(52);
		playerCards.add(allCards.get(rand));
		allCards.get(rand).cardUsed=true;
		
		rand=new Random().nextInt(52);
		while(true)
		{
			if(allCards.get(rand).cardUsed==false)
			{
				dealerCards.add(allCards.get(rand));
				allCards.get(rand).cardUsed=true;
				break;
			}else
			{
				rand=new Random().nextInt(52);
			}
		}
		
		
		rand=new Random().nextInt(52);
		while(true)
		{
			if(allCards.get(rand).cardUsed==false)
			{
				playerCards.add(allCards.get(rand));
				allCards.get(rand).cardUsed=true;
				break;
			}else
			{
				rand=new Random().nextInt(52);
			}
		}
		
		rand=new Random().nextInt(52);
		while(true)
		{
			if(allCards.get(rand).cardUsed==false)
			{
				dealerCards.add(allCards.get(rand));
				allCards.get(rand).cardUsed=true;
				break;
			}else
			{
				rand=new Random().nextInt(52);
			}
		}
		
		for(Card c: playerCards)
		{
			System.out.println("Player has the card " + c.name +" of "+ c.shape );
		}
		for(Card c: dealerCards)
		{
			System.out.println("Dealer has the card " + c.name +" of "+ c.shape );
		}
		
	}
	

		//totals checker
		
		
	public void totalsChecker() {
		
		//player total
		int sum=0;
		boolean hasAces=false;
		for(Card c:playerCards)
		{ if(c.symbol.equalsIgnoreCase("A")) {
			hasAces=true;
		}
			sum=sum+c.value;
		}
		total_player_min=sum;
		total_player_max=sum;
		
		if(hasAces==true)
		{
			total_player_max=sum+10;
		}
		
		//dealer total
		
		sum=0;
	   hasAces=false;
		for(Card c:dealerCards)
		{ if(c.symbol.equalsIgnoreCase("A")) {
			hasAces=true;
		}
			sum=sum+c.value;
		}
		total_dealer_min=sum;
		total_dealer_max=sum;
		
		if(hasAces==true)
		{
			total_dealer_max=sum+10;
		}
		
		
	}
	
	public void setWinner() {
	
		int pPoints = 0;
		int dPoints = 0;
		
		if (total_player_max > 21) {
			pPoints = total_player_min;
		} else {
			pPoints = total_player_max;
		}
		
		if (total_dealer_max > 21) {
			dPoints = total_dealer_min;
		} else {
			dPoints = total_dealer_max;
		}
		
		if (pPoints > 21 && dPoints > 21) {
			Log.add(new Message("Nobody wins!", "Dealer"));
		} else if (dPoints > 21) {
			Log.add(new Message("You win!", "Player"));
			Main.pWins++;
		} else if (pPoints > 21) {
			Log.add(new Message("Dealer wins!", "Dealer"));
			Main.dWins++;
		} else if (pPoints > dPoints) {
			Log.add(new Message("You win!", "Player"));
			Main.pWins++;
		} else {
			Log.add(new Message("Dealer wins!", "Dealer"));
			Main.dWins++;
		}
		
	}
	public void dealerHitStay()
	{
dHitter = true;
		
		int dAvailable = 0;
		if (total_dealer_max > 21) {
			dAvailable = total_dealer_min;
		} else {
			dAvailable = total_dealer_max;
		}
		
		int pAvailable = 0;
		if (total_player_max > 21) {
			pAvailable = total_player_min;
		} else {
			pAvailable = total_player_max;
		}
		
		repaint();
		
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		if ((dAvailable < pAvailable && pAvailable <= 21) || dAvailable < 16) {
			int tempMax = 0;
			if (total_dealer_max <= 21) {
				tempMax = total_dealer_max;
			} else {
				tempMax = total_dealer_min;
			}
			String mess = ("Dealer decided to hit! (total: " + Integer.toString(tempMax) + ")");
			Log.add(new Message(mess, "Dealer"));
		//	System.out.println(mess);
			tempC =  new Random().nextInt(52);
			while (allCards.get(tempC).cardUsed == true) {
				tempC = new Random().nextInt(52);
			}
			dealerCards.add(allCards.get(tempC));
			allCards.get(tempC).cardUsed=true;
	//		System.out.println("Card " + dCards.get(dCards.size()-1).name + " of " + dCards.get(dCards.size()-1).shape + " added to the dealer's cards.");
		} else {
			int tempMax = 0;
			if (total_dealer_max <= 21) {
				tempMax = total_dealer_max;
			} else {
				tempMax = total_dealer_min;
			}
			String mess = ("Dealer decided to stay! (total: " + Integer.toString(tempMax) + ")");
			Log.add(new Message(mess, "Dealer"));
			setWinner();
			bool_dealer_turn = false;
			bool_play_more = true;
		}
		dHitter = false;
	}
	
	public void refresher()
	{
		
		//button visibility
		if (bool_hit_stay == true) {
			bHit.setVisible(true);
			bStay.setVisible(true);
		} else {
			bHit.setVisible(false);
			bStay.setVisible(false);
		}
		
		if (bool_dealer_turn == true) {
			if (dHitter == false)
				dealerHitStay();
		}
		
		if (bool_play_more == true) {
			bYes.setVisible(true);
			bNo.setVisible(true);
		} else {
			bYes.setVisible(false);
			bNo.setVisible(false);
		}
		
   totalsChecker();
		
		if ((total_player_min == 21 || total_player_max >= 21) && bool_hit_stay == true) {
			int tempMax = 0;
			if (total_player_max <= 21) {
				tempMax = total_player_max;
			} else {
				tempMax = total_player_min;
			}
			String mess = ("Auto pass! (total: " + Integer.toString(tempMax) + ")");
			Log.add(new Message(mess, "Player"));
			bool_hit_stay = false;
			bool_dealer_turn = true;
		}
		
		if ((total_dealer_max == 21 || total_dealer_min >= 21) && bool_dealer_turn == true) {
			int tempMax = 0;
			if (total_dealer_max <= 21) {
				tempMax = total_dealer_max;
			} else {
				tempMax = total_dealer_min;
			}
			String mess = ("Dealer auto pass! (total: " + Integer.toString(tempMax) + ")");
			Log.add(new Message(mess, "Dealer"));
			setWinner();
			bool_dealer_turn = false;
			bool_play_more= true;
		}
		
		repaint();
	}
	
	public class Board extends JPanel
	{
		public void paintComponent (Graphics g)
		{
			g.setColor(colorBackground);
			g.fillRect(0, 0, aW, aH);
			
			//temporary grid painting
			g.setColor(Color.black);
			g.drawRect(gridX, gridY, gridW, gridH);
			//temporary log borders painting
			//g.drawRect(gridX, gridY+gridH+50, gridW, 500);
			//temporary totals and hit-stay messages and buttons grids
			g.drawRect(hsX, hsY, hsW, hsH);
			//TEMPORARY PLAY MORE GRID
			g.drawRect(pmX, pmY, pmW, pmH);
			
			
			
			//question
			if (bool_hit_stay == true) {
				g.setColor(Color.black);
				g.setFont(fontQuestion);
				g.drawString(questHitStay, pmX+30, pmY-260);
				g.drawString("Total:", pmX+30, pmY-220);
				if (total_player_min == total_player_max) {
					g.drawString(Integer.toString(total_player_max), pmX+150, pmY-220);
				} else if (total_player_min <= 21) {
					g.drawString(Integer.toString(total_player_min) + " / " + Integer.toString(total_player_max), pmX+130, pmY-220);
				} else {
					g.drawString(Integer.toString(total_player_min), gridX+gridW+60, gridY+350);
				}
			} else if (bool_play_more == true) {
				g.setColor(Color.black);
				g.setFont(fontQuestion);
				g.drawString(play_more_q, gridX+gridW+70, gridY+490);
			}
			
			for( int i=0;i<6;i++)
			{
				
				g.drawRect(gridX+i*cardTW+cardSpacing, gridY+cardSpacing, cardAW, cardAH );
				g.drawRect(gridX+i*cardTW+cardSpacing, gridY+cardSpacing+cardTH, cardAW, cardAH );
			}
			g.setColor(card);
			g.fillRect(gridX, gridY+gridH+50, gridW, 500);
			
			//Log
			g.setFont(fontLog);
			int logIndex = 0;
			for (Message L : Log) {
				if (L.getWho().equalsIgnoreCase("Dealer")) {
					g.setColor(cDealer);
				} else {
					g.setColor(cPlayer);
				}
				g.drawString(L.getMessage(), gridX+20, gridY+480+logIndex*35);
				logIndex++;
			}
			
			//score
			g.setColor(Color.BLACK);
			g.setFont(fontQuestion);
			String score = ("Score: " + Integer.toString(Main.pWins) + " - " + Integer.toString(Main.dWins));
			g.drawString(score, gridX+gridW+70, gridY+gridH+300);
			
			
			//cards painting
			//player cards
			int index=0;
			for(Card c:playerCards)
			{
				
				
				g.setColor(Color.white);
				g.fillRect(gridX+index*cardTW+cardSpacing, gridY+cardSpacing+cardEdgeSofting, cardAW, cardAH-2*cardEdgeSofting );
				g.fillRect(gridX+index*cardTW+cardSpacing+cardEdgeSofting, gridY+cardSpacing, cardAW-2*cardEdgeSofting, cardAH );
			
				g.fillOval(gridX+index*cardTW+cardSpacing, gridY+cardSpacing, 2*cardEdgeSofting,2*cardEdgeSofting);
		    	g.fillOval(gridX+index*cardTW+cardSpacing+cardAW- 2*cardEdgeSofting, gridY+cardSpacing, 2*cardEdgeSofting,2*cardEdgeSofting);
		    	g.fillOval(gridX+index*cardTW+cardSpacing, gridY+cardSpacing+cardAH-2*cardEdgeSofting, 2*cardEdgeSofting,2*cardEdgeSofting);
		    	g.fillOval(gridX+index*cardTW+cardSpacing+cardAW- 2*cardEdgeSofting, gridY+cardSpacing +cardAH-2*cardEdgeSofting, 2*cardEdgeSofting,2*cardEdgeSofting);
				
				g.setColor(Color.black);
				if(c.shape.equalsIgnoreCase("Hearts")||c.shape.equalsIgnoreCase("Diamonds"))
				{
					g.setColor(Color.red);
				}
				g.setFont(fontCard);
				g.drawString(c.symbol, gridX+index*cardTW+cardSpacing*2,gridY+cardAH);
				
				if(c.shape.equalsIgnoreCase("Spades"))
		    	{
		    		g.setColor(Color.black);
		    		g.fillOval(gridX+index*cardTW+40, gridY+85, 40, 40);
		    		g.fillOval(gridX+index*cardTW+70, gridY+85, 40, 40);
		    		g.fillArc(gridX+index*cardTW+30, gridY+28, 90, 70, 230, 80); 
			    	g.fillRect(gridX+index*cardTW+70,gridY+90,10,50);
		    	}
		    	else if(c.shape.equalsIgnoreCase("Hearts"))
		    	{
		    		g.setColor(Color.red);
		    		g.fillOval(gridX+index*cardTW+40, gridY+70, 40, 40);
		    		g.fillOval(gridX+index*cardTW+70, gridY+70, 40, 40);
		    		g.fillArc(gridX+index*cardTW+30, gridY+96, 90, 70, 50, 80);
		    	} else if(c.shape.equalsIgnoreCase("Diamonds"))
		    	 { 
		    		g.setColor(Color.red);
		    		int x1=75+gridX+index*cardTW,x2=50+gridX+index*cardTW,x3=75+gridX+index*cardTW,x4=100+gridX+index*cardTW,y1=60+gridY,y2=100+gridY,y3=140+gridY,y4=100+gridY;
		    		int[]xPoly= {x1,x2,x3,x4};
		    		int[]yPoly= {y1,y2,y3,y4};
		    		g.fillPolygon(xPoly,yPoly,4);
		    	}else
		    	{
		    			g.setColor(Color.black);
	    		g.fillOval(gridX+index*cardTW+35, gridY+85, 40, 40);
	    		g.fillOval(gridX+index*cardTW+75, gridY+85, 40, 40);
	    		g.fillOval(gridX+index*cardTW+55, gridY+55, 40, 40);
		    	g.fillRect(gridX+index*cardTW+70,gridY+90,10,50);
		    	}
				
				index++;
			}
			
		
			
			if(bool_dealer_turn==true || bool_play_more==true)
			{
				//dealer cards
				 index=0;
				for(Card c:dealerCards)
				{
					
					
					g.setColor(Color.white);
					g.fillRect(gridX+index*cardTW+cardSpacing, gridY+cardTH+cardSpacing+cardEdgeSofting, cardAW, cardAH-2*cardEdgeSofting );
					g.fillRect(gridX+index*cardTW+cardSpacing+cardEdgeSofting, gridY+cardTH+cardSpacing, cardAW-2*cardEdgeSofting, cardAH );
				
					g.fillOval(gridX+index*cardTW+cardSpacing, gridY+cardTH+cardSpacing, 2*cardEdgeSofting,2*cardEdgeSofting);
			    	g.fillOval(gridX+index*cardTW+cardSpacing+cardAW- 2*cardEdgeSofting, gridY+cardTH+cardSpacing, 2*cardEdgeSofting,2*cardEdgeSofting);
			    	g.fillOval(gridX+index*cardTW+cardSpacing, gridY+cardTH+cardSpacing+cardAH-2*cardEdgeSofting, 2*cardEdgeSofting,2*cardEdgeSofting);
			    	g.fillOval(gridX+index*cardTW+cardSpacing+cardAW- 2*cardEdgeSofting, gridY+cardTH+cardSpacing +cardAH-2*cardEdgeSofting, 2*cardEdgeSofting,2*cardEdgeSofting);
					
					g.setColor(Color.black);
					if(c.shape.equalsIgnoreCase("Hearts")||c.shape.equalsIgnoreCase("Diamonds"))
					{
						g.setColor(Color.red);
					}
					g.setFont(fontCard);
					g.drawString(c.symbol, gridX+index*cardTW+cardSpacing*2,gridY+cardAH+cardTH);
					
					if(c.shape.equalsIgnoreCase("Spades"))
			    	{
			    		g.setColor(Color.black);
			    		g.fillOval(gridX+index*cardTW+40, gridY+cardTH+85, 40, 40);
			    		g.fillOval(gridX+index*cardTW+70, gridY+cardTH+85, 40, 40);
			    		g.fillArc(gridX+index*cardTW+30, gridY+cardTH+28, 90, 70, 230, 80); 
				    	g.fillRect(gridX+index*cardTW+70,gridY+cardTH+90,10,50);
			    	}
			    	else if(c.shape.equalsIgnoreCase("Hearts"))
			    	{
			    		g.setColor(Color.red);
			    		g.fillOval(gridX+index*cardTW+40, gridY+cardTH+70, 40, 40);
			    		g.fillOval(gridX+index*cardTW+70, gridY+cardTH+70, 40, 40);
			    		g.fillArc(gridX+index*cardTW+30, gridY+cardTH+96, 90, 70, 50, 80);
			    	} else if(c.shape.equalsIgnoreCase("Diamonds"))
			    	 { 
			    		g.setColor(Color.red);
			    		int x1=75+gridX+index*cardTW,x2=50+gridX+index*cardTW,x3=75+gridX+index*cardTW,x4=100+gridX+index*cardTW,y1=60+gridY+cardTH,y2=100+gridY+cardTH,y3=140+gridY+cardTH,y4=100+gridY+cardTH;
			    		int[]xPoly= {x1,x2,x3,x4};
			    		int[]yPoly= {y1,y2,y3,y4};
			    		g.fillPolygon(xPoly,yPoly,4);
			    	}else
			    	{
			    			g.setColor(Color.black);
		    		g.fillOval(gridX+index*cardTW+35, gridY+cardTH+85, 40, 40);
		    		g.fillOval(gridX+index*cardTW+75, gridY+cardTH+85, 40, 40);
		    		g.fillOval(gridX+index*cardTW+55, gridY+cardTH+55, 40, 40);
			    	g.fillRect(gridX+index*cardTW+70,gridY+cardTH+90,10,50);
			    	}
					
					index++;
			   }
				
				g.setColor(Color.black);
				g.setFont(fontQuestion);
				g.drawString("Your total: ", gridX+gridW+60, gridY+30);
				if (total_player_max <= 21) {
					g.drawString(Integer.toString(total_player_max), gridX+gridW+60, gridY+120);
				} else {
					g.drawString(Integer.toString(total_player_min), gridX+gridW+60, gridY+120);
				}
				g.drawString("Dealer's total: ", gridX+gridW+60, gridY+240);
				if (total_dealer_max <= 21) {
					g.drawString(Integer.toString(total_dealer_max), gridX+gridW+60, gridY+320);
				} else {
					g.drawString(Integer.toString(total_dealer_min), gridX+gridW+60, gridY+320);
				}
			}
		}
	}
	
	public class Move implements MouseMotionListener {

		@Override
		public void mouseDragged(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseMoved(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		
	}
	
	public class Click implements MouseListener {

		@Override
		public void mouseClicked(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseEntered(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseExited(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mousePressed(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseReleased(MouseEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		
	}
	
	public class ActHit implements ActionListener
	{

		@Override
		public void actionPerformed(ActionEvent e) {
			if (bool_hit_stay == true) {
				//	System.out.println("You clicked 'HIT'");
					
					int tempMax = 0;
					if (total_player_max <= 21) {
						tempMax = total_player_max;
					} else {
						tempMax = total_player_min;
					}
					String mess = ("You decided to hit! (total: " + Integer.toString(tempMax) + ")");
					Log.add(new Message(mess, "Player"));
					
					tempC = new Random().nextInt(52);
					while (allCards.get(tempC).cardUsed == true) {
						tempC = new  Random().nextInt(52);
					}
					playerCards.add(allCards.get(tempC));
					allCards.get(tempC).cardUsed=true;
				//	System.out.println("Card " + pCards.get(pCards.size()-1).name + " of " + pCards.get(pCards.size()-1).shape + " added to the player's cards.");
				}
			}
			
		
	}
	
	public class ActStay implements ActionListener
	{

		@Override
		public void actionPerformed(ActionEvent e) {
			if (bool_hit_stay == true) {
				//	System.out.println("You clicked 'STAY'");
					
					int tempMax = 0;
					if (total_player_max <= 21) {
						tempMax = total_player_max;
					} else {
						tempMax = total_player_min;
					}
					String mess = ("You decided to stay! (total: " + Integer.toString(tempMax) + ")");
					Log.add(new Message(mess, "Player"));
					
					bool_hit_stay = false;
					bool_dealer_turn = true;
				}
			
		}
		
	}
	
	public class ActYes implements ActionListener
	{

		@Override
		public void actionPerformed(ActionEvent e) {
			for (Card c : allCards) {
				c.cardUsed=false;
			}
			
			playerCards.clear();
			dealerCards.clear();
			Log.clear();
			
			bool_play_more = false;
			bool_hit_stay = true;
			
			tempC = new Random().nextInt(52);
			playerCards.add(allCards.get(tempC));
			allCards.get(tempC).cardUsed=true;
	//		System.out.println("Card " + pCards.get(0).name + " of " + pCards.get(0).shape + " added to the player's cards.");
			
			tempC = new Random().nextInt(52);
			while (allCards.get(tempC).cardUsed == true) {
				tempC = new Random().nextInt(52);
			}
			dealerCards.add(allCards.get(tempC));
			allCards.get(tempC).cardUsed=true;
	//		System.out.println("Card " + dCards.get(0).name + " of " + dCards.get(0).shape + " added to the dealer's cards.");
			
			tempC = new Random().nextInt(52);
			while (allCards.get(tempC).cardUsed == true) {
				tempC = new Random().nextInt(52);
			}
			playerCards.add(allCards.get(tempC));
			allCards.get(tempC).cardUsed=true;
	//		System.out.println("Card " + pCards.get(1).name + " of " + pCards.get(1).shape + " added to the player's cards.");
			
			tempC = new Random().nextInt(52);
			while (allCards.get(tempC).cardUsed == true) {
				tempC = new Random().nextInt(52);
			}
			dealerCards.add(allCards.get(tempC));
			allCards.get(tempC).cardUsed=true;
		//	System.out.println("Card " + dCards.get(1).name + " of " + dCards.get(1).shape + " added to the dealer's cards.");
			
		
			
		}
		
	}
	
	public class ActNo implements ActionListener
	{

		@Override
		public void actionPerformed(ActionEvent e) {
//			System.out.println("You clicked 'NO'");
					Main.terminator = true;
					dispose();
			
		}
		
	}
}
