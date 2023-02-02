/******************************************************************************
                    ONWARD!
                    
This game was designed was developed while preparing to teach programming
Second Semster. It is essenailly a maze. Can you find the way out?

                                                Brian Dailey
                                                Dec '22-- Jan '23

*******************************************************************************/

#include <iostream>
#include<cstdlib>
using namespace std;

// int variables
int row =1;    // indicates row in the 2d array, map [][]
int col =2;     // indicates the column in the 2d array, map [][] 
int location;   // stores the value from 2d array map [][], this value = the location on the map 
char extraDetail ='n';
int healthMeter = 5;
int money = 3;
int localCost;
char localAnswer;
string localItem;
int beenTo36 = 0;
int localInt;
int shieldTaken = 1;
int lanternTaken =1;
int bookTaken=1;
int block12 = 1;
int block14 =1;
int block4 = 1;
int roadTraveler = 1;
int block18=1;
int rollReason;
int susTravHealth = 5;
int endgame = 1;
int susTravDead=0;
int oldManMet=0;
int hide=0;
int compass=0;
int endCredits=0;
int quitgame=0;
int chest=0;
int candleLit=0;
int box=0;
int fruit=0;
int eatFish=0;
int wildBerries=0;
int agua=0;
int callTaken=0;
int password=0;

// following are from BLACKJACK
int playerCard1;
int oldManCard1;

//char localAnswer;
int playerTotal;
int oldManTotal;
int drawCard;

// following variables are for dice roll 
int diceTotal;
int result;
char rollRep;

// travel ban variables. used to block passage through obstacles 
bool northBan = false;
bool southBan = false;
bool eastBan = false;
bool westBan = false;

//char variables 
char direction; // variable to store location chosen

//arrays
int map[6][12] = {
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
  { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
  { 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 },
  { 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 },
  { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 },
  { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71 }
 }; // 2d array which assigns a number to each location on the map 
string inventory[6] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};

// strings to be used for results from dice engage
const string damage [5] = {"You've hit your opponent ", "He didn't see that one coming!", "Nice hit!! ", " You've hurt your opponent bad with that one! ","Devastating Blow to your opponent!  "}; 
const string damageTaken [5]{"C'mon, is that all you've got!!","That was just a scratch!!", "Hey now??!, that kind of hurt", "You've been knocked to the ground", "Not sure you can take another blow like that!!"};

//function list 
void onward();          // interprets direction to place player on correct square of the map 
void locationDesc (int l); // contains info for each square on map
void resetBan();
void titleScreen();
void nextMove();
void spacing();
void callInventory();
void addInventory();
void transaction();
void callMoney();
void callHealth();
void roadTrav ();
void block6Function();
void gameOver();
void vitals();
void engageRoll();
void mainGame();
void deal();
void checkTotal();
void draw();
void oldManDraw();
void checkOldTotal();
void callMap();
void gameComplete();
void inventoryReplace();



int main()  // main program 
{
   titleScreen();
   
   if (healthMeter > 0)
   {
    cout << endl;   // just here for visual spacing on screen
    nextMove();
    
   }

else if (healthMeter < 1)
{
    cout <<"Thank you for playing!!";
        return 0; // end of program 
}

}

void titleScreen()
{
        localItem="AXE";
        cout << endl;
        cout << endl;
        location = map [1][2];
        cout << "***********************************************************************************************************"<<endl;
        westBan=true;
        cout << "While on a trip out WEST, our TRAVELER was taken by the scenery...especially the MOUNTAINS " <<endl;
        cout << "He followed a MOUNTAIN TRAIL into a Valley and discovered a quiet VILLAGE and surrounding FARMLAND" <<endl;
        cout<<endl;
        cout << "The TRAVELER decided to move to this area permanently. The TRAVELER needed to return home first to gether" <<endl;
        cout<< "his possessions, and tie up loose ends. When returning to the MOUNTAIN TRAIL however, he discovered  " << endl;
        cout<< "it no longer led out of the area. Instead it led up to a SCENIC OVERLOOK. With no idea where you are" <<endl;
        cout << "or how to get home, you returned to the VILLAGE, taking shelter in a barn next to an OLD GREY FARMHOUSE" <<endl;
        cout<<endl;
        cout << "In the barn you find a MAP of the area." <<endl;
        cout << endl;
        cout << endl;
        cout << "There is an axe driven into a tree stump...want to take it?" << endl;
        cin>>localAnswer;
        
        if (localAnswer=='y')
        { 
            addInventory();
            block14 = block14 + 2;
        }
        else
        {nextMove();}
        cout << "************************************************************************************************************" <<endl;
      
} // title screen

void spacing()
{
        cout << endl;
        cout << "                                                    Press I for inventory" <<endl;
        cout << "                                                    Press H to check your health meter" <<endl;
        cout << "                                                    Press $ to check your money level" <<endl;
        cout << "               Here are your OPTIONS  -->           Press G to go on" <<endl;
        cout << "                                                    Press Y for Yes" <<endl;
        cout << "                                                    Press N for No" << endl;
        cout << "                                                    PRESS M to see the MAP" <<endl;
        cout << endl;
}  // helps with spacing between turns and lists player's options

void addInventory()
{
   cout << "Would you like to store the " << localItem << " in slot  0,1,2,3,4 or 5?" <<endl;
   cout <<endl;
   callInventory();
   cout <<endl;
    
            cin >> localInt;
            inventoryReplace();
            inventory[localInt] = localItem;
            callInventory();
            cout <<endl;
}  // asks user which slot to store a new item, then stores it

void inventoryReplace()
{
    if (inventory[localInt] == "LANTERN")
        {
            lanternTaken=1;
        }
        
    else if (inventory[localInt]=="SHIELD")
        {
            shieldTaken=1;
        }
    else if (inventory[localInt]== "BREAD")
        {
            block4=1;
        }
    else if (inventory[localInt]== "compass")
        {
            compass=0;
        }
    else if (inventory[localInt]== "AXE")
        {
            block14=0;
        }
    else if (inventory[localInt]== "PASSWORD")
        {
            password=0;
        }
    else if (inventory[localInt]== "CROW_CALL")
        {
            callTaken=0;
        }
    else if (inventory[localInt]== "BOOK")
        {
            bookTaken=1;
        }
}

void callMoney()
{
    cout <<endl;
    cout <<"you have  " << money << "  GOLD COINS" <<endl;
    cout <<endl;
} // prints how much money the player currently has

void transaction()
{
    if (money >= localCost) 
                    {
                    money = money - localCost;
                    cout <<endl;
                    addInventory();
                    cout <<endl;
                    callMoney();
                    }
                     
                 else 
                    {
                    cout <<endl;
                    cout << "That's not enough money, get out of here!!" << endl;
                    cout <<endl;
                    
                    }
        
} // compares money held to cost of item, subtracts cost from total money held if appropriate

void nextMove ()  // assigns outcome to potential moves made by player 
{
//void onward(); 

char move;



spacing();
 cout << "What is your next Move? "  <<endl;
   cin >>move;
   
   if (move == 'i')
   {
       callInventory();
       cout <<endl;
       nextMove();
   }
   
   else if (move == 'm')
   {
      callMap();
      nextMove();
   }
   else if (move == 'l'){
       cout <<extraDetail << endl; //this may need to be a separate swtich case
       cout <<endl;
       nextMove();
   }
   
   else if (move == 'h'){
      callHealth();
      cout <<endl;
      nextMove();
   }
 
     
    else if (move == '$'){
        callMoney();
        nextMove();
        
    }
    
    else if (move == 'g'){
        onward();
       
    }
    
    else
    
    cout<< "please choose a valid expression " << endl;
    nextMove();
    cin >> move;
    
        
    
}

void vitals()
{
    if (healthMeter < 1)
            {
                cout <<"You start to feel dizzy...then you collapse. You've died." <<endl;
                endgame =2;
                cout<< "Thank you for playing Onward!" <<endl;
            
                abort ();
            }
}

void onward() // this function handles the moves
{
    cout<<"which direction?...n,s,e,w?" << endl;  //prints request for directions
    cin >> direction;
    
    if (direction == 'n'){
        if (northBan == true) {
            cout << "you cannot go that way" << endl;
            cout <<endl;
            cout << "you're in [block] " << location <<endl;
           onward();
        }
        else
        --row;
    }
    
    else if (direction == 's') {
        if (southBan == true) {
            cout << "you cannot go that way" << endl;
            cout <<endl;
            cout << "you're in [block] " << location <<endl;
           onward();
        }
        else
        ++row;
    }
    
    else if ( direction == 'e'){
        if (eastBan == true) {
            cout << "you cannot go that way" << endl;
            cout <<endl;
            cout << "you're in [block] " << location <<endl;
           onward();
        }
        else
        ++col;
    }
    
    else if (direction == 'w'){
        if (westBan == true) {
            cout << "you cannot go that way" << endl;
            cout <<endl;
            cout << "you're in [block] " << location <<endl;
           onward();
        }
        else
        --col;
    }
     
    else 
        cout << "please enter a valid direction! " <<  endl;
    
 

    cout <<"**************" <<endl;
    location = map [row][col];  // re-sets location 
    resetBan();
    cout <<endl;
    cout << "you're in [block] " << location <<endl;
    cout <<endl;
    locationDesc(location); // contains descriptions for each location on map 
    cout <<endl;
    nextMove();
 


}  

void callInventory()
{
    cout <<endl;
    cout << "YOUR CURRENT INVENTORY:  " <<"0 = " <<inventory [0] << "   " <<"1 = "<< inventory [1]  <<"   " <<"2 = "<<inventory [2] << "   " <<"3 = "<<inventory [3] <<"   " <<"4 = "<<inventory[4] <<"   " <<"5 = "<<inventory[5];      
} // prints current inventory to the screen

void roadTrav()
{
   if (susTravDead <1)
   {
        if (roadTraveler >8 and roadTraveler <12)
        {
        cout << "Did you just see a shadow or a person...?" <<endl;
        cout << endl;
        }
    
        else if (roadTraveler == 12)
        {
        cout << " That was NOT a shadow!!... You were pushed from behind into the ditch. When you awoke you had no money left" <<endl;
        cout << endl;
        money = 0;
        healthMeter = healthMeter -3;
        roadTraveler = 0;
        }
    
   }

}

void mainGame()
{

   if (money >0)
   {
   
    cout << "Excellent!, Ready to play then?";
    cout <<endl;
    cin >> localAnswer;
            if (localAnswer == 'y')
                {
                    deal ();
                    checkTotal();
                }
                
                else if (localAnswer == 'n')
                    {
                        cout <<endl;
                        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                        cout << "Come back when you want to play" <<endl;
                        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                        cout <<endl;
                       
                      // quitgame=quitgame + 5;
                       nextMove();
                    }
                
                else 
                {
                   cout <<"That is not a valid response!" <<endl;
                   cout << "Do you want to play??" <<endl;
                   cin>>localAnswer;
                   
                   if (localAnswer == 'y')
                {
                    deal ();
                    checkTotal();
                }
                
                else if (localAnswer == 'n')
                    {
                        cout <<endl;
                        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                        cout << "Come back when you want to play" <<endl;
                        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                        cout <<endl;
                       
                       //quitgame=quitgame + 5;
                       nextMove();
                    }
                }
    
    
   }
   
   else 
    {
        cout <<endl;
        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
        cout << "Come back when you have some money to spend" <<endl;
        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
        cout <<endl;
        
        //quitgame=quitgame + 5;
        nextMove();
    }
    
}

void callMap()
{
cout <<endl;
cout <<endl;
cout << "                                                   MAP                                                     " <<endl;
cout << " Block ****************************************************************************************************" <<endl;
cout << "  0 -> * Old                                 | |                        :::     jjjjjj  SCENIC TRAIL  jjj  *" <<endl;
cout << "       * Settlement                Home of   | |       Farmland         :::    jjjjjjjjjjjjjjjjjjjjjjjjjjj *" <<endl;
cout << "       *          Merchants        Riverfolk | |                        :::   jjjjjjjjjjjjj     jjjjjjjjjj *" <<endl;
cout << "       *                                     / /                        :::   jjjjjjjjjjj    T  jjjjjjjjjj *" <<endl;
cout << "       *         _____________#_____________/ /    ::::::::::::::::::::::::   jjjjjjjjj    S  jjjjjjjjjjjj *" <<endl;
cout << "       * Cave   | ____________#______________/     ::::::::::::::::::::::::   jjjjjjjj   E  jjjjjjjjjjjjjj *" <<endl;
cout << "       *        ||            #                   :::  ______                 jjjjjj   R  jjjjjjjj         *" <<endl;
cout << "       *________||       Grey Farm  ::::::::::::::::: [ POND ]               jjjj   O   jjjjjjjjj  STUMP  *" <<endl;
cout << "       *_________|         House    ::::::::::::::::: [ ____ ]  STATUE        jjj  F   jjjjjjjjjjj         *" <<endl;
cout << "       *                            :::                                      jjjjjjjjjjjjjjjjjjjjjjjjjjjjj *" <<endl;
cout << "       *     FARMLAND               :::  Mtg.                              jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj *" <<endl;
cout << "       * ::::::::::::::::::::::::::::::  House     xxxxxx   xxxxxxx                                        *" <<endl;
cout << "       * ::::::::::::::::::::::::::::::            x t t t  t  t  x                [UNCHARTED]             *" <<endl;
cout << " Block *             ______     ~~~~~~~   ----     x t t t  t  t  x                                        *" <<endl;
cout << " 60 -> *            |Apoth.|   | Temple| | B&B|    x t t grave t  x                                        *" <<endl;
cout << "       *****************************************************************************************************" <<endl;
cout << "                                                                                                            " <<endl;

    
}

void callHealth()
{
    cout <<endl;
    cout <<"your HEALTH is now " << healthMeter << endl;
    
}

void gameOver()
{
    while (endgame ==2)
    {
    
        for (int i = 0; i < 200; i++) 
        {
            //cout << i << "\n";
            cout <<"GAME OVER!!" <<endl;
            endgame = 3;
            
        }
    
    }
    
    cout <<"Thank you for playing ONWARD!" <<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cin >> localAnswer;
    
    abort ();
    
    

   
}

void block6Function()
{
    cout << "You have located the suspicious traveler that has been robbing folks on the FOREST RD!" << endl;
                cout << "What do you want to do? Run 'r', Hide 'h' or Fight 'f'??" <<endl;
                cin >> localAnswer;
            
                if (localAnswer == 'h')
                {
                if (hide<1)
                {
                    cout<< "Hiding worked that time...but that suspicious traveler knows something, or someone, is closeby" <<endl;
                    hide++;
                    cout <<endl;
                    
                    cout <<endl;
                    cout <<endl;
                }
                
                else 
                {
                    cout<< "The suspicious travler grazed you with his blade" <<endl;
                    cout <<endl;
                    cout <<"you cannot hide forever!!" <<endl;
                    healthMeter--;
                    callHealth();
                    cout <<endl;
                    
                }
                }
            
                else if (localAnswer == 'r')
                {
                cout << "run, run, run!!!" <<endl;
                nextMove();
                }
            
                else if (localAnswer == 'f')
                {
                
                engageRoll();
                callHealth();
               cout << "Your opponent's health is  " << susTravHealth << endl; 
                
                }
                else 
                {
                cout <<"you have to do SOMETHING!!" <<endl;
                }
            }

void engageRoll() 
{    //dice roll funcion defined 
// Providing a seed value
	srand((unsigned) time(NULL));
		
		
		int randomD1 = 1 + (rand() % 6);
		int randomD2  = 1 + (rand() % 6);
		
	
		cout <<endl;
		cout << "ENGAGING IN COMBAT ... " <<endl;
		
		if (randomD1 > randomD2) 
		{
		    result = randomD1 - randomD2;

		    
		}
		
		else if (randomD2 > randomD1) 
		    {
		     result = randomD2 - randomD1;
		    
		     
		    
		   	}
	
	    else 
	    {
	        result = 0;
	    }
	    

	    cout <<endl;
	    
	  if (block14 > 1 and randomD1 > randomD2)
	        {
	            result = result + 1;
	            cout << "The AXE Strengthens your attack!!  " <<endl;
	            damage[result];
	        }
	        

	        
	   if (shieldTaken > 1 and randomD2 > randomD1)
	   {
	       
	       result = result - 1;
	       cout << "The SHIELD reduces your opponent's attack!!" <<endl;
	   }
	   
	   if (randomD1 > randomD2)
	   {
	       susTravHealth = susTravHealth - result;
	       cout << damage [result];
	   }
	   
	   else if (randomD2 > randomD1)
	    {
	        healthMeter= healthMeter - result;
	        cout <<damageTaken [result];
	    }

}

void locationDesc (int l)
{


int localInt;
char extraDetail;
int itemTaken;

     switch (location)
    {
       case 0 :
       {
           localItem = "SHIELD";
           northBan = true;
           westBan = true;
           
           if (shieldTaken<2)
           {
                cout << "This is a strange area, and you can almost hear whispers from beyond the treeline." <<endl; 
                cout << "The woods are dense and uninviting. A sign reading 'look elsewhere' lays on the ground." << endl;
                cout << "want to look around more?" <<endl;
                cout <<endl;
                cin >> extraDetail;
                
                if (extraDetail == 'y')
                {
                    cout <<"There are remnants of a camp, and tracks that lead off into the mountains." <<endl;
                    cout <<"You're curious, and decide to follow them a bit. About 50 yards up the trail you find a  " << localItem <<endl;
                    cout <<"would you like to add this to your inventory?" << endl;
                    extraDetail == 'n';
                    localAnswer == 'n';
                    cin >> localAnswer;
                    
                    if (localAnswer == 'y')
                    {
                        addInventory();
                        shieldTaken = shieldTaken + 4;
                    }
                    
                    else 
                    {
                        cout << "you drop the sheield..." <<endl;
                    }
                
                cout<< "after a few moments you hear a strange howl from beyond the treeline" <<endl;
                nextMove();
                }
            }
                     else 
                 {
                    cout <<"There are remnants of a camp, and tracks that lead off into the mountains." <<endl;
                    cout<< "after a few moments you hear a strange howl from beyond the treeline" <<endl;
                    nextMove();
                        
                     
                 }       
          vitals();
           break;
        }
        
        case 1 :
       {    
           localItem = "LANTERN";
           localCost =2;
           northBan = true;
           
           if (lanternTaken <2){
            cout << "A few MERCHANTS are meeting and trading in the shade of the mountains." << endl;
            cout << "it is impassable to the NORTH. The Bridge is in sight to the EAST" <<endl;
            cout <<endl;
            cout << "Talk to MERCHANTS? " << endl;
            cin >>localAnswer;
            cout <<endl;
            
            if (localAnswer == 'y'){
                cout << "You try to inquire about the local area but the merchants continuously direct your conversation" <<endl;
                cout << "to their goods. They insist they are the only source of goods between here and the" <<endl;
                cout << "village of Koi, approximately 7 blocks SE from here...'You cant get there from here'... says one merchant" <<endl;
                cout <<endl;
                cout << "Want to try to buy anything?" <<endl;
                cout <<endl;
                
            }
            
            
            
            else {
               cout << "Want to try to buy anything?" <<endl;
               cout <<endl;
               
            }
            
            cin >>localAnswer;
            
            if (localAnswer =='y')
            {
                cout << "A Merchant in a BROWN CLOAK says: 'Hello there TRAVELER! I have an eletric lantern for sale...just 2 COINS,today only" <<endl;
                cout << "Want to buy it?" <<endl;
                cout <<endl;
                
                cin>> localAnswer;
                cout <<endl;
                
                if (localAnswer =='y') 
                {
                    transaction();
                    lanternTaken = lanternTaken + 4;
                   
                    
                }
                
                else {
                     cout << "Well get on out of here then cheapskate !!"<<endl;
                }
            }
            
           }
           
           else {
               cout << "The MERCHANTS have left the area" <<endl;
           }
           
            vitals();
            break;
       }
       
        case 2 :
       {
            northBan = true;
            
            cout << "  You found a BRIDGE, and are able to cross the RIVER here! To the NORTH you can see large MOUNTAINS" << endl;
            vitals();
            break;
       }
       
        case 3 :
       {
            northBan = true;
            southBan=true;
            
            cout << " It's quiet, and unfamiliar. To the east you see a small settlement of people  " << endl;
            cout << " to the North runs a great mountain range. One would need a look for passage through, as they're " << endl;
            cout << "far too tall to climb" <<endl;
            vitals();
            break;
       }
       
        case 4 :
       {
            localItem = "BREAD";
            northBan = true;
            southBan=true;
            
           cout << "There are River folk here. Would you like to talk to them? " << endl;
           cin >> localAnswer;
           
           if (localAnswer=='y')
           {
              
              if (block4 <2)
              {
              
               //healthMeter++;
               cout <<"The RIVERFOLK are kind and inviting. One member of the group approaches you: 'Hello FRIEND, unfortunately we do not have"<<endl;
               cout <<"any of our delicoius TROUT to offer you. Here is some BREAD and ALE in stead.' ....Turns out the BREAD isn't very good..." <<endl;
               cout << "Fortunately the ALE helped you get it down. You're feeling a bit better! Want to keep the leftover BREAD for later?" <<endl;
               cin >>localAnswer;
               
               if (localAnswer == 'n')
               {
                   block4 = block4 + 4;
                   cout << "You throw the remaining BREAD in the RIVER when nobody is looking" <<endl;
                   callHealth();
               }
               
               else 
               {
                   addInventory();
                   callHealth();
               }
              }
              
              else
              {
                  cout <<"The RIVERFOLK are not as talkative nor are they inviting!....let's move on." <<endl;
              }
               
           }
           
           else 
           {
               
              cout << "Onward then!" << endl;
           }
           
            vitals();
            break;
       }
       
        case 5 :
       {
           
            northBan = true;
            southBan=true;
            eastBan = true;
           
           cout << "these are the FIELDS and FISHING STREAM of the RIVERFOLK. The RIVER blocks passage to the SOUTH and EAST, the MOUNTAINS to the WEST" <<endl; 
           
           if (block4 >2 and eatFish ==0)
           {
               cout <<"There is an abundance of TROUT in a feeding frenzy! ... you easily catch your supper!" <<endl;
               eatFish=1;
               healthMeter++;
               callHealth();
           }
           
           else 
           {
               cout <<"This looks like a great stretch of water to hold TROUT. Any way to bring them to the surface?..." <<endl;
           }
            
            vitals();
           break;
       }
       
        case 6 :
       {
              
                northBan = true;
                westBan = true;
                localItem="COMPASS";
                
                
                while (compass==1)
                {
                    cout <<"This would be a nice place for a hideout!" <<endl;
                    vitals();
                    break;
                }
                
                while (healthMeter > 0 and susTravHealth > 0)
            {
                block6Function();
                cout <<endl;
                cout <<endl;
                
            }

            {
                if (healthMeter <1)
                {
                    endgame=2;
                    gameOver ();
                }
                else if (susTravHealth <1)
                {
                cout <<"The MARAUDER has fallen!" <<endl;
                cout <<endl;
                cout <<endl;
                susTravDead = 1;
                }
                
                
                if (susTravDead >0 and compass==0)
                {
                    cout << "With his last breath the MARAUDER says to you 'my compass' and hands you an OLD PEWTER COMPASS" <<endl;
                    cout << "This might be useful!" <<endl;
                    cout <<endl;
                    cout <<"want to keep it?" <<endl;
                    cout <<endl;
                    cin>> localAnswer;
                    cout <<endl;
                    
                    if (localAnswer=='y')
                    {
                    compass=1;
                    addInventory();
                    cout <<"Upon closer inspection you notice this COMPASS does not appear to point towards Magnetic NORTH" <<endl;
                    cout << "You're not sure if it's damaged or not" <<endl;
                    }
                    
                    else if (localAnswer == 'n')
                    { 
                        cout << "ONWARD THEN!" <<endl;
                        break;
                    }    
                }
                
                
            }
            
            vitals();
            break;
       }
       
        case 7 :
       {
            northBan = true;
            cout << "Looks like the Forest Road Eastern Trailhead might be just ahead to the east!" << endl;
            vitals();
            break;
       }
       
        case 8 :
       {
            northBan = true;
            cout << "Hello travler, and welcome to the Eastern Trailhead of the forest road." << endl;
            cout << "Head SOUTH then WEST to continue on the road." << endl;
            cout << "A WARNING poster is hung on the sign...an unknown person has been lurking on this trail as of late " <<endl;
            cout << "It is not advised that you linger on the road" <<endl;
           
            vitals();
            break;
       }
       
        case 9 :
       {
            northBan = true;
            cout << "A single trail winds up into the mountains. A Sign reads 'scenic overlook: 2 miles up'" << endl;
            cout << endl;
            cout << "Want to hike the path?" <<endl;
            cin>> localAnswer;
            
            if (localAnswer == 'y')
            {
                cout << "After an arduous climb, you reach the overlook. Due SOUTH, off in the distance, you see a clearing with a single LARGE TREE in it" <<endl;
                cout << "It's strange, but it almost looks like the path to the tree is blocked... maybe you should head SOUTH and check it out." <<endl;
            }
            
            else 
            {
                cout << "Onward then! " << endl;
            }
            
             vitals();
            break;
       }
       
        case 10 :
       {
            northBan = true;
                if (agua==0)
                    {
                        cout << "This part of the FOREST is quite and serene. You can see the tips of MOUNTAINS off to the NORTH" << endl;
                        cout << "a cool SPRING quenches your THIRST" <<endl;
                        agua=1;
                        healthMeter++;
                        callHealth();
                    }
                    
                else
                {
                    cout << "This part of the FOREST is quite and serene. You can see the tips of MOUNTAINS off to the NORTH" << endl;
                }    
                    
            cout <<endl;
            cout <<endl;
            vitals();
            break;
       }
       
        case 11 :
       {
            northBan = true;
            eastBan = true;
           cout << "You've reached what appears to be the edge of the forest" << endl;
           cout << "To the NORTH and to the EAST it is far too overgrown to travel any further" <<endl;
           
            vitals();
           break;
       }
       
        case 12 :
       {
            
            westBan = true;
            cout << "The WEST is blocked by high cliffs, but there are interesting ROCK FORMATIONS here, all running NORTH to SOUTH" << endl;
            cout << "Want to rest in the shade of the CLIFFS?" <<endl;
            cin >>localAnswer;
            cout <<endl;
            
            if (localAnswer == 'y')
            {
                
                if (block12 <2)
                {
                    healthMeter = healthMeter + 2;
                    money = money + 1;
                    block12 = block12 + 3;
                    cout << "That was needed! While sitting you discover a piece of GOLD." <<endl;
                    cout << "A previous traveller must have dropped it while resting!" <<endl;
                    callHealth();
                    cout <<endl;
                    callMoney();
                    cout << endl;
                }
                
                    else
                    {
                        
                        if (money >1)
                        {
                        cout << "that was a nice little nap,... but you seem to have dropped a COIN." <<endl;
                        cout<<"time to get back on the move" <<endl;
                        cout <<endl;
                        money--;
                        callMoney();
                        cout<<endl;
                        }
                        
                        else 
                        {
                            cout <<"time to get back on the move" <<endl;
                        }
                    }
            }
            
            else {
                --healthMeter;
                cout << "onward then!...but you're feeling tired " <<endl;
                cout << "Your HEALTH is now " <<healthMeter << endl;
                cout << endl;
            }
           
            vitals();
            break;
       }
       
        case 13 :
       {
            eastBan = true;
            cout << "It's quiet here.., and it looks like the OLD GREY FARMHOUSE is just ahead to the EAST. " << endl;
            cout << "the RIVER blocks your path back to the OLD GREY FARMHOUSE " << endl;
            cout <<endl;
           
            vitals();
           break;
       }
       
        case 14 :
        {
            localItem="AXE";
            westBan = true;
                if (block14<2)
                    {
                        cout << "This is where you began your journey, in barn of the OLD GREY FARMHOUSE ..." << endl;
                        cout << "There is an AXE driven into a tree stump...want to take it?" << endl;
                        cin>>localAnswer;
                            if (localAnswer=='y')
                                { 
                                    addInventory();
                                    block14 = block14 + 2 ;
                                }
                            else
                                {
                                    nextMove();
                                }
           }
           
            else 
            {
                cout <<"This is where you began your journey, in the barn of the OLD GREY FARMHOUSE" <<endl;
            }
            
            vitals();
            break;
         }
         
        case 15:
        
        {
            northBan=true;
            cout<< "What beautiful FARMLAND here. You approach the fence of a local farmer who quickly ducks inside his house" << endl;
            cout << "As you try to converse with a man passing by he shouts: ' I think it is that MARAUDER OF THE FOREST RD that has been terrorizing the town as of late" <<endl;
            cout <<endl;
            cout << "You decide not to stick around to find out what he meant by that" <<endl;
            
            vitals();
            break;
        }
        
        case 16:
        {
            northBan=true;
            cout<< "More FARMLAND. A small area looks to have been recently dug and filled." << endl;
            cout << endl; 
            cout << "Want to check it out?.." <<endl;
            cin >> localAnswer;
            
            if (localAnswer=='y')
            {
             
                cout << "You dig in the dirt, only to uncover a BURROWING MAMMAL DEN. Not only did you break quite the sweat,"<<endl;
                cout << "you also got bit by the ANIMAL who's house you just wrecked!!...ooof, tough break" <<endl;
                healthMeter = healthMeter - 2;
                callHealth();
            }
            
            else
            {
                cout << " You're right, it is far too hot to exert oneself by digging in an unknown area!!!" <<endl;
            }
            
            vitals();
            break;
        }
        
        case 17:
        {
            northBan=true;
            
            
            cout <<endl;
            cout << "A Sign reads: Forest Rd...Head East to THE FOREST, or South to Town" << endl;
            cout << "What's that smell?? Could it be the POND off to the SOUTHEAST?" <<endl;
            cout <<endl;
            roadTraveler++;
            roadTrav();
            
            vitals();
            break;
        }
        
        case 18:
        {
            southBan=true;
            
            if (oldManMet <1)
            {
                cout<< "The FOREST ROAD continues. You cross paths with an OLD MAN and his grandson. The OLD MAN says:" << endl;
                cout << "This is my grandson, he really likes to play games. He has hidden my glasses and I cannot 'see'..m to find them" <<endl;
                cout <<".....see what I did there!!? Something about apples and trees they say."  <<endl;
                cout<< endl;
                cout <<endl;
                cout << "You ask him then about this FOREST RD MARAUDER that people are talking about.." <<endl;
                cout << "The OLD MAN says: 'not to be spoken of in front of the wee one here...I have a place I sit and rest in the EAST" <<endl;
                cout<< "stop by there and I will tell you more. Bye for now!..." <<endl;
                oldManMet = 2;
                cout <<endl;
                block18 = block18 + 4;
            }
                cout <<"This might be a nice place to sit when you're old and tired!" <<endl;
                roadTraveler++;
                roadTrav();
                vitals();
                break;
        }
        
        case 19:
        {
            localItem = "PASSWORD";
            cout <<endl;
            cout<< "The FOREST RD continues on. The sound of CROWS is deafening right now " << endl;
            
            if (callTaken==1)
            {
               cout <<"Want to try using the CROW_CALL?" <<endl;
               cin>>localAnswer;
               
                if (localAnswer=='y')
                    {
                        cout<< "The CROWS seem annoyed and leave the trees revealing '8675309'..."<<endl;
                        cout<< "Not sure if that is important, maybe it's a PASSWORD or something" <<endl;
                        cout<<"want to keep that for later?"<<endl;
                        cin >>localAnswer;
                        
                            if (localAnswer=='y')
                                {
                                    password=1;
                                    addInventory();
                                }
                    }
                    
                    else 
                        {
                            
                            cout<<"ONWARD THEN!"<<endl;
                        }   
            }
            
            roadTraveler++;
            roadTrav();
            cout <<endl;
            vitals();
            break;
        }
        
        case 20:
        {
            if (wildBerries==0)
            {
            cout<< "The FOREST RD Continues on. You snack on some WILD BERRIES " << endl;
            healthMeter++;
            wildBerries=1;
            callHealth();
            }
            
            else 
            {
                cout<<"The FOREST RD Continues on. The BERRY BUSHES are bare" <<endl;
            }
            roadTraveler++;
            roadTrav();
            
            vitals();
            break;
        }
        
        case 21:
        {
            localItem = "CROW_CALL";
            
             if (callTaken==0)
            {
                cout<< "The ROAD gives way to a FOREST. The TREES stand tall, and birds of all sizes are perched high in their branches." << endl;
                cout<<"It looks like a HUNTER has dropped a CROW CALL. Want to pick it up?" <<endl;
                cin>>localAnswer;
                if (localAnswer=='y')
                {
                    addInventory();
                    callTaken=1;
                
                }
                else
                {
                    cout<< "ONWARD THEN!" <<endl; 
                }
            }    
            
            else
            {
                cout<< "The ROAD gives way to a FOREST. The TREES stand tall, and birds of all sizes are perched high in their branches." << endl;
            }
            
            vitals();
            break;
        }
        
        case 22:
        {
            if (fruit ==0)
            {
            cout<< "You snag a few pieces of low handing fruit, that should boost your energy levels!" << endl;
            healthMeter++;
            fruit=1;
            callHealth();
            }
            
            else
            {
                cout<< "The FRUIT trees which once bore FRUIT are now whithered" <<endl;
            }
            vitals();
            break;
        }
        
        case 23:
        {
            eastBan = true;
            cout<< "The FOREST GROWS very dense in the EAST. It does not look passable." << endl;
            cout<< "I believe the ROAD is back to the WEST" <<endl;
            vitals();
            break;
        }
        
         case 24:
        {
            localItem = "BOOK";
            westBan = true;
            southBan=true;
            cout<< "There is a CAVE in the ledge, enter it? " << endl;
            cout <<endl;
            cin >>localAnswer;
            
            if (localAnswer == 'y')
            {
                if (lanternTaken >3)
                {
                   cout << "great move purchasing that LANTERN. You use it to light up the CAVE" <<endl;
                   cout <<"you find a BOOK with strange characters inside. Looks like a translator or sorts" <<endl;
                   cout <<endl;
                   cout <<"want to take it?" <<endl;
                   cout <<endl;
                   cin >>localAnswer;
                   
                   if (localAnswer== 'y'){
                       bookTaken = bookTaken + 4;
                       addInventory();
                       money = money + 2;
                       cout <<endl;
                       cout << "hey! you found 2 GOLD COINS!" <<endl;
                       cout <<endl;
                       callMoney();
                   }
                   else {
                       cout <<endl;
                       cout << "You leave the BOOK" <<endl;
                       cout <<endl;
                   }
                   
                }
                
                else {
                   cout <<endl;
                   cout << "It's far too dark to see anything in here. You EXIT the CAVE" <<endl;
                   cout <<endl;
                    
                }
            }
            
            else {
                cout<< "CAVES are a bit scary I suppose" <<endl;
                
            }
            
             vitals();
            break;
        }
        
        case 25:
        {
           
            southBan = true;
            eastBan = true;
            cout<< "Looks like FARMLAND. Not much happening here, the RIVER blocks passage EAST and SOUTH" << endl;
            vitals();
            break;
        }
    
        case 26:
        {
            
            westBan = true;
            cout<< "You see another BARN ahead" << endl;
            cout<< "Want to Check it out?" <<endl;
            cin>> localAnswer;
            
            if (localAnswer == 'y')
            {
                cout <<"It is incredibly dusty in the barn, sending you into a sneezing fit! You try to run out of there"<<endl;
                cout<<"as quickly as possible, and hit your knee on the door frame....ouch!"<<endl;
                healthMeter--;
                callHealth();
            }
            
            else if (localAnswer=='n')
            {
                cout<<"ONWARD THEN!" <<endl;
            }
            vitals();
            break;
        }
        
        case 27:
        {
            cout<< "FOREST ROAD... A Sign reads: Head EAST to the POND or SOUTH to the TEMPLE" << endl;
            roadTraveler++;
            roadTrav();
             vitals();
            break;
        }
        
        case 28:
        {
            cout<< "This section has a STEEP incline that is tough on the legs! " << endl;
            healthMeter--;
            callHealth();
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 29:
        {
            eastBan=true;
            cout<< "FOREST RD, POND just ahead" << endl;
            cout <<"'BEWARE, dangerous folk about' is etched into a tree along the FOREST ROAD here" << endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 30:
        {
            cout<< "You've located the POND, and boy does it smell bad!" << endl;
             vitals();
            break;
        }
        
        case 31:
        {
            westBan=true;
            cout<< "A STONE STATUE of a large healthy tree stands tall... unfamiliar characters read" << endl;
            
            if (bookTaken > 2)
            {
            cout<< "trim away the whithered so the new growth can thrive" <<endl;
            }
            
            else 
            {
                cout << "coatza uf tchold pura yonguea execelsior" <<endl;
            }
            vitals();
            break;
        }
        
        case 32:
        {
            cout<< "This is the EDGE OF TOWN, outside the protection of any authorities. THE FOREST is just ahead to the East" << endl;
            vitals();
            break;
        }
        
        case 33:
        {
            cout<< "Entering edge of THE FOREST " << endl;
            vitals();
            break;
        }
        
        case 34:
        {
            cout<< "Forest" << endl;
            vitals();
            break;
        }
        
        case 35:
        {
            quitgame = 0;
            eastBan=true;
            cout<< "An OLD MAN sits on a stump. Want to talk to him?" << endl;
            cin >> localAnswer;
            
            if (localAnswer == 'y')
            {
                
                if (block18 >2)
                {
                    cout << "why yes I do remember meeting you on the FOREST RD. I will tell you what I know, but it's not pretty" <<endl;
                    cout << "Want to play Blackjack?" <<endl;
                    cin >> localAnswer;
                    
                    if (localAnswer = 'y')
                        {
                            while (quitgame < 1)
                                {
                                mainGame();
                                }
                         }
                    
                    else 
                    {
                        cout << "well what do you want then!!!?" <<endl;
                    }
                    
                    
                }
                
                else
                {
                    cout <<"The OLD MAN might be asleep right now, hard to tell..." <<endl;
                }
                
            }
            
            else 
            {
                cout << "Onward then!" <<endl;
            }
            
            vitals();
            break;
        }
        
        case 36:
        {
            
            northBan=true;
            westBan = true;
            cout<< "An APIARY! want to collect some HONEY?" << endl;
            cin>>localAnswer;
            
            
            if (beenTo36==2)
            {
                cout <<"The FARMER appears to have let his APIARY fall to disrepair" <<endl;
                cout <<"The SWARMS of BEES help you decide to move on!" <<endl;
            }
            else if (beenTo36==0)
            {
                if (localAnswer=='y')
                    {
                        cout<<" It might have been 15, but it also might have been 20...BEE STINGS that is..." <<endl;
                        cout<<"The HONEY is a nice snack though!" <<endl;
                        healthMeter--;
                        callHealth();
                    }
                         else if (localAnswer =='n')
                            {
                                beenTo36=2;
                                cout <<"I never trusted BEES either!" <<endl;
                                cout <<"The BEE FARMER approaches you and offers a MEAL and COOL GLASS OF WATER ... which you accept!" <<endl;
                                healthMeter++;
                                callHealth();
                                vitals();
                                break;
                                
                            }
                        
            }   
            
            
            
            vitals();
            break;
        }
        
        case 37:
        {
            
            northBan=true;
            cout<< "You've located an OLD WELL that seems to be dry. You can't see the bottom." << endl;
            cout <<"Want to throw a GOLD COIN in for good luck" <<endl;
            cin >>localAnswer;
            
            if (localAnswer == 'y')
            {
                cout <<endl;
                cout <<"That was dumb" <<endl;
                money--;
                cout <<endl;
                callMoney();
                
            }
            
            else 
            {
                cout <<"If you didn't have bad luck you wouldn't have luck at all!" <<endl;
            }
            vitals();
            break;
        }
        
        case 38:
        {
            
            cout<< "The local FARMLAND is beautiful. You enjoy traversing the fields and admire the handmade fences and walkways" << endl;
            cout<<endl;
            vitals();
            break;
        }
        
        case 39:
        {
            
            cout<< "Forest Road. The TOWN MEETINGHOUSE is just to the EAST" << endl;
            cout <<"Head SOUTH to visit the TEMPLE" <<endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 40:
        {
            cout<< "You have arrived at the Town Meeting House..." << endl;
            cout << "A couple is chatting and offer some unsolicited advice..." <<endl;
            cout <<endl;
            cout <<"They say that 'a book which will help you decipher the ancient language can be found in the NORTHWEST" <<endl;
            cout <<"You must shine light in the darkenss to find this ancient relic...'" <<endl;
            cout<<endl;
            
            if (bookTaken >2){
                cout <<endl;
                cout<< "You ask them ....what might it be used for?" <<endl;
                cout<< endl;
                cout <<endl;
                cout << "'why...for translating of course!!'....they say" <<endl;
                cout <<endl;
            }
            
            else {
            cout <<endl;
            cout <<"you politley thank them and ask for more details " <<endl;
            cout<< "They say 'There is one bridge to cross into the NORTHWEST. You then must follow the WESTERN CLIFFS South" <<endl;
            }
            vitals();
            break;
        }
        
        case 41:
        {
            
            southBan=true;
            cout<< "This section of TOWN is fairly quiet. To the WEST you can see the MEETINGHOUSE" << endl;
            vitals();
            break;
        }
        
        case 42:
        {
            
            northBan=true;
            cout<< "To the SOUTH you see the CEMETARY GATE" << endl;
            vitals();
            break;
        }
        
        case 43:
        {
           
            southBan = true;
            cout<< "Off to the NORTH you see a STATUE, to the WEST is TOWN, and the FOREST is in the EAST" << endl;
            vitals();
            break;
        }
        
        case 44:
        {
            
            southBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTHEAST" <<endl;
            }
            
            cout<< "Forest" << endl;
            vitals();
            break;
        }
        
        case 45:
        {
            southBan = true;
            
            if (compass == 1)
            {
                cout<<"You're really enjoying this FOREST, it reminds you of the TRAILS you hike back HOME"<<endl;
                cout << "The COMPASS points SOUTH" <<endl;
            }
            
           else if (compass ==5)
           {
            cout<<"You're really enjoying this FOREST, it reminds you of the TRAILS you hike back HOME"<<endl;
           }
            
            vitals();
            break;
        }
        
        case 46:
        {
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTHWEST" <<endl;
            }
            
            cout<<"To the NORTHEAST you can just barely see the OLD MAN that loves to play GAMES" <<endl;
            vitals();
            break;
        }
        
        case 47:
        {
            eastBan = true;
            cout<< "This FOREST IS huge! ...A STEEP LEDGE blocks passage to the EAST " << endl;
            vitals();
            break;
        }
        
        case 48:
        {
            westBan = true;
            cout<< "Forest Road, West Trailhead." << endl;
            cout<< "BE ADVISED! On more than one occasion it has been reported that travelers on this road were abducted" <<endl;
            cout<< "many have reported that they were hit from behind, with their money and or possessions taken" <<endl;
            cout <<endl;
            cout<< "You have been warned!" <<endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 49:
        {
            cout<< "The FOREST RD makes TRAVEL easy here, The TOWN can be seen in the SOUTH" << endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 50:
        {
            cout<< "The FOREST RD continues, the APOTHECARY can be seen in the SOUTH" << endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 51:
        {
            cout<< "Forest Road. Head North to continue on the road, head east to explore the town " << endl;
            cout << "Looks like there may have been a fight here..." <<endl;
            roadTraveler++;
            roadTrav();
            vitals();
            break;
        }
        
        case 52:
        {
            eastBan=true;
            
            if (money >=2 and box <4)
            {
                cout<< "You have located the TOWN MARKET. There are a variety of PEDDLARS here offering up interesting GOODS" << endl;
                cout<< "You decide to visit a GREEN TENT in the far corner of the market" <<endl;
                cout<< "The PEDDLAR offers you the chance to purchase a box for 2 COINS. Want to buy one"<<endl;
                cin >> localAnswer;
                    if (localAnswer =='y')
                        {
                         int chance = 1 + (rand() % 4);
                            if (chance == 1)
                                {
                                    cout <<endl;
                                    cout << "The BOX was EMPTY!, what a waste!" <<endl;
                                    cout<< "ONWARD!" <<endl;
                                    money = money - 2;
                                    callHealth();
                                    callMoney();
                                    box++;
                                    
                                }
                            else if (chance == 2)
                                 {
                                    cout <<endl;
                                    cout << "Inside the BOX was an APPLE... very tasty!" <<endl;
                                    cout<< "ONWARD!" <<endl;
                                    healthMeter++;
                                    money = money - 2;
                                    callHealth();
                                    callMoney();
                                    box++;
                                    
                                }
                            else if (chance == 3)
                                {
                                    cout <<endl;
                                    cout <<"The BOX contained 3 GOLD COINS!" <<endl;
                                    money++;
                                    callHealth();
                                    callMoney();
                                    box++;
                                    
                                }
                            else if (chance == 4)
                                {
                                    cout <<endl;
                                    cout <<"Inside the BOX was the PEDDLAR'S WRISTWATCH. The PEDDLAR GREW VERY ANGRY AT THE SIGHT OF THIS" <<endl;
                                    cout << "What kind of game are you playing here???! said the PEDDLAR"<<endl;
                                    cout<<endl;
                                    cout<< "He chases you out of the TENT, and while running away you twist an ankle. OUCH!" <<endl;
                                    healthMeter--;
                                    callHealth();
                                    callMoney();
                                    box++;
                                    
                                }
                        }
                        else if (localAnswer =='n')
                        {
                            cout << "ONWARD THEN!"<<endl;
                        }
            }            
            
            else if (money <2 or box ==4)
            {
                cout <<"A SIGN is posted:  OUT TO LUNCH" <<endl;
            }
            
            vitals();
            break;
        }
        
        case 53:
        {
            northBan = true;
            westBan = true;
            cout<< "Some of these GRAVESTONES date back hundreds of years. Looks like a large MAUSOLEUM is in the" << endl;
            cout<<"SOUTHERN section of the CEMETARY" <<endl;
            vitals();
            break;
        }
        
        case 54:
        {
            cout<< "Cemetary Gate" << endl;
            vitals();
            break;
        }
        
        case 55:
        {
            northBan = true;
            eastBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points EAST" <<endl;
            }
            
            cout<< "The CEMETARY GATE blocks your passage to the east" << endl;
            cout <<"Want to try to climb it?" <<endl;
            cin >>localAnswer;
            
            if (localAnswer == 'y')
            {
                cout<< "bad idea.... you hurt yourself badly trying the scale the fence"<<endl;
                healthMeter = healthMeter - 3;
                callHealth();
            }
            
            else if (localAnswer =='n')
            {
                cout <<"ONWARD THEN!"<<endl;
            }
            vitals();
            break;
        }
        
        case 56:
        {
            northBan = true;
            westBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTHEAST" <<endl;
            }
            
            cout<< "The FOREST gives way in the WEST, and you can see the CEMETARY in the distance" << endl;
            vitals();
            break;
        }
        
        case 57:
        {
            northBan = true;
            southBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTH" <<endl;
            }
            
            cout<< "Forest" << endl;
            vitals();
            break;
        }
        
        case 58:
        {
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTHWEST" <<endl;
            }
            
            cout<< "Tall trees block your vision SOUTHWEST" << endl;
            vitals();
            break;
        }
        
        case 59:
        {
            
            eastBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points SOUTHWEST" <<endl;
            }
            
            cout<< "THe FOREST is very THICK here. Very THICK indeed! It is quite difficult to move through the BRIAR" << endl;
            healthMeter--;
            vitals();
            break;
        }
        
        case 60:
        {
            southBan = true;
            westBan = true;
            cout<< "You have located a WOODEN CHEST. Would you like to OPEN IT?" << endl;
            cin>>localAnswer;
            
                if (chest <1)
                {
                        if (localAnswer=='y')
                    {
                    chest=1;
                    money = money + 5;
                    cout << "You have found 5 GOLD COINS!...Let's GO!!" <<endl;
                    callMoney();
                    }
                          else if (localAnswer=='n')
                        {
                            cout<< "ONWARD THEN!" <<endl;
                        }
                }    
                
                else if (chest > 0)
                {
                    cout <<"You stop for a second to remember that time you found 5 GOLD COINS here." <<endl;
                    cout << "ONWARD!"<<endl;
                }
                
            vitals();
            break;
        }
        
        case 61:
        {
            southBan = true;
            cout<< "Village of KOI. Off to the WEST you see what appears to be a QUARRY of some sort" << endl;
            cout << "from the EAST you can still smell the APOTHECARY. The FOREST RD is due NORTH" <<endl;
            vitals();
            break;
        }
        
        case 62:
        {
            southBan = true;
            char medicine;
            char answer;
            
            cout<< "Apothecary, Villiage of Koi. Many interesting medicines ... have a look around?" << endl;
            cout <<endl;
            cin >>answer;
            cout << endl;
            
            if (answer =='y')
                {
                    cout << "The Alchemist asks 'oh you're a traveller eh...?, try this. Made from the blood of cloven beasts it is." <<endl;
                    cout <<"It'll uplift you when weary, and is known to produce temporary bursts of strenght!!'" << endl;
                    cout <<endl;
                    cout <<"Purchase medicine?" <<endl;
                    cin >>medicine;
                     if (medicine =='y') 
                        {
                             cout << "that'll be 3 gold coins thanks" <<endl;
                             if (money <3)
                                 {
                                    cout << "what'ya mean you dont have 3 coins!??.." <<endl;
                                    cout << "get on out of here!!" <<endl;
                                    break;
                         }
                    
                    else 
                    {
                    healthMeter++;
                    money = money - 3;
                    callMoney();
                    callHealth();
                    }
                   
                }
                    }
                        else
                            {
                            cout <<"ONWARD THEN!"  <<endl;
                            }
            vitals();
            break;
        }
        
        case 63:
        {
           southBan = true;
           
            
            cout<< "The TEMPLE STEPS are before you, would you like to ENTER the TEMPLE?" << endl;
            cin>> localAnswer;
            
            
            if (candleLit == 0)
            {
                if (localAnswer == 'y')
                    {
                        cout<< "The TEMPLE is empty, except for a SHRINE with candles and incense burning. It's COLD and DRAFTY"<<endl;
                        cout<<"Would you like to light a CANDLE?" <<endl;
                        cin >> localAnswer;
                            if (localAnswer =='y')
                                {
                                    healthMeter = healthMeter + 2;
                                    candleLit=1;
                                    cout << "After lighting the CANDLE you rest momemtarily and reflect on your journey thus far." <<endl;
                                    cout << "You feel inspired and invigorated!"<<endl;
                                    callHealth();
                                }
                    }
                        else if (localAnswer == 'n')
                            {
                                cout <<"ONWARD THEN!" <<endl;
                                healthMeter--;
                                callHealth();
                            }
            }
            
            else if (candleLit ==1)
            {
                 cout<< "The TEMPLE is empty, except for a SHRINE with candles and incense burning. It's COLD and DRAFTY" <<endl;
                 cout <<"There are no CANDLES that you may light" <<endl;
                 cout <<"ONWARD THEN!" <<endl;
                 
            }
            
            vitals();
            break;
        }
        
        case 64:
        {
            char drink;
            southBan = true;
            eastBan = true;
            
            //spacing();
            
            cout<< "The Bark & Barell Tavern, town of Koi. Appropriately named, as a" << endl;
            cout << "clump of tavern goers pour draughts off a single barrel while an old dog snores away" <<endl;
            cout<< "strange music is errupting  in the corner. A single performer with a disproportionate sound is mid set. " <<endl; 
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout<< "thirsty are ye??? " <<endl;
            cin >>drink;
            
            if (drink == 'y'){
                cout <<endl;
                cout << "you saddle up and drink into the wee hours with your new ahhem....friends. They mistake you for another and you" <<endl;
                cout <<"do not correct them. In your conversation you learn of a tree in the east which sounds hollow but is actually" <<endl;
                cout << "stone-like and petrified. You fell asleep at the table, and when you awoke the barkeep demanded 8 gold " << endl;
                cout << "coins for your tab" <<endl;
                
                if (money >8)
                {money = money - 8;
                cout <<endl;
                cout <<endl;
                cout << " you pay the tab and consider yourself lucky to get out of there." <<endl;
                callMoney();
                }
                
                else 
                --healthMeter;
                cout <<endl;
                cout <<endl;
                cout << "you wash dishes for 3 days to pay your tab. You hardly sleep and you don't eat well" <<endl;
                cout << "your health meter now reads ..." << healthMeter <<endl;
                cout <<endl;
                cout <<endl;
                
                
            }
           
            vitals();
            break;
        }
        
        case 65:
        {
            
            southBan = true;
            westBan = true;
            cout<< "This section of the CEMETARY contains very small headstones. There probably isnt anything of interest here. Want to look around anways? " << endl;
            
            if (localAnswer =='y')
            {
                cout << "You stroll among the headstones, paying close attention to the dates. Some of these stones date back hundreds of years, and others" <<endl;
                cout <<"are marked with unfamiliar characters. A thicket of grass approximately 3 feet tall grows. Want to check it out?" <<endl;
                cin >>localAnswer;
                
                if (localAnswer=='y')
                {
                    cout << "you brush the grass aside in search of COINS, and cut your hand on an OLD SICKLE" <<endl;
                    healthMeter--;
                    callHealth();
                    cout<< endl;
                    cout <<"Let's get out of here" <<endl;
                }
                
                else
                {
                   cout<< "good move, it's probably not right to dig throug a cemetary" <<endl; 
                    
                }
            }
            
            else 
            {
                cout <<"OK, let's get out of here" <<endl;
            }
            
            vitals();
            break;
        }
        
        case 66:
        {
             southBan = true;
             cout<< "A large MAUSOLEUM towers above the cemetary" << endl;
             cout << "It bears an odd message in an unfamiliar language" <<endl;
             
             if (bookTaken >2)
             {
                 cout << "One will find their way out in the South EAST" <<endl;
             }
             
             else 
             {
                 cout <<"fofity truhg clige, en lez Suiode Eshme" <<endl;
             }
            break;
        }
        
        case 67:
        {
            southBan = true;
            eastBan = true;
            if (compass == 1)
            {
                cout <<"This CEMETARY is bigger than you expected!" <<endl;
                cout << "The COMPASS points EAST" <<endl;
                
            }
            
            cout <<"This CEMETARY is bigger than you expected!" <<endl;
            vitals();
            break;
        }
        
        case 68:
        {
            southBan = true;
            westBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points EAST" <<endl;
            }
            
             cout<< "forest" << endl;
            vitals();
            break;
        }
        
        case 69:
        {
           
            cout<< "You have reached the OLD TREE! Could this be the way out?" << endl;
            cout<<endl;
            
            if (block14 >1)
            {
                cout << "You see that the tree is covered in VINES. Want to cut VINES?" <<endl;
                cin >> localAnswer;
                
                if (localAnswer== 'y')
                {
                   
                   cout <<"You swing the AXE repeatedly at the VINES, successfully cutting them away and"<<endl;
                   cout<<"revealing a door. You knock and are prompted for the password. Do you know it?" <<endl;
                   cin>> localAnswer;
                   
                        if (localAnswer =='y' and password==1)
                            {
                                gameComplete();
                                abort();
                            }
                            
                        else
                            {
                                cout<<"Better go find that PASSWORD THEN!" <<endl;
                            }
                    
                    
                    
                }
                
                else if (localAnswer == 'n')
                {
                    cout <<"So....now what?" <<endl;
                    vitals();
                    break;
                }
            }
            
            else 
            {
            cout << "You see that the tree is covered in VINES. Is there any way you could cut the VINES?" <<endl;
            vitals();
            break;
            }
        }
        
        case 70:
        {
            southBan = true;
            westBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points WEST" <<endl;
            }
            
            cout<< "Forest" << endl;
            vitals();
            break;
        }
        
        case 71:
        {
            southBan = true;
            eastBan = true;
            if (compass == 1)
            {
                cout << "The COMPASS points WEST" <<endl;
            }
            
            cout<< "Forest " << endl;
             vitals();
            break;
        }
    }
    
}  // function contains location descriptions 

void gameComplete()
{
                    cout<<endl;
                    //cout << "After cutting the VINES, the TRAVELER was able to see an OPENING in the TREE TRUNK" <<endl;
                    cout<<"++++++++++++++++++++++++++++++++++++" <<endl;
                    cout<<"C O N G R A T U L A T I O N S !!"<<endl;
                    cout<<"++++++++++++++++++++++++++++++++++++" <<endl;
                    cout<<endl;
                    cout<< "The TRAVELER passed through the OPENING, and quickly realized he had entered an UNDERWORLD. He turned around, only to see" <<endl;
                    cout <<"that the OPENING has already closed behind him." <<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<< "Stay tuned for Part 2 of ONWARD!, in which our travelling friend will continue his journey home" <<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<< "Thank you for playing ONWARD!" <<endl;
                    cout<<"Goodbye!" <<endl;
                    cin>>localAnswer;
}

void deal () // deals starting cards, labels those as totals, and prints totals
{
    if (money >0)
    {
   	    srand((unsigned) time(NULL));
		int playerCard1 = 1 + (rand() % 11);
		int oldManCard1  = 1 + (rand() % 11); 
		
		cout << endl;
		cout << "+++++++++++++++" << endl;
		cout << "YOU have  " <<playerCard1 <<endl;
		cout << "the OLD MAN has  " << " ** " <<endl;
		cout <<endl;
		playerTotal = playerCard1;
		oldManTotal = oldManCard1;
    }
        else
        {
            cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
            cout<<"YOU'RE BROKE!" <<endl;
            cout <<"Come back when you want to lose more money!" <<endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
            //abort();
            quitgame=quitgame + 5;
            nextMove();
        }
}

void checkTotal()
{
    while (playerTotal < 22)
    {
        cout <<endl;
        cout << "Would you like another card?" <<endl;
        cout <<endl;
        cin >> localAnswer;
        
        if (localAnswer == 'y')
        { 
            draw ();
        }
        
        else if (localAnswer == 'n')
        {
            cout << "The OLD MAN says: 'OK, OK, my turn..." <<endl;
            cout <<endl;
            oldManDraw();
          
        }
        
    }
    
        cout <<endl;
        cout << "Your total is " << playerTotal <<endl;  
        cout << "BUSTED! YOU LOSE...the OLD MAN says: 'pay up!!" <<endl;
        
        money--;
        
        cout << "YOU have " << money << " COINS" <<endl;
        
        oldManTotal=0;
        playerTotal=0;
        cout <<endl;
        
        cout << "Want to play again??" <<endl;
        cout <<endl;
        cin >>localAnswer;
                
            if (localAnswer == 'y')
                {
                    deal();
                    checkTotal();
                }
                                
            else if (localAnswer =='n')
                {
                cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                cout <<"Come back when you want to lose more money!" <<endl;
                cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                nextMove();
                //abort();
                //quitgame=quitgame + 5;
                    //cout <<"Come back when you want to lose more money!!" <<endl;
                    //abort ();
                }

}

void draw ()
{
  int drawCard = 1 + (rand() % 11);
  playerTotal = playerTotal + drawCard;
  cout << "YOU have  " << playerTotal <<endl;
  cout << "The OLD MAN has  " << " ** " << endl;
  checkTotal();
}

void oldManDraw()
{
    while (oldManTotal < 17)
    {
        int drawCard = 1 + (rand() % 11);
        oldManTotal = oldManTotal + drawCard;
        cout <<endl;
        cout << "I'd better take another card...."  <<endl;
        cout <<endl;
        checkOldTotal();
    }
}

void checkOldTotal()
{
   
        if (oldManTotal < 16)
        {
            oldManDraw();
        }
            
        else if (oldManTotal > 16 and oldManTotal <= 21)
            {
                    
                if (oldManTotal > playerTotal)
                    {
                        cout << "#" <<endl;
                        cout << "YOU lose!... The OLD MAN says: 'pay up!!" <<endl;
                        money--;
                        cout <<endl;
                        cout << "YOU HAD " << playerTotal << endl;;
                        cout << "THE OLD MAN had " << oldManTotal<< endl;
                        cout << endl;
                        cout << "YOU have " << money << " COINS" <<endl;
                        cout <<endl;
                        oldManTotal=0;
                        playerTotal=0;
                        cout << "Want to play again" <<endl;
                        cin >>localAnswer;
                            if (localAnswer == 'y')
                                {
                                    deal();
                                    checkTotal();
                                }
                                
                                else if (localAnswer =='n')
                                    {
                                        cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                        cout <<"Come back when you want to lose more money!" <<endl;
                                        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                        nextMove();
                                        //abort();
                                       // quitgame=quitgame + 5;
                                        //abort ();
                                    }
                    }
                    
                    else if (playerTotal > oldManTotal and oldManTotal <22)
                    {
                        cout << "YOU had " << playerTotal <<endl;
                        cout << "THE OLD MAN had " <<oldManTotal <<endl;
                        cout <<endl;
                        cout <<"$" <<endl;
                        cout <<"YOU win!!.... the OLD MAN says: oooof!" <<endl;
                        money++;
                        cout << "YOU have " << money << " COINS" <<endl;
                        cout <<endl;
                        oldManTotal=0;
                        playerTotal=0; 
                        cout <<"Want to play again??" <<endl;
                        cin >>localAnswer;
                            if (localAnswer == 'y')
                                {
                                    deal();
                                    checkTotal();
                                }
                                
                                else if (localAnswer =='n')
                                    {
                                        cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                        cout <<"Come back when you want to lose more money!" <<endl;
                                        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                     nextMove();
                                     //abort();
                                        //quitgame=quitgame + 5;
                                        //cout <<"Come back when you want to lose more money!!" <<endl;
                                        //abort ();
                                    }
                    }
                    
                    else if (playerTotal == oldManTotal)
                    {
                        cout <<"&" <<endl;
                        cout << "BOTH PLAYERS HAVE " <<playerTotal << endl;
                        cout <<"IT'S A PUSH" <<endl;
                        cout << "YOU have " << money << " COINS" <<endl;
                        cout <<endl;
                        oldManTotal=0;
                        playerTotal=0; 
                        cout <<"Want to play again??" <<endl;
                        cin >>localAnswer;
                            if (localAnswer == 'y')
                                {
                                    deal();
                                    checkTotal();
                                }
                                
                                else if (localAnswer =='n')
                                    {
                                        //abort ();
                                        cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                        cout <<"Come back when you want to lose more money!" <<endl;
                                        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                                        //abort();
                                        //quitgame=quitgame + 5;
                                        nextMove();
                                    }
                    }
            }
            
            else 
            {
                cout <<"YOU had " <<playerTotal <<endl;
                cout << "THE OLD MAN had " <<oldManTotal <<endl;
                cout <<endl;
                cout <<"$" <<endl;
                cout <<"YOU win!!.... the OLD MAN says: oooof!" <<endl;
                money++;
                cout << endl;
                cout << "YOU have " << money << " COINS" <<endl;
                cout <<endl;
                oldManTotal=0;
                playerTotal=0; 
                cout <<"Want to play again??" <<endl;
                cin >>localAnswer;
                    if (localAnswer == 'y')
                        {
                            deal();
                            checkTotal();
                        }
                                
                    else if (localAnswer =='n')
                        {
                            cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                            cout <<"Come back when you want to lose more money!" <<endl;
                            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
                            nextMove();
                            //abort();
                            //quitgame=quitgame + 5;
                            //abort ();
                        }
            }
    
    }
    
void resetBan ()
{
    northBan = false;
    southBan = false;
    eastBan = false;
    westBan = false;
 
}  // funcion removes travel bans
