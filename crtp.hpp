template <class T>
class CRTP {
	public:	
	inline void doSomething() {
		static_cast<T*>(this)->actuallyDoSomething();
	}

	inline void actuallyDoSomething() {
		// std::cout << "CRTP actually did something" << std::endl;
	}

	int i = 0;

};

class SpecificCRTP : public CRTP<SpecificCRTP> {
	
	public:
	__attribute__((always_inline))
	void actuallyDoSomething() {
		i++;
	}

};

class SpecificCRTP2 : public CRTP<SpecificCRTP> {
	
	public: 
	inline void actuallyDoSomething() {
		i++;
		// std::cout << "SpecificCRTP actually did something" << std::endl;
	}

};

