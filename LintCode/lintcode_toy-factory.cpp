/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
 /*
 *
 * Tag: Implementation
 * Time: O(1)
 * Space: O(1)
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
public:
    void talk() const {
        puts("Wow");
    }
};

class Cat: public Toy {
    // Write your code here
public:
    void talk() const {
        puts("Meow");
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if(type == "Dog")
            return new Dog();
        else if(type == "Cat")
            return new Cat();
        else
            return NULL;
    }
};
