#include <iostream>
#include <string>
#include <deque>
#include <ctime>
#if std_lib//CREATE A REAL STL EXAMPLE
	#define TESTING "Testing with std library"
	#include <map>
	#include <stack>
	#include <limits>
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "../utils/metafunctions.hpp"
	#include "../iterators/iterator.hpp"
	#include "../iterators/reverse_iterator.hpp"
	#include "../containers/vector.hpp"
	#include "../containers/stack.hpp"
	#include "../containers/map.hpp"
	#include "../utils/pair.hpp"
#endif
#include "tester_class.hpp"


void stack_relational_operators(){
	ft::stack<A, ft::vector<A> >  lhs(ft::vector<A>(12, A(12, 5)));
	ft::stack<A, ft::vector<A> >  rhs(ft::vector<A>(12, A(3, 5)));
	ft::stack<A, ft::vector<A> >  rhs_other(lhs);

	ft::stack<int, ft::vector<int> >  lhs_int(ft::vector<int>(12, 7));
	// for (size_t i = 0; i < lhs_int.size(); i++)
		// lhs_int[i] = i + 2;
	ft::stack<int, ft::vector<int> >  lhs_copy(ft::vector<int>(12, 7));
	// lhs_int[2] = 16;
	ft::stack<int, ft::vector<int> >  rhs_int(ft::vector<int>(12, 4));
	ft::stack<int, ft::vector<int> >  rhs_other_int(ft::vector<int>(12, 7));
	
	std::cout << std::boolalpha << "\n\nlhs_int == rhs_int = " << (lhs_int == rhs_int) << "\nlhs_int == rhs_other_int = " << (lhs_int == rhs_other_int) << " lhs_int == lhs_copy = " << (lhs_int == lhs_copy) << "\n\n" << std::endl;

	std::cout << "lhsint < rhs_int = " << (lhs_int < rhs_int) << std::endl;
	std::cout << "lhsint != rhs_int = " << (lhs_int != rhs_int) << std::endl;
	std::cout << "lhsint <= rhs_int = " << (lhs_int <= rhs_int) << std::endl;
	std::cout << "lhsint >= rhs_int = " << (lhs_int >= rhs_int) << std::endl;
	std::cout << "lhsint > rhs_int = " << (lhs_int > rhs_int) << std::endl;
	
	std::cout << "lhs_int != lhs_copy = " << (lhs_int != lhs_copy) << std::endl;
	std::cout << "lhs_int == lhs_copy = " << (lhs_int == lhs_copy) << std::endl;
	std::cout << "lhs_int < lhs_copy = " << (lhs_int < lhs_copy) << std::endl;
	std::cout << "lhs_int >= lhs_copy = " << (lhs_int >= lhs_copy) << std::endl;
	std::cout << "lhs_int > lhs_copy = " << (lhs_int > lhs_copy) << std::endl;
	std::cout << "lhs_int <= lhs_copy = " << (lhs_int <= lhs_copy) << std::endl;

	std::cout << "lhs != rhs_other = " << (lhs != rhs_other) << std::endl;
	std::cout << "lhs == rhs_other = " << (lhs == rhs_other) << std::endl;
	std::cout << "lhs < rhs_other = " << (lhs < rhs_other) << std::endl;
	std::cout << "lhs >= rhs_other = " << (lhs >= rhs_other) << std::endl;
	std::cout << "lhs > rhs_other = " << (lhs > rhs_other) << std::endl;
	std::cout << "lhs <= rhs_other = " << (lhs <= rhs_other) << std::endl;
}

void stack_push_pop() {
	ft::stack<A, ft::vector<A> > 	stack_push_pop(ft::vector<A>(3, A(12, 4)));

	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
	std::cout << "stack_push_pop.push(A(2, 10))" << std::endl;
	std::cout << "stack_push_pop size = " << stack_push_pop.size() << std::endl;
	stack_push_pop.push(A(2, 10));
	std::cout << "BEFORE EXIT" << std::endl;
	
	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
	std::cout << "stack_push_pop.pop() x 2" << std::endl;
	stack_push_pop.pop();
	stack_push_pop.pop();
	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
}

void stack_top_back_empty() {
	std::cout << "TESTING TOP AND BACK on stack\n\n" << std::endl;

	ft::vector<A>		vec_for_stack(4, A(12, 5));
	ft::vector<A>	empty_vec;
	ft::stack<A, ft::vector<A> >   empty_stack(empty_vec);
	ft::stack<A, ft::vector<A> >   stack_from_vec(vec_for_stack);

	std::cout << std::boolalpha;
	std::cout << "empty stack is empty = " << empty_stack.empty() << std::endl;
	std::cout << "stack_from_vec stack is empty " << stack_from_vec.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "empty stack size = " << empty_stack.size() << std::endl;
	std::cout << "stack_from_vec stack size " << stack_from_vec.size() << std::endl;
	std::cout << std::endl;

	// std::cout << "Testing stack top" << std::endl;
	// std::cout << "empty stack top = " << empty_stack.top() << std::endl;
	// std::cout << "empty_vec back = " << empty_vec.back() << std::endl;
	// std::cout << std::endl;
	
	std::cout << "stack_from_vec stack top " << stack_from_vec.top() << std::endl;
	std::cout << "vec_for_stack stack back " << vec_for_stack.back() << std::endl;
	std::cout << std::endl;
}

void stack_tests(){
	stack_relational_operators();
	stack_push_pop();
	stack_top_back_empty();
}

void vector_modifiers(){
	/*DONE*/std::cout << "VECTOR MODIFIERS - assign, push_back, pop_back, insert, erase, swap, clear " << std::endl;

	/*
		ft::vector<A> empty_vec_assign;
	ft::vector<A> range_vec_assign(10, A(3, 5));
	ft::vector<A>::iterator itrange = range_vec_assign.begin();

	empty_vec_assign.assign(itrange, range_vec_assign.end());
	print_any_vector(empty_vec_assign, "empty_vec_assign");
	std::cout << std::endl;
	for (int i = 0; i < 7; i++)
		itrange++;
	empty_vec_assign.assign(itrange, range_vec_assign.end());
	print_any_vector(empty_vec_assign, "empty_vec_assign");
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		itrange--;
	empty_vec_assign.assign(itrange, range_vec_assign.end());
	std::cout << std::endl;

	print_any_vector(empty_vec_assign, "empty_vec_assign");
	*/

	std::cout << "Testing erase" << std::endl;
	ft::vector<A>  erase_test(3, A(12, 5));
	
	print_any_vector(erase_test, "erase_test");
	ft::vector<A>::iterator result = erase_test.erase((--erase_test.end()));
	std::cout << "return value = " << *result << std::endl;
	print_any_vector(erase_test, "erase_test");

	std::cout << "Testing erase range" << std::endl;
	ft::vector<A>  erase_range_test(12, A(12, 5));
	
	print_any_vector(erase_range_test, "erase_range_test");

	ft::vector<A>::iterator result_range = erase_range_test.erase(erase_range_test.begin(), erase_range_test.end());
	std::cout << "return value = " << *result_range << std::endl;
	print_any_vector(erase_range_test, "erase_test");
	/*
	for (int i = 0; i < 8; i++)
		erase_range_test.push_back(A(2,5));

	ft::vector<A>::iterator first_erase_range = ++(++erase_range_test.begin());
	ft::vector<A>::iterator last_erase_range = --(--(--erase_range_test.end()));
	ft::vector<A>::iterator result_range_2 = erase_range_test.erase(first_erase_range, last_erase_range);
	std::cout << "return value = " << *result_range_2 << std::endl;
	print_any_vector(erase_range_test, "erase_test");
	*/
	
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


	/*
	std::cout << "Testing swap member function" << std::endl;
	//Constructor and destructors in random order
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

	/*
	//Gives malloc err for std AND ft, would need rhs set to NULL
	std::cout << "Testing void insert (iterator position, InputIterator first, InputIterator last);" << std::endl;
	ft::vector<A> to_insert(4, A(5, 1));
	ft::vector<A> to_grow(12, A(5, 1));
	
	std::cout << "\nBefore RESERVE\n\n";
	to_grow.reserve(50);
	std::cout << "\nRESERVE DONE\n\n";
	// to_grow.push_back(A(3, 2)); //augments capacity to 2 * initial _capacity
	// to_grow.pop_back();
	
	print_any_vector(to_insert, "to_insert");
	print_any_vector(to_grow, "to_grow");
	std::cout << "to_grow.capacity() : " << to_grow.capacity() << std::endl;

	ft::vector<A>::iterator it_grow = to_grow.begin();
	// it_grow++;
	// it_grow++;
	// it_grow++;

	std::cout << "\ninsert : " << std::endl;
	to_grow.insert(it_grow, to_insert.begin(), to_insert.end());

	print_any_vector(to_insert, "to_insert");
	print_any_vector(to_grow, "to_grow");
	*/

	std::cout << "Testing void insert (iterator position, InputIterator first, InputIterator last);" << std::endl;
	ft::vector<int> to_insert(3);
	for (size_t i = 0; i < to_insert.size(); i++)
		to_insert[i] = i + 3;
	ft::vector<int> to_grow(12);
	for (size_t i = 0; i < to_grow.size(); i++)
		to_grow[i] = i;
	
	std::cout << "\nBefore RESERVE\n\n";
	// to_grow.reserve(50);
	std::cout << "\nRESERVE DONE\n\n";
	// to_grow.push_back(A(3, 2)); //augments capacity to 2 * initial _capacity
	// to_grow.pop_back();
	
	print_any_vector(to_insert, "to_insert");
	print_any_vector(to_grow, "to_grow");
	std::cout << "to_grow.capacity() : " << to_grow.capacity() << std::endl;

	ft::vector<int>::iterator it_grow_simple = ++to_grow.begin();
	it_grow_simple++;
	// it_grow_simple++;
	// it_grow_simple++;

	std::cout << "\ninsert : " << std::endl;
	to_grow.insert(it_grow_simple, to_insert.begin(), to_insert.end());

	print_any_vector(to_insert, "to_insert");
	print_any_vector(to_grow, "to_grow");

	std::cout << "\nTesting void insert (iterator position, size_type n, const value_type& val); " << std::endl;
	ft::vector<A> to_grow_by_value(9, A(2, 3));
	
	to_grow_by_value.reserve(12);
	
	print_any_vector(to_grow_by_value, "to_grow_by_value");
	std::cout << "to_grow_by_value.capacity() : " << to_grow_by_value.capacity() << std::endl;
	std::cout << "inserted elements are 3*7 at position 4" << std::endl;
	
	ft::vector<A>::iterator it_grow = to_grow_by_value.begin();
	for (int i = 0; i < 3; i++)
		it_grow++;

	std::cout << "\ninsert : " << std::endl;
	to_grow_by_value.insert(it_grow, 7, A(3, 4));

	print_any_vector(to_grow_by_value, "to_grow_by_value");
	

	std::cout << "\nTesting void insert (iterator position, size_type n, const value_type& val); " << std::endl;
	ft::vector<int> to_grow_by_value_int(6);
	for (size_t i = 0; i < to_grow_by_value_int.size(); i++)
		to_grow_by_value_int[i] = i;
	
	to_grow_by_value_int.reserve(12);
	
	print_any_vector(to_grow_by_value_int, "to_grow_by_value_int");
	std::cout << "to_grow_by_value_int.capacity() : " << to_grow_by_value_int.capacity() << std::endl;
	std::cout << "inserted elements are 3*7" << std::endl;
	
	ft::vector<int>::iterator it_grow_int = ++to_grow_by_value_int.begin();
	it_grow_int++;
	it_grow_int++;
	it_grow_int++;
	
	print_any_vector(to_grow_by_value_int, "to_grow_by_value_int");

	std::cout << "\ninsert : " << std::endl;
	to_grow_by_value_int.insert(it_grow_int, 3, 7);

	print_any_vector(to_grow_by_value_int, "to_grow_by_value");

	std::cout << "Testing iterator insert (iterator position, const value_type& val); " << std::endl;
	ft::vector<A> insert_single_value(6, A(5, 1));

	std::cout << "\ninserted element : " << std::endl;
	A instance(8,2);
	std::cout << std::endl;
	
	insert_single_value.reserve(12);
	
	print_any_vector(insert_single_value, "insert_single_value");
	std::cout << "insert_single_value.capacity() : " << insert_single_value.capacity() << std::endl;
	std::cout << "inserted elements is A(8, 2)" << std::endl;

	// ft::vector<A>::iterator it_single = insert_single_value.begin();
	// for (int i = 0; i < 3; i++)
		// it_single++;

	std::cout << "\ninsert : " << std::endl;
	std::cout << *(insert_single_value.insert(insert_single_value.end(), instance)) << std::endl;
	// insert_single_value.insert(it_single,  instance);

	print_any_vector(insert_single_value, "insert_single_value");

};

void vector_non_member_functions() {
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

	std::cout << "Testing == operator" << std::endl;
	ft::vector<A>  lhs(12, A(12, 5));
	ft::vector<A>  rhs(12, A(3, 5));
	ft::vector<A>  rhs_other(lhs);

	ft::vector<int>  lhs_int(12, 7);
	for (size_t i = 0; i < lhs_int.size(); i++)
		lhs_int[i] = i + 2;
	ft::vector<int>  lhs_copy(lhs_int);
	lhs_int[2] = 16;
	ft::vector<int>  rhs_int(12, 4);
	ft::vector<int>  rhs_other_int(lhs_int);

	std::cout << std::boolalpha << "\n\nlhs_int == rhs_int = " << (lhs_int == rhs_int) << "\nlhs_int == rhs_other_int = " << (lhs_int == rhs_other_int) << " lhs_int == lhs_copy = " << (lhs_int == lhs_copy) << "\n\n" << std::endl;

	std::cout << "lhsint < rhs_int" << (lhs_int < rhs_int) << std::endl;
	std::cout << "lhsint != rhs_int" << (lhs_int != rhs_int) << std::endl;
	std::cout << "lhsint <= rhs_int" << (lhs_int <= rhs_int) << std::endl;
	std::cout << "lhsint >= rhs_int" << (lhs_int >= rhs_int) << std::endl;
	std::cout << "lhsint > rhs_int" << (lhs_int > rhs_int) << std::endl;
	
	std::cout << "lhs_int != lhs_copy" << (lhs_int != lhs_copy) << std::endl;
	std::cout << "lhs_int == lhs_copy" << (lhs_int == lhs_copy) << std::endl;
	std::cout << "lhs_int < lhs_copy" << (lhs_int < lhs_copy) << std::endl;
	std::cout << "lhs_int >= lhs_copy" << (lhs_int >= lhs_copy) << std::endl;
	std::cout << "lhs_int > lhs_copy" << (lhs_int > lhs_copy) << std::endl;
	std::cout << "lhs_int <= lhs_copy" << (lhs_int <= lhs_copy) << std::endl;

	std::cout << "lhs != rhs_other" << (lhs != rhs_other) << std::endl;
	std::cout << "lhs == rhs_other" << (lhs == rhs_other) << std::endl;
	std::cout << "lhs < rhs_other" << (lhs < rhs_other) << std::endl;
	std::cout << "lhs >= rhs_other" << (lhs >= rhs_other) << std::endl;
	std::cout << "lhs > rhs_other" << (lhs > rhs_other) << std::endl;
	std::cout << "lhs <= rhs_other" << (lhs <= rhs_other) << std::endl;

	ft::vector<int> swap1_int(2, 5);
	ft::vector<int> swap2_int;
	
	for (int i = 0; i < 6; i++)
		swap2_int.push_back(i);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1_int");

	swap1_int.swap(swap2_int);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1");
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

void vector_functions() {
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

	ft::vector<A> resize_growth(4, A(12, 5));
	print_any_vector(resize_growth, "resize_growth");
	// resize_growth.reserve(9);
	// std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;
	std::cout << "\nBefore resize : " << std::endl;
	resize_growth.resize(2, A(3, 0));
	std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;

	std::cout << "\nAfter resize : " << std::endl;
	print_any_vector(resize_growth, "resize_growth");

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
	vector_modifiers();
	//-------------------------------------------------------------------
	vector_non_member_functions();
}

void pair_tests() {
	ft::pair<int, char>  pairinstance(1, 'd');
	
	std::cout << "first = " << pairinstance.first << " second = " << pairinstance.second << std::endl; 
	
	ft::pair<int, char>  paircopy(pairinstance);
	
	std::cout << "first = " << paircopy.first << " second = " << paircopy.second << std::endl; 
	
	ft::pair<int, int> 	paircopy2 = ft::make_pair(6, 78);
	std::cout << "first = " << paircopy2.first << " second = " << paircopy2.second << std::endl; 

	pairinstance = paircopy2;
	std::cout << "first = " << pairinstance.first << " second = " << pairinstance.second << std::endl; 

	//test relational operators
	std::cout << std::boolalpha;
	std::cout << (pairinstance != paircopy) << std::endl;
	std::cout << (pairinstance == paircopy) << std::endl;
	std::cout << (pairinstance > paircopy) << std::endl;
	std::cout << (pairinstance >= paircopy) << std::endl;
};

//missing max_size
void map_other_functions() {
	ft::map<int, int>	simple_inserts;
	
	for (int i = 12; i >= 0; i--)
		simple_inserts.insert(ft::make_pair(i, i + 2));
	for (int i = 0; i < 5; i++)
		simple_inserts.insert(ft::make_pair(i, i + 2));

	simple_inserts.insert(ft::make_pair(-5, 2));

	ft::map<int, int>::iterator		it_em = simple_inserts.begin();

	for (; it_em != simple_inserts.end(); it_em++)
		std::cout << "begin key = " << it_em->first << " value =  "<< it_em->second << std::endl;

	std::cout << "\n REVERSE" << std::endl;
	ft::map<int, int>::reverse_iterator		rit_em = simple_inserts.rbegin();
	
	for (; rit_em != simple_inserts.rend(); rit_em++)
		std::cout << "begin key = " << rit_em->first << " value =  "<< rit_em->second << std::endl;

	std::cout << simple_inserts.size() << std::endl;

	std::cout << std::boolalpha << "Simple_insert is empty : " << simple_inserts.empty() << std::endl;
	
	std::cout << "simple inserts cleared" << std::endl;
	simple_inserts.clear();
	std::cout << simple_inserts.size() << std::endl;
	std::cout << std::boolalpha << "Simple_insert is empty : " << simple_inserts.empty() << std::endl;

	ft::map<int, int>	range_insert;
	
	for (int i = -5; i < 0; i++)
		range_insert.insert(ft::make_pair(i, i + 2));
	
	ft::vector< ft::pair<int, int> > 	range_for_insert;
	for (int i = 0; i < 12; i++)
		range_for_insert.push_back(ft::make_pair(i, i + 3));
	
	range_insert.insert(range_for_insert.begin(), range_for_insert.end());
	std::cout<< range_insert.size() << std::endl;
	// range_insert.print_tree();

	ft::map<int, int>	map_const_range(range_for_insert.begin(), range_for_insert.end());

	// map_const_range.print_tree();
	
	ft::map<int, int>	map_by_copy(range_insert);
	// map_by_copy.print_tree();
	std::cout << map_by_copy.size() << std::endl;

	ft::map<int, int>::iterator		it_range_copy = map_by_copy.begin();

	for (; it_range_copy != map_by_copy.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	it_range_copy = range_insert.begin();

	for (; it_range_copy != range_insert.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	ft::map<int, int>	map_assign_overload = range_insert;

	it_range_copy = map_assign_overload.begin();

	for (; it_range_copy != map_assign_overload.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	//adding new values to range_insert so that it is different than map_by_copy
	for (int i = -12; i < -5; i++)
		range_insert.insert(ft::make_pair(i, i + 2));
	
	std::cout << "\nRANGE INSERT" << std::endl;
	it_range_copy = range_insert.begin();
	for (; it_range_copy != range_insert.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	std::cout << "\nMAP_BY_COPY" << std::endl;
	it_range_copy = map_by_copy.begin();
	for (; it_range_copy != map_by_copy.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	std::cout << "\nSWAP" << std::endl;
	range_insert.swap(map_by_copy);
	
	std::cout << "\nRANGE INSERT" << std::endl;
	it_range_copy = range_insert.begin();
	for (; it_range_copy != range_insert.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	std::cout << "\nMAP_BY_COPY" << std::endl;
	it_range_copy = map_by_copy.begin();
	for (; it_range_copy != map_by_copy.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	for (int i = -20; i < -12; i++)
		range_insert.insert(ft::make_pair(i, i + 2));
	std::cout << "\nRANGE INSERT" << std::endl;
	it_range_copy = range_insert.begin();
	for (; it_range_copy != range_insert.end(); it_range_copy++)
		std::cout << "begin key = " << it_range_copy->first << " value =  "<< it_range_copy->second << std::endl;

	ft::map<int, int>		simple_map;

	for (int i = 0; i < 12; i++)
		simple_map.insert( ft::make_pair(i, i-2));
	
	ft::map<int, int>::iterator		it_simple_map = simple_map.begin();
	for (int i = 0; i < 4; i++)
		it_simple_map++;

	ft::map<int, int>::iterator		return_value;
	return_value = simple_map.insert(it_simple_map, ft::make_pair(12, 12));
	std::cout << "return_value->first = " << return_value->first << " second = " << return_value->second << std::endl;
}

void map_operations() {
	ft::map<int, int>	map_for_operations;
	
	for (int i = -5; i < 0; i++)
		map_for_operations.insert(ft::make_pair(i, i + 2));
	
	ft::vector< ft::pair<int, int> > 	range_for_insert;
	for (int i = 0; i < 9; i++)
		range_for_insert.push_back(ft::make_pair(i, i + 3));
	
	map_for_operations.insert(range_for_insert.begin(), range_for_insert.end());
	std::cout<< map_for_operations.size() << std::endl;

	ft::map<int, int>::iterator	it_operations;
	it_operations = map_for_operations.find(6);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	
	it_operations = map_for_operations.find(-50);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;

	std::cout << "Count for key == 6 : " << map_for_operations.count(6) << " Count for key == -50 : " << map_for_operations.count(-50) << std::endl;
	
	for (int i = -12; i < -5; i++)
		map_for_operations.insert(ft::make_pair(i, i + 2));

	for (int i = -12; i > -25; i -= 2)
		map_for_operations.insert(ft::make_pair(i, i + 2));
	// map_for_operations.print_tree();

	it_operations = map_for_operations.lower_bound(-18);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "lower bound(-18) == " << it_operations->first << std::endl; 
	
	it_operations = map_for_operations.lower_bound(-19);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "lower bound(-19) == " << it_operations->first << std::endl; 
	
	it_operations = map_for_operations.upper_bound(-18);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "upper_bound(-18) == " << it_operations->first << std::endl; 
	
	it_operations = map_for_operations.upper_bound(-19);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "upper_bound(-19) == " << it_operations->first << std::endl; 

	it_operations = map_for_operations.upper_bound(-24);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "upper_bound(-24) == " << it_operations->first << std::endl; 

	it_operations = map_for_operations.upper_bound(-29);
	std::cout << "it operations == end ? " << std::boolalpha << (it_operations == map_for_operations.end()) << std::endl;
	std::cout << "upper_bound(-29) == " << it_operations->first << std::endl; 

	ft::map<char,int> mymap;
	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void map_tests() {
	map_operations();
	// map_erase();
	map_other_functions();
};

int main()
{
	const clock_t start_time = clock();
	//-------------------------------------------------------------------
	vector_functions();
	stack_tests();
	pair_tests();
	map_tests();
	//-------------------------------------------------------------------
	std::cout << "Tester : " << TESTING << std::endl;
	float time = float(clock () - start_time) / CLOCKS_PER_SEC;
	std::cout << "Program ran in : " << time << "s time" << std::endl;
	if (std::string("Testing with std library").compare(TESTING) == 0)
		std::cout << "Max time for ft : " << time * 20 << "s" << std::endl;
	return 0;
}