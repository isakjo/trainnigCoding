#include <iostream>
#include <string>

using namespace std;

struct Animal
{
	virtual ~Animal() { }
	virtual string sound() = 0;
	void setName(const string& s) { name = s; }
	string getName() const { return name; }
private:
	string name;
};

class Chicken : public Animal
{
public:
	string sound() { return "꼬끼오"; }
};

class Cat : public Animal
{
public:
	string sound() { return "야옹"; }
};

class Cow : public Animal
{
public:
	string sound() { return "음메"; }
};

class Pig : public Animal
{
public:
	string sound() { return "꿀꿀"; }
};

class Mouse : public Animal
{
public:
	string sound() { return "찍찍"; }
};

int main()
{
	enum ANIMAL {CHICKEN=1, CAT, COW, PIG, MOUSE};
	string name[] = { "", "장닭", "톰", "미노타우르스", "저팔계", "제리" };

	Animal *pAnimal;
	int select;
	char cont;

	do{
		cout << "동물 하나를 선택하시오. (1)닭, (2)고양이, (3)소, (4)돼지, (5)쥐: ";
		cin >> select;

		switch(select) {
		case CHICKEN:
			pAnimal = new Chicken();
			break;
		case CAT:
			pAnimal = new Cat();
			break;
		case COW:
			pAnimal = new Cow();
			break;
		case PIG:
			pAnimal = new Pig();
			break;
		case MOUSE:
			pAnimal = new Mouse();
			break;
		default:
			pAnimal = 0;
			break;
		}

		if(pAnimal != 0) {
			pAnimal->setName(name[select]);

			cout << "이름 : " << pAnimal->getName() << endl;
			cout << "울음 : " << pAnimal->sound() << endl;

			delete pAnimal;
		}
		else {
			cout << "선택한 동물 없음!\n";
		}

		cout << "continue? (y/n) ";
		cin >> cont;
	} while(cont == 'Y' || cont == 'y');

	return 0;
}
