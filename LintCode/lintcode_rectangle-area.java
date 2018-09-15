/**
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
public class Rectangle {
    /*
     * Define two public attributes width and height of type int.
     */
    private int width;
    private int height;

    /*
     * Define a constructor which expects two parameters width and height here.
     */
    public Rectangle(int width, int height){
        this.width = width;
        this.height = height;
    }
    
    /*
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
     */
    public int getArea(){
        //TODO: throw exception if width or height is illegal
        if(isWidthOrHeightInValid())
            return -1;
        return width*height;
    }
    
    private boolean isWidthOrHeightInValid(){
        return width < 0 || height < 0;
    }
}
