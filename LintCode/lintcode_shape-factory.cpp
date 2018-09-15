/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
    
};

class Rectangle: public Shape {
    // Write your code here
public:
    void draw() const{
        puts(" ---- ");
        puts("|    |");
        puts(" ---- ");
    }
};

class Square: public Shape {
    // Write your code here
public:
    void draw() const{
        puts(" ---- ");
        puts("|    |");
        puts("|    |");
        puts(" ----");
    }
};

class Triangle: public Shape {
    // Write your code here
public:
    void draw() const{
        puts("  /\\");
        puts(" /  \\");
        puts("/____\\");
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        // Write your code here
        if(shapeType == "Rectangle")
            return new Rectangle();
        else if(shapeType == "Square")
            return new Square();
        else if(shapeType == "Triangle")
            return new Triangle();
            
        return NULL;
    }
    
};
