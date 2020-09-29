#include <iostream>
#include <string>

using namespace std;

const string unk = "unknown";
const string clonePrefixe = "clone-";

class Animals {
	string name		= unk;
	string specie	= unk;
	string sound	= unk;
public:
	Animals();
	Animals(const string & n, const string & sp, const string & s);
	Animals(const Animals&);
	~Animals();
	void print() const;
};


Animals::Animals(){
	cout << "Default constructor\t";
}

Animals::Animals(const string & n, const string & sp, const string & s)
	: name(n), specie(sp), sound(s) {
	cout << "Constructor with arguments\t";
};

Animals::Animals(const Animals& a){
	cout << "Constructor copycat\t";
	name	= clonePrefixe + a.name;
	specie	= a.specie;
	sound	= a.sound;
};

Animals::~Animals()
{
	cout << "Destructor \t"
		<< "Destroys " << name.c_str()
		<< " the " << specie.c_str()
		<< " who says " << sound.c_str()
		<< endl;
};

void Animals::print() const{
	cout << "Today I met " << name.c_str()
		<< " the " << specie.c_str()
		<< " it said " << sound.c_str()
		<< "\n";
}
int main()
{
	Animals a;
	a.print();

	const Animals b("Mary" , "llama" , "mggmum");
	b.print();

	const Animals c = b;
	c.print();

	return 0;
}