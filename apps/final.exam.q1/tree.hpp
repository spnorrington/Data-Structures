// 
// Purpose of this program is to write three functions of the Tree class that provide information about a tree (hint traversal). The functions cannot be methods of the class

#pragma once



template <typename T>
class Container 
{
	virtual size_t size() = 0;
	virtual size_t max_size() = 0;
	virtual bool empty() = 0;
	virtual void swap(T&, T&) = 0;
	virtual void clear() = 0;
}




for (list<string>::iterator j = projects.begin();
	j != projects.end();
	++j) {
	cout << *j << endl;
}
return 0;

//                        EXAMPLE DSFUI
template <class Item>
Item maximum(Item a, Item b)
{
	if (a > b) { return a; }
	else { return b; }
}
int ival = 3;
int ival2 = 4
double dval = 2.55;
double anotherDouble = 3.44;
int maxint = maximum(ival, ival2);
double maxdouble = maximum(dval, anotherDouble);

//We aren’t limited to just a single type parameter in a template:
:: :
	Function templates can be overloaded
	Each template must have a unique parameter list
	template <class Item>

template <class T>
T sumAll(T num) ...
template <class T1, class T2>
T1 sumAll(T1 num1, T2 num2) ...

template <class T>
class Rectangle { ... };
template <class T>
class Square<T> : public Rectangle<T>
{
	...
};