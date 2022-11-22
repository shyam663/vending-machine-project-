

#include <iostream>
#include <string>
using namespace std;

const int ORDER_MAX = 5;
const int AUTOMAT_MAX = 10;

class Food {  
  private:
    string myName;
    int myCalories;
    double myPrice;

  public:
    Food();
    Food(string name,int cal, double price);
    int getCalories();
    double getPrice();
    void setName(string name);
    void setCalories(int cal);
    void setPrice(double price);
    void display();
    
};
Food::Food()
{
  myName = "";
  myCalories = 0;
  myPrice = 0;
}

Food::Food(string name,int cal, double price)
{
  myName = name;
  myCalories = cal;
  myPrice = price;
}

int Food::getCalories()
{
  return myCalories;
}

double Food::getPrice()
{
  return myPrice;
}

void Food:: setName(string name)
{
  myName = name;
}

void Food::setCalories(int cal)
{
  myCalories = cal;
}

void Food::setPrice(double price)
{
  myPrice = price;
}
void Food::display()
{
  cout<< myName <<": "<< myCalories <<" calories, $"<<myPrice;
}

class Drink 
{
  private:
    string myName;
    int myOunces;
    double myPrice;

  public:
    Drink();
    string getName();
    int getOunces();
    double getPrice();
    void setName(string name);
    void setOunces(int onces);
    void setPrice(double price);
    void display();
    Drink(string name, int oz , double price);
};

 Drink::Drink()
 {
      myName = "";
      myOunces = 0;
      myPrice = 0;
    }

Drink::Drink(string name, int oz , double price)
    {
      myName = name;
      myOunces = oz;
      myPrice = price;
    }

string Drink::getName()
{
  return myName;
}

int Drink::getOunces()
{
  return myOunces;
}

double Drink::getPrice()
{
  return myPrice;
}

void Drink::setName(string name)
{
  myName = name;
}

void Drink::setOunces(int ounces)
{
  myOunces = ounces;
}

void Drink::setPrice(double price)
{
  myPrice = price;
}

void Drink::display()
{
  cout<< myName <<": "<<myOunces <<" ounces, $"<<myPrice;
}

class Automat 
{
  private:
    Food myFood[AUTOMAT_MAX];
    Drink myDrink[AUTOMAT_MAX];
    int myFoodFront;
    int myFoodBack;
    int myDrinkFront;
    int myDrinkBack;

  public:
    Automat();
    bool emptyFood();
    bool emptyDrink();
    void enqueue(Food food_item);
    void enqueue(Drink drink_item);
    void dequeueFood();
    void dequeueDrink();
    Food frontFood();
    Drink frontDrink();
    int foodCount();
    int drinkCount();
    int getTotalCalories();
    int getTotalOunces();
    double getTotalPrice();
    void display();
};

void Automat::display()
{
	cout << "Automat: " << endl;
	cout << "  Food: " << endl;
	for(int i=myFoodFront; i!=myFoodBack; i = (i+1)%AUTOMAT_MAX)
	{
		cout << "\t";
		myFood[i].display();
	}
	cout << "  Drink: " << endl;
	for(int i=myDrinkFront; i!=myDrinkBack; i = (i+1)%AUTOMAT_MAX)
	{
		cout << "\t";
		myDrink[i].display();
	}
	cout << endl;
}

Automat::Automat()
{
  myFoodFront = 0;
  myFoodBack = 0;
  myDrinkFront = 0;
  myDrinkBack = 0;
}

bool Automat::emptyFood()
{
  return myFoodFront == myFoodBack;
}

bool Automat::emptyDrink()
{
  return myDrinkFront == myDrinkBack;
}

void Automat::enqueue(Food food_item)
{
  myFood[myFoodBack] = food_item;
  myFoodBack++;
}

void Automat::enqueue(Drink drink_item)
{
  myDrink[myDrinkBack] = drink_item;
  myFoodBack++;
}

void Automat::dequeueFood()
{
  myFoodBack--;
}

void Automat::dequeueDrink()
{
  myFoodBack--;
}

Food Automat::frontFood()
{
  return myFood[myFoodFront];
}

Drink Automat::frontDrink()
{
  return myDrink[myDrinkFront];
}

int Automat::foodCount()
{
  return myFoodBack - myFoodFront + 1;
}

int Automat::drinkCount()
{
  return myFoodBack - myFoodFront + 1;
}

int Automat::getTotalCalories()
{
  int total_cal = 0;
  for (int i = myFoodFront;i<myFoodBack;i++){
    total_cal += myFood[i].getCalories();
  }
  return total_cal;
}

int Automat::getTotalOunces()
{
  int total_oz = 0;
  for (int i = myDrinkFront;i<myDrinkBack;i++){
    total_oz += myDrink[i].getOunces();
  }
  return total_oz;
}

double Automat::getTotalPrice()
{
  double total_price = 0.0;
  for (int i = myFoodFront;i<myFoodBack;i++){
    total_price += myFood[i].getCalories();
  }
  for (int i = myDrinkFront;i<myDrinkBack;i++){
    total_price += myDrink[i].getOunces();
  }
  return total_price;
}

class Order 
{
  private:
  Food myFood[ORDER_MAX];
    Drink myDrink[ORDER_MAX];
    int myFoodTop;
    int myDrinkTop;
    static int myTotalOrders;
    

  public :
    Order();
    bool emptyFood();
    bool emptyDrink();
    void push(Food f);
    void push(Drink d);
    void popFood();
    void popDrink();
    int foodCount();
    int drinkCount();
    double getTotalPrice();
    void display();
    void cancel();
    void purchase();
    Food topFood();
    Drink topDrink();
    void cancel(Automat & a);
    static int getTotalOrder();
};
// start
int Order::myTotalOrders = 0;


Order::Order()
{
  myFoodTop = -1;
  myDrinkTop = -1;
  myTotalOrders++;
}

bool Order::emptyFood()
{
return myFoodTop==-1;
}

bool Order::emptyDrink()
{
return myDrinkTop==-1 ;
}

void Order::push(Food f)
{

  if (myFoodTop+1 == ORDER_MAX)
  {
   cout << "Error"<< endl;
  }

  else 
  {
  myFoodTop++;
  myFood[myFoodTop]=f;
  }
  
}

void Order::push(Drink d)
{
 if (myDrinkTop+1 == ORDER_MAX)
  {
  cout << "Error"<< endl;
  }

  else 
  {
  myDrinkTop++;
  myDrink[myDrinkTop]=d;
  }
}

void Order::popFood()
{
  if (myFoodTop==-1)
  {
  cout << "Error"<<endl;
  }

  else
  {
  myFoodTop--;
  }
}

void Order::popDrink()
{
  if (myDrinkTop==-1)
  {
  cout << "Error"<<endl;
  }

  else
  {
  myDrinkTop--;
  }
}

Food Order::topFood()
{
return myFood[myFoodTop];
}

Drink Order::topDrink()
{
return myDrink[myDrinkTop];
}

int Order::foodCount()
{
  int sum = 0;

  for (int i = 0;i <= myFoodTop;i++)
  {
  sum++;
  }  

  return sum;
}

int Order::drinkCount()
{
  int sum = 0;

  for (int i = 0;i <= myDrinkTop;i++)
  {
  sum++;
  }  

  return sum;
}

double Order::getTotalPrice()
{
  int sum = 0;

  for (int i = 0;i <= myFoodTop;i++)
  {
  sum+=myFood[i].getPrice();
  }  

  for (int i = 0;i <= myDrinkTop;i++)
  {
  sum+=myDrink[i].getPrice();
  } 

  return sum;
}

void Order::display()
{
  cout << "Order: " << endl;
  cout << "\t Food (" << foodCount() << " items):" << endl;

  for (int i=0;i <= myFoodTop;i++)
  {
  cout <<"\t\t ";
  myFood[i].display();
  }
  
  cout << "\t Drink ( " << drinkCount() << "items): " << endl;
  for (int i =0;i <= myDrinkTop;i++)
  {
  cout <<" \t\t ";
  myDrink[i].display();
  }

  cout << "Order Total: $ " << getTotalPrice() << endl;
}

void Order::cancel(Automat & a)
{
  for (int i = 0;i <= myFoodTop;i++)
  {
  a.enqueue(topFood());
  popFood();
  }
  
  for (int i = 0;i <= myDrinkTop;i++)
  {
  a.enqueue(topDrink());
  popDrink();
  }
}

void Order::purchase()
{
myFoodTop=-1;
myDrinkTop=-1;
}

int Order::getTotalOrder()
{
return myTotalOrders;
}

//stop

int main() 

{

  Automat a;
a.enqueue(Food("Let's Potato Chips", 300, 1.50));
a.enqueue(Food("Mini Donuts", 500, 1));
a.enqueue(Drink("Coffee", 6, 5.50));
a.enqueue(Drink("Nacho Drink", 22, 2.50));
cout << "Starting Automat\n";
a.display();
Order o;
o.push(a.frontFood());
a.dequeueFood();
o.push(a.frontDrink());
a.dequeueDrink();
cout << "Ordered one food, one drink\n";
o.display();
a.display();
cout << "Canceled Order\n";
o.cancel(a);
o.display();
a.display();
cout << "Ordered one food, one drink, purchased\n";
o.push(a.frontFood());
a.dequeueFood();
o.push(a.frontDrink());
a.dequeueDrink();
o.purchase();
o.display();
a.display();

return 0;
}
