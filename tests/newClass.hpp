#ifndef NEWCLASS_H
#define NEWCLASS_H
	
class newClass  
{
	private:
		int fraise;
		int poire;
		int pomme;
		int pistache;

	public :
		newClass(int fraise, int poire);
		newClass(int fraise);
		newClass(newClass const &to_copy);
		~newClass();
		int haha(int index);

		int getFraise();
		void setFraise(int fraise);
		int getPoire();
		void setPoire(int poire);




};

#endif