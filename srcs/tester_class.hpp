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
	A& operator=(const A& rhs) {
		number = rhs.number;
		size = rhs.size;
		id_instance = rhs.id_instance;
		array = rhs.array; //lhs gets rhs array
		// rhs.array = NULL; //rhs array set to NULL so that it is not deleted
		std::cout << "= overload from : " << id_instance << std::endl;
		return *this;
	};
	A() {
		std::cout << "DEFAULT constructor" << std::endl;
	}
	~A(){
		//Not using destructor debug msg bc destruction happens in reverse order at exit -> creates diff between tester files
		std::cout << "Destructor called for number = " << number << " and id_instance = " << id_instance << std::endl;
		if (array)
			delete [] array;
	};	
	int operator[](int const &index) const {
		(void)index;
		return id_instance;
	};
	friend bool operator== (const A& lhs, const A& rhs) {
		if (lhs.size != rhs.size || lhs.number != rhs.number)
			return (false);
		return (true);
	};
	friend bool operator< (const A& lhs, const A& rhs) {
		if (lhs.size < rhs.size)
			return (true);
		return (false);
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