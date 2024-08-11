class MyClass {
    int x;
    String name;

    // Default constructor
    public MyClass() {
        this(0, "Default"); // Calls the parameterized constructor with default values
    }

    // Parameterized constructor with one parameter
    public MyClass(int x) {
        this(x, "Unknown"); // Calls the two-parameter constructor with a default name
    }

    // Parameterized constructor with two parameters
    public MyClass(int x, String name) {
        this.x = x;
        this.name = name;
    }

    public void display() {
        System.out.println("X: " + x);
        System.out.println("Name: " + name);
    }
    
}
public class Main {
    public static void main(String[] args) {
        MyClass obj1 = new MyClass();
        obj1.display();

        MyClass obj2 = new MyClass(10);
        obj2.display();

        MyClass obj3 = new MyClass(20, "Custom");
        obj3.display();
    }
}

