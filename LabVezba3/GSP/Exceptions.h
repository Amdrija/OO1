#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <ostream>
class Exception {
	virtual void write(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const Exception& e);
};

class CurrentElementMissingException : public Exception {
	void write(std::ostream& os) const;
};


#endif
