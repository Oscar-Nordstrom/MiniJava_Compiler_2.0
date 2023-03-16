public class Factorial {
    public static void main(String[] a) {
        System.out.println(new Pemis().Pen(1, 2));

    }
}

class Factorial {
    int a;
    int a;//fail

    public boolean func() {
        return true;
    }

    public int func() {
        return 1;
    }//fail
}//fail

class Pemis {
    boolean b;
    boolean b;//fail

    public int Pen(int param, int param) {//fail
        return 1;
    }

    public int Pen2(int param) {
        int param; //fail
        return 1;
    }
}
