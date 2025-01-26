class SlowPath
{
private:
    /* data */
public:
    SlowPath(/* args */) {};
    ~SlowPath() {};

    bool validationA(){ return true; };
    void handleValidationFailureA(){};

    bool validationB(){ return true; };
    void handleValidationFailureB(){};

    bool validationC(){ return true; };
    void handleValidationFailureD(){};

    void latencyCriticalActivity() {
        if (validationA() == false) {
            handleValidationFailureA();
        }
        else if (validationB() == false) {
            handleValidationFailureB();
        }
        else if (validationC() == false) {
            handleValidationFailureD();
        }
        else {
            sendMessage();
        }
    };

    void sendMessage() {
        // sends message
        // get network card and flip a bit
    }
};

class OptimizedPath
{

    private:
        int isValid = 1;
    public:
        void latencyCriticalActivity() {
            if (isValid) {
                sendMessage();
            }
            else {
                handleValidationFailure();
            }
        };

        void sendMessage() {
            // sends message
            // get network card and flip a bit
        }

        void handleValidationFailure() {
            
        }

        void setIsValid(const int& _) {
            isValid = _;
        }




};

