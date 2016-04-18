#include "EAN.h"

class iOrder {
public:
	virtual EAN& getEAN() = 0; //Returns the EAN object held by the Order, SpcialOrder.........
	virtual bool add(int) = 0; //Adds the value passed into the noOrdered in Order object........
	virtual bool add(std::istream&) = 0; //Adds the value user inputs into the noOrdered in Order object......
	virtual bool receive(std::istream&) = 0; //Adds number noDelivered according to the input entered by the user...........
	virtual int outstanding() const = 0; //Returns the number of copies left to deliver in the order...........
	virtual void display(std::ostream&) const = 0; //Displays Order....
	virtual ~iOrder() = 0;
};

class Order : public iOrder {
	EAN orderedEAN; //Holds the EAN object......
	int noOrdered; //Hold number of copies ordered.....
	int noDelivered; //Holds number of copies delivered......
public:
	Order(); //Order safe empty safe Constructor......
	~Order(); //Order destructor......
	Order(const EAN& ean); //Recieves a reference to an ean object and creates an Order object........
	EAN& getEAN(); //Returns a reference to current objects ean........
	int outstanding() const; //Returns remaining copies left in the order.......
	bool add(std::istream&); //Increases the number of copies by the amount that the user enters.......
	bool add(int); //Recieves the number of copies that need to be added to the number of orders.......
	bool receive(std::istream&); //Takes the input from the user with some validation and updates the number of deliveries.....
	void display(std::ostream&) const; //Displays the eanOrder, numorders and the numdelivery........
	Order(const Order& source); //Copy Constructor that calls operator=.....
	Order& operator=(const Order& source); //Assignment Operator that copies source to current object....
};

class SpecialOrder : public Order {
	char* instructions; //Holds instructions for the Oreder......
public: 
	SpecialOrder(); //SpecialOrder safe empty safe Constructor......
	~SpecialOrder(); //SpecialOrder desructor desroying dynamic memory.......
	SpecialOrder(const EAN& isbn, const char* instr); //Passes EAN object to order to deal with it and copies instr into instructions if it's valid........
	bool add(std::istream&); //Calls the add function in Order.cpp and if it's a special order, it asks for the instruction.........
	void display(std::ostream&) const; //Displays the previous output with the special instruction.......
	SpecialOrder(const SpecialOrder& source); //Copy constructor that calls operator=...........
	SpecialOrder& operator=(const SpecialOrder& source); //Assignment operator that copes variables from source object to current object......
};

std::ostream& operator<<(std::ostream& os, const iOrder& order); //Helper that calls display function....