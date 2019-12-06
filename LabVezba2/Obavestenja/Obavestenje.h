#ifndef OBAVESTENJE_H
#define OBAVESTENJE_H

#include <ctime>
#include <iostream>

class Korisnik;

class Obavestenje
{
public:
	//Korisnik je friend da bi mogao da kada prima obavestenje
	//da postavi pokazivac obavestenja na sebe
	friend Korisnik;
	Obavestenje(Korisnik*);
	Obavestenje(const Obavestenje&);
	Obavestenje(Obavestenje&&);
	Obavestenje& operator=(const Obavestenje&);
	Obavestenje& operator=(Obavestenje&&);
	//koristimo default destruktor
	int getID() const;
	Korisnik* getUser() const;
	bool isRead() const;
	bool readNotification();
	friend std::ostream& operator<<(std::ostream& os, const Obavestenje& o);
protected:
	//koristimo da bi u naslednjeim klasama mogli da ispisujemo
	//specificne stvari za tu nasledjenu klasu
	virtual void write(std::ostream&) const {}
private:
	static int setID;
	time_t creation_time = time(NULL);
	int id = ++setID;
	bool read = false;
	Korisnik* user;
	void copy(const Obavestenje&);
	void move(Obavestenje&);
};

#endif

