#include <iostream>
#include "component.h"
#include "vector_container.h"
#include "list_container.h"
#include "strategy.h"
#include "operatordecorator.h"

using namespace std;

int main() {
    Op* op1 = new Op(5);
    Op* op2 = new Op(2);
    Op* op3 = new Op(4);
    Op* op4 = new Op(6);
/*  Extend test cases here */
//    Op* op5 = new Op(0);
    Op* op6 = new Op(-1.4);
    Op* op7 = new Op(1e-2);
    Mult* A = new Mult(op1, op2);
    Sub* B = new Sub(op3, op4);
    Add* C = new Add(A, B);
    Sqr* D = new Sqr(C);
/*  Extend test cases here */
    Div* E = new Div(D, op2);
    Mult* F = new Mult(E, op6); //-44.8
    Ceil* G = new Ceil(F);      //-44
    Abs* H = new Abs(G);        //44
    Mult* I = new Mult(H, op7); //.44
    Floor* J = new Floor(I);    //0

    VectorContainer* v_container = new VectorContainer();
    v_container->add_element(A);
    v_container->add_element(B);
    v_container->add_element(D);
    v_container->add_element(E);
    v_container->add_element(F);
    v_container->add_element(G);
    v_container->add_element(H);
    v_container->add_element(I);
    v_container->add_element(J);    
    cout << "Container Before Sort: " << endl;
    v_container->print();
    cout << endl;
    v_container->set_sort_function(new SelectionSort());
    v_container->sort();	
    cout << "Container After Sort: " << endl;
    v_container->print();
    cout << endl;
    
    ListContainer* l_container = new ListContainer();
    l_container->add_element(A);
    l_container->add_element(B);
    l_container->add_element(D);
    l_container->add_element(E);
    l_container->add_element(F);
    l_container->add_element(G);
    l_container->add_element(H);
    l_container->add_element(I);
    l_container->add_element(J);
    cout << "Container Before Sort: " << endl;
    l_container->print();
    cout << endl;
//    l_container->set_sort_function(new SelectionSort());
//    l_container->set_sort_function(new BubbleSort());
    cout << "\nIntentionally generate set_sort_function() here.";
    l_container->sort();	// call sort without calling set_sort_function()
    l_container->set_sort_function(new BubbleSort());
    l_container->sort();	
    cout << "Container After Sort: " << endl;
    l_container->print();
    cout << endl;
    //delete(l_container);    

    
    
};
