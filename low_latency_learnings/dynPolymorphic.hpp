class DynPolymorphic {
	public:
		__attribute__((always_inline))
		virtual void doSomething(){ i--;};
	int i = 0;
};

class SpecificDynPolymorphic : public DynPolymorphic {
	public:
		__attribute__((always_inline))
		void doSomething() override {
			i++;
		}
};

class SpecificDynPolymorphic2 : public DynPolymorphic {
	public:
		inline virtual void doSomething() override {
			i++;
			// std::cout << "SpecificDynPolymorphic actually did somthing" << std::endl;
		}
};
