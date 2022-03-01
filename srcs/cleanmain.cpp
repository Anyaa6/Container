#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#define TESTING "Testing with std library"
	#include <map>
	#include <stack>
	#include <limits>
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "metafunctions.hpp"
	#include "iterator.hpp"
	#include "vector.hpp"
#endif


class A{
	public :
	static int id;
	int		number;
	int		id_instance;
	int 	size;
	int		*array;
	A(int num, int size) : number(num), size(size), array(NULL) {
		id_instance = id;
		std::cout << "Constructor called for id_instance = " << id_instance << std::endl;
		array = new int[12];
		id++;
	};
	A(A const &rhs){ //with proper copy constructor they do have their own memory -> deep copy
		number = rhs.number;
		size = rhs.size;
		id_instance = this->id;
		array = new int[12];
		id++;	
		std::cout << "COPY Constructor called for id_instance = " << id_instance << " from id_instance = " << rhs.id_instance << std::endl;
	};
	A() {
		std::cout << "DEFAULT constructor" << std::endl;
	}
	~A(){
		//Not using destructor debug msg bc destruction happens in reverse order at exit -> creates diff between tester files
		// std::cout << "Destructor called for number = " << number << " and id_instance = " << id_instance << std::endl;
		if (array)
			delete [] array;
	};	
	int operator[](int const &index) const {
		(void)index;
		return id_instance;
	};
};

std::ostream & operator<<(std::ostream &cout, A const &A)
{
	cout << A.id_instance;
	return cout;
}

int A::id = 0;

//changed ft::vector<T> to T to be able to use function with std
template <typename T>
void	print_any_vector(T &to_display, std::string vector_name)
{
	std::cout << "\nVector " << vector_name << std::endl;
	for (typename T::size_type i = 0; i < to_display.size(); i++)
		std::cout << to_display[i] << " ";
	std::cout << "\n" << std::endl;
}

void modifiers(){
	/*insert, erase*/std::cout << "VECTOR MODIFIERS - assign, push_back, pop_back, insert, erase, swap, clear " << std::endl;
	std::cout << "Assign with debug messages from class A" << std::endl;
	ft::vector<A> assignclasses(3, A(1, 2));

	std::cout << "\n" << std::endl;
	std::cout << "before assign with value" << std::endl;
	assignclasses.assign(7, A(3, 5));
	std::cout << "\n" << std::endl;

	print_any_vector(assignclasses, "assignclasses");

	ft::vector<A> assigned_by_assign_function(1, A(2, 5));
	std::cout << "\nbefore assign with iterator" << std::endl;

	assigned_by_assign_function.assign(&assignclasses[0], &assignclasses[3]);
	assigned_by_assign_function.assign(assignclasses.begin(), assignclasses.end());
	
	std::cout << "\n" << std::endl;
	print_any_vector(assignclasses, "assignclasses");
	std::cout << "Assign with reverse iterator" << std::endl;
	ft::vector<int> toassign(6, 5);
	ft::vector<int> suite(6, 5);
	int int_array[7] = {7,6, 8, 9, 2, 3};

	for (int i = 0; i < 6; i++)
	{
		toassign[i] = i;
		suite[i] = i + 1;
	}
	
	std::cout << "toassign : " << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << toassign[i] << " ";

	std::cout << "\nsuite : " << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << suite[i] << " ";

	std::cout << std::endl;
	
	toassign.assign(suite.rbegin(), suite.rend()); //reverse_iterator

	std::cout << "toassign after assign(suite.rbegin(), suite.rend()) : " << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << toassign[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Assigning from int_array pointer :" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << int_array[i] << " ";

	toassign.assign(int_array, int_array + 3); //reverse_iterator
	std::cout << "\ntoassign : " << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << toassign[i] << " ";

	std::cout << "TESTING CLEAR" << std::endl;
	ft::vector<int> clear_test;
	
	clear_test.clear();
	clear_test.push_back(12);
	clear_test.push_back(12);
	clear_test.pop_back();
	clear_test.push_back(12);
	clear_test.push_back(12);
	clear_test.push_back(12);
	std::cout << "size = " << clear_test.size() << " capacity = " << clear_test.capacity() << std::endl;
	clear_test.clear();
	clear_test.clear();
	std::cout << "size = " << clear_test.size() << " capacity = " << clear_test.capacity() << std::endl;

	std::cout << "Testing swap member function" << std::endl;
	//Constructor and destructors in random order
	/*
	ft::vector<A> swap1(2, A(3, 2));
	ft::vector<A> swap2;
	
	for (int i = 0; i < 6; i++)
		swap2.push_back(A(2, i));
	print_any_vector(swap2, "swap2");
	print_any_vector(swap1, "swap1");

	swap1.swap(swap2);
	print_any_vector(swap2, "swap2");
	print_any_vector(swap1, "swap1");
	*/

	ft::vector<int> swap1_int(2, 5);
	ft::vector<int> swap2_int;
	
	for (int i = 0; i < 6; i++)
		swap2_int.push_back(i);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1_int");

	swap1_int.swap(swap2_int);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1");
};

void non_member_functions() {
	/*relational operators*/std::cout << "VECTOR NON MEMBER FUNCTION OVERLOADS - relational operators, swap " << std::endl;

	std::cout << "Testing swap non-member function" << std::endl;
	ft::vector<int> swap_overload_int(2, 7);
	ft::vector<int> swap_overload2_int;

	for (int i = 0; i < 6; i++)
		swap_overload2_int.push_back(i);

	print_any_vector(swap_overload2_int, "swap_overload2_int");
	print_any_vector(swap_overload_int, "swap_overload_int");

	swap(swap_overload_int, swap_overload2_int);
	print_any_vector(swap_overload2_int, "swap_overload2_int");
	print_any_vector(swap_overload_int, "swap_overload_int");

	/*
	//Const and dest in different order
	ft::vector<A> swap_overload_class(2, A(3, 2));
	ft::vector<A> swap2_overload_class;
	
	for (int i = 0; i < 6; i++)
		swap2_overload_class.push_back(A(2, i));
	print_any_vector(swap2_overload_class, "swap2_overload_class");
	print_any_vector(swap_overload_class, "swap_overload_class");

	swap(swap_overload_class, swap2_overload_class);
	print_any_vector(swap2_overload_class, "swap2_overload_class");
	print_any_vector(swap_overload_class, "swap_overload_class");
	*/

	//Check ok : triggers same warning as std when using swap on vectors of different types
	//and allocators
	// swap(swap_overload_int, swap2_overload_class);
	// print_any_vector(swap2_overload_class, "swap2_overload_class");
	// print_any_vector(swap_overload_class, "swap_overload_class");
};

int main()
{
	std::cout << "Tester : " << TESTING << std::endl;
	//-------------------------------------------------------------------
	/*DONE*/std::cout << "VECTOR CONSTRUCTORS AND DESTRUCTORS " << std::endl;

	std::cout << "creating vector, copy..." << std::endl;
	ft::vector<int>	haha(4, 12);
	haha[2] = 66;
	haha[3] = 226;
	ft::vector<int> hoho(haha); //par copy
	print_any_vector(hoho, "hoho");

	std::cout << "Testing iterator constructor" << std::endl;
	ft::vector<int> base_vector(4, 2);
	ft::vector<int> iterator_contructor(base_vector.begin(), base_vector.end());

	print_any_vector(iterator_contructor, "iterator_contructor");

	ft::vector<A> class_base_vector(4, A(5,2));
	ft::vector<A> class_iterator_contructor(class_base_vector.begin(), class_base_vector.end());

	print_any_vector(iterator_contructor, "class A iterator_contructor");

	std::cout << "Testing = operator" << std::endl;
	ft::vector<A> initial(5, A(2, 3));
	ft::vector<A> deep_copy;

	deep_copy = initial;

	deep_copy[3].id_instance = 5;
	std::cout << "deep_copy[3] : " << deep_copy[3] << " initial[3] : " << initial[3] << std::endl;
	print_any_vector(initial, "initial");
	print_any_vector(deep_copy, "deep_copy");
	
	//-------------------------------------------------------------------
	/*DONE*/std::cout << "VECTOR ITERATORS - begin, end, rbegin, rend" << std::endl;

	ft::vector<int>::iterator	last = haha.end();
	std::cout << "last - 1 : " << *(last--) << std::endl;

	ft::vector<int> iter_tests(12,42);

	std::cout << "index_test begin " << *(++iter_tests.begin()) << std::endl;

	std::cout << "Testing begin front end back" << std::endl;
	// std::cout << "index_test begin " << ft_index_test.begin() << std::endl;
	// std::cout << "index_test begin " << *(index_test.end() - 1) << std::endl;
	ft::vector<int>::iterator first = iter_tests.begin();
	iter_tests[1] = 12;
	std::cout << "index_test begin " << *first << std::endl;
	std::cout << "index_test begin " << *(++iter_tests.begin()) << std::endl;
	first++;
	std::cout << "index_test begin " << *first << std::endl;

	std::cout << "Testing random_access_iterators" << std::endl;
	ft::vector<int>	hehe(4, 12);

	ft::vector<int>::iterator it = hehe.begin();
	ft::vector<int>::iterator it2 = hehe.begin();
	ft::vector<int>::iterator it3 = ++hehe.begin();
	
	std::cout << "The different iterators are equal to :\nit == it2\nit3 = ++begin()\nit4 = begin()++\n" << std::endl;
	std::cout << std::boolalpha << "(it == it2) :" << (it == it2) << std::endl;
	std::cout << "(it != it2) :" << (it != it2) << std::endl;
	std::cout << "(it <= it2) :"<< (it <= it2) << std::endl;
	std::cout << "(it >= it2) :" << (it >= it2) << std::endl;
	std::cout << "it < it2 :" << (it < it2) << std::endl;
	std::cout << "it < it3 :" << (it < it3) << std::endl;
	std::cout << "(it > it2) :" << (it > it2) << std::endl;
	std::cout << std::noboolalpha << std::endl; //stop printing as bool
	std::cout << "Printing values with index []: " << std::endl;
	for (size_t i = 0; i < hehe.size(); i++)
		std::cout << "it[" << i << "] = " << it[i] << std::endl;

	std::cout << "changing second value to 52 from iterator *it3 = 52" << std::endl;
	*it3 = 52;	
	std::cout << "Printing values with iterators *it : " << std::endl;
	for (ft::vector<int>::iterator it = hehe.begin(); it < hehe.end(); it++)
		std::cout << "it = " << *it << std::endl;

	std::cout << "Printing values with iterators *it from the end : " << std::endl;
	for (ft::vector<int>::iterator it = --hehe.end(); it >= hehe.begin(); --it)
		std::cout << "it = " << *it << std::endl;

	ft::vector<int>::iterator fifty_two = it + 1;
	std::cout << "it + 1 = " << *fifty_two << std::endl;
	std::cout << "it + 1 + 1 = " << *(fifty_two -= 1) << std::endl;
	
	ft::vector<int>::iterator itbegin = hehe.begin();
	ft::vector<int>::iterator itoffset = 1 + itbegin; //hehe.begin();
	
	std::cout << "itoffset = 1 + hehe.begin() = " << *itoffset << std::endl;
	
	ft::vector<int>::iterator::difference_type diff_btw_ptr = itoffset - itbegin; //hehe.begin();
	std::cout << "diff between itoffset - begin() = " << diff_btw_ptr << std::endl;

	ft::vector<int>::iterator itft = hehe.begin();
	ft::vector<int>::iterator itstd;
	std::cout << "itft = " << *itft << std::endl;

	std::cout << "Test reverse iterators" << std::endl;
    ft::vector<int> v(5, 0);
	for (int i = 0; i < 5; i++)
		v[i] = i;
 
	ft::vector<int> copy(v);
	for (int i = 0; i < 5; i++)
		std::cout << copy[i] << std::endl;
	
	typedef ft::reverse_iterator<ft::vector<int>::iterator> RevIt;
    ft::vector<int>::iterator rit = v.begin() + 3;
    RevIt r_rit(rit);
 
    std::cout << "*rit == " << *rit << '\n'
			//   << "*ritstd == " << *ritstd << '\n'
              << "*r_rit == " << *r_rit << '\n'
              << "*r_rit.base() == " << *r_rit.base() << '\n'
              << "*(r_rit.base()-1) == " << *(r_rit.base() - 1) << '\n';
 
    RevIt r_end(v.begin());
    RevIt r_begin(v.end());

	RevIt newrev = r_end - 2;
	std::cout << "rev_end + 2 = " << *newrev << std::endl;
	std::cout << "++newrev = " << *++newrev << std::endl;
	std::cout << "--newrev = " << *--newrev << std::endl;
	std::cout << "newrev-- = " << *newrev-- << std::endl;
	std::cout << "newrev = " << *newrev << std::endl;

	std::cout << "r_begin[2] = " << r_begin[2] << std::endl;

	r_begin += 2;	
	std::cout << "r_begin += 2 = " << *r_begin << std::endl;
	
	r_begin -= 2;	
	std::cout << "r_begin -= 2 = " << *r_begin << std::endl;

	std::cout << "r_end - r_begin = " << r_end - r_begin << std::endl;

	RevIt added = 1 + r_begin;
	std::cout << "1 + r_begin = " << *added << std::endl;
	
	std::cout << "Testing relationnal operators of reverse iterators" << std::endl;
	std::cout << std::boolalpha << (r_end == r_end) << std::endl;
	std::cout << (r_end != r_end) << std::endl;
	std::cout << (r_end != r_begin) << std::endl;
	std::cout << (r_end < r_begin) << std::endl;
	std::cout << (r_end > r_begin) << std::noboolalpha << std::endl;

	RevIt 	ending = v.rend();
	RevIt 	beginning = v.rbegin();

	for (;beginning != ending; beginning++)
		std::cout << *beginning << std::endl;

	std::cout << "Test operator ->" << std::endl;
	ft::vector<A> vclass(5, A(3,42));
	ft::vector<A>::iterator itvclass = vclass.begin();
	
	for (; itvclass < vclass.end(); itvclass++)
		itvclass->number = 12;
	for (itvclass = vclass.begin(); itvclass < vclass.end(); itvclass++)
		std::cout << itvclass->number << std ::endl;

	//-------------------------------------------------------------------
	/*DONE*/std::cout << "VECTOR CAPACITY FUNCTIONS - size, max_size, resize, capacity, empty, reserve " << std::endl;
	ft::vector<int> real_stuff(5,12);
	ft::vector<int> cp_real_stuff(real_stuff);
	ft::vector<int> empty_cont;
	
	std::cout << "Testing empty : " << std::endl;
	std::cout << std::boolalpha << "Real_stuff is empty : " << real_stuff.empty() 
	<< " empty_cont is empty : " << empty_cont.empty() << std::noboolalpha << std::endl;

	std::cout << "Creating vector from another vector and checking capacity" << std::endl;
	std::cout << real_stuff.size() << std::endl;
	std::cout << real_stuff.max_size() << std::endl;
	std::cout << real_stuff.capacity() << std::endl;
	std::cout << cp_real_stuff.size() << std::endl;
	std::cout << cp_real_stuff.capacity() << std::endl;

	std::cout << "Capacity growth after push backs" << std::endl;
	for (int i = 0; i < 16 ; i++)
	{
		real_stuff.push_back(42);
		std::cout << "size : " << real_stuff.size() << std::endl;
		std::cout << "capacity : " << real_stuff.capacity() << std::endl;
	}

	ft::vector<int> cpcpreal(real_stuff);
	std::cout << real_stuff.size() << std::endl;
	std::cout << real_stuff.capacity() << std::endl;
	std::cout << cpcpreal.size() << std::endl;
	std::cout << cpcpreal.capacity() << std::endl;

	std::cout << "Testing capacity growth with reserve function" << std::endl;
	ft::vector<int> capacitytest(3, 42);

	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(10);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(20);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(21);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	std::cout << "capacitytest size = " << capacitytest.size() << std::endl;
	capacitytest.reserve(169);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	print_any_vector(capacitytest, "capacitytest");

	std::cout << "Testing resize : " << std::endl;
	ft::vector<int> resize_test(3, 42);

	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(12);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.push_back(12);
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(13);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(2);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;

	//-------------------------------------------------------------------
	/*DONE*/std::cout << "VECTOR ELEMENT ACCESS - operator[], at, front, back " << std::endl;

	std::cout << "testing [] operator" << std::endl;
	ft::vector<int> index(3, 5);

	for (size_t i = 0; i < haha.size(); i++)
	{
		std::cout << "haha["<< i << "] " << haha[i] << std::endl;
		std::cout << "hoho["<< i << "] " << hoho[i] << std::endl;
	}

	std::cout << "testing at, front, back" << std::endl;
	std::cout << haha.at(2) << std::endl; //works
	try
	{
		std::cout << haha.at(4) << std::endl; //throw exception bc out of range
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << index.at(524534456) << std::endl; //throw exception bc out of range
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	ft::vector<int> empty_vector;
	ft::vector<int> value_test(12,42);

	// std::cout << "Testing front on empty container" << std::endl;
	// std::cout << empty_vector.front() << std::endl;
	
	std::cout << "Testing front on NON empty container" << std::endl;
	std::cout << value_test.front() << std::endl;

	// std::cout << "Testing back on empty container" << std::endl;
	// std::cout << empty_vector.back() << std::endl;
	
	std::cout << "Testing back on NON empty container" << std::endl;
	std::cout << value_test.back() << std::endl;
	
	//-------------------------------------------------------------------
	modifiers();
	//-------------------------------------------------------------------
	non_member_functions();

	return 0;
}