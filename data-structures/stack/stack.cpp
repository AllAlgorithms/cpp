#define STACK_MAX 100

class Stack {

    private:
        int        data[STACK_MAX];
        int        size;

    public:
        Stack() {       // Constructor
            size = 0;
        }

        ~Stack() { }    // Destructor

        int Top() {

            if (size == 0) {
                fprintf(stderr, "Error: stack empty\n");
                return -1;
            }
            return data[size-1];
        }

        void Push(int d) {

            if (size < STACK_MAX)
                data[size++] = d;
            else
                fprintf(stderr, "Error: stack full\n");
        }

        void Pop() {

            if (size == 0)
                fprintf(stderr, "Error: stack empty\n");
            else
                size--;
        }
};
