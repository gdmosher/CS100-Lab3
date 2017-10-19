// Gordon Mosher / Yichao Chen
// SID: 861266106 / 861303577
// Email: gordon.mosher@email.ucr.edu / ychen177@ucr.edu
#ifndef Add_hh
#define Add_hh

class Add: public Operator
{
  public:
    Add() : Operator();
    ~Add();
    Add (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() + this->right->evaluate();
	};

  private:
};
#endif
