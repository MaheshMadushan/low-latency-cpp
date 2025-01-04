class DynPolymorphic {
	public:
		virtual void doSomething(){ i--;};
	int i = 0;
};

class SpecificDynPolymorphic : public DynPolymorphic {
	public:
		inline virtual void doSomething() override {
			i++;
			// std::cout << "SpecificDynPolymorphic actually did somthing" << std::endl;
		}

		
};

class SpecificDynPolymorphic2 : public DynPolymorphic {
	public:
		inline virtual void doSomething() override {
			i++;
			// std::cout << "SpecificDynPolymorphic actually did somthing" << std::endl;
		}
};
