#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <ostream>
class Exception {
	virtual void write(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os ,const Exception& e);
};

class InsecurePasswordException : public Exception {
	void write(std::ostream& os) const override;
};

class WrongPasswordException : public Exception {
	void write(std::ostream& os) const override;
};

class ElementIndexOutOfBoundsException : public Exception {
	void write(std::ostream& os) const override;
};

class UserAlreadyExistsException : public Exception {
	void write(std::ostream& os) const override;
};

class UserNotFoundException : public Exception {
	void write(std::ostream& os) const override;
};

#endif
