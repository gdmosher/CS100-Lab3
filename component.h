// Gordon Mosher / Yichao Chen
// SID: 861266106 / 861303577
// Email: gordon.mosher@email.ucr.edu / ychen177@ucr.edu

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class Operator: public Base {
	protected:
		Base* left, *right;
	public:
		Operator() : Base() {};
		Operator(Base* l, Base* r) : left(l), right(r) {};
		
		Base* get_left() { return left; };
		Base* get_right() { return right; };
		
		virtual double evaluate() = 0;
};

//Leaf Class
class Op: public Base {
	private:
		double value;
		
	public:
		Op() : Base(), value(0){};
		Op(double val) : Base(), value(val){};
		double evaluate() { return this->value; }
};

class Add: public Operator {
  public:
    Add() : Operator() { };
    ~Add();
    Add (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() + this->right->evaluate();
	};
};

class Sub: public Operator {
  public:
    Sub() : Operator() { };
    ~Sub();
    Sub (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() - this->right->evaluate();
	};
};

class Mult: public Operator {
  public:
    Mult() : Operator(){ };
    ~Mult();
    Mult (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() * this->right->evaluate();
	};
};

class Divide: public Operator {
  public:
    Divide() : Operator(){ };
    ~Divide();
    Divide (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() / this->right->evaluate();
	};
};

class Sqr: public Operator {
  public:
    Sqr() : Operator(){ };
    ~Sqr();
    Sqr (Base* left) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() * this->left->evaluate();
	};
};

#endif // __COMPONENT_H__
